#pragma once

#include "DatabaseConnection.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace CourrierEase
{
	public ref class TrackingRepository
	{
	public:

		// GET PARCEL TRACKING DETAILS
		static DataRow^ GetTrackingDetails(
			String^ trackingNo)
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
					"p.receiver_city, "
					"p.parcel_type, "
					"d.delivery_option, "
					"d.status, "
					"d.charge, "
					"d.created_at, "
					"db.full_name AS delivery_boy "
					"FROM parcels p "
					"INNER JOIN deliveries d "
					"ON p.parcel_id = d.parcel_id "
					"LEFT JOIN delivery_boys db "
					"ON d.boy_id = db.boy_id "
					"WHERE p.tracking_no = @trackingNo "
					"LIMIT 1";

				MySqlCommand^ command =
					gcnew MySqlCommand(
						query,
						connection
					);

				command->Parameters->AddWithValue(
					"@trackingNo",
					trackingNo
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
				if (
					connection->State ==
					System::Data::ConnectionState::Open
					)
				{
					connection->Close();
				}

				throw;
			}
		}


		// GET PUBLIC STATUS HISTORY
		static DataTable^ GetTrackingHistory(
			String^ trackingNo)
		{
			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			try
			{
				connection->Open();

				String^ query =
					"SELECT "
					"sh.status, "
					"sh.changed_at "
					"FROM status_history sh "
					"INNER JOIN deliveries d "
					"ON sh.delivery_id = d.delivery_id "
					"INNER JOIN parcels p "
					"ON d.parcel_id = p.parcel_id "
					"WHERE p.tracking_no = @trackingNo "
					"ORDER BY sh.changed_at ASC";

				MySqlCommand^ command =
					gcnew MySqlCommand(
						query,
						connection
					);

				command->Parameters->AddWithValue(
					"@trackingNo",
					trackingNo
				);

				MySqlDataAdapter^ adapter =
					gcnew MySqlDataAdapter(command);

				DataTable^ table =
					gcnew DataTable();

				adapter->Fill(table);

				connection->Close();

				return table;
			}
			catch (Exception^)
			{
				if (
					connection->State ==
					System::Data::ConnectionState::Open
					)
				{
					connection->Close();
				}

				throw;
			}
		}


		// CHECK TRACKING NUMBER
		static bool TrackingNumberExists(
			String^ trackingNo)
		{
			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			try
			{
				connection->Open();

				String^ query =
					"SELECT COUNT(*) "
					"FROM parcels "
					"WHERE tracking_no = @trackingNo";

				MySqlCommand^ command =
					gcnew MySqlCommand(
						query,
						connection
					);

				command->Parameters->AddWithValue(
					"@trackingNo",
					trackingNo
				);

				int count =
					Convert::ToInt32(
						command->ExecuteScalar()
					);

				connection->Close();

				return count > 0;
			}
			catch (Exception^)
			{
				if (
					connection->State ==
					System::Data::ConnectionState::Open
					)
				{
					connection->Close();
				}

				throw;
			}
		}
	};
}