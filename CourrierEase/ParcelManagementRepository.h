#pragma once

#include "DatabaseConnection.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace CourrierEase
{
    public ref class ParcelManagementRepository
    {
    public:

        // =========================================================
        // READ - GET ALL PARCELS OF CUSTOMER
        // =========================================================

        static DataTable^ GetCustomerParcels(int customerId)
        {
            MySqlConnection^ connection =
                DatabaseConnection::GetConnection();

            try
            {
                connection->Open();

                String^ query =
                    "SELECT "
                    "p.parcel_id, "
                    "p.tracking_no, "
                    "p.receiver_name, "
                    "p.receiver_phone, "
                    "p.receiver_address, "
                    "p.receiver_city, "
                    "p.description, "
                    "p.weight_kg, "
                    "p.parcel_type, "
                    "p.declared_value, "
                    "d.delivery_option, "
                    "d.charge, "
                    "d.pickup_address, "
                    "d.status, "
                    "d.created_at "
                    "FROM parcels p "
                    "INNER JOIN deliveries d "
                    "ON p.parcel_id = d.parcel_id "
                    "WHERE p.customer_id = @customerId "
                    "ORDER BY d.created_at DESC";

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


        // =========================================================
        // READ - GET ONE PARCEL
        // =========================================================

        static DataRow^ GetParcelById(
            int parcelId,
            int customerId)
        {
            MySqlConnection^ connection =
                DatabaseConnection::GetConnection();

            try
            {
                connection->Open();

                String^ query =
                    "SELECT "
                    "p.parcel_id, "
                    "p.tracking_no, "
                    "p.receiver_name, "
                    "p.receiver_phone, "
                    "p.receiver_address, "
                    "p.receiver_city, "
                    "p.description, "
                    "p.weight_kg, "
                    "p.parcel_type, "
                    "p.declared_value, "
                    "d.delivery_option, "
                    "d.charge, "
                    "d.pickup_address, "
                    "d.status "
                    "FROM parcels p "
                    "INNER JOIN deliveries d "
                    "ON p.parcel_id = d.parcel_id "
                    "WHERE p.parcel_id = @parcelId "
                    "AND p.customer_id = @customerId";

                MySqlCommand^ command =
                    gcnew MySqlCommand(
                        query,
                        connection
                    );

                command->Parameters->AddWithValue(
                    "@parcelId",
                    parcelId
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

                if (table->Rows->Count == 0)
                {
                    return nullptr;
                }

                return table->Rows[0];
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


        // =========================================================
        // UPDATE PARCEL
        // Only allowed while status = Order Placed
        // =========================================================

        static bool UpdateParcel(
            int parcelId,
            int customerId,
            String^ receiverName,
            String^ receiverPhone,
            String^ receiverAddress,
            String^ receiverCity,
            String^ description,
            double weightKg,
            String^ parcelType,
            double declaredValue,
            String^ deliveryOption,
            double charge,
            String^ pickupAddress)
        {
            MySqlConnection^ connection =
                DatabaseConnection::GetConnection();

            MySqlTransaction^ transaction =
                nullptr;

            try
            {
                connection->Open();

                transaction =
                    connection->BeginTransaction();

                // -------------------------------------------------
                // CHECK PARCEL OWNERSHIP AND STATUS
                // -------------------------------------------------

                String^ checkQuery =
                    "SELECT d.status "
                    "FROM parcels p "
                    "INNER JOIN deliveries d "
                    "ON p.parcel_id = d.parcel_id "
                    "WHERE p.parcel_id = @parcelId "
                    "AND p.customer_id = @customerId";

                MySqlCommand^ checkCommand =
                    gcnew MySqlCommand(
                        checkQuery,
                        connection,
                        transaction
                    );

                checkCommand->Parameters->AddWithValue(
                    "@parcelId",
                    parcelId
                );

                checkCommand->Parameters->AddWithValue(
                    "@customerId",
                    customerId
                );

                Object^ statusResult =
                    checkCommand->ExecuteScalar();

                if (statusResult == nullptr)
                {
                    transaction->Rollback();
                    connection->Close();

                    return false;
                }

                String^ status =
                    statusResult->ToString();

                if (status != "Order Placed")
                {
                    transaction->Rollback();
                    connection->Close();

                    return false;
                }


                // -------------------------------------------------
                // UPDATE PARCEL TABLE
                // -------------------------------------------------

                String^ parcelQuery =
                    "UPDATE parcels SET "
                    "receiver_name = @receiverName, "
                    "receiver_phone = @receiverPhone, "
                    "receiver_address = @receiverAddress, "
                    "receiver_city = @receiverCity, "
                    "description = @description, "
                    "weight_kg = @weight, "
                    "parcel_type = @parcelType, "
                    "declared_value = @declaredValue "
                    "WHERE parcel_id = @parcelId "
                    "AND customer_id = @customerId";

                MySqlCommand^ parcelCommand =
                    gcnew MySqlCommand(
                        parcelQuery,
                        connection,
                        transaction
                    );

                parcelCommand->Parameters->AddWithValue(
                    "@receiverName",
                    receiverName
                );

                parcelCommand->Parameters->AddWithValue(
                    "@receiverPhone",
                    receiverPhone
                );

                parcelCommand->Parameters->AddWithValue(
                    "@receiverAddress",
                    receiverAddress
                );

                parcelCommand->Parameters->AddWithValue(
                    "@receiverCity",
                    receiverCity
                );

                parcelCommand->Parameters->AddWithValue(
                    "@description",
                    description
                );

                parcelCommand->Parameters->AddWithValue(
                    "@weight",
                    weightKg
                );

                parcelCommand->Parameters->AddWithValue(
                    "@parcelType",
                    parcelType
                );

                parcelCommand->Parameters->AddWithValue(
                    "@declaredValue",
                    declaredValue
                );

                parcelCommand->Parameters->AddWithValue(
                    "@parcelId",
                    parcelId
                );

                parcelCommand->Parameters->AddWithValue(
                    "@customerId",
                    customerId
                );

                int affected =
                    parcelCommand->ExecuteNonQuery();

                if (affected == 0)
                {
                    transaction->Rollback();
                    connection->Close();

                    return false;
                }


                // -------------------------------------------------
                // UPDATE DELIVERY TABLE
                // -------------------------------------------------

                String^ deliveryQuery =
                    "UPDATE deliveries SET "
                    "delivery_option = @deliveryOption, "
                    "charge = @charge, "
                    "pickup_address = @pickupAddress "
                    "WHERE parcel_id = @parcelId";

                MySqlCommand^ deliveryCommand =
                    gcnew MySqlCommand(
                        deliveryQuery,
                        connection,
                        transaction
                    );

                deliveryCommand->Parameters->AddWithValue(
                    "@deliveryOption",
                    deliveryOption
                );

                deliveryCommand->Parameters->AddWithValue(
                    "@charge",
                    charge
                );

                deliveryCommand->Parameters->AddWithValue(
                    "@pickupAddress",
                    pickupAddress
                );

                deliveryCommand->Parameters->AddWithValue(
                    "@parcelId",
                    parcelId
                );

                deliveryCommand->ExecuteNonQuery();

                transaction->Commit();
                connection->Close();

                return true;
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


        // =========================================================
        // DELETE / CANCEL PARCEL
        // Only Order Placed parcels can be deleted
        // =========================================================

        static bool DeleteParcel(
            int parcelId,
            int customerId)
        {
            MySqlConnection^ connection =
                DatabaseConnection::GetConnection();

            MySqlTransaction^ transaction =
                nullptr;

            try
            {
                connection->Open();

                transaction =
                    connection->BeginTransaction();

                // -------------------------------------------------
                // CHECK STATUS
                // -------------------------------------------------

                String^ checkQuery =
                    "SELECT d.status "
                    "FROM parcels p "
                    "INNER JOIN deliveries d "
                    "ON p.parcel_id = d.parcel_id "
                    "WHERE p.parcel_id = @parcelId "
                    "AND p.customer_id = @customerId";

                MySqlCommand^ checkCommand =
                    gcnew MySqlCommand(
                        checkQuery,
                        connection,
                        transaction
                    );

                checkCommand->Parameters->AddWithValue(
                    "@parcelId",
                    parcelId
                );

                checkCommand->Parameters->AddWithValue(
                    "@customerId",
                    customerId
                );

                Object^ result =
                    checkCommand->ExecuteScalar();

                if (result == nullptr)
                {
                    transaction->Rollback();
                    connection->Close();

                    return false;
                }

                String^ status =
                    result->ToString();

                if (status != "Order Placed")
                {
                    transaction->Rollback();
                    connection->Close();

                    return false;
                }


                // -------------------------------------------------
                // DELETE PARCEL
                // -------------------------------------------------
                // deliveries is ON DELETE CASCADE from parcels.
                // status_history is ON DELETE CASCADE from deliveries.
                // Therefore deleting parcel removes related records too.

                String^ deleteQuery =
                    "DELETE FROM parcels "
                    "WHERE parcel_id = @parcelId "
                    "AND customer_id = @customerId";

                MySqlCommand^ deleteCommand =
                    gcnew MySqlCommand(
                        deleteQuery,
                        connection,
                        transaction
                    );

                deleteCommand->Parameters->AddWithValue(
                    "@parcelId",
                    parcelId
                );

                deleteCommand->Parameters->AddWithValue(
                    "@customerId",
                    customerId
                );

                int affected =
                    deleteCommand->ExecuteNonQuery();

                if (affected == 0)
                {
                    transaction->Rollback();
                    connection->Close();

                    return false;
                }

                transaction->Commit();
                connection->Close();

                return true;
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