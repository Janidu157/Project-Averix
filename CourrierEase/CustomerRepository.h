#pragma once

#include "DatabaseConnection.h"
#include "Customer.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace CourrierEase
{
    public ref class CustomerRepository
    {
    public:

        // CREATE CUSTOMER
        static bool CreateCustomer(
            Customer^ customer,
            String^ passwordHash)
        {
            MySqlConnection^ connection =
                DatabaseConnection::GetConnection();

            try
            {
                connection->Open();

                String^ query =
                    "INSERT INTO customers "
                    "(full_name, phone, email, address, password_hash) "
                    "VALUES "
                    "(@name, @phone, @email, @address, @password)";

                MySqlCommand^ command =
                    gcnew MySqlCommand(query, connection);

                command->Parameters->AddWithValue(
                    "@name",
                    customer->FullName
                );

                command->Parameters->AddWithValue(
                    "@phone",
                    customer->Phone
                );

                command->Parameters->AddWithValue(
                    "@email",
                    customer->Email
                );

                command->Parameters->AddWithValue(
                    "@address",
                    customer->Address
                );

                command->Parameters->AddWithValue(
                    "@password",
                    passwordHash
                );

                int rows =
                    command->ExecuteNonQuery();

                connection->Close();

                return rows > 0;
            }
            catch (Exception^)
            {
                if (connection->State ==
                    System::Data::ConnectionState::Open)
                {
                    connection->Close();
                }

                throw;
            }
        }

        // FIND CUSTOMER FOR LOGIN
        static bool GetCustomerLogin(
            String^ email,
            int% customerId,
            String^% fullName,
            String^% passwordHash)
        {
            MySqlConnection^ connection =
                DatabaseConnection::GetConnection();

            try
            {
                connection->Open();

                String^ query =
                    "SELECT customer_id, full_name, password_hash "
                    "FROM customers "
                    "WHERE email = @email "
                    "LIMIT 1";

                MySqlCommand^ command =
                    gcnew MySqlCommand(query, connection);

                command->Parameters->AddWithValue(
                    "@email",
                    email
                );

                MySqlDataReader^ reader =
                    command->ExecuteReader();

                if (reader->Read())
                {
                    customerId =
                        Convert::ToInt32(
                            reader["customer_id"]
                        );

                    fullName =
                        reader["full_name"]->ToString();

                    passwordHash =
                        reader["password_hash"]->ToString();

                    reader->Close();
                    connection->Close();

                    return true;
                }

                reader->Close();
                connection->Close();

                return false;
            }
            catch (Exception^)
            {
                if (connection->State ==
                    System::Data::ConnectionState::Open)
                {
                    connection->Close();
                }

                throw;
            }
        }

        // READ CUSTOMER PROFILE
        static DataRow^ GetCustomerById(
            int customerId)
        {
            MySqlConnection^ connection =
                DatabaseConnection::GetConnection();

            try
            {
                connection->Open();

                String^ query =
                    "SELECT "
                    "customer_id, full_name, phone, email, address, created_at "
                    "FROM customers "
                    "WHERE customer_id = @customerId "
                    "LIMIT 1";

                MySqlCommand^ command =
                    gcnew MySqlCommand(query, connection);

                command->Parameters->AddWithValue(
                    "@customerId",
                    customerId
                );

                MySqlDataAdapter^ adapter =
                    gcnew MySqlDataAdapter(command);

                DataTable^ table =
                    gcnew DataTable();

                adapter->Fill(table);

                connection->Close();

                if (table->Rows->Count == 0)
                {
                    return nullptr;
                }

                return table->Rows[0];
            }
            catch (Exception^)
            {
                if (connection->State ==
                    System::Data::ConnectionState::Open)
                {
                    connection->Close();
                }

                throw;
            }
        }

        // UPDATE CUSTOMER PROFILE
        static bool UpdateCustomer(
            int customerId,
            String^ fullName,
            String^ phone,
            String^ email,
            String^ address)
        {
            MySqlConnection^ connection =
                DatabaseConnection::GetConnection();

            try
            {
                connection->Open();

                String^ query =
                    "UPDATE customers "
                    "SET full_name = @name, "
                    "phone = @phone, "
                    "email = @email, "
                    "address = @address "
                    "WHERE customer_id = @customerId";

                MySqlCommand^ command =
                    gcnew MySqlCommand(query, connection);

                command->Parameters->AddWithValue(
                    "@name",
                    fullName
                );

                command->Parameters->AddWithValue(
                    "@phone",
                    phone
                );

                command->Parameters->AddWithValue(
                    "@email",
                    email
                );

                command->Parameters->AddWithValue(
                    "@address",
                    address
                );

                command->Parameters->AddWithValue(
                    "@customerId",
                    customerId
                );

                int rows =
                    command->ExecuteNonQuery();

                connection->Close();

                return rows > 0;
            }
            catch (Exception^)
            {
                if (connection->State ==
                    System::Data::ConnectionState::Open)
                {
                    connection->Close();
                }

                throw;
            }
        }

        // DELETE CUSTOMER ACCOUNT
        static bool DeleteCustomer(
            int customerId)
        {
            MySqlConnection^ connection =
                DatabaseConnection::GetConnection();

            MySqlTransaction^ transaction = nullptr;

            try
            {
                connection->Open();

                transaction =
                    connection->BeginTransaction();

                // Delete parcels first.
                // Related deliveries and status history
                // are deleted by database cascade rules.
                String^ parcelQuery =
                    "DELETE FROM parcels "
                    "WHERE customer_id = @customerId";

                MySqlCommand^ parcelCommand =
                    gcnew MySqlCommand(
                        parcelQuery,
                        connection,
                        transaction
                    );

                parcelCommand->Parameters->AddWithValue(
                    "@customerId",
                    customerId
                );

                parcelCommand->ExecuteNonQuery();

                // Delete customer
                String^ customerQuery =
                    "DELETE FROM customers "
                    "WHERE customer_id = @customerId";

                MySqlCommand^ customerCommand =
                    gcnew MySqlCommand(
                        customerQuery,
                        connection,
                        transaction
                    );

                customerCommand->Parameters->AddWithValue(
                    "@customerId",
                    customerId
                );

                int rows =
                    customerCommand->ExecuteNonQuery();

                transaction->Commit();

                connection->Close();

                return rows > 0;
            }
            catch (Exception^)
            {
                if (transaction != nullptr)
                {
                    try
                    {
                        transaction->Rollback();
                    }
                    catch (Exception^)
                    {
                    }
                }

                if (connection->State ==
                    System::Data::ConnectionState::Open)
                {
                    connection->Close();
                }

                throw;
            }
        }
    };
}