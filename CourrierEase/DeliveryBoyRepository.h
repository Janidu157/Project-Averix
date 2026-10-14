#pragma once

#include "DatabaseConnection.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace CourrierEase
{
	public ref class DeliveryBoyRepository
	{
	public:

		// GET ALL DELIVERY BOYS
		static DataTable^ GetAllDeliveryBoys()
		{
			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			try
			{
				connection->Open();

				String^ query =
					"SELECT "
					"boy_id, "
					"full_name, "
					"phone, "
					"email, "
					"vehicle_no, "
					"is_active, "
					"created_at "
					"FROM delivery_boys "
					"ORDER BY created_at DESC";

				MySqlCommand^ command =
					gcnew MySqlCommand(
						query,
						connection
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


		// GET ONE DELIVERY BOY
		static DataRow^ GetDeliveryBoyById(
			int boyId)
		{
			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			try
			{
				connection->Open();

				String^ query =
					"SELECT "
					"boy_id, "
					"full_name, "
					"phone, "
					"email, "
					"vehicle_no, "
					"is_active, "
					"created_at "
					"FROM delivery_boys "
					"WHERE boy_id = @boyId "
					"LIMIT 1";

				MySqlCommand^ command =
					gcnew MySqlCommand(
						query,
						connection
					);

				command->Parameters->AddWithValue(
					"@boyId",
					boyId
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


		// CREATE DELIVERY BOY
		static bool CreateDeliveryBoy(
			String^ fullName,
			String^ phone,
			String^ email,
			String^ vehicleNo)
		{
			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			try
			{
				connection->Open();

				String^ query =
					"INSERT INTO delivery_boys "
					"(full_name, phone, email, vehicle_no, is_active) "
					"VALUES "
					"(@fullName, @phone, @email, @vehicleNo, 1)";

				MySqlCommand^ command =
					gcnew MySqlCommand(
						query,
						connection
					);

				command->Parameters->AddWithValue(
					"@fullName",
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
					"@vehicleNo",
					vehicleNo
				);

				int rows =
					command->ExecuteNonQuery();

				connection->Close();

				return rows > 0;
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


		// UPDATE DELIVERY BOY
		static bool UpdateDeliveryBoy(
			int boyId,
			String^ fullName,
			String^ phone,
			String^ email,
			String^ vehicleNo)
		{
			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			try
			{
				connection->Open();

				String^ query =
					"UPDATE delivery_boys "
					"SET "
					"full_name = @fullName, "
					"phone = @phone, "
					"email = @email, "
					"vehicle_no = @vehicleNo "
					"WHERE boy_id = @boyId";

				MySqlCommand^ command =
					gcnew MySqlCommand(
						query,
						connection
					);

				command->Parameters->AddWithValue(
					"@fullName",
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
					"@vehicleNo",
					vehicleNo
				);

				command->Parameters->AddWithValue(
					"@boyId",
					boyId
				);

				int rows =
					command->ExecuteNonQuery();

				connection->Close();

				return rows > 0;
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


		// CHANGE ACTIVE STATUS
		static bool SetDeliveryBoyActiveStatus(
			int boyId,
			bool isActive)
		{
			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			try
			{
				connection->Open();

				String^ query =
					"UPDATE delivery_boys "
					"SET is_active = @isActive "
					"WHERE boy_id = @boyId";

				MySqlCommand^ command =
					gcnew MySqlCommand(
						query,
						connection
					);

				command->Parameters->AddWithValue(
					"@isActive",
					isActive ? 1 : 0
				);

				command->Parameters->AddWithValue(
					"@boyId",
					boyId
				);

				int rows =
					command->ExecuteNonQuery();

				connection->Close();

				return rows > 0;
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


		// CHECK EMAIL EXISTS
		static bool EmailExists(
			String^ email,
			int excludeBoyId)
		{
			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			try
			{
				connection->Open();

				String^ query =
					"SELECT COUNT(*) "
					"FROM delivery_boys "
					"WHERE email = @email "
					"AND boy_id <> @excludeBoyId";

				MySqlCommand^ command =
					gcnew MySqlCommand(
						query,
						connection
					);

				command->Parameters->AddWithValue(
					"@email",
					email
				);

				command->Parameters->AddWithValue(
					"@excludeBoyId",
					excludeBoyId
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


		// CHECK IF DELIVERY BOY HAS ACTIVE DELIVERIES
		static bool HasActiveDeliveries(
			int boyId)
		{
			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			try
			{
				connection->Open();

				String^ query =
					"SELECT COUNT(*) "
					"FROM deliveries "
					"WHERE boy_id = @boyId "
					"AND status <> 'Delivered'";

				MySqlCommand^ command =
					gcnew MySqlCommand(
						query,
						connection
					);

				command->Parameters->AddWithValue(
					"@boyId",
					boyId
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