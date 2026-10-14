#pragma once

#include "CustomerRepository.h"

namespace CourrierEase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class CustomerProfileDesigner :
		public System::Windows::Forms::Form
	{
	public:

		CustomerProfileDesigner(void)
		{
			customerId = 0;
			customerName = L"Customer";
			updatedCustomerName = L"Customer";

			InitializeComponent();
		}

		CustomerProfileDesigner(
			int id,
			System::String^ name)
		{
			customerId = id;
			customerName = name;
			updatedCustomerName = name;

			InitializeComponent();

			LoadHeader();
			LoadProfile();
		}

		property System::String^ UpdatedCustomerName
		{
			System::String^ get()
			{
				return updatedCustomerName;
			}
		}

	protected:

		~CustomerProfileDesigner()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		int customerId;
		System::String^ customerName;
		System::String^ updatedCustomerName;

		System::Windows::Forms::Panel^ pnlSidebar;


		System::Windows::Forms::Label^ lblBrand;
		System::Windows::Forms::Label^ lblCustomer;

		System::Windows::Forms::Button^ btnDashboard;
		System::Windows::Forms::Button^ btnBookParcel;
		System::Windows::Forms::Button^ btnMyDeliveries;
		System::Windows::Forms::Button^ btnMyProfile;
		System::Windows::Forms::Button^ btnLogout;

		System::Windows::Forms::Panel^ pnlHeader;
		System::Windows::Forms::Label^ lblPageTitle;

		System::Windows::Forms::Panel^ pnlAvatar;
		System::Windows::Forms::Label^ lblInitial;
		System::Windows::Forms::Label^ lblHeaderName;

		System::Windows::Forms::Panel^ pnlMain;
		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Label^ lblSubtitle;

		System::Windows::Forms::Panel^ pnlProfileCard;
		System::Windows::Forms::Label^ lblProfileTitle;

		System::Windows::Forms::Label^ lblCustomerIdTitle;
		System::Windows::Forms::Label^ lblCustomerId;

		System::Windows::Forms::Label^ lblFullName;
		System::Windows::Forms::TextBox^ txtFullName;

		System::Windows::Forms::Label^ lblPhone;
		System::Windows::Forms::TextBox^ txtPhone;

		System::Windows::Forms::Label^ lblEmail;
		System::Windows::Forms::TextBox^ txtEmail;

		System::Windows::Forms::Label^ lblAddress;
		System::Windows::Forms::TextBox^ txtAddress;

		System::Windows::Forms::Label^ lblMemberSinceTitle;
		System::Windows::Forms::Label^ lblMemberSince;

		System::Windows::Forms::Button^ btnSave;
		System::Windows::Forms::Button^ btnReset;

		System::Windows::Forms::Panel^ pnlDanger;
		System::Windows::Forms::Label^ lblDangerTitle;
		System::Windows::Forms::Label^ lblDangerText;
		System::Windows::Forms::Button^ btnDeleteAccount;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->pnlSidebar = (gcnew System::Windows::Forms::Panel());
			this->lblBrand = (gcnew System::Windows::Forms::Label());
			this->lblCustomer = (gcnew System::Windows::Forms::Label());
			this->btnDashboard = (gcnew System::Windows::Forms::Button());
			this->btnBookParcel = (gcnew System::Windows::Forms::Button());
			this->btnMyDeliveries = (gcnew System::Windows::Forms::Button());
			this->btnMyProfile = (gcnew System::Windows::Forms::Button());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			this->lblPageTitle = (gcnew System::Windows::Forms::Label());
			this->pnlAvatar = (gcnew System::Windows::Forms::Panel());
			this->lblInitial = (gcnew System::Windows::Forms::Label());
			this->lblHeaderName = (gcnew System::Windows::Forms::Label());
			this->pnlMain = (gcnew System::Windows::Forms::Panel());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblSubtitle = (gcnew System::Windows::Forms::Label());
			this->pnlProfileCard = (gcnew System::Windows::Forms::Panel());
			this->lblProfileTitle = (gcnew System::Windows::Forms::Label());
			this->lblCustomerIdTitle = (gcnew System::Windows::Forms::Label());
			this->lblCustomerId = (gcnew System::Windows::Forms::Label());
			this->lblFullName = (gcnew System::Windows::Forms::Label());
			this->txtFullName = (gcnew System::Windows::Forms::TextBox());
			this->lblPhone = (gcnew System::Windows::Forms::Label());
			this->txtPhone = (gcnew System::Windows::Forms::TextBox());
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->lblAddress = (gcnew System::Windows::Forms::Label());
			this->txtAddress = (gcnew System::Windows::Forms::TextBox());
			this->lblMemberSinceTitle = (gcnew System::Windows::Forms::Label());
			this->lblMemberSince = (gcnew System::Windows::Forms::Label());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->pnlDanger = (gcnew System::Windows::Forms::Panel());
			this->lblDangerTitle = (gcnew System::Windows::Forms::Label());
			this->lblDangerText = (gcnew System::Windows::Forms::Label());
			this->btnDeleteAccount = (gcnew System::Windows::Forms::Button());
			this->pnlSidebar->SuspendLayout();
			this->pnlHeader->SuspendLayout();
			this->pnlAvatar->SuspendLayout();
			this->pnlMain->SuspendLayout();
			this->pnlProfileCard->SuspendLayout();
			this->pnlDanger->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlSidebar
			// 
			this->pnlSidebar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->pnlSidebar->Controls->Add(this->lblBrand);
			this->pnlSidebar->Controls->Add(this->lblCustomer);
			this->pnlSidebar->Controls->Add(this->btnDashboard);
			this->pnlSidebar->Controls->Add(this->btnBookParcel);
			this->pnlSidebar->Controls->Add(this->btnMyDeliveries);
			this->pnlSidebar->Controls->Add(this->btnMyProfile);
			this->pnlSidebar->Controls->Add(this->btnLogout);
			this->pnlSidebar->Location = System::Drawing::Point(0, 0);
			this->pnlSidebar->Name = L"pnlSidebar";
			this->pnlSidebar->Size = System::Drawing::Size(190, 700);
			this->pnlSidebar->TabIndex = 0;
			// 
			// lblBrand
			// 
			this->lblBrand->AutoSize = true;
			this->lblBrand->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblBrand->ForeColor = System::Drawing::Color::White;
			this->lblBrand->Location = System::Drawing::Point(18, 21);
			this->lblBrand->Name = L"lblBrand";
			this->lblBrand->Size = System::Drawing::Size(123, 28);
			this->lblBrand->TabIndex = 1;
			this->lblBrand->Text = L"CourierEase";
			// 
			// lblCustomer
			// 
			this->lblCustomer->AutoSize = true;
			this->lblCustomer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7));
			this->lblCustomer->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->lblCustomer->Location = System::Drawing::Point(20, 68);
			this->lblCustomer->Name = L"lblCustomer";
			this->lblCustomer->Size = System::Drawing::Size(68, 15);
			this->lblCustomer->TabIndex = 2;
			this->lblCustomer->Text = L"CUSTOMER";
			// 
			// btnDashboard
			// 
			this->btnDashboard->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->btnDashboard->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnDashboard->FlatAppearance->BorderSize = 0;
			this->btnDashboard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDashboard->ForeColor = System::Drawing::Color::White;
			this->btnDashboard->Location = System::Drawing::Point(20, 95);
			this->btnDashboard->Name = L"btnDashboard";
			this->btnDashboard->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnDashboard->Size = System::Drawing::Size(150, 38);
			this->btnDashboard->TabIndex = 0;
			this->btnDashboard->Text = L"Dashboard";
			this->btnDashboard->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDashboard->UseVisualStyleBackColor = false;
			this->btnDashboard->Click += gcnew System::EventHandler(this, &CustomerProfileDesigner::btnDashboard_Click);
			// 
			// btnBookParcel
			// 
			this->btnBookParcel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->btnBookParcel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnBookParcel->FlatAppearance->BorderSize = 0;
			this->btnBookParcel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBookParcel->ForeColor = System::Drawing::Color::White;
			this->btnBookParcel->Location = System::Drawing::Point(20, 145);
			this->btnBookParcel->Name = L"btnBookParcel";
			this->btnBookParcel->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnBookParcel->Size = System::Drawing::Size(150, 38);
			this->btnBookParcel->TabIndex = 1;
			this->btnBookParcel->Text = L"Book Parcel";
			this->btnBookParcel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnBookParcel->UseVisualStyleBackColor = false;
			this->btnBookParcel->Click += gcnew System::EventHandler(this, &CustomerProfileDesigner::btnBookParcel_Click);
			// 
			// btnMyDeliveries
			// 
			this->btnMyDeliveries->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->btnMyDeliveries->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnMyDeliveries->FlatAppearance->BorderSize = 0;
			this->btnMyDeliveries->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMyDeliveries->ForeColor = System::Drawing::Color::White;
			this->btnMyDeliveries->Location = System::Drawing::Point(20, 195);
			this->btnMyDeliveries->Name = L"btnMyDeliveries";
			this->btnMyDeliveries->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnMyDeliveries->Size = System::Drawing::Size(150, 38);
			this->btnMyDeliveries->TabIndex = 2;
			this->btnMyDeliveries->Text = L"My Deliveries";
			this->btnMyDeliveries->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnMyDeliveries->UseVisualStyleBackColor = false;
			this->btnMyDeliveries->Click += gcnew System::EventHandler(this, &CustomerProfileDesigner::btnMyDeliveries_Click);
			// 
			// btnMyProfile
			// 
			this->btnMyProfile->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnMyProfile->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnMyProfile->FlatAppearance->BorderSize = 0;
			this->btnMyProfile->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMyProfile->ForeColor = System::Drawing::Color::White;
			this->btnMyProfile->Location = System::Drawing::Point(20, 245);
			this->btnMyProfile->Name = L"btnMyProfile";
			this->btnMyProfile->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnMyProfile->Size = System::Drawing::Size(150, 38);
			this->btnMyProfile->TabIndex = 3;
			this->btnMyProfile->Text = L"My Profile";
			this->btnMyProfile->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnMyProfile->UseVisualStyleBackColor = false;
			this->btnMyProfile->Click += gcnew System::EventHandler(this, &CustomerProfileDesigner::btnMyProfile_Click);
			// 
			// btnLogout
			// 
			this->btnLogout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->btnLogout->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnLogout->FlatAppearance->BorderSize = 0;
			this->btnLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogout->ForeColor = System::Drawing::Color::White;
			this->btnLogout->Location = System::Drawing::Point(20, 620);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnLogout->Size = System::Drawing::Size(150, 38);
			this->btnLogout->TabIndex = 4;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &CustomerProfileDesigner::btnLogout_Click);
			// 
			// pnlHeader
			// 
			this->pnlHeader->BackColor = System::Drawing::Color::White;
			this->pnlHeader->Controls->Add(this->lblPageTitle);
			this->pnlHeader->Controls->Add(this->pnlAvatar);
			this->pnlHeader->Controls->Add(this->lblHeaderName);
			this->pnlHeader->Location = System::Drawing::Point(190, 0);
			this->pnlHeader->Name = L"pnlHeader";
			this->pnlHeader->Size = System::Drawing::Size(910, 65);
			this->pnlHeader->TabIndex = 1;
			// 
			// lblPageTitle
			// 
			this->lblPageTitle->AutoSize = true;
			this->lblPageTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblPageTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblPageTitle->Location = System::Drawing::Point(30, 21);
			this->lblPageTitle->Name = L"lblPageTitle";
			this->lblPageTitle->Size = System::Drawing::Size(111, 28);
			this->lblPageTitle->TabIndex = 0;
			this->lblPageTitle->Text = L"My Profile";
			// 
			// pnlAvatar
			// 
			this->pnlAvatar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pnlAvatar->Controls->Add(this->lblInitial);
			this->pnlAvatar->Location = System::Drawing::Point(770, 17);
			this->pnlAvatar->Name = L"pnlAvatar";
			this->pnlAvatar->Size = System::Drawing::Size(32, 32);
			this->pnlAvatar->TabIndex = 1;
			// 
			// lblInitial
			// 
			this->lblInitial->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lblInitial->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblInitial->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->lblInitial->Location = System::Drawing::Point(0, 0);
			this->lblInitial->Name = L"lblInitial";
			this->lblInitial->Size = System::Drawing::Size(32, 32);
			this->lblInitial->TabIndex = 0;
			this->lblInitial->Text = L"C";
			this->lblInitial->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblHeaderName
			// 
			this->lblHeaderName->AutoSize = true;
			this->lblHeaderName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblHeaderName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblHeaderName->Location = System::Drawing::Point(810, 23);
			this->lblHeaderName->Name = L"lblHeaderName";
			this->lblHeaderName->Size = System::Drawing::Size(73, 19);
			this->lblHeaderName->TabIndex = 2;
			this->lblHeaderName->Text = L"Customer";
			// 
			// pnlMain
			// 
			this->pnlMain->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(252)));
			this->pnlMain->Controls->Add(this->lblTitle);
			this->pnlMain->Controls->Add(this->lblSubtitle);
			this->pnlMain->Controls->Add(this->pnlProfileCard);
			this->pnlMain->Controls->Add(this->pnlDanger);
			this->pnlMain->Location = System::Drawing::Point(190, 65);
			this->pnlMain->Name = L"pnlMain";
			this->pnlMain->Size = System::Drawing::Size(910, 635);
			this->pnlMain->TabIndex = 2;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
			this->lblTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblTitle->Location = System::Drawing::Point(35, 25);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(165, 41);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"My Profile";
			// 
			// lblSubtitle
			// 
			this->lblSubtitle->AutoSize = true;
			this->lblSubtitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblSubtitle->Location = System::Drawing::Point(37, 70);
			this->lblSubtitle->Name = L"lblSubtitle";
			this->lblSubtitle->Size = System::Drawing::Size(295, 20);
			this->lblSubtitle->TabIndex = 1;
			this->lblSubtitle->Text = L"View and update your account information.";
			// 
			// pnlProfileCard
			// 
			this->pnlProfileCard->BackColor = System::Drawing::Color::White;
			this->pnlProfileCard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlProfileCard->Controls->Add(this->lblProfileTitle);
			this->pnlProfileCard->Controls->Add(this->lblCustomerIdTitle);
			this->pnlProfileCard->Controls->Add(this->lblCustomerId);
			this->pnlProfileCard->Controls->Add(this->lblFullName);
			this->pnlProfileCard->Controls->Add(this->txtFullName);
			this->pnlProfileCard->Controls->Add(this->lblPhone);
			this->pnlProfileCard->Controls->Add(this->txtPhone);
			this->pnlProfileCard->Controls->Add(this->lblEmail);
			this->pnlProfileCard->Controls->Add(this->txtEmail);
			this->pnlProfileCard->Controls->Add(this->lblAddress);
			this->pnlProfileCard->Controls->Add(this->txtAddress);
			this->pnlProfileCard->Controls->Add(this->lblMemberSinceTitle);
			this->pnlProfileCard->Controls->Add(this->lblMemberSince);
			this->pnlProfileCard->Controls->Add(this->btnSave);
			this->pnlProfileCard->Controls->Add(this->btnReset);
			this->pnlProfileCard->Location = System::Drawing::Point(35, 110);
			this->pnlProfileCard->Name = L"pnlProfileCard";
			this->pnlProfileCard->Size = System::Drawing::Size(550, 455);
			this->pnlProfileCard->TabIndex = 2;
			// 
			// lblProfileTitle
			// 
			this->lblProfileTitle->AutoSize = true;
			this->lblProfileTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->lblProfileTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblProfileTitle->Location = System::Drawing::Point(25, 22);
			this->lblProfileTitle->Name = L"lblProfileTitle";
			this->lblProfileTitle->Size = System::Drawing::Size(199, 25);
			this->lblProfileTitle->TabIndex = 0;
			this->lblProfileTitle->Text = L"Account Information";
			// 
			// lblCustomerIdTitle
			// 
			this->lblCustomerIdTitle->AutoSize = true;
			this->lblCustomerIdTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblCustomerIdTitle->Location = System::Drawing::Point(365, 27);
			this->lblCustomerIdTitle->Name = L"lblCustomerIdTitle";
			this->lblCustomerIdTitle->Size = System::Drawing::Size(94, 20);
			this->lblCustomerIdTitle->TabIndex = 1;
			this->lblCustomerIdTitle->Text = L"Customer ID:";
			// 
			// lblCustomerId
			// 
			this->lblCustomerId->AutoSize = true;
			this->lblCustomerId->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblCustomerId->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->lblCustomerId->Location = System::Drawing::Point(465, 27);
			this->lblCustomerId->Name = L"lblCustomerId";
			this->lblCustomerId->Size = System::Drawing::Size(15, 19);
			this->lblCustomerId->TabIndex = 2;
			this->lblCustomerId->Text = L"-";
			// 
			// lblFullName
			// 
			this->lblFullName->AutoSize = true;
			this->lblFullName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblFullName->Location = System::Drawing::Point(25, 75);
			this->lblFullName->Name = L"lblFullName";
			this->lblFullName->Size = System::Drawing::Size(76, 19);
			this->lblFullName->TabIndex = 3;
			this->lblFullName->Text = L"Full Name";
			// 
			// txtFullName
			// 
			this->txtFullName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtFullName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->txtFullName->Location = System::Drawing::Point(25, 100);
			this->txtFullName->Name = L"txtFullName";
			this->txtFullName->Size = System::Drawing::Size(495, 27);
			this->txtFullName->TabIndex = 0;
			// 
			// lblPhone
			// 
			this->lblPhone->AutoSize = true;
			this->lblPhone->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblPhone->Location = System::Drawing::Point(25, 145);
			this->lblPhone->Name = L"lblPhone";
			this->lblPhone->Size = System::Drawing::Size(110, 19);
			this->lblPhone->TabIndex = 4;
			this->lblPhone->Text = L"Phone Number";
			// 
			// txtPhone
			// 
			this->txtPhone->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPhone->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->txtPhone->Location = System::Drawing::Point(25, 170);
			this->txtPhone->Name = L"txtPhone";
			this->txtPhone->Size = System::Drawing::Size(235, 27);
			this->txtPhone->TabIndex = 1;
			// 
			// lblEmail
			// 
			this->lblEmail->AutoSize = true;
			this->lblEmail->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblEmail->Location = System::Drawing::Point(285, 145);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(103, 19);
			this->lblEmail->TabIndex = 5;
			this->lblEmail->Text = L"Email Address";
			// 
			// txtEmail
			// 
			this->txtEmail->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtEmail->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->txtEmail->Location = System::Drawing::Point(285, 170);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(235, 27);
			this->txtEmail->TabIndex = 2;
			// 
			// lblAddress
			// 
			this->lblAddress->AutoSize = true;
			this->lblAddress->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblAddress->Location = System::Drawing::Point(25, 215);
			this->lblAddress->Name = L"lblAddress";
			this->lblAddress->Size = System::Drawing::Size(63, 19);
			this->lblAddress->TabIndex = 6;
			this->lblAddress->Text = L"Address";
			// 
			// txtAddress
			// 
			this->txtAddress->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtAddress->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->txtAddress->Location = System::Drawing::Point(25, 240);
			this->txtAddress->Multiline = true;
			this->txtAddress->Name = L"txtAddress";
			this->txtAddress->Size = System::Drawing::Size(495, 60);
			this->txtAddress->TabIndex = 3;
			// 
			// lblMemberSinceTitle
			// 
			this->lblMemberSinceTitle->AutoSize = true;
			this->lblMemberSinceTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblMemberSinceTitle->Location = System::Drawing::Point(25, 320);
			this->lblMemberSinceTitle->Name = L"lblMemberSinceTitle";
			this->lblMemberSinceTitle->Size = System::Drawing::Size(105, 20);
			this->lblMemberSinceTitle->TabIndex = 7;
			this->lblMemberSinceTitle->Text = L"Member since:";
			// 
			// lblMemberSince
			// 
			this->lblMemberSince->AutoSize = true;
			this->lblMemberSince->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblMemberSince->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(105)));
			this->lblMemberSince->Location = System::Drawing::Point(135, 321);
			this->lblMemberSince->Name = L"lblMemberSince";
			this->lblMemberSince->Size = System::Drawing::Size(15, 19);
			this->lblMemberSince->TabIndex = 8;
			this->lblMemberSince->Text = L"-";
			// 
			// btnSave
			// 
			this->btnSave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnSave->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSave->FlatAppearance->BorderSize = 0;
			this->btnSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnSave->ForeColor = System::Drawing::Color::White;
			this->btnSave->Location = System::Drawing::Point(25, 365);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(235, 42);
			this->btnSave->TabIndex = 4;
			this->btnSave->Text = L"Save Changes";
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &CustomerProfileDesigner::btnSave_Click);
			// 
			// btnReset
			// 
			this->btnReset->BackColor = System::Drawing::Color::White;
			this->btnReset->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnReset->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(203)),
				static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->btnReset->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReset->ForeColor = System::Drawing::Color::Black;
			this->btnReset->Location = System::Drawing::Point(285, 365);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(235, 42);
			this->btnReset->TabIndex = 5;
			this->btnReset->Text = L"Reset";
			this->btnReset->UseVisualStyleBackColor = false;
			this->btnReset->Click += gcnew System::EventHandler(this, &CustomerProfileDesigner::btnReset_Click);
			// 
			// pnlDanger
			// 
			this->pnlDanger->BackColor = System::Drawing::Color::White;
			this->pnlDanger->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlDanger->Controls->Add(this->lblDangerTitle);
			this->pnlDanger->Controls->Add(this->lblDangerText);
			this->pnlDanger->Controls->Add(this->btnDeleteAccount);
			this->pnlDanger->Location = System::Drawing::Point(610, 110);
			this->pnlDanger->Name = L"pnlDanger";
			this->pnlDanger->Size = System::Drawing::Size(265, 250);
			this->pnlDanger->TabIndex = 3;
			// 
			// lblDangerTitle
			// 
			this->lblDangerTitle->AutoSize = true;
			this->lblDangerTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->lblDangerTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->lblDangerTitle->Location = System::Drawing::Point(20, 22);
			this->lblDangerTitle->Name = L"lblDangerTitle";
			this->lblDangerTitle->Size = System::Drawing::Size(129, 25);
			this->lblDangerTitle->TabIndex = 0;
			this->lblDangerTitle->Text = L"Danger Zone";
			// 
			// lblDangerText
			// 
			this->lblDangerText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->lblDangerText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblDangerText->Location = System::Drawing::Point(20, 65);
			this->lblDangerText->Name = L"lblDangerText";
			this->lblDangerText->Size = System::Drawing::Size(220, 80);
			this->lblDangerText->TabIndex = 1;
			this->lblDangerText->Text = L"Deleting your account permanently removes your customer account and all associate"
				L"d parcel records.";
			// 
			// btnDeleteAccount
			// 
			this->btnDeleteAccount->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->btnDeleteAccount->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnDeleteAccount->FlatAppearance->BorderSize = 0;
			this->btnDeleteAccount->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDeleteAccount->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnDeleteAccount->ForeColor = System::Drawing::Color::White;
			this->btnDeleteAccount->Location = System::Drawing::Point(20, 175);
			this->btnDeleteAccount->Name = L"btnDeleteAccount";
			this->btnDeleteAccount->Size = System::Drawing::Size(220, 42);
			this->btnDeleteAccount->TabIndex = 2;
			this->btnDeleteAccount->Text = L"Delete Account";
			this->btnDeleteAccount->UseVisualStyleBackColor = false;
			this->btnDeleteAccount->Click += gcnew System::EventHandler(this, &CustomerProfileDesigner::btnDeleteAccount_Click);
			// 
			// CustomerProfileDesigner
			// 
			this->AcceptButton = this->btnSave;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(252)));
			this->ClientSize = System::Drawing::Size(1100, 700);
			this->Controls->Add(this->pnlSidebar);
			this->Controls->Add(this->pnlHeader);
			this->Controls->Add(this->pnlMain);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"CustomerProfileDesigner";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CourierEase - My Profile";
			this->pnlSidebar->ResumeLayout(false);
			this->pnlSidebar->PerformLayout();
			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();
			this->pnlAvatar->ResumeLayout(false);
			this->pnlMain->ResumeLayout(false);
			this->pnlMain->PerformLayout();
			this->pnlProfileCard->ResumeLayout(false);
			this->pnlProfileCard->PerformLayout();
			this->pnlDanger->ResumeLayout(false);
			this->pnlDanger->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion

	private:

		void LoadHeader()
		{
			if (System::String::IsNullOrWhiteSpace(
				customerName))
			{
				customerName = L"Customer";
			}

			this->lblHeaderName->Text =
				customerName;

			System::String^ name =
				customerName->Trim();

			if (name->Length > 0)
			{
				this->lblInitial->Text =
					name->Substring(0, 1)->ToUpper();
			}
		}

		void LoadProfile()
		{
			if (customerId <= 0)
			{
				return;
			}

			try
			{
				System::Data::DataRow^ row =
					CustomerRepository::GetCustomerById(
						customerId);

				if (row == nullptr)
				{
					System::Windows::Forms::MessageBox::Show(
						L"Customer account could not be found.",
						L"My Profile",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Warning);

					return;
				}

				this->lblCustomerId->Text =
					row[L"customer_id"]->ToString();

				this->txtFullName->Text =
					row[L"full_name"]->ToString();

				this->txtPhone->Text =
					row[L"phone"]->ToString();

				this->txtEmail->Text =
					row[L"email"]->ToString();

				this->txtAddress->Text =
					row[L"address"]->ToString();

				System::DateTime createdAt =
					System::Convert::ToDateTime(
						row[L"created_at"]);

				this->lblMemberSince->Text =
					createdAt.ToString(
						L"dd MMMM yyyy");

				customerName =
					this->txtFullName->Text;

				updatedCustomerName =
					customerName;

				LoadHeader();
			}
			catch (System::Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Unable to load your profile.\n\n" +
					ex->Message,
					L"My Profile",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
			}
		}

		bool ValidateProfile()
		{
			System::String^ fullName =
				this->txtFullName->Text->Trim();

			System::String^ phone =
				this->txtPhone->Text->Trim();

			System::String^ email =
				this->txtEmail->Text->Trim();

			System::String^ address =
				this->txtAddress->Text->Trim();

			if (
				System::String::IsNullOrWhiteSpace(fullName) ||
				System::String::IsNullOrWhiteSpace(phone) ||
				System::String::IsNullOrWhiteSpace(email) ||
				System::String::IsNullOrWhiteSpace(address))
			{
				System::Windows::Forms::MessageBox::Show(
					L"Please complete all profile fields.",
					L"My Profile",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Warning);

				return false;
			}

			if (
				phone->Length < 9 ||
				phone->Length > 15)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Please enter a valid phone number.",
					L"My Profile",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Warning);

				return false;
			}

			if (
				!email->Contains(L"@") ||
				!email->Contains(L"."))
			{
				System::Windows::Forms::MessageBox::Show(
					L"Please enter a valid email address.",
					L"My Profile",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Warning);

				return false;
			}

			return true;
		}

		void Save_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (!ValidateProfile())
			{
				return;
			}

			try
			{
				bool updated =
					CustomerRepository::UpdateCustomer(
						customerId,
						this->txtFullName->Text->Trim(),
						this->txtPhone->Text->Trim(),
						this->txtEmail->Text->Trim(),
						this->txtAddress->Text->Trim());

				if (updated)
				{
					customerName =
						this->txtFullName->Text->Trim();

					updatedCustomerName =
						customerName;

					LoadHeader();

					System::Windows::Forms::MessageBox::Show(
						L"Profile updated successfully.",
						L"My Profile",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Information);
				}
				else
				{
					System::Windows::Forms::MessageBox::Show(
						L"No profile changes were saved.",
						L"My Profile",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Information);
				}
			}
			catch (MySql::Data::MySqlClient::MySqlException^ ex)
			{
				if (ex->Number == 1062)
				{
					System::Windows::Forms::MessageBox::Show(
						L"That email address is already "
						L"registered to another account.",
						L"My Profile",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Warning);
				}
				else
				{
					System::Windows::Forms::MessageBox::Show(
						L"Database error:\n\n" +
						ex->Message,
						L"My Profile",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Error);
				}
			}
			catch (System::Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Unable to update your profile.\n\n" +
					ex->Message,
					L"My Profile",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
			}
		}

		void Reset_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			LoadProfile();
		}

		void DeleteAccount_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			System::Windows::Forms::DialogResult firstResult =
				System::Windows::Forms::MessageBox::Show(
					L"Are you sure you want to delete your account?\n\n"
					L"This will permanently delete your customer "
					L"account and all parcel records.",
					L"Delete Account",
					System::Windows::Forms::MessageBoxButtons::YesNo,
					System::Windows::Forms::MessageBoxIcon::Warning);

			if (
				firstResult !=
				System::Windows::Forms::DialogResult::Yes)
			{
				return;
			}

			System::Windows::Forms::DialogResult secondResult =
				System::Windows::Forms::MessageBox::Show(
					L"This action cannot be undone.\n\n"
					L"Do you still want to continue?",
					L"Confirm Account Deletion",
					System::Windows::Forms::MessageBoxButtons::YesNo,
					System::Windows::Forms::MessageBoxIcon::Warning);

			if (
				secondResult !=
				System::Windows::Forms::DialogResult::Yes)
			{
				return;
			}

			try
			{
				bool deleted =
					CustomerRepository::DeleteCustomer(
						customerId);

				if (deleted)
				{
					System::Windows::Forms::MessageBox::Show(
						L"Your account has been deleted.",
						L"CourierEase",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Information);

					this->DialogResult =
						System::Windows::Forms::DialogResult::Abort;

					this->Close();
				}
				else
				{
					System::Windows::Forms::MessageBox::Show(
						L"The customer account could not be deleted.",
						L"Delete Account",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Warning);
				}
			}
			catch (System::Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Unable to delete the account.\n\n" +
					ex->Message,
					L"Delete Account",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
			}
		}

		void Dashboard_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->DialogResult =
				System::Windows::Forms::DialogResult::OK;

			this->Close();
		}

		void BookParcel_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->DialogResult =
				System::Windows::Forms::DialogResult::Retry;

			this->Close();
		}

		void MyDeliveries_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->DialogResult =
				System::Windows::Forms::DialogResult::Ignore;

			this->Close();
		}

		void Logout_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			System::Windows::Forms::DialogResult result =
				System::Windows::Forms::MessageBox::Show(
					L"Are you sure you want to logout?",
					L"Logout",
					System::Windows::Forms::MessageBoxButtons::YesNo,
					System::Windows::Forms::MessageBoxIcon::Question);

			if (
				result ==
				System::Windows::Forms::DialogResult::Yes)
			{
				this->DialogResult =
					System::Windows::Forms::DialogResult::Abort;

				this->Close();
			}
		}

	private:

		System::Void btnDashboard_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Dashboard_Click(sender, e);
		}

		System::Void btnBookParcel_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			BookParcel_Click(sender, e);
		}

		System::Void btnMyDeliveries_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			MyDeliveries_Click(sender, e);
		}

		System::Void btnMyProfile_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			// Current page
		}

		System::Void btnDeleteAccount_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			DeleteAccount_Click(sender, e);
		}

		System::Void btnSave_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Save_Click(sender, e);
		}

		System::Void btnReset_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Reset_Click(sender, e);
		}

		System::Void btnLogout_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Logout_Click(sender, e);
		}
	};
}