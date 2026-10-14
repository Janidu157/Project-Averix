#pragma once

#include "DatabaseConnection.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

namespace CourrierEase
{
	public ref class AdminDashboardRepository
	{
	public:

		// TOTAL DELIVERIES
		static int GetTotalDeliveries()
		{
			return GetCount(
				"SELECT COUNT(*) FROM deliveries"
			);
		}

		// ORDER PLACED
		static int GetOrderPlacedDeliveries()
		{
			return GetCount(
				"SELECT COUNT(*) "
				"FROM deliveries "
				"WHERE status = 'Order Placed'"
			);
		}

		// IN TRANSIT
		static int GetInTransitDeliveries()
		{
			return GetCount(
				"SELECT COUNT(*) "
				"FROM deliveries "
				"WHERE status = 'In Transit'"
			);
		}

		// DELIVERED
		static int GetDeliveredDeliveries()
		{
			return GetCount(
				"SELECT COUNT(*) "
				"FROM deliveries "
				"WHERE status = 'Delivered'"
			);
		}

	private:

		static int GetCount(String^ query)
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

				Object^ result =
					command->ExecuteScalar();

				int count = 0;

				if (
					result != nullptr &&
					result != DBNull::Value
					)
				{
					count =
						Convert::ToInt32(result);
				}

				connection->Close();

				return count;
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