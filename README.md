# CourierEase

CourierEase is a desktop-based Courier Delivery Management System developed using C++/CLI, Windows Forms, MySQL, and .NET Framework.

The system allows customers to register, log in, book parcels, track deliveries, manage their profiles, and view delivery history. Administrators can manage deliveries, delivery staff, and parcel statuses.

---

## Technologies Used

- C++/CLI
- Windows Forms
- .NET Framework 4.7.2
- MySQL
- MySQL Connector/NET
- Visual Studio
- Git
- GitHub

---

## Main Features

### Customer Features

- Customer registration
- Customer login
- Customer profile management
- Book parcels
- Edit parcel details
- Cancel eligible parcel bookings
- View delivery history
- Track parcel status

### Administrator Features

- Admin login
- Admin dashboard
- View and manage deliveries
- Assign delivery boys
- Update delivery status
- Add delivery boys
- Edit delivery boy information
- Delete delivery boys
- View delivery statistics

---

## Object-Oriented Programming Concepts

CourierEase demonstrates the main Object-Oriented Programming concepts used in the project.

### Class and Object

Classes such as:

- `Customer`
- `Parcel`
- `DeliveryService`
- `StandardDelivery`
- `ExpressDelivery`

are used to represent system entities and behaviour.

### Encapsulation

Classes use private fields and public properties to control access to data.

### Abstraction

`DeliveryService` is implemented as an abstract class.

### Inheritance

`StandardDelivery` and `ExpressDelivery` inherit from `DeliveryService`.

### Polymorphism

Both delivery classes override the same virtual functions:

```cpp
CalculateCharge()
GetServiceName()
```

This allows different delivery services to calculate charges through the same base class interface.

---

## Delivery Services

### Standard Delivery

```text
Base charge: Rs. 250.00
Charge per kg: Rs. 80.00
```

### Express Delivery

```text
Base charge: Rs. 400.00
Charge per kg: Rs. 120.00
```

The final delivery charge is calculated according to the selected service and parcel weight.

---

## Database

CourierEase uses a MySQL database named:

```text
courierease_db
```

The database contains the following tables:

- `customers`
- `admins`
- `delivery_boys`
- `parcels`
- `deliveries`
- `status_history`

---

## Password Security

CourierEase does not store customer or administrator passwords as plain text.

Passwords are hashed using:

```text
PBKDF2
SHA-256
100,000 iterations
16-byte random salt
32-byte derived hash
```

The stored format is:

```text
Base64Salt:Base64Hash
```

Password hashing and verification are handled by:

```text
PasswordHasher.h
```

---

## Database Connection

The MySQL root password is not stored directly in the source code.

CourierEase uses Windows user environment variables:

```text
COURIEREASE_DB_PASSWORD
COURIEREASE_DB_PORT
```

These values are configured automatically by the included PowerShell setup script.

The database connection is handled by:

```text
DatabaseConnection.h
```

This allows different computers to use different MySQL passwords and port numbers without editing the source code.

---

# Setup Guide

Follow these steps to run CourierEase on a new Windows computer.

---

## 1. Install Required Software

Install the following first:

- Git for Windows
- Visual Studio
- MySQL Server
- MySQL Workbench
- MySQL Connector/NET

### Required Visual Studio Components

Open Visual Studio Installer and install:

```text
Desktop development with C++
C++/CLI support
.NET Framework 4.7.2 targeting pack
.NET Framework 4.7.2 SDK
Windows SDK
MSVC Build Tools for x64/x86
```

---

## 2. Clone the Repository

Open PowerShell and go to the normal Visual Studio repository folder:

```powershell
cd C:\Users\YOURNAME\source\repos
```

Replace `YOURNAME` with the Windows username of the computer.

Clone CourierEase:

```powershell
git clone https://github.com/Isurika-Aberathne/CourierEase.git
```

Enter the project folder:

```powershell
cd CourierEase
```

---

## 3. Run the Automatic Database Setup

Allow PowerShell scripts for the current terminal session:

```powershell
Set-ExecutionPolicy -Scope Process Bypass
```

Run the setup script:

```powershell
.\setup-courierease.ps1
```

The setup script will automatically:

- Find `mysql.exe`
- Ask for the MySQL root password
- Check MySQL port `3306`
- Check MySQL port `3307`
- Ask for another port if required
- Create the `courierease_db` database
- Create all required tables
- Create all required foreign keys
- Ask for an administrator username
- Ask for the administrator full name
- Ask for the administrator password
- Generate the administrator password hash
- Create or update the administrator account
- Create the `COURIEREASE_DB_PASSWORD` environment variable
- Create the `COURIEREASE_DB_PORT` environment variable
- Verify the administrator account

