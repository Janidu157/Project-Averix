#pragma once

#include "DatabaseConnection.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace CourrierEase
{
	public ref class AdminDeliveryRepository
	{
	public:

		// GET ALL DELIVERIES
		static DataTable^ GetAllDeliveries()
		{
			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			try
			{
				connection->Open();

				String^ query =
					"SELECT "
					"d.delivery_id, "
					"p.parcel_id, "
					"p.tracking_no, "
					"c.full_name AS customer_name, "
					"c.phone AS customer_phone, "
					"p.receiver_name, "
					"p.receiver_phone, "
					"p.receiver_address, "
					"p.receiver_city, "
					"p.description, "
					"p.weight_kg, "
					"p.parcel_type, "
					"d.delivery_option, "
					"d.charge, "
					"d.pickup_address, "
					"d.status, "
					"d.boy_id, "
					"db.full_name AS delivery_boy, "
					"db.vehicle_no, "
					"d.created_at "
					"FROM deliveries d "
					"INNER JOIN parcels p "
					"ON d.parcel_id = p.parcel_id "
					"INNER JOIN customers c "
					"ON p.customer_id = c.customer_id "
					"LEFT JOIN delivery_boys db "
					"ON d.boy_id = db.boy_id "
					"ORDER BY d.created_at DESC";

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


		// GET ONE DELIVERY
		static DataRow^ GetDeliveryById(
			int deliveryId)
		{
			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			try
			{
				connection->Open();

				String^ query =
					"SELECT "
					"d.delivery_id, "
					"p.parcel_id, "
					"p.tracking_no, "
					"c.full_name AS customer_name, "
					"c.phone AS customer_phone, "
					"c.email AS customer_email, "
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
					"d.boy_id, "
					"db.full_name AS delivery_boy, "
					"db.vehicle_no, "
					"d.created_at, "
					"d.updated_at "
					"FROM deliveries d "
					"INNER JOIN parcels p "
					"ON d.parcel_id = p.parcel_id "
					"INNER JOIN customers c "
					"ON p.customer_id = c.customer_id "
					"LEFT JOIN delivery_boys db "
					"ON d.boy_id = db.boy_id "
					"WHERE d.delivery_id = @deliveryId "
					"LIMIT 1";

				MySqlCommand^ command =
					gcnew MySqlCommand(
						query,
						connection
					);

				command->Parameters->AddWithValue(
					"@deliveryId",
					deliveryId
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


		// GET ACTIVE DELIVERY BOYS
		static DataTable^ GetActiveDeliveryBoys()
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
					"vehicle_no "
					"FROM delivery_boys "
					"WHERE is_active = 1 "
					"ORDER BY full_name ASC";

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


		// ASSIGN DELIVERY BOY
		static bool AssignDeliveryBoy(
			int deliveryId,
			int boyId)
		{
			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			try
			{
				connection->Open();

				// CHECK DELIVERY BOY
				String^ boyQuery =
					"SELECT COUNT(*) "
					"FROM delivery_boys "
					"WHERE boy_id = @boyId "
					"AND is_active = 1";

				MySqlCommand^ boyCommand =
					gcnew MySqlCommand(
						boyQuery,
						connection
					);

				boyCommand->Parameters->AddWithValue(
					"@boyId",
					boyId
				);

				int boyCount =
					Convert::ToInt32(
						boyCommand->ExecuteScalar()
					);

				if (boyCount == 0)
				{
					connection->Close();
					return false;
				}

				// ASSIGN DELIVERY BOY
				String^ updateQuery =
					"UPDATE deliveries "
					"SET boy_id = @boyId "
					"WHERE delivery_id = @deliveryId";

				MySqlCommand^ updateCommand =
					gcnew MySqlCommand(
						updateQuery,
						connection
					);

				updateCommand->Parameters->AddWithValue(
					"@boyId",
					boyId
				);

				updateCommand->Parameters->AddWithValue(
					"@deliveryId",
					deliveryId
				);

				int rows =
					updateCommand->ExecuteNonQuery();

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


		// REMOVE DELIVERY BOY
		static bool RemoveDeliveryBoy(
			int deliveryId)
		{
			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			try
			{
				connection->Open();

				String^ query =
					"UPDATE deliveries "
					"SET boy_id = NULL "
					"WHERE delivery_id = @deliveryId";

				MySqlCommand^ command =
					gcnew MySqlCommand(
						query,
						connection
					);

				command->Parameters->AddWithValue(
					"@deliveryId",
					deliveryId
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


		// UPDATE DELIVERY STATUS
		static bool UpdateDeliveryStatus(
			int deliveryId,
			String^ newStatus,
			int adminId)
		{
			if (
				newStatus != L"Order Placed" &&
				newStatus != L"In Transit" &&
				newStatus != L"Delivered"
				)
			{
				return false;
			}

			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			MySqlTransaction^ transaction = nullptr;

			try
			{
				connection->Open();

				transaction =
					connection->BeginTransaction();

				// CHECK DELIVERY
				String^ checkQuery =
					"SELECT status "
					"FROM deliveries "
					"WHERE delivery_id = @deliveryId "
					"LIMIT 1";

				MySqlCommand^ checkCommand =
					gcnew MySqlCommand(
						checkQuery,
						connection,
						transaction
					);

				checkCommand->Parameters->AddWithValue(
					"@deliveryId",
					deliveryId
				);

				Object^ currentStatusObject =
					checkCommand->ExecuteScalar();

				if (
					currentStatusObject == nullptr ||
					currentStatusObject == DBNull::Value
					)
				{
					transaction->Rollback();
					connection->Close();

					return false;
				}

				String^ currentStatus =
					currentStatusObject->ToString();

				if (currentStatus == newStatus)
				{
					transaction->Commit();
					connection->Close();

					return true;
				}

				// UPDATE STATUS
				String^ updateQuery =
					"UPDATE deliveries "
					"SET status = @status "
					"WHERE delivery_id = @deliveryId";

				MySqlCommand^ updateCommand =
					gcnew MySqlCommand(
						updateQuery,
						connection,
						transaction
					);

				updateCommand->Parameters->AddWithValue(
					"@status",
					newStatus
				);

				updateCommand->Parameters->AddWithValue(
					"@deliveryId",
					deliveryId
				);

				int rows =
					updateCommand->ExecuteNonQuery();

				if (rows == 0)
				{
					transaction->Rollback();
					connection->Close();

					return false;
				}

				// ADD STATUS HISTORY
				String^ historyQuery =
					"INSERT INTO status_history "
					"(delivery_id, admin_id, status) "
					"VALUES "
					"(@deliveryId, @adminId, @status)";

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
					"@adminId",
					adminId
				);

				historyCommand->Parameters->AddWithValue(
					"@status",
					newStatus
				);

				historyCommand->ExecuteNonQuery();

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
					System::Data::ConnectionState::Open
					)
				{
					connection->Close();
				}

				throw;
			}
		}


		// GET DELIVERY STATUS HISTORY
		static DataTable^ GetStatusHistory(
			int deliveryId)
		{
			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			try
			{
				connection->Open();

				String^ query =
					"SELECT "
					"sh.history_id, "
					"sh.status, "
					"sh.changed_at, "
					"a.full_name AS changed_by "
					"FROM status_history sh "
					"LEFT JOIN admins a "
					"ON sh.admin_id = a.admin_id "
					"WHERE sh.delivery_id = @deliveryId "
					"ORDER BY sh.changed_at DESC";

				MySqlCommand^ command =
					gcnew MySqlCommand(
						query,
						connection
					);

				command->Parameters->AddWithValue(
					"@deliveryId",
					deliveryId
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
	};
}