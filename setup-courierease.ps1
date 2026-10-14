# CourierEase Database Setup

Clear-Host

Write-Host ""
Write-Host "========================================"
Write-Host "       CourierEase Database Setup"
Write-Host "========================================"
Write-Host ""

# Find mysql.exe
$mysql = $null

$command = Get-Command mysql.exe -ErrorAction SilentlyContinue

if ($command)
{
    $mysql = $command.Source
}

if (-not $mysql)
{
    $possibleMySql =
        Get-ChildItem `
            "C:\Program Files\MySQL" `
            -Filter mysql.exe `
            -Recurse `
            -ErrorAction SilentlyContinue |
        Where-Object {
            $_.FullName -match "\\bin\\mysql.exe$"
        } |
        Select-Object -First 1

    if ($possibleMySql)
    {
        $mysql = $possibleMySql.FullName
    }
}

if (-not $mysql)
{
    Write-Host ""
    Write-Host "MySQL client was not found."
    Write-Host "Install MySQL Server before running this setup."
    Write-Host ""
    exit 1
}

Write-Host "MySQL found:"
Write-Host $mysql
Write-Host ""

# MySQL password
$secureMySqlPassword =
    Read-Host "Enter MySQL root password" -AsSecureString

$mysqlPtr =
    [Runtime.InteropServices.Marshal]::SecureStringToBSTR(
        $secureMySqlPassword
    )

$mysqlPassword =
    [Runtime.InteropServices.Marshal]::PtrToStringBSTR(
        $mysqlPtr
    )

# Temporary password for mysql.exe
$env:MYSQL_PWD = $mysqlPassword

# Detect port
Write-Host ""
Write-Host "Detecting MySQL port..."

$mysqlPort = $null

$commonPorts = @(3306, 3307)

foreach ($port in $commonPorts)
{
    & $mysql `
        -h 127.0.0.1 `
        -P $port `
        -u root `
        --connect-timeout=2 `
        -N `
        -e "SELECT 1;" `
        2>$null |
        Out-Null

    if ($LASTEXITCODE -eq 0)
    {
        $mysqlPort = $port
        break
    }
}

# Ask for another port if needed
if (-not $mysqlPort)
{
    Write-Host ""
    Write-Host "MySQL was not detected on port 3306 or 3307."

    $mysqlPort =
        Read-Host "Enter MySQL port number"

    & $mysql `
        -h 127.0.0.1 `
        -P $mysqlPort `
        -u root `
        --connect-timeout=3 `
        -N `
        -e "SELECT 1;" `
        2>$null |
        Out-Null

    if ($LASTEXITCODE -ne 0)
    {
        Write-Host ""
        Write-Host "Unable to connect to MySQL."
        Write-Host "Check the password, server and port."
        Write-Host ""

        Remove-Item Env:\MYSQL_PWD -ErrorAction SilentlyContinue

        [Runtime.InteropServices.Marshal]::ZeroFreeBSTR(
            $mysqlPtr
        )

        exit 1
    }
}

Write-Host ""
Write-Host "MySQL detected on port $mysqlPort"
Write-Host ""

# Admin details
$adminUsername =
    Read-Host "Enter CourierEase admin username"

if ([String]::IsNullOrWhiteSpace($adminUsername))
{
    $adminUsername = "admin"
}

$adminFullName =
    Read-Host "Enter admin full name"

if ([String]::IsNullOrWhiteSpace($adminFullName))
{
    $adminFullName = "System Administrator"
}

$secureAdminPassword =
    Read-Host "Enter CourierEase admin password" -AsSecureString

$adminPtr =
    [Runtime.InteropServices.Marshal]::SecureStringToBSTR(
        $secureAdminPassword
    )

$adminPassword =
    [Runtime.InteropServices.Marshal]::PtrToStringBSTR(
        $adminPtr
    )

# Generate password hash to match PasswordHasher.h
$salt = New-Object byte[] 16

$rng =
    [System.Security.Cryptography.RandomNumberGenerator]::Create()

$rng.GetBytes($salt)
$rng.Dispose()

$pbkdf2 =
    [System.Security.Cryptography.Rfc2898DeriveBytes]::new(
        $adminPassword,
        $salt,
        100000,
        [System.Security.Cryptography.HashAlgorithmName]::SHA256
    )

$hash = $pbkdf2.GetBytes(32)

$pbkdf2.Dispose()

$saltText =
    [Convert]::ToBase64String($salt)

$hashText =
    [Convert]::ToBase64String($hash)

$storedAdminPassword =
    $saltText + ":" + $hashText

# Escape SQL values
$adminUsernameSql =
    $adminUsername.Replace("'", "''")

$adminFullNameSql =
    $adminFullName.Replace("'", "''")

$adminPasswordSql =
    $storedAdminPassword.Replace("'", "''")

# SQL
$sql = @"
CREATE DATABASE IF NOT EXISTS courierease_db;
USE courierease_db;

