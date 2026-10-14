#pragma once

using namespace System;
using namespace MySql::Data::MySqlClient;

namespace CourrierEase
{
    public ref class DatabaseConnection
    {
    private:

        static String^ GetConnectionString()
        {
            String^ password =
                Environment::GetEnvironmentVariable(
                    "COURIEREASE_DB_PASSWORD"
                );

            if (String::IsNullOrWhiteSpace(password))
            {
                throw gcnew InvalidOperationException(
                    "COURIEREASE_DB_PASSWORD environment variable is not configured."
                );
            }

            String^ port =
                Environment::GetEnvironmentVariable(
                    "COURIEREASE_DB_PORT"
                );

            if (String::IsNullOrWhiteSpace(port))
            {
                port = "3306";
            }

            return
                "server=127.0.0.1;"
                "port=" + port + ";"
                "database=courierease_db;"
                "uid=root;"
                "pwd=" + password + ";";
        }

    public:

        static MySqlConnection^ GetConnection()
        {
            return gcnew MySqlConnection(
                GetConnectionString()
            );
        }
    };
}