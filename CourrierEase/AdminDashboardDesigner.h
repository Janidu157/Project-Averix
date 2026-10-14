#pragma once

#include "AdminDashboardRepository.h"
#include "ManageDeliveriesDesigner.h"
#include "DeliveryBoysDesigner.h"

namespace CourrierEase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AdminDashboardDesigner : public System::Windows::Forms::Form
	{
	public:
		AdminDashboardDesigner(void)
		{
			adminId = 0;
			adminName = L"Administrator";

			InitializeComponent();
			LoadAdminDetails();
			LoadDashboardData();
		}

		AdminDashboardDesigner(
			int loggedAdminId,
			String^ loggedAdminName)
		{
			adminId = loggedAdminId;
			adminName = loggedAdminName;

			InitializeComponent();
			LoadAdminDetails();
			LoadDashboardData();
		}

	protected:
		~AdminDashboardDesigner()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		int adminId;
		String^ adminName;

		// SIDEBAR
		System::Windows::Forms::Panel^ pnlSidebar;

		System::Windows::Forms::Label^ lblBrand;
		System::Windows::Forms::Label^ lblAdminArea;

		System::Windows::Forms::Button^ btnDashboard;
		System::Windows::Forms::Button^ btnDeliveries;
		System::Windows::Forms::Button^ btnDeliveryBoys;
		System::Windows::Forms::Button^ btnLogout;

		// HEADER
		System::Windows::Forms::Panel^ pnlHeader;
		System::Windows::Forms::Label^ lblPageTitle;
		System::Windows::Forms::Label^ lblHeaderAdmin;
		System::Windows::Forms::Panel^ pnlAvatar;
		System::Windows::Forms::Label^ lblInitial;

		// CONTENT
		System::Windows::Forms::Panel^ pnlContent;
		System::Windows::Forms::Label^ lblWelcome;
		System::Windows::Forms::Label^ lblDescription;

		// STAT CARDS
		System::Windows::Forms::Panel^ pnlTotalCard;
		System::Windows::Forms::Label^ lblTotalCaption;
		System::Windows::Forms::Label^ lblTotalValue;

		System::Windows::Forms::Panel^ pnlPendingCard;
		System::Windows::Forms::Label^ lblPendingCaption;
		System::Windows::Forms::Label^ lblPendingValue;

		System::Windows::Forms::Panel^ pnlTransitCard;
		System::Windows::Forms::Label^ lblTransitCaption;
		System::Windows::Forms::Label^ lblTransitValue;

		System::Windows::Forms::Panel^ pnlDeliveredCard;
		System::Windows::Forms::Label^ lblDeliveredCaption;
		System::Windows::Forms::Label^ lblDeliveredValue;

		// QUICK ACTIONS
		System::Windows::Forms::Label^ lblQuickActions;

		System::Windows::Forms::Panel^ pnlManageDeliveries;
		System::Windows::Forms::Label^ lblManageDeliveriesTitle;
		System::Windows::Forms::Label^ lblManageDeliveriesText;
		System::Windows::Forms::Button^ btnManageDeliveries;

		System::Windows::Forms::Panel^ pnlManageBoys;
		System::Windows::Forms::Label^ lblManageBoysTitle;
		System::Windows::Forms::Label^ lblManageBoysText;
		System::Windows::Forms::Button^ btnManageBoys;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->pnlSidebar = (gcnew System::Windows::Forms::Panel());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->btnDeliveryBoys = (gcnew System::Windows::Forms::Button());
			this->btnDeliveries = (gcnew System::Windows::Forms::Button());
			this->btnDashboard = (gcnew System::Windows::Forms::Button());
			this->lblAdminArea = (gcnew System::Windows::Forms::Label());
			this->lblBrand = (gcnew System::Windows::Forms::Label());
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			this->pnlAvatar = (gcnew System::Windows::Forms::Panel());
			this->lblInitial = (gcnew System::Windows::Forms::Label());
			this->lblHeaderAdmin = (gcnew System::Windows::Forms::Label());
			this->lblPageTitle = (gcnew System::Windows::Forms::Label());
			this->pnlContent = (gcnew System::Windows::Forms::Panel());
			this->pnlManageBoys = (gcnew System::Windows::Forms::Panel());
			this->btnManageBoys = (gcnew System::Windows::Forms::Button());
			this->lblManageBoysText = (gcnew System::Windows::Forms::Label());
			this->lblManageBoysTitle = (gcnew System::Windows::Forms::Label());
			this->pnlManageDeliveries = (gcnew System::Windows::Forms::Panel());
			this->btnManageDeliveries = (gcnew System::Windows::Forms::Button());
			this->lblManageDeliveriesText = (gcnew System::Windows::Forms::Label());
			this->lblManageDeliveriesTitle = (gcnew System::Windows::Forms::Label());
			this->lblQuickActions = (gcnew System::Windows::Forms::Label());
			this->pnlDeliveredCard = (gcnew System::Windows::Forms::Panel());
			this->lblDeliveredValue = (gcnew System::Windows::Forms::Label());
			this->lblDeliveredCaption = (gcnew System::Windows::Forms::Label());
			this->pnlTransitCard = (gcnew System::Windows::Forms::Panel());
			this->lblTransitValue = (gcnew System::Windows::Forms::Label());
			this->lblTransitCaption = (gcnew System::Windows::Forms::Label());
			this->pnlPendingCard = (gcnew System::Windows::Forms::Panel());
			this->lblPendingValue = (gcnew System::Windows::Forms::Label());
			this->lblPendingCaption = (gcnew System::Windows::Forms::Label());
			this->pnlTotalCard = (gcnew System::Windows::Forms::Panel());
			this->lblTotalValue = (gcnew System::Windows::Forms::Label());
			this->lblTotalCaption = (gcnew System::Windows::Forms::Label());
			this->lblDescription = (gcnew System::Windows::Forms::Label());
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->pnlSidebar->SuspendLayout();
			this->pnlHeader->SuspendLayout();
			this->pnlAvatar->SuspendLayout();
			this->pnlContent->SuspendLayout();
			this->pnlManageBoys->SuspendLayout();
			this->pnlManageDeliveries->SuspendLayout();
			this->pnlDeliveredCard->SuspendLayout();
			this->pnlTransitCard->SuspendLayout();
			this->pnlPendingCard->SuspendLayout();
			this->pnlTotalCard->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlSidebar
			// 
			this->pnlSidebar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->pnlSidebar->Controls->Add(this->btnLogout);
			this->pnlSidebar->Controls->Add(this->btnDeliveryBoys);
			this->pnlSidebar->Controls->Add(this->btnDeliveries);
			this->pnlSidebar->Controls->Add(this->btnDashboard);
			this->pnlSidebar->Controls->Add(this->lblAdminArea);
			this->pnlSidebar->Controls->Add(this->lblBrand);
			this->pnlSidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlSidebar->Location = System::Drawing::Point(0, 0);
			this->pnlSidebar->Name = L"pnlSidebar";
			this->pnlSidebar->Size = System::Drawing::Size(240, 720);
			this->pnlSidebar->TabIndex = 0;
			// 
			// btnLogout
			// 
			this->btnLogout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->btnLogout->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)), static_cast<System::Int32>(static_cast<System::Byte>(105)));
			this->btnLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogout->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnLogout->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(113)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)));
			this->btnLogout->Location = System::Drawing::Point(25, 645);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(190, 40);
			this->btnLogout->TabIndex = 6;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &AdminDashboardDesigner::btnLogout_Click);
			// 
			// btnDeliveryBoys
			// 
			this->btnDeliveryBoys->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->btnDeliveryBoys->FlatAppearance->BorderSize = 0;
			this->btnDeliveryBoys->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDeliveryBoys->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->btnDeliveryBoys->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(203)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
				static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->btnDeliveryBoys->Location = System::Drawing::Point(20, 235);
			this->btnDeliveryBoys->Name = L"btnDeliveryBoys";
			this->btnDeliveryBoys->Size = System::Drawing::Size(200, 48);
			this->btnDeliveryBoys->TabIndex = 5;
			this->btnDeliveryBoys->Text = L"Delivery Boys";
			this->btnDeliveryBoys->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDeliveryBoys->UseVisualStyleBackColor = false;
			this->btnDeliveryBoys->Click += gcnew System::EventHandler(this, &AdminDashboardDesigner::btnDeliveryBoys_Click);
			// 
			// btnDeliveries
			// 
			this->btnDeliveries->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->btnDeliveries->FlatAppearance->BorderSize = 0;
			this->btnDeliveries->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDeliveries->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->btnDeliveries->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(203)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
				static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->btnDeliveries->Location = System::Drawing::Point(20, 180);
			this->btnDeliveries->Name = L"btnDeliveries";
			this->btnDeliveries->Size = System::Drawing::Size(200, 48);
			this->btnDeliveries->TabIndex = 4;
			this->btnDeliveries->Text = L"Manage Deliveries";
			this->btnDeliveries->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDeliveries->UseVisualStyleBackColor = false;
			this->btnDeliveries->Click += gcnew System::EventHandler(this, &AdminDashboardDesigner::btnDeliveries_Click);
			// 
			// btnDashboard
			// 
			this->btnDashboard->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(59)));
			this->btnDashboard->FlatAppearance->BorderSize = 0;
			this->btnDashboard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDashboard->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnDashboard->ForeColor = System::Drawing::Color::White;
			this->btnDashboard->Location = System::Drawing::Point(20, 125);
			this->btnDashboard->Name = L"btnDashboard";
			this->btnDashboard->Size = System::Drawing::Size(200, 48);
			this->btnDashboard->TabIndex = 3;
			this->btnDashboard->Text = L"Dashboard";
			this->btnDashboard->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDashboard->UseVisualStyleBackColor = false;
			this->btnDashboard->Click += gcnew System::EventHandler(this, &AdminDashboardDesigner::btnDashboard_Click);
			// 
			// lblAdminArea
			// 
			this->lblAdminArea->AutoSize = true;
			this->lblAdminArea->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblAdminArea->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->lblAdminArea->Location = System::Drawing::Point(29, 78);
			this->lblAdminArea->Name = L"lblAdminArea";
			this->lblAdminArea->Size = System::Drawing::Size(97, 19);
			this->lblAdminArea->TabIndex = 2;
			this->lblAdminArea->Text = L"ADMIN AREA";
			// 
			// lblBrand
			// 
			this->lblBrand->AutoSize = true;
			this->lblBrand->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->lblBrand->ForeColor = System::Drawing::Color::White;
			this->lblBrand->Location = System::Drawing::Point(27, 25);
			this->lblBrand->Name = L"lblBrand";
			this->lblBrand->Size = System::Drawing::Size(149, 32);
			this->lblBrand->TabIndex = 1;
			this->lblBrand->Text = L"CourierEase";
			// 
			// pnlHeader
			// 
			this->pnlHeader->BackColor = System::Drawing::Color::White;
			this->pnlHeader->Controls->Add(this->pnlAvatar);
			this->pnlHeader->Controls->Add(this->lblHeaderAdmin);
			this->pnlHeader->Controls->Add(this->lblPageTitle);
			this->pnlHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlHeader->Location = System::Drawing::Point(240, 0);
			this->pnlHeader->Name = L"pnlHeader";
			this->pnlHeader->Size = System::Drawing::Size(960, 85);
			this->pnlHeader->TabIndex = 1;
			// 
			// pnlAvatar
			// 
			this->pnlAvatar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->pnlAvatar->Controls->Add(this->lblInitial);
			this->pnlAvatar->Location = System::Drawing::Point(885, 20);
			this->pnlAvatar->Name = L"pnlAvatar";
			this->pnlAvatar->Size = System::Drawing::Size(45, 45);
			this->pnlAvatar->TabIndex = 2;
			// 
			// lblInitial
			// 
			this->lblInitial->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lblInitial->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			this->lblInitial->ForeColor = System::Drawing::Color::White;
			this->lblInitial->Location = System::Drawing::Point(0, 0);
			this->lblInitial->Name = L"lblInitial";
			this->lblInitial->Size = System::Drawing::Size(45, 45);
			this->lblInitial->TabIndex = 0;
			this->lblInitial->Text = L"A";
			this->lblInitial->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblHeaderAdmin
			// 
			this->lblHeaderAdmin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblHeaderAdmin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->lblHeaderAdmin->Location = System::Drawing::Point(650, 29);
			this->lblHeaderAdmin->Name = L"lblHeaderAdmin";
			this->lblHeaderAdmin->Size = System::Drawing::Size(220, 30);
			this->lblHeaderAdmin->TabIndex = 1;
			this->lblHeaderAdmin->Text = L"Administrator";
			this->lblHeaderAdmin->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblPageTitle
			// 
			this->lblPageTitle->AutoSize = true;
			this->lblPageTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 17, System::Drawing::FontStyle::Bold));
			this->lblPageTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblPageTitle->Location = System::Drawing::Point(35, 23);
			this->lblPageTitle->Name = L"lblPageTitle";
			this->lblPageTitle->Size = System::Drawing::Size(166, 40);
			this->lblPageTitle->TabIndex = 0;
			this->lblPageTitle->Text = L"Dashboard";
			// 
			// pnlContent
			// 
			this->pnlContent->AutoScroll = true;
			this->pnlContent->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(252)));
			this->pnlContent->Controls->Add(this->pnlManageBoys);
			this->pnlContent->Controls->Add(this->pnlManageDeliveries);
			this->pnlContent->Controls->Add(this->lblQuickActions);
			this->pnlContent->Controls->Add(this->pnlDeliveredCard);
			this->pnlContent->Controls->Add(this->pnlTransitCard);
			this->pnlContent->Controls->Add(this->pnlPendingCard);
			this->pnlContent->Controls->Add(this->pnlTotalCard);
			this->pnlContent->Controls->Add(this->lblDescription);
			this->pnlContent->Controls->Add(this->lblWelcome);
			this->pnlContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlContent->Location = System::Drawing::Point(240, 85);
			this->pnlContent->Name = L"pnlContent";
			this->pnlContent->Size = System::Drawing::Size(960, 635);
			this->pnlContent->TabIndex = 2;
			// 
			// pnlManageBoys
			// 
			this->pnlManageBoys->BackColor = System::Drawing::Color::White;
			this->pnlManageBoys->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlManageBoys->Controls->Add(this->btnManageBoys);
			this->pnlManageBoys->Controls->Add(this->lblManageBoysText);
			this->pnlManageBoys->Controls->Add(this->lblManageBoysTitle);
			this->pnlManageBoys->Location = System::Drawing::Point(490, 340);
			this->pnlManageBoys->Name = L"pnlManageBoys";
			this->pnlManageBoys->Size = System::Drawing::Size(430, 190);
			this->pnlManageBoys->TabIndex = 8;
			// 
			// btnManageBoys
			// 
			this->btnManageBoys->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->btnManageBoys->FlatAppearance->BorderSize = 0;
			this->btnManageBoys->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnManageBoys->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnManageBoys->ForeColor = System::Drawing::Color::White;
			this->btnManageBoys->Location = System::Drawing::Point(28, 125);
			this->btnManageBoys->Name = L"btnManageBoys";
			this->btnManageBoys->Size = System::Drawing::Size(170, 40);
			this->btnManageBoys->TabIndex = 2;
			this->btnManageBoys->Text = L"Manage Staff";
			this->btnManageBoys->UseVisualStyleBackColor = false;
			this->btnManageBoys->Click += gcnew System::EventHandler(this, &AdminDashboardDesigner::btnManageBoys_Click);
			// 
			// lblManageBoysText
			// 
			this->lblManageBoysText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblManageBoysText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblManageBoysText->Location = System::Drawing::Point(25, 62);
			this->lblManageBoysText->Name = L"lblManageBoysText";
			this->lblManageBoysText->Size = System::Drawing::Size(370, 45);
			this->lblManageBoysText->TabIndex = 1;
			this->lblManageBoysText->Text = L"Add, view, update and manage CourierEase delivery staff.";
			// 
			// lblManageBoysTitle
			// 
			this->lblManageBoysTitle->AutoSize = true;
			this->lblManageBoysTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			this->lblManageBoysTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblManageBoysTitle->Location = System::Drawing::Point(24, 22);
			this->lblManageBoysTitle->Name = L"lblManageBoysTitle";
			this->lblManageBoysTitle->Size = System::Drawing::Size(154, 30);
			this->lblManageBoysTitle->TabIndex = 0;
			this->lblManageBoysTitle->Text = L"Delivery Boys";
			// 
			// pnlManageDeliveries
			// 
			this->pnlManageDeliveries->BackColor = System::Drawing::Color::White;
			this->pnlManageDeliveries->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlManageDeliveries->Controls->Add(this->btnManageDeliveries);
			this->pnlManageDeliveries->Controls->Add(this->lblManageDeliveriesText);
			this->pnlManageDeliveries->Controls->Add(this->lblManageDeliveriesTitle);
			this->pnlManageDeliveries->Location = System::Drawing::Point(40, 340);
			this->pnlManageDeliveries->Name = L"pnlManageDeliveries";
			this->pnlManageDeliveries->Size = System::Drawing::Size(430, 190);
			this->pnlManageDeliveries->TabIndex = 7;
			// 
			// btnManageDeliveries
			// 
			this->btnManageDeliveries->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnManageDeliveries->FlatAppearance->BorderSize = 0;
			this->btnManageDeliveries->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnManageDeliveries->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnManageDeliveries->ForeColor = System::Drawing::Color::White;
			this->btnManageDeliveries->Location = System::Drawing::Point(28, 125);
			this->btnManageDeliveries->Name = L"btnManageDeliveries";
			this->btnManageDeliveries->Size = System::Drawing::Size(170, 40);
			this->btnManageDeliveries->TabIndex = 2;
			this->btnManageDeliveries->Text = L"Open Deliveries";
			this->btnManageDeliveries->UseVisualStyleBackColor = false;
			this->btnManageDeliveries->Click += gcnew System::EventHandler(this, &AdminDashboardDesigner::btnManageDeliveries_Click);
			// 
			// lblManageDeliveriesText
			// 
			this->lblManageDeliveriesText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblManageDeliveriesText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblManageDeliveriesText->Location = System::Drawing::Point(25, 62);
			this->lblManageDeliveriesText->Name = L"lblManageDeliveriesText";
			this->lblManageDeliveriesText->Size = System::Drawing::Size(370, 45);
			this->lblManageDeliveriesText->TabIndex = 1;
			this->lblManageDeliveriesText->Text = L"View parcels, assign delivery staff and update delivery status.";
			// 
			// lblManageDeliveriesTitle
			// 
			this->lblManageDeliveriesTitle->AutoSize = true;
			this->lblManageDeliveriesTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			this->lblManageDeliveriesTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblManageDeliveriesTitle->Location = System::Drawing::Point(24, 22);
			this->lblManageDeliveriesTitle->Name = L"lblManageDeliveriesTitle";
			this->lblManageDeliveriesTitle->Size = System::Drawing::Size(204, 30);
			this->lblManageDeliveriesTitle->TabIndex = 0;
			this->lblManageDeliveriesTitle->Text = L"Manage Deliveries";
			// 
			// lblQuickActions
			// 
			this->lblQuickActions->AutoSize = true;
			this->lblQuickActions->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->lblQuickActions->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblQuickActions->Location = System::Drawing::Point(36, 290);
			this->lblQuickActions->Name = L"lblQuickActions";
			this->lblQuickActions->Size = System::Drawing::Size(172, 32);
			this->lblQuickActions->TabIndex = 6;
			this->lblQuickActions->Text = L"Quick Actions";
			// 
			// pnlDeliveredCard
			// 
			this->pnlDeliveredCard->BackColor = System::Drawing::Color::White;
			this->pnlDeliveredCard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlDeliveredCard->Controls->Add(this->lblDeliveredValue);
			this->pnlDeliveredCard->Controls->Add(this->lblDeliveredCaption);
			this->pnlDeliveredCard->Location = System::Drawing::Point(715, 130);
			this->pnlDeliveredCard->Name = L"pnlDeliveredCard";
			this->pnlDeliveredCard->Size = System::Drawing::Size(205, 120);
			this->pnlDeliveredCard->TabIndex = 5;
			// 
			// lblDeliveredValue
			// 
			this->lblDeliveredValue->AutoSize = true;
			this->lblDeliveredValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold));
			this->lblDeliveredValue->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)),
				static_cast<System::Int32>(static_cast<System::Byte>(163)), static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->lblDeliveredValue->Location = System::Drawing::Point(15, 49);
			this->lblDeliveredValue->Name = L"lblDeliveredValue";
			this->lblDeliveredValue->Size = System::Drawing::Size(46, 54);
			this->lblDeliveredValue->TabIndex = 1;
			this->lblDeliveredValue->Text = L"0";
			// 
			// lblDeliveredCaption
			// 
			this->lblDeliveredCaption->AutoSize = true;
			this->lblDeliveredCaption->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblDeliveredCaption->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblDeliveredCaption->Location = System::Drawing::Point(18, 17);
			this->lblDeliveredCaption->Name = L"lblDeliveredCaption";
			this->lblDeliveredCaption->Size = System::Drawing::Size(75, 20);
			this->lblDeliveredCaption->TabIndex = 0;
			this->lblDeliveredCaption->Text = L"Delivered";
			// 
			// pnlTransitCard
			// 
			this->pnlTransitCard->BackColor = System::Drawing::Color::White;
			this->pnlTransitCard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlTransitCard->Controls->Add(this->lblTransitValue);
			this->pnlTransitCard->Controls->Add(this->lblTransitCaption);
			this->pnlTransitCard->Location = System::Drawing::Point(490, 130);
			this->pnlTransitCard->Name = L"pnlTransitCard";
			this->pnlTransitCard->Size = System::Drawing::Size(205, 120);
			this->pnlTransitCard->TabIndex = 4;
			// 
			// lblTransitValue
			// 
			this->lblTransitValue->AutoSize = true;
			this->lblTransitValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold));
			this->lblTransitValue->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(144)));
			this->lblTransitValue->Location = System::Drawing::Point(15, 49);
			this->lblTransitValue->Name = L"lblTransitValue";
			this->lblTransitValue->Size = System::Drawing::Size(46, 54);
			this->lblTransitValue->TabIndex = 1;
			this->lblTransitValue->Text = L"0";
			// 
			// lblTransitCaption
			// 
			this->lblTransitCaption->AutoSize = true;
			this->lblTransitCaption->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblTransitCaption->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblTransitCaption->Location = System::Drawing::Point(18, 17);
			this->lblTransitCaption->Name = L"lblTransitCaption";
			this->lblTransitCaption->Size = System::Drawing::Size(75, 20);
			this->lblTransitCaption->TabIndex = 0;
			this->lblTransitCaption->Text = L"In Transit";
			// 
			// pnlPendingCard
			// 
			this->pnlPendingCard->BackColor = System::Drawing::Color::White;
			this->pnlPendingCard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlPendingCard->Controls->Add(this->lblPendingValue);
			this->pnlPendingCard->Controls->Add(this->lblPendingCaption);
			this->pnlPendingCard->Location = System::Drawing::Point(265, 130);
			this->pnlPendingCard->Name = L"pnlPendingCard";
			this->pnlPendingCard->Size = System::Drawing::Size(205, 120);
			this->pnlPendingCard->TabIndex = 3;
			// 
			// lblPendingValue
			// 
			this->lblPendingValue->AutoSize = true;
			this->lblPendingValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold));
			this->lblPendingValue->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(6)));
			this->lblPendingValue->Location = System::Drawing::Point(15, 49);
			this->lblPendingValue->Name = L"lblPendingValue";
			this->lblPendingValue->Size = System::Drawing::Size(46, 54);
			this->lblPendingValue->TabIndex = 1;
			this->lblPendingValue->Text = L"0";
			// 
			// lblPendingCaption
			// 
			this->lblPendingCaption->AutoSize = true;
			this->lblPendingCaption->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblPendingCaption->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblPendingCaption->Location = System::Drawing::Point(18, 17);
			this->lblPendingCaption->Name = L"lblPendingCaption";
			this->lblPendingCaption->Size = System::Drawing::Size(98, 20);
			this->lblPendingCaption->TabIndex = 0;
			this->lblPendingCaption->Text = L"Order Placed";
			// 
			// pnlTotalCard
			// 
			this->pnlTotalCard->BackColor = System::Drawing::Color::White;
			this->pnlTotalCard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlTotalCard->Controls->Add(this->lblTotalValue);
			this->pnlTotalCard->Controls->Add(this->lblTotalCaption);
			this->pnlTotalCard->Location = System::Drawing::Point(40, 130);
			this->pnlTotalCard->Name = L"pnlTotalCard";
			this->pnlTotalCard->Size = System::Drawing::Size(205, 120);
			this->pnlTotalCard->TabIndex = 2;
			// 
			// lblTotalValue
			// 
			this->lblTotalValue->AutoSize = true;
			this->lblTotalValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold));
			this->lblTotalValue->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->lblTotalValue->Location = System::Drawing::Point(15, 49);
			this->lblTotalValue->Name = L"lblTotalValue";
			this->lblTotalValue->Size = System::Drawing::Size(46, 54);
			this->lblTotalValue->TabIndex = 1;
			this->lblTotalValue->Text = L"0";
			// 
			// lblTotalCaption
			// 
			this->lblTotalCaption->AutoSize = true;
			this->lblTotalCaption->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblTotalCaption->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblTotalCaption->Location = System::Drawing::Point(18, 17);
			this->lblTotalCaption->Name = L"lblTotalCaption";
			this->lblTotalCaption->Size = System::Drawing::Size(116, 20);
			this->lblTotalCaption->TabIndex = 0;
			this->lblTotalCaption->Text = L"Total Deliveries";
			// 
			// lblDescription
			// 
			this->lblDescription->AutoSize = true;
			this->lblDescription->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblDescription->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblDescription->Location = System::Drawing::Point(39, 82);
			this->lblDescription->Name = L"lblDescription";
			this->lblDescription->Size = System::Drawing::Size(365, 20);
			this->lblDescription->TabIndex = 1;
			this->lblDescription->Text = L"Monitor and manage CourierEase delivery operations.";
			// 
			// lblWelcome
			// 
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblWelcome->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblWelcome->Location = System::Drawing::Point(35, 30);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(410, 46);
			this->lblWelcome->TabIndex = 0;
			this->lblWelcome->Text = L"Welcome, Administrator";
			// 
			// AdminDashboardDesigner
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(252)));
			this->ClientSize = System::Drawing::Size(1200, 720);
			this->Controls->Add(this->pnlContent);
			this->Controls->Add(this->pnlHeader);
			this->Controls->Add(this->pnlSidebar);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"AdminDashboardDesigner";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CourierEase - Admin Dashboard";
			this->pnlSidebar->ResumeLayout(false);
			this->pnlSidebar->PerformLayout();
			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();
			this->pnlAvatar->ResumeLayout(false);
			this->pnlContent->ResumeLayout(false);
			this->pnlContent->PerformLayout();
			this->pnlManageBoys->ResumeLayout(false);
			this->pnlManageBoys->PerformLayout();
			this->pnlManageDeliveries->ResumeLayout(false);
			this->pnlManageDeliveries->PerformLayout();
			this->pnlDeliveredCard->ResumeLayout(false);
			this->pnlDeliveredCard->PerformLayout();
			this->pnlTransitCard->ResumeLayout(false);
			this->pnlTransitCard->PerformLayout();
			this->pnlPendingCard->ResumeLayout(false);
			this->pnlPendingCard->PerformLayout();
			this->pnlTotalCard->ResumeLayout(false);
			this->pnlTotalCard->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion

	private:

		void LoadAdminDetails()
		{
			if (String::IsNullOrWhiteSpace(adminName))
			{
				adminName = L"Administrator";
			}

			lblHeaderAdmin->Text = adminName;
			lblWelcome->Text = L"Welcome, " + adminName;

			String^ trimmedName = adminName->Trim();

			if (trimmedName->Length > 0)
			{
				lblInitial->Text =
					trimmedName->Substring(0, 1)->ToUpper();
			}
			else
			{
				lblInitial->Text = L"A";
			}
		}

		void LoadDashboardData()
		{
			try
			{
				int total =
					AdminDashboardRepository::GetTotalDeliveries();

				int orderPlaced =
					AdminDashboardRepository::GetOrderPlacedDeliveries();

				int inTransit =
					AdminDashboardRepository::GetInTransitDeliveries();

				int delivered =
					AdminDashboardRepository::GetDeliveredDeliveries();

				lblTotalValue->Text =
					total.ToString();

				lblPendingValue->Text =
					orderPlaced.ToString();

				lblTransitValue->Text =
					inTransit.ToString();

				lblDeliveredValue->Text =
					delivered.ToString();
			}
			catch (Exception^ ex)
			{
				lblTotalValue->Text = L"0";
				lblPendingValue->Text = L"0";
				lblTransitValue->Text = L"0";
				lblDeliveredValue->Text = L"0";

				System::Windows::Forms::MessageBox::Show(
					L"Unable to load dashboard statistics.\n\n" +
					ex->Message,
					L"CourierEase",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
			}
		}

		void Dashboard_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			lblPageTitle->Text = L"Dashboard";
			LoadDashboardData();
		}

		void Deliveries_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			ManageDeliveriesDesigner^ deliveriesForm =
				gcnew ManageDeliveriesDesigner(adminId);

			this->Hide();

			deliveriesForm->ShowDialog();

			delete deliveriesForm;

			this->Show();
			this->Activate();

			lblPageTitle->Text = L"Dashboard";
			LoadDashboardData();
		}

		void DeliveryBoys_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			DeliveryBoysDesigner^ deliveryBoysForm =
				gcnew DeliveryBoysDesigner();

			this->Hide();

			deliveryBoysForm->ShowDialog();

			delete deliveryBoysForm;

			this->Show();
			this->Activate();

			lblPageTitle->Text = L"Dashboard";
			LoadDashboardData();
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
				System::Windows::Forms::DialogResult::Yes
				)
			{
				this->DialogResult =
					System::Windows::Forms::DialogResult::OK;

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

		System::Void btnDeliveries_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Deliveries_Click(sender, e);
		}

		System::Void btnDeliveryBoys_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			DeliveryBoys_Click(sender, e);
		}

		System::Void btnManageBoys_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			DeliveryBoys_Click(sender, e);
		}

		System::Void btnManageDeliveries_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Deliveries_Click(sender, e);
		}

		System::Void btnLogout_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Logout_Click(sender, e);
		}
	};
}