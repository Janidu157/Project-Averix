#pragma once

#include "DatabaseConnection.h"
#include "Parcel.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

namespace CourrierEase
{
    public ref class ParcelRepository
    {
    public:

        // =========================================================
        // CREATE PARCEL BOOKING
        // =========================================================

        static bool CreateParcel(
            Parcel^ parcel,
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
                // OPEN DATABASE CONNECTION
                connection->Open();

                // START TRANSACTION
                transaction =
                    connection->BeginTransaction();

                // =================================================
                // INSERT PARCEL
                // =================================================

                String^ parcelQuery =
                    "INSERT INTO parcels "
                    "(tracking_no, customer_id, "
                    "receiver_name, receiver_phone, "
                    "receiver_address, receiver_city, "
                    "description, weight_kg, parcel_type, "
                    "declared_value) "
                    "VALUES "
                    "(@tracking, @customer, "
                    "@receiverName, @receiverPhone, "
                    "@receiverAddress, @receiverCity, "
                    "@description, @weight, "
                    "@parcelType, @declaredValue)";

                MySqlCommand^ parcelCommand =
                    gcnew MySqlCommand(
                        parcelQuery,
                        connection,
                        transaction
                    );

                parcelCommand->Parameters->AddWithValue(
                    "@tracking",
                    parcel->TrackingNo
                );

                parcelCommand->Parameters->AddWithValue(
                    "@customer",
                    parcel->CustomerId
                );

                parcelCommand->Parameters->AddWithValue(
                    "@receiverName",
                    parcel->ReceiverName
                );

                parcelCommand->Parameters->AddWithValue(
                    "@receiverPhone",
                    parcel->ReceiverPhone
                );

                parcelCommand->Parameters->AddWithValue(
                    "@receiverAddress",
                    parcel->ReceiverAddress
                );

                parcelCommand->Parameters->AddWithValue(
                    "@receiverCity",
                    parcel->ReceiverCity
                );

                parcelCommand->Parameters->AddWithValue(
                    "@description",
                    parcel->Description
                );

                parcelCommand->Parameters->AddWithValue(
                    "@weight",
                    parcel->WeightKg
                );

                parcelCommand->Parameters->AddWithValue(
                    "@parcelType",
                    parcel->ParcelType
                );

                parcelCommand->Parameters->AddWithValue(
                    "@declaredValue",
                    parcel->DeclaredValue
                );

                parcelCommand->ExecuteNonQuery();

                // GET NEW PARCEL ID
                int parcelId =
                    Convert::ToInt32(
                        parcelCommand->LastInsertedId
                    );

                // =================================================
                // INSERT DELIVERY
                // =================================================

                String^ deliveryQuery =
                    "INSERT INTO deliveries "
                    "(parcel_id, delivery_option, "
                    "charge, pickup_address, status) "
                    "VALUES "
                    "(@parcelId, @option, "
                    "@charge, @pickupAddress, @status)";

                MySqlCommand^ deliveryCommand =
                    gcnew MySqlCommand(
                        deliveryQuery,
                        connection,
                        transaction
                    );

                deliveryCommand->Parameters->AddWithValue(
                    "@parcelId",
                    parcelId
                );

                deliveryCommand->Parameters->AddWithValue(
                    "@option",
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
                    "@status",
                    "Order Placed"
                );

                deliveryCommand->ExecuteNonQuery();

                // GET NEW DELIVERY ID
                int deliveryId =
                    Convert::ToInt32(
                        deliveryCommand->LastInsertedId
                    );

                // =================================================
                // INSERT INITIAL STATUS HISTORY
                // =================================================

                String^ historyQuery =
                    "INSERT INTO status_history "
                    "(delivery_id, admin_id, status) "
                    "VALUES "
                    "(@deliveryId, NULL, @status)";

                MySqlCommand^ historyCommand =
                    gcnew MySqlCommand(
                        historyQuery,
                        connection,
                        transaction
                    );

                historyCommand->Parameters->AddWithValue(
                    "@deliveryId",
                    deliveryId
                );

                historyCommand->Parameters->AddWithValue(
                    "@status",
                    "Order Placed"
                );

                historyCommand->ExecuteNonQuery();

                // =================================================
                // COMMIT TRANSACTION
                // =================================================

                transaction->Commit();

                connection->Close();

                // SAVE DATABASE ID TO OBJECT
                parcel->ParcelId =
                    parcelId;

                return true;
            }

            catch (Exception^)
            {
                // ROLLBACK IF SOMETHING FAILED
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

                // CLOSE CONNECTION
                if (
                    connection->State ==
                    System::Data::
                    ConnectionState::Open
                    )
                {
                    connection->Close();
                }

                throw;
            }
        }

        // =========================================================
        // GENERATE TRACKING NUMBER
        // =========================================================

        static String^ GenerateTrackingNumber()
        {
            // Example:
            // CR20261012A4F921

            String^ datePart =
                DateTime::Now.ToString(
                    "yyyyMMdd"
                );

            Guid newGuid =
                Guid::NewGuid();

            String^ guidText =
                newGuid.ToString(
                    "N"
                );

            String^ randomPart =
                guidText->Substring(
                    0,
                    6
                );

            randomPart =
                randomPart->ToUpper();

            String^ trackingNumber =
                "CR" +
                datePart +
                randomPart;

            return trackingNumber;
        }
    };
}