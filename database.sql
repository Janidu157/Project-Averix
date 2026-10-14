CREATE DATABASE IF NOT EXISTS courierease_db;
USE courierease_db;

CREATE TABLE customers (
    customer_id INT AUTO_INCREMENT PRIMARY KEY,
    full_name VARCHAR(60) NOT NULL,
    phone VARCHAR(15) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    address VARCHAR(150) NOT NULL,
    password_hash VARCHAR(255) NOT NULL,
    created_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE admins (
    admin_id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(30) NOT NULL UNIQUE,
    full_name VARCHAR(60) NOT NULL,
    password_hash VARCHAR(255) NOT NULL,
    created_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE delivery_boys (
    boy_id INT AUTO_INCREMENT PRIMARY KEY,
    full_name VARCHAR(60) NOT NULL,
    phone VARCHAR(15) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    vehicle_no VARCHAR(20) NOT NULL,
    is_active TINYINT(1) NOT NULL DEFAULT 1,
    created_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE parcels (
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

CREATE TABLE deliveries (
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

CREATE TABLE status_history (
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