---

## 4. Example Database Setup

The setup may look similar to this:

```text
========================================
       CourierEase Database Setup
========================================

MySQL found:
C:\Program Files\MySQL\MySQL Server 8.0\bin\mysql.exe

Enter MySQL root password:

Detecting MySQL port...

MySQL detected on port 3306

Enter CourierEase admin username:
Enter admin full name:
Enter CourierEase admin password:
```

Passwords are hidden while typing.

---

## 5. MySQL Port Support

The setup script automatically checks:

```text
3306
3307
```

If MySQL is running on another port, the script asks for that port.

The selected port is stored in:

```text
COURIEREASE_DB_PORT
```

This allows CourierEase to run on different computers without changing the database port in the source code.

---

## 6. Restart Visual Studio

After the setup script completes:

1. Close Visual Studio if it is open.
2. Open Visual Studio again.

This allows Visual Studio to load the newly created environment variables.

---

## 7. Open the Project

Open:

```text
C:\Users\YOURNAME\source\repos\CourierEase\CourrierEase.slnx
```

The application branding is:

```text
CourierEase
```

The internal project and namespace use:

```text
CourrierEase
```

Do not rename the internal project or namespace because this may affect the C++/CLI Windows Forms Designer.

---

## 8. Build the Project

In Visual Studio select:

```text
Configuration: Debug
Platform: x64
```

Then select:

```text
Build -> Rebuild Solution
```

Wait until the build completes successfully.

---

## 9. Run CourierEase

Press:

```text
F5
```

or click the green Start button in Visual Studio.

---

# Quick Setup

After installing Git, Visual Studio, MySQL, and MySQL Connector/NET, run:

```powershell
cd C:\Users\YOURNAME\source\repos
git clone https://github.com/Isurika-Aberathne/CourierEase.git
cd CourierEase
Set-ExecutionPolicy -Scope Process Bypass
.\setup-courierease.ps1
```

Then:

```text
1. Close and reopen Visual Studio
2. Open CourrierEase.slnx
3. Select Debug
4. Select x64
5. Rebuild Solution
6. Press F5
```

---

# Working with Git

Before starting work:

```powershell
git pull
```

After making and testing changes:

```powershell
git status
git add .
git commit -m "Describe your changes"
git push
```

Always pull before working on another computer and push before switching computers.

---

# Important Security Notes

Do not commit:

```text
MySQL root password
Administrator plaintext password
Customer plaintext passwords
COURIEREASE_DB_PASSWORD value
```

The MySQL password is stored only in the local Windows user environment.

Administrator and customer passwords are stored in the database as password hashes.

---

# Generated Visual Studio Files

The following generated folders should not be committed:

```text
.vs/
x64/
Debug/
Release/
```

They are ignored using `.gitignore`.

If the Windows Forms Designer stops loading correctly, close Visual Studio and remove the generated folders:

```powershell
Remove-Item -Recurse -Force .vs
Remove-Item -Recurse -Force x64
Remove-Item -Recurse -Force .\CourrierEase\x64
```

Then reopen Visual Studio and rebuild the solution.

---

# Project Structure

```text
CourierEase/
|
|-- .gitignore
|-- README.md
|-- database.sql
|-- setup-courierease.ps1
|-- CourrierEase.slnx
|
`-- CourrierEase/
    |
    |-- DatabaseConnection.h
    |-- PasswordHasher.h
    |-- DeliveryService.h
    |-- Customer.h
    |-- Parcel.h
    |
    |-- MainForm.cpp
    |-- MainForm.h
    |
    |-- LoginFormDesigner.h
    |-- RegisterFormDesigner.h
    |-- CustomerDashboardDesigner.h
    |-- BookParcelFormDesigner.h
    |-- MyDeliveriesFormDesigner.h
    |-- EditParcelFormDesigner.h
    |-- CustomerProfileDesigner.h
    |
    |-- AdminLoginDesigner.h
    |-- AdminDashboardDesigner.h
    |-- ManageDeliveriesDesigner.h
    |-- DeliveryBoysDesigner.h
    |
    `-- other project files
```

---

## Database Setup Files

The project contains:

```text
database.sql
setup-courierease.ps1
```

`setup-courierease.ps1` is the recommended setup method because it automatically creates the database, detects the MySQL port, creates an administrator account, and configures the required environment variables.

`database.sql` can be used as a manual schema reference.

---

## Project Information

**Project Name:** CourierEase  
**Project Type:** Courier Delivery Management System  
**Application Type:** Windows Desktop Application  
**Programming Language:** C++/CLI  
**GUI Framework:** Windows Forms  
**Database:** MySQL  
**Framework:** .NET Framework 4.7.2