CREATE TABLE IF NOT EXISTS customers (
    customer_id INT AUTO_INCREMENT PRIMARY KEY,
    full_name VARCHAR(60) NOT NULL,
    phone VARCHAR(15) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    address VARCHAR(150) NOT NULL,
    password_hash VARCHAR(255) NOT NULL,
    created_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS admins (
    admin_id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(30) NOT NULL UNIQUE,
    full_name VARCHAR(60) NOT NULL,
    password_hash VARCHAR(255) NOT NULL,
    created_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS delivery_boys (
    boy_id INT AUTO_INCREMENT PRIMARY KEY,
    full_name VARCHAR(60) NOT NULL,
    phone VARCHAR(15) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    vehicle_no VARCHAR(20) NOT NULL,
    is_active TINYINT(1) NOT NULL DEFAULT 1,
    created_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS parcels (
    parcel_id INT AUTO_INCREMENT PRIMARY KEY,
    tracking_no VARCHAR(25) NOT NULL UNIQUE,
    customer_id INT NOT NULL,
    receiver_name VARCHAR(60) NOT NULL,
    receiver_phone VARCHAR(15) NOT NULL,
    receiver_address VARCHAR(150) NOT NULL,
    receiver_city VARCHAR(50) NOT NULL,
    description VARCHAR(120) NOT NULL,
    weight_kg DECIMAL(6,2) NOT NULL,
    parcel_type VARCHAR(20) NOT NULL,
    declared_value DECIMAL(12,2) NOT NULL DEFAULT 0,
    created_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,

    CONSTRAINT fk_parcel_customer
        FOREIGN KEY (customer_id)
        REFERENCES customers(customer_id)
);

CREATE TABLE IF NOT EXISTS deliveries (
    delivery_id INT AUTO_INCREMENT PRIMARY KEY,
    parcel_id INT NOT NULL UNIQUE,
    boy_id INT NULL,
    delivery_option VARCHAR(20) NOT NULL,
    charge DECIMAL(10,2) NOT NULL,
    pickup_address VARCHAR(150) NOT NULL,
    status VARCHAR(30) NOT NULL DEFAULT 'Order Placed',
    created_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
        ON UPDATE CURRENT_TIMESTAMP,

    CONSTRAINT fk_delivery_parcel
        FOREIGN KEY (parcel_id)
        REFERENCES parcels(parcel_id)
        ON DELETE CASCADE,

    CONSTRAINT fk_delivery_boy
        FOREIGN KEY (boy_id)
        REFERENCES delivery_boys(boy_id)
        ON DELETE SET NULL
);

CREATE TABLE IF NOT EXISTS status_history (
    history_id INT AUTO_INCREMENT PRIMARY KEY,
    delivery_id INT NOT NULL,
    admin_id INT NULL,
    status VARCHAR(30) NOT NULL,
    changed_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,

    CONSTRAINT fk_history_delivery
        FOREIGN KEY (delivery_id)
        REFERENCES deliveries(delivery_id)
        ON DELETE CASCADE,

    CONSTRAINT fk_history_admin
        FOREIGN KEY (admin_id)
        REFERENCES admins(admin_id)
        ON DELETE SET NULL
);

INSERT INTO admins (
    username,
    full_name,
    password_hash
)
VALUES (
    '$adminUsernameSql',
    '$adminFullNameSql',
    '$adminPasswordSql'
)
ON DUPLICATE KEY UPDATE
    full_name = VALUES(full_name),
    password_hash = VALUES(password_hash);
"@

# Create database
Write-Host ""
Write-Host "Creating CourierEase database..."
Write-Host ""

$sql |
    & $mysql `
        -h 127.0.0.1 `
        -P $mysqlPort `
        -u root

if ($LASTEXITCODE -ne 0)
{
    Write-Host ""
    Write-Host "Database setup failed."
    Write-Host ""

    Remove-Item Env:\MYSQL_PWD -ErrorAction SilentlyContinue

    [Runtime.InteropServices.Marshal]::ZeroFreeBSTR(
        $mysqlPtr
    )

    [Runtime.InteropServices.Marshal]::ZeroFreeBSTR(
        $adminPtr
    )

    exit 1
}

# Save environment variables
[Environment]::SetEnvironmentVariable(
    "COURIEREASE_DB_PASSWORD",
    $mysqlPassword,
    "User"
)

[Environment]::SetEnvironmentVariable(
    "COURIEREASE_DB_PORT",
    "$mysqlPort",
    "User"
)

# Verify admin
Write-Host "Verifying database..."

$verification =
    & $mysql `
        -h 127.0.0.1 `
        -P $mysqlPort `
        -u root `
        -N `
        -e "
            USE courierease_db;
            SELECT username
            FROM admins
            WHERE username='$adminUsernameSql';
        "

if ($verification -ne $adminUsername)
{
    Write-Host ""
    Write-Host "Admin verification failed."
    Write-Host ""

    Remove-Item Env:\MYSQL_PWD -ErrorAction SilentlyContinue
    exit 1
}

# Clean sensitive values
Remove-Item Env:\MYSQL_PWD -ErrorAction SilentlyContinue

[Runtime.InteropServices.Marshal]::ZeroFreeBSTR(
    $mysqlPtr
)

[Runtime.InteropServices.Marshal]::ZeroFreeBSTR(
    $adminPtr
)

$mysqlPassword = $null
$adminPassword = $null
$storedAdminPassword = $null

# Success
Write-Host ""
Write-Host "========================================"
Write-Host "   CourierEase Setup Completed"
Write-Host "========================================"
Write-Host ""

Write-Host "Database       : courierease_db"
Write-Host "MySQL Server   : 127.0.0.1"
Write-Host "MySQL Port     : $mysqlPort"
Write-Host "Admin Username : $adminUsername"

Write-Host ""
Write-Host "Environment variables created:"
Write-Host "COURIEREASE_DB_PASSWORD"
Write-Host "COURIEREASE_DB_PORT"

Write-Host ""
Write-Host "Close and reopen Visual Studio."
Write-Host "CourierEase is ready to run."
Write-Host ""