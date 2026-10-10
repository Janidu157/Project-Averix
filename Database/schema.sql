-- Courier Service Management System - MySQL 8 schema
CREATE DATABASE IF NOT EXISTS courier_db CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
USE courier_db;

CREATE TABLE IF NOT EXISTS admins (
    admin_id      INT AUTO_INCREMENT PRIMARY KEY,
    username      VARCHAR(40)  NOT NULL UNIQUE,
    full_name     VARCHAR(60)  NOT NULL,
    password_hash VARCHAR(200) NOT NULL
);

CREATE TABLE IF NOT EXISTS customers (
    customer_id   INT AUTO_INCREMENT PRIMARY KEY,
    full_name     VARCHAR(60)  NOT NULL,
    phone         VARCHAR(15)  NOT NULL,
    email         VARCHAR(100) NOT NULL UNIQUE,
    address       VARCHAR(200) NOT NULL,
    password_hash VARCHAR(200) NOT NULL,
    created_at    DATETIME DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS delivery_boys (
    delivery_boy_id INT AUTO_INCREMENT PRIMARY KEY,
    full_name       VARCHAR(60)  NOT NULL,
    phone           VARCHAR(15)  NOT NULL,
    email           VARCHAR(100) NOT NULL UNIQUE,
    vehicle_no      VARCHAR(15)  NOT NULL,
    is_active       TINYINT(1)   NOT NULL DEFAULT 1,
    password_hash   VARCHAR(200) NOT NULL
);

CREATE TABLE IF NOT EXISTS parcels (
    parcel_id        INT AUTO_INCREMENT PRIMARY KEY,
    tracking_no      VARCHAR(20)  NOT NULL UNIQUE,
    customer_id      INT          NOT NULL,
    sender_name      VARCHAR(60)  NOT NULL,
    sender_phone     VARCHAR(15)  NOT NULL,
    sender_address   VARCHAR(200) NOT NULL,
    receiver_name    VARCHAR(60)  NOT NULL,
    receiver_phone   VARCHAR(15)  NOT NULL,
    receiver_address VARCHAR(200) NOT NULL,
    description      VARCHAR(200) NOT NULL,
    weight_kg        DOUBLE       NOT NULL,
    parcel_type      VARCHAR(30)  NOT NULL,
    delivery_option  VARCHAR(20)  NOT NULL,
    price            DECIMAL(10,2) NOT NULL,
    created_at       DATETIME DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT fk_parcel_customer FOREIGN KEY (customer_id) REFERENCES customers(customer_id) ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS deliveries (
    delivery_id     INT AUTO_INCREMENT PRIMARY KEY,
    parcel_id       INT NOT NULL UNIQUE,
    delivery_boy_id INT NULL,
    status          VARCHAR(40) NOT NULL DEFAULT 'Order Placed',
    updated_at      DATETIME DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    CONSTRAINT fk_delivery_parcel FOREIGN KEY (parcel_id) REFERENCES parcels(parcel_id) ON DELETE CASCADE,
    CONSTRAINT fk_delivery_boy FOREIGN KEY (delivery_boy_id) REFERENCES delivery_boys(delivery_boy_id) ON DELETE SET NULL
);

CREATE TABLE IF NOT EXISTS delivery_status_history (
    history_id  INT AUTO_INCREMENT PRIMARY KEY,
    delivery_id INT NOT NULL,
    status      VARCHAR(40) NOT NULL,
    note        VARCHAR(255),
    changed_at  DATETIME DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT fk_history_delivery FOREIGN KEY (delivery_id) REFERENCES deliveries(delivery_id) ON DELETE CASCADE
);
