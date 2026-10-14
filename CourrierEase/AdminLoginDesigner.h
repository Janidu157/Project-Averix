#pragma once

#include "AdminRepository.h"
#include "PasswordHasher.h"
#include "AdminDashboardDesigner.h"

namespace CourrierEase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AdminLoginDesigner :
		public System::Windows::Forms::Form
	{
	public:

		AdminLoginDesigner(void)
		{
			InitializeComponent();
		}

	protected:

		~AdminLoginDesigner()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		System::Windows::Forms::Panel^ pnlLeft;

		System::Windows::Forms::Label^ lblBrand;
		System::Windows::Forms::Label^ lblLeftTitle;
		System::Windows::Forms::Label^ lblLeftText;

		System::Windows::Forms::Panel^ pnlRight;
		System::Windows::Forms::Label^ lblAdminPortal;
		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Label^ lblSubtitle;

		System::Windows::Forms::Label^ lblUsername;
		System::Windows::Forms::TextBox^ txtUsername;

		System::Windows::Forms::Label^ lblPassword;
		System::Windows::Forms::TextBox^ txtPassword;

		System::Windows::Forms::CheckBox^ chkShowPassword;

		System::Windows::Forms::Button^ btnLogin;
		System::Windows::Forms::Button^ btnBack;

		System::Windows::Forms::Label^ lblSecurity;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->pnlLeft = (gcnew System::Windows::Forms::Panel());
			this->lblLeftText = (gcnew System::Windows::Forms::Label());
			this->lblLeftTitle = (gcnew System::Windows::Forms::Label());
			this->lblBrand = (gcnew System::Windows::Forms::Label());
			this->pnlRight = (gcnew System::Windows::Forms::Panel());
			this->lblSecurity = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->chkShowPassword = (gcnew System::Windows::Forms::CheckBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->lblUsername = (gcnew System::Windows::Forms::Label());
			this->lblSubtitle = (gcnew System::Windows::Forms::Label());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblAdminPortal = (gcnew System::Windows::Forms::Label());
			this->pnlLeft->SuspendLayout();
			this->pnlRight->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlLeft
			// 
			this->pnlLeft->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->pnlLeft->Controls->Add(this->lblLeftText);
			this->pnlLeft->Controls->Add(this->lblLeftTitle);
			this->pnlLeft->Controls->Add(this->lblBrand);
			this->pnlLeft->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlLeft->Location = System::Drawing::Point(0, 0);
			this->pnlLeft->Name = L"pnlLeft";
			this->pnlLeft->Size = System::Drawing::Size(400, 600);
			this->pnlLeft->TabIndex = 0;
			// 
			// lblLeftText
			// 
			this->lblLeftText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblLeftText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(203)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
				static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->lblLeftText->Location = System::Drawing::Point(48, 325);
			this->lblLeftText->Name = L"lblLeftText";
			this->lblLeftText->Size = System::Drawing::Size(300, 75);
			this->lblLeftText->TabIndex = 3;
			this->lblLeftText->Text = L"Access the CourierEase administration portal to manage deliveries, delivery staff"
				L" and parcel status.";
			// 
			// lblLeftTitle
			// 
			this->lblLeftTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold));
			this->lblLeftTitle->ForeColor = System::Drawing::Color::White;
			this->lblLeftTitle->Location = System::Drawing::Point(45, 200);
			this->lblLeftTitle->Name = L"lblLeftTitle";
			this->lblLeftTitle->Size = System::Drawing::Size(310, 110);
			this->lblLeftTitle->TabIndex = 2;
			this->lblLeftTitle->Text = L"Manage Deliveries\nwith Confidence.";
			// 
			// lblBrand
			// 
			this->lblBrand->AutoSize = true;
			this->lblBrand->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->lblBrand->ForeColor = System::Drawing::Color::White;
			this->lblBrand->Location = System::Drawing::Point(48, 43);
			this->lblBrand->Name = L"lblBrand";
			this->lblBrand->Size = System::Drawing::Size(153, 35);
			this->lblBrand->TabIndex = 1;
			this->lblBrand->Text = L"CourierEase";
			// 
			// pnlRight
			// 
			this->pnlRight->BackColor = System::Drawing::Color::White;
			this->pnlRight->Controls->Add(this->lblSecurity);
			this->pnlRight->Controls->Add(this->btnBack);
			this->pnlRight->Controls->Add(this->btnLogin);
			this->pnlRight->Controls->Add(this->chkShowPassword);
			this->pnlRight->Controls->Add(this->txtPassword);
			this->pnlRight->Controls->Add(this->lblPassword);
			this->pnlRight->Controls->Add(this->txtUsername);
			this->pnlRight->Controls->Add(this->lblUsername);
			this->pnlRight->Controls->Add(this->lblSubtitle);
			this->pnlRight->Controls->Add(this->lblTitle);
			this->pnlRight->Controls->Add(this->lblAdminPortal);
			this->pnlRight->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlRight->Location = System::Drawing::Point(400, 0);
			this->pnlRight->Name = L"pnlRight";
			this->pnlRight->Size = System::Drawing::Size(500, 600);
			this->pnlRight->TabIndex = 1;
			// 
			// lblSecurity
			// 
			this->lblSecurity->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7));
			this->lblSecurity->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->lblSecurity->Location = System::Drawing::Point(68, 535);
			this->lblSecurity->Name = L"lblSecurity";
			this->lblSecurity->Size = System::Drawing::Size(350, 30);
			this->lblSecurity->TabIndex = 10;
			this->lblSecurity->Text = L"Authorized CourierEase administrators only.";
			this->lblSecurity->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::Color::White;
			this->btnBack->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(203)),
				static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->btnBack->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(105)));
			this->btnBack->Location = System::Drawing::Point(68, 480);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(350, 38);
			this->btnBack->TabIndex = 9;
			this->btnBack->Text = L"Back";
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &AdminLoginDesigner::btnBack_Click);
			// 
			// btnLogin
			// 
			this->btnLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnLogin->FlatAppearance->BorderSize = 0;
			this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnLogin->ForeColor = System::Drawing::Color::White;
			this->btnLogin->Location = System::Drawing::Point(68, 425);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(350, 42);
			this->btnLogin->TabIndex = 8;
			this->btnLogin->Text = L"Login to Admin Portal";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &AdminLoginDesigner::btnLogin_Click);
			// 
			// chkShowPassword
			// 
			this->chkShowPassword->AutoSize = true;
			this->chkShowPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->chkShowPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(105)));
			this->chkShowPassword->Location = System::Drawing::Point(68, 378);
			this->chkShowPassword->Name = L"chkShowPassword";
			this->chkShowPassword->Size = System::Drawing::Size(126, 23);
			this->chkShowPassword->TabIndex = 7;
			this->chkShowPassword->Text = L"Show password";
			this->chkShowPassword->UseVisualStyleBackColor = true;
			this->chkShowPassword->CheckedChanged += gcnew System::EventHandler(this, &AdminLoginDesigner::chkShowPassword_CheckedChanged);
			// 
			// txtPassword
			// 
			this->txtPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtPassword->Location = System::Drawing::Point(68, 337);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(350, 30);
			this->txtPassword->TabIndex = 6;
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->lblPassword->Location = System::Drawing::Point(65, 310);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(76, 20);
			this->lblPassword->TabIndex = 5;
			this->lblPassword->Text = L"Password";
			// 
			// txtUsername
			// 
			this->txtUsername->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtUsername->Location = System::Drawing::Point(68, 252);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(350, 30);
			this->txtUsername->TabIndex = 4;
			// 
			// lblUsername
			// 
			this->lblUsername->AutoSize = true;
			this->lblUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblUsername->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->lblUsername->Location = System::Drawing::Point(65, 225);
			this->lblUsername->Name = L"lblUsername";
			this->lblUsername->Size = System::Drawing::Size(80, 20);
			this->lblUsername->TabIndex = 3;
			this->lblUsername->Text = L"Username";
			// 
			// lblSubtitle
			// 
			this->lblSubtitle->AutoSize = true;
			this->lblSubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblSubtitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblSubtitle->Location = System::Drawing::Point(65, 170);
			this->lblSubtitle->Name = L"lblSubtitle";
			this->lblSubtitle->Size = System::Drawing::Size(327, 20);
			this->lblSubtitle->TabIndex = 2;
			this->lblSubtitle->Text = L"Enter your administrator credentials to continue.";
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 23, System::Drawing::FontStyle::Bold));
			this->lblTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblTitle->Location = System::Drawing::Point(60, 110);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(258, 52);
			this->lblTitle->TabIndex = 1;
			this->lblTitle->Text = L"Admin Login";
			// 
			// lblAdminPortal
			// 
			this->lblAdminPortal->AutoSize = true;
			this->lblAdminPortal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblAdminPortal->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->lblAdminPortal->Location = System::Drawing::Point(65, 80);
			this->lblAdminPortal->Name = L"lblAdminPortal";
			this->lblAdminPortal->Size = System::Drawing::Size(114, 19);
			this->lblAdminPortal->TabIndex = 0;
			this->lblAdminPortal->Text = L"ADMIN PORTAL";
			// 
			// AdminLoginDesigner
			// 
			this->AcceptButton = this->btnLogin;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(900, 600);
			this->Controls->Add(this->pnlRight);
			this->Controls->Add(this->pnlLeft);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"AdminLoginDesigner";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CourierEase - Admin Login";
			this->pnlLeft->ResumeLayout(false);
			this->pnlLeft->PerformLayout();
			this->pnlRight->ResumeLayout(false);
			this->pnlRight->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion

	private:

		void Back_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->Close();
		}

		void Login_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			String^ username =
				txtUsername->Text->Trim();

			String^ password =
				txtPassword->Text;

			if (String::IsNullOrWhiteSpace(username))
			{
				System::Windows::Forms::MessageBox::Show(
					L"Please enter the admin username.",
					L"Admin Login",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Warning);

				txtUsername->Focus();
				return;
			}

			if (String::IsNullOrWhiteSpace(password))
			{
				System::Windows::Forms::MessageBox::Show(
					L"Please enter the admin password.",
					L"Admin Login",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Warning);

				txtPassword->Focus();
				return;
			}

			try
			{
				int adminId = 0;
				String^ fullName = nullptr;
				String^ passwordHash = nullptr;

				bool adminExists =
					AdminRepository::GetAdminLogin(
						username,
						adminId,
						fullName,
						passwordHash);

				if (!adminExists)
				{
					System::Windows::Forms::MessageBox::Show(
						L"Invalid username or password.",
						L"Admin Login",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Error);

					txtPassword->Clear();
					txtUsername->Focus();
					return;
				}

				bool passwordCorrect =
					PasswordHasher::VerifyPassword(
						password,
						passwordHash);

				if (!passwordCorrect)
				{
					System::Windows::Forms::MessageBox::Show(
						L"Invalid username or password.",
						L"Admin Login",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Error);

					txtPassword->Clear();
					txtPassword->Focus();
					return;
				}

				txtPassword->Clear();

				AdminDashboardDesigner^ dashboard =
					gcnew AdminDashboardDesigner(
						adminId,
						fullName);

				this->Hide();

				dashboard->ShowDialog();

				delete dashboard;

				this->Show();

				txtPassword->Clear();
				txtPassword->Focus();
			}
			catch (FormatException^)
			{
				System::Windows::Forms::MessageBox::Show(
					L"The administrator password data is invalid. "
					L"Please create the administrator account using "
					L"the CourierEase password hashing method.",
					L"Admin Login",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Unable to login.\n\n" +
					ex->Message,
					L"Admin Login",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
			}
		}

		void ShowPassword_CheckedChanged(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (chkShowPassword->Checked)
			{
				txtPassword->PasswordChar =
					L'\0';
			}
			else
			{
				txtPassword->PasswordChar =
					L'*';
			}
		}

	private:

		System::Void btnLogin_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Login_Click(sender, e);
		}

		System::Void btnBack_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Back_Click(sender, e);
		}

		System::Void chkShowPassword_CheckedChanged(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			ShowPassword_CheckedChanged(sender, e);
		}
	};
}