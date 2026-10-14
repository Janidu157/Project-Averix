#pragma once

#include "DatabaseConnection.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace CourrierEase
{
    public ref class DashboardRepository
    {
    public:

        // =========================================================
        // TOTAL DELIVERIES
        // =========================================================

        static int GetTotalDeliveries(int customerId)
        {
            String^ query =
                "SELECT COUNT(*) "
                "FROM parcels p "
                "INNER JOIN deliveries d "
                "ON p.parcel_id = d.parcel_id "
                "WHERE p.customer_id = @customerId";

            return GetCount(
                query,
                customerId
            );
        }

        // =========================================================
        // IN TRANSIT
        // =========================================================

        static int GetInTransitDeliveries(int customerId)
        {
            String^ query =
                "SELECT COUNT(*) "
                "FROM parcels p "
                "INNER JOIN deliveries d "
                "ON p.parcel_id = d.parcel_id "
                "WHERE p.customer_id = @customerId "
                "AND d.status = 'In Transit'";

            return GetCount(
                query,
                customerId
            );
        }

        // =========================================================
        // DELIVERED
        // =========================================================

        static int GetDeliveredDeliveries(int customerId)
        {
            String^ query =
                "SELECT COUNT(*) "
                "FROM parcels p "
                "INNER JOIN deliveries d "
                "ON p.parcel_id = d.parcel_id "
                "WHERE p.customer_id = @customerId "
                "AND d.status = 'Delivered'";

            return GetCount(
                query,
                customerId
            );
        }

        // =========================================================
        // RECENT DELIVERIES
        // =========================================================

        static DataTable^ GetRecentDeliveries(int customerId)
        {
            MySqlConnection^ connection =
                DatabaseConnection::GetConnection();

            try
            {
                connection->Open();

                String^ query =
                    "SELECT "
                    "p.tracking_no, "
                    "p.receiver_name, "
                    "d.delivery_option, "
                    "d.status, "
                    "d.created_at "
                    "FROM parcels p "
                    "INNER JOIN deliveries d "
                    "ON p.parcel_id = d.parcel_id "
                    "WHERE p.customer_id = @customerId "
                    "ORDER BY d.created_at DESC "
                    "LIMIT 3";

                MySqlCommand^ command =
                    gcnew MySqlCommand(
                        query,
                        connection
                    );

                command->Parameters->AddWithValue(
                    "@customerId",
                    customerId
                );

                MySqlDataReader^ reader =
                    command->ExecuteReader();

                DataTable^ table =
                    gcnew DataTable();

                table->Load(reader);

                reader->Close();
                connection->Close();

                return table;
            }
            catch (Exception^)
            {
                if (
                    connection->State ==
                    ConnectionState::Open
                    )
                {
                    connection->Close();
                }

                throw;
            }
        }

    private:

        // =========================================================
        // COMMON COUNT FUNCTION
        // =========================================================

        static int GetCount(
            String^ query,
            int customerId)
        {
            MySqlConnection^ connection =
                DatabaseConnection::GetConnection();

            try
            {
                connection->Open();

                MySqlCommand^ command =
                    gcnew MySqlCommand(
                        query,
                        connection
                    );

                command->Parameters->AddWithValue(
                    "@customerId",
                    customerId
                );

                Object^ result =
                    command->ExecuteScalar();

                int count =
                    Convert::ToInt32(
                        result
                    );

                connection->Close();

                return count;
            }
            catch (Exception^)
            {
                if (
                    connection->State ==
                    ConnectionState::Open
                    )
                {
                    connection->Close();
                }

                throw;
            }
        }
    };
}