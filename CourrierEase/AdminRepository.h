#pragma once
#pragma once

#include "DatabaseConnection.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

namespace CourrierEase
{
	public ref class AdminRepository
	{
	public:

		// FIND ADMIN FOR LOGIN
		static bool GetAdminLogin(
			String^ username,
			int% adminId,
			String^% fullName,
			String^% passwordHash)
		{
			MySqlConnection^ connection =
				DatabaseConnection::GetConnection();

			try
			{
				connection->Open();

				String^ query =
					"SELECT admin_id, full_name, password_hash "
					"FROM admins "
					"WHERE username = @username "
					"LIMIT 1";

				MySqlCommand^ command =
					gcnew MySqlCommand(
						query,
						connection
					);

				command->Parameters->AddWithValue(
					"@username",
					username
				);

				MySqlDataReader^ reader =
					command->ExecuteReader();

				if (reader->Read())
				{
					adminId =
						Convert::ToInt32(
							reader["admin_id"]
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