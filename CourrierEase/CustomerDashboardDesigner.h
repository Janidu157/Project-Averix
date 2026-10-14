#pragma once

#include "DashboardRepository.h"
#include "CustomerRepository.h"
#include "BookParcelFormDesigner.h"
#include "MyDeliveriesFormDesigner.h"
#include "CustomerProfileDesigner.h"

namespace CourrierEase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class CustomerDashboardDesigner : public System::Windows::Forms::Form
	{
	private:
		int customerId;
		String^ customerName;

	public:
		CustomerDashboardDesigner(void)
		{
			customerId = 0;
			customerName = L"Customer";

			InitializeComponent();
		}

		CustomerDashboardDesigner(int id, String^ name)
		{
			customerId = id;
			customerName = name;

			InitializeComponent();

			LoadCustomerDetails();
			LoadDashboardData();
		}

	protected:
		~CustomerDashboardDesigner()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		// SIDEBAR
		System::Windows::Forms::Panel^ pnlSidebar;

		System::Windows::Forms::Label^ lblBrand;
		System::Windows::Forms::Label^ lblCustomer;

		System::Windows::Forms::Button^ btnDashboard;
		System::Windows::Forms::Button^ btnBookParcel;
		System::Windows::Forms::Button^ btnMyDeliveries;
		System::Windows::Forms::Button^ btnMyProfile;
		System::Windows::Forms::Button^ btnLogout;

		// HEADER
		System::Windows::Forms::Panel^ pnlHeader;
		System::Windows::Forms::Label^ lblPageTitle;
		System::Windows::Forms::Panel^ pnlAvatar;
		System::Windows::Forms::Label^ lblInitial;
		System::Windows::Forms::Label^ lblHeaderName;

		// MAIN
		System::Windows::Forms::Panel^ pnlMain;
		System::Windows::Forms::Label^ lblWelcome;
		System::Windows::Forms::Label^ lblSubtitle;

		// STAT CARDS
		System::Windows::Forms::Panel^ pnlTotal;
		System::Windows::Forms::Panel^ pnlTransit;
		System::Windows::Forms::Panel^ pnlDelivered;









		System::Windows::Forms::Label^ lblTotalNumber;
		System::Windows::Forms::Label^ lblTransitNumber;
		System::Windows::Forms::Label^ lblDeliveredNumber;

		System::Windows::Forms::Label^ lblTotalTitle;
		System::Windows::Forms::Label^ lblTransitTitle;
		System::Windows::Forms::Label^ lblDeliveredTitle;

		System::Windows::Forms::Label^ lblTotalText;
		System::Windows::Forms::Label^ lblTransitText;
		System::Windows::Forms::Label^ lblDeliveredText;

		// QUICK ACTIONS
		System::Windows::Forms::Label^ lblQuickActions;
		System::Windows::Forms::Button^ btnQuickBook;
		System::Windows::Forms::Button^ btnQuickDeliveries;

		// RECENT
		System::Windows::Forms::Label^ lblRecent;
		System::Windows::Forms::LinkLabel^ linkViewAll;
		System::Windows::Forms::DataGridView^ dgvRecent;

		System::Windows::Forms::DataGridViewTextBoxColumn^ trackingColumn;
		System::Windows::Forms::DataGridViewTextBoxColumn^ receiverColumn;
		System::Windows::Forms::DataGridViewTextBoxColumn^ serviceColumn;
		System::Windows::Forms::DataGridViewTextBoxColumn^ statusColumn;
		System::Windows::Forms::DataGridViewTextBoxColumn^ dateColumn;
		System::Windows::Forms::DataGridViewButtonColumn^ colAction;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->pnlSidebar = (gcnew System::Windows::Forms::Panel());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->btnMyProfile = (gcnew System::Windows::Forms::Button());
			this->btnMyDeliveries = (gcnew System::Windows::Forms::Button());
			this->btnBookParcel = (gcnew System::Windows::Forms::Button());
			this->btnDashboard = (gcnew System::Windows::Forms::Button());
			this->lblCustomer = (gcnew System::Windows::Forms::Label());
			this->lblBrand = (gcnew System::Windows::Forms::Label());
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			this->lblHeaderName = (gcnew System::Windows::Forms::Label());
			this->pnlAvatar = (gcnew System::Windows::Forms::Panel());
			this->lblInitial = (gcnew System::Windows::Forms::Label());
			this->lblPageTitle = (gcnew System::Windows::Forms::Label());
			this->pnlMain = (gcnew System::Windows::Forms::Panel());
			this->dgvRecent = (gcnew System::Windows::Forms::DataGridView());
			this->trackingColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->receiverColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->serviceColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->statusColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dateColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colAction = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->linkViewAll = (gcnew System::Windows::Forms::LinkLabel());
			this->lblRecent = (gcnew System::Windows::Forms::Label());
			this->btnQuickDeliveries = (gcnew System::Windows::Forms::Button());
			this->btnQuickBook = (gcnew System::Windows::Forms::Button());
			this->lblQuickActions = (gcnew System::Windows::Forms::Label());
			this->pnlDelivered = (gcnew System::Windows::Forms::Panel());
			this->lblDeliveredText = (gcnew System::Windows::Forms::Label());
			this->lblDeliveredTitle = (gcnew System::Windows::Forms::Label());
			this->lblDeliveredNumber = (gcnew System::Windows::Forms::Label());
			this->pnlTransit = (gcnew System::Windows::Forms::Panel());
			this->lblTransitText = (gcnew System::Windows::Forms::Label());
			this->lblTransitTitle = (gcnew System::Windows::Forms::Label());
			this->lblTransitNumber = (gcnew System::Windows::Forms::Label());
			this->pnlTotal = (gcnew System::Windows::Forms::Panel());
			this->lblTotalText = (gcnew System::Windows::Forms::Label());
			this->lblTotalTitle = (gcnew System::Windows::Forms::Label());
			this->lblTotalNumber = (gcnew System::Windows::Forms::Label());
			this->lblSubtitle = (gcnew System::Windows::Forms::Label());
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->pnlSidebar->SuspendLayout();
			this->pnlHeader->SuspendLayout();
			this->pnlAvatar->SuspendLayout();
			this->pnlMain->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRecent))->BeginInit();
			this->pnlDelivered->SuspendLayout();
			this->pnlTransit->SuspendLayout();
			this->pnlTotal->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlSidebar
			// 
			this->pnlSidebar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->pnlSidebar->Controls->Add(this->btnLogout);
			this->pnlSidebar->Controls->Add(this->btnMyProfile);
			this->pnlSidebar->Controls->Add(this->btnMyDeliveries);
			this->pnlSidebar->Controls->Add(this->btnBookParcel);
			this->pnlSidebar->Controls->Add(this->btnDashboard);
			this->pnlSidebar->Controls->Add(this->lblCustomer);
			this->pnlSidebar->Controls->Add(this->lblBrand);
			this->pnlSidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlSidebar->Location = System::Drawing::Point(0, 0);
			this->pnlSidebar->Name = L"pnlSidebar";
			this->pnlSidebar->Size = System::Drawing::Size(190, 700);
			this->pnlSidebar->TabIndex = 0;
			// 
			// btnLogout
			// 
			this->btnLogout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->btnLogout->FlatAppearance->BorderSize = 0;
			this->btnLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogout->ForeColor = System::Drawing::Color::White;
			this->btnLogout->Location = System::Drawing::Point(20, 620);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnLogout->Size = System::Drawing::Size(150, 38);
			this->btnLogout->TabIndex = 0;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &CustomerDashboardDesigner::btnLogout_Click);
			// 
			// btnMyProfile
			// 
			this->btnMyProfile->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->btnMyProfile->FlatAppearance->BorderSize = 0;
			this->btnMyProfile->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMyProfile->ForeColor = System::Drawing::Color::White;
			this->btnMyProfile->Location = System::Drawing::Point(20, 245);
			this->btnMyProfile->Name = L"btnMyProfile";
			this->btnMyProfile->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnMyProfile->Size = System::Drawing::Size(150, 38);
			this->btnMyProfile->TabIndex = 1;
			this->btnMyProfile->Text = L"My Profile";
			this->btnMyProfile->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnMyProfile->UseVisualStyleBackColor = false;
			this->btnMyProfile->Click += gcnew System::EventHandler(this, &CustomerDashboardDesigner::btnMyProfile_Click);
			// 
			// btnMyDeliveries
			// 
			this->btnMyDeliveries->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
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
			this->btnMyDeliveries->Click += gcnew System::EventHandler(this, &CustomerDashboardDesigner::btnMyDeliveries_Click);
			// 
			// btnBookParcel
			// 
			this->btnBookParcel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->btnBookParcel->FlatAppearance->BorderSize = 0;
			this->btnBookParcel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBookParcel->ForeColor = System::Drawing::Color::White;
			this->btnBookParcel->Location = System::Drawing::Point(20, 145);
			this->btnBookParcel->Name = L"btnBookParcel";
			this->btnBookParcel->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnBookParcel->Size = System::Drawing::Size(150, 38);
			this->btnBookParcel->TabIndex = 3;
			this->btnBookParcel->Text = L"Book Parcel";
			this->btnBookParcel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnBookParcel->UseVisualStyleBackColor = false;
			this->btnBookParcel->Click += gcnew System::EventHandler(this, &CustomerDashboardDesigner::btnBookParcel_Click);
			// 
			// btnDashboard
			// 
			this->btnDashboard->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnDashboard->FlatAppearance->BorderSize = 0;
			this->btnDashboard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDashboard->ForeColor = System::Drawing::Color::White;
			this->btnDashboard->Location = System::Drawing::Point(20, 95);
			this->btnDashboard->Name = L"btnDashboard";
			this->btnDashboard->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->btnDashboard->Size = System::Drawing::Size(150, 38);
			this->btnDashboard->TabIndex = 4;
			this->btnDashboard->Text = L"Dashboard";
			this->btnDashboard->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDashboard->UseVisualStyleBackColor = false;
			this->btnDashboard->Click += gcnew System::EventHandler(this, &CustomerDashboardDesigner::btnDashboard_Click);
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
			this->lblCustomer->TabIndex = 5;
			this->lblCustomer->Text = L"CUSTOMER";
			// 
			// lblBrand
			// 
			this->lblBrand->AutoSize = true;
			this->lblBrand->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblBrand->ForeColor = System::Drawing::Color::White;
			this->lblBrand->Location = System::Drawing::Point(18, 24);
			this->lblBrand->Name = L"lblBrand";
			this->lblBrand->Size = System::Drawing::Size(123, 28);
			this->lblBrand->TabIndex = 6;
			this->lblBrand->Text = L"CourierEase";
			// 
			// pnlHeader
			// 
			this->pnlHeader->BackColor = System::Drawing::Color::White;
			this->pnlHeader->Controls->Add(this->lblHeaderName);
			this->pnlHeader->Controls->Add(this->pnlAvatar);
			this->pnlHeader->Controls->Add(this->lblPageTitle);
			this->pnlHeader->Location = System::Drawing::Point(190, 0);
			this->pnlHeader->Name = L"pnlHeader";
			this->pnlHeader->Size = System::Drawing::Size(910, 65);
			this->pnlHeader->TabIndex = 1;
			// 
			// lblHeaderName
			// 
			this->lblHeaderName->AutoSize = true;
			this->lblHeaderName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblHeaderName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblHeaderName->Location = System::Drawing::Point(795, 24);
			this->lblHeaderName->Name = L"lblHeaderName";
			this->lblHeaderName->Size = System::Drawing::Size(73, 19);
			this->lblHeaderName->TabIndex = 0;
			this->lblHeaderName->Text = L"Customer";
			// 
			// pnlAvatar
			// 
			this->pnlAvatar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pnlAvatar->Controls->Add(this->lblInitial);
			this->pnlAvatar->Location = System::Drawing::Point(750, 16);
			this->pnlAvatar->Name = L"pnlAvatar";
			this->pnlAvatar->Size = System::Drawing::Size(34, 34);
			this->pnlAvatar->TabIndex = 0;
			// 
			// lblInitial
			// 
			this->lblInitial->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lblInitial->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblInitial->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->lblInitial->Location = System::Drawing::Point(0, 0);
			this->lblInitial->Name = L"lblInitial";
			this->lblInitial->Size = System::Drawing::Size(34, 34);
			this->lblInitial->TabIndex = 0;
			this->lblInitial->Text = L"C";
			this->lblInitial->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblPageTitle
			// 
			this->lblPageTitle->AutoSize = true;
			this->lblPageTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblPageTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblPageTitle->Location = System::Drawing::Point(30, 20);
			this->lblPageTitle->Name = L"lblPageTitle";
			this->lblPageTitle->Size = System::Drawing::Size(114, 28);
			this->lblPageTitle->TabIndex = 1;
			this->lblPageTitle->Text = L"Dashboard";
			// 
			// pnlMain
			// 
			this->pnlMain->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(252)));
			this->pnlMain->Controls->Add(this->dgvRecent);
			this->pnlMain->Controls->Add(this->linkViewAll);
			this->pnlMain->Controls->Add(this->lblRecent);
			this->pnlMain->Controls->Add(this->btnQuickDeliveries);
			this->pnlMain->Controls->Add(this->btnQuickBook);
			this->pnlMain->Controls->Add(this->lblQuickActions);
			this->pnlMain->Controls->Add(this->pnlDelivered);
			this->pnlMain->Controls->Add(this->pnlTransit);
			this->pnlMain->Controls->Add(this->pnlTotal);
			this->pnlMain->Controls->Add(this->lblSubtitle);
			this->pnlMain->Controls->Add(this->lblWelcome);
			this->pnlMain->Location = System::Drawing::Point(190, 65);
			this->pnlMain->Name = L"pnlMain";
			this->pnlMain->Size = System::Drawing::Size(910, 635);
			this->pnlMain->TabIndex = 2;
			// 
			// dgvRecent
			// 
			this->dgvRecent->AllowUserToAddRows = false;
			this->dgvRecent->AllowUserToDeleteRows = false;
			this->dgvRecent->AllowUserToResizeRows = false;
			this->dgvRecent->BackgroundColor = System::Drawing::Color::White;
			this->dgvRecent->ColumnHeadersHeight = 38;
			this->dgvRecent->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->trackingColumn,
					this->receiverColumn, this->serviceColumn, this->statusColumn, this->dateColumn, this->colAction
			});
			this->dgvRecent->Location = System::Drawing::Point(35, 375);
			this->dgvRecent->MultiSelect = false;
			this->dgvRecent->Name = L"dgvRecent";
			this->dgvRecent->ReadOnly = true;
			this->dgvRecent->RowHeadersVisible = false;
			this->dgvRecent->RowHeadersWidth = 51;
			this->dgvRecent->RowTemplate->Height = 38;
			this->dgvRecent->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvRecent->Size = System::Drawing::Size(810, 185);
			this->dgvRecent->TabIndex = 0;
			this->dgvRecent->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CustomerDashboardDesigner::dgvRecent_CellContentClick);
			// 
			// trackingColumn
			// 
			this->trackingColumn->DataPropertyName = L"tracking_no";
			this->trackingColumn->HeaderText = L"Tracking No.";
			this->trackingColumn->MinimumWidth = 6;
			this->trackingColumn->Name = L"trackingColumn";
			this->trackingColumn->ReadOnly = true;
			this->trackingColumn->Width = 155;
			// 
			// receiverColumn
			// 
			this->receiverColumn->DataPropertyName = L"receiver_name";
			this->receiverColumn->HeaderText = L"Receiver";
			this->receiverColumn->MinimumWidth = 6;
			this->receiverColumn->Name = L"receiverColumn";
			this->receiverColumn->ReadOnly = true;
			this->receiverColumn->Width = 160;
			// 
			// serviceColumn
			// 
			this->serviceColumn->DataPropertyName = L"delivery_option";
			this->serviceColumn->HeaderText = L"Service";
			this->serviceColumn->MinimumWidth = 6;
			this->serviceColumn->Name = L"serviceColumn";
			this->serviceColumn->ReadOnly = true;
			this->serviceColumn->Width = 110;
			// 
			// statusColumn
			// 
			this->statusColumn->DataPropertyName = L"status";
			this->statusColumn->HeaderText = L"Status";
			this->statusColumn->MinimumWidth = 6;
			this->statusColumn->Name = L"statusColumn";
			this->statusColumn->ReadOnly = true;
			this->statusColumn->Width = 130;
			// 
			// dateColumn
			// 
			this->dateColumn->DataPropertyName = L"created_at";
			this->dateColumn->HeaderText = L"Date";
			this->dateColumn->MinimumWidth = 6;
			this->dateColumn->Name = L"dateColumn";
			this->dateColumn->ReadOnly = true;
			this->dateColumn->Width = 130;
			// 
			// colAction
			// 
			this->colAction->HeaderText = L"Action";
			this->colAction->MinimumWidth = 6;
			this->colAction->Name = L"colAction";
			this->colAction->ReadOnly = true;
			this->colAction->Text = L"View";
			this->colAction->UseColumnTextForButtonValue = true;
			this->colAction->Width = 80;
			// 
			// linkViewAll
			// 
			this->linkViewAll->AutoSize = true;
			this->linkViewAll->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->linkViewAll->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->linkViewAll->Location = System::Drawing::Point(780, 345);
			this->linkViewAll->Name = L"linkViewAll";
			this->linkViewAll->Size = System::Drawing::Size(75, 19);
			this->linkViewAll->TabIndex = 1;
			this->linkViewAll->TabStop = true;
			this->linkViewAll->Text = L"View all >";
			this->linkViewAll->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &CustomerDashboardDesigner::linkViewAll_LinkClicked);
			// 
			// lblRecent
			// 
			this->lblRecent->AutoSize = true;
			this->lblRecent->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->lblRecent->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblRecent->Location = System::Drawing::Point(35, 340);
			this->lblRecent->Name = L"lblRecent";
			this->lblRecent->Size = System::Drawing::Size(162, 25);
			this->lblRecent->TabIndex = 2;
			this->lblRecent->Text = L"Recent Deliveries";
			// 
			// btnQuickDeliveries
			// 
			this->btnQuickDeliveries->BackColor = System::Drawing::Color::White;
			this->btnQuickDeliveries->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnQuickDeliveries->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnQuickDeliveries->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnQuickDeliveries->Location = System::Drawing::Point(220, 270);
			this->btnQuickDeliveries->Name = L"btnQuickDeliveries";
			this->btnQuickDeliveries->Size = System::Drawing::Size(170, 40);
			this->btnQuickDeliveries->TabIndex = 3;
			this->btnQuickDeliveries->Text = L"View My Deliveries";
			this->btnQuickDeliveries->UseVisualStyleBackColor = false;
			this->btnQuickDeliveries->Click += gcnew System::EventHandler(this, &CustomerDashboardDesigner::btnQuickDeliveries_Click);
			// 
			// btnQuickBook
			// 
			this->btnQuickBook->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnQuickBook->FlatAppearance->BorderSize = 0;
			this->btnQuickBook->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnQuickBook->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnQuickBook->ForeColor = System::Drawing::Color::White;
			this->btnQuickBook->Location = System::Drawing::Point(35, 270);
			this->btnQuickBook->Name = L"btnQuickBook";
			this->btnQuickBook->Size = System::Drawing::Size(170, 40);
			this->btnQuickBook->TabIndex = 4;
			this->btnQuickBook->Text = L"Book a Parcel";
			this->btnQuickBook->UseVisualStyleBackColor = false;
			this->btnQuickBook->Click += gcnew System::EventHandler(this, &CustomerDashboardDesigner::btnQuickBook_Click);
			// 
			// lblQuickActions
			// 
			this->lblQuickActions->AutoSize = true;
			this->lblQuickActions->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->lblQuickActions->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblQuickActions->Location = System::Drawing::Point(35, 235);
			this->lblQuickActions->Name = L"lblQuickActions";
			this->lblQuickActions->Size = System::Drawing::Size(134, 25);
			this->lblQuickActions->TabIndex = 5;
			this->lblQuickActions->Text = L"Quick Actions";
			// 
			// pnlDelivered
			// 
			this->pnlDelivered->BackColor = System::Drawing::Color::White;
			this->pnlDelivered->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlDelivered->Controls->Add(this->lblDeliveredText);
			this->pnlDelivered->Controls->Add(this->lblDeliveredTitle);
			this->pnlDelivered->Controls->Add(this->lblDeliveredNumber);
			this->pnlDelivered->Location = System::Drawing::Point(505, 105);
			this->pnlDelivered->Name = L"pnlDelivered";
			this->pnlDelivered->Size = System::Drawing::Size(215, 105);
			this->pnlDelivered->TabIndex = 2;
			// 
			// lblDeliveredText
			// 
			this->lblDeliveredText->AutoSize = true;
			this->lblDeliveredText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7));
			this->lblDeliveredText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(163)), static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->lblDeliveredText->Location = System::Drawing::Point(17, 78);
			this->lblDeliveredText->Name = L"lblDeliveredText";
			this->lblDeliveredText->Size = System::Drawing::Size(122, 15);
			this->lblDeliveredText->TabIndex = 0;
			this->lblDeliveredText->Text = L"Successfully delivered";
			// 
			// lblDeliveredTitle
			// 
			this->lblDeliveredTitle->AutoSize = true;
			this->lblDeliveredTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)), static_cast<System::Int32>(static_cast<System::Byte>(105)));
			this->lblDeliveredTitle->Location = System::Drawing::Point(16, 56);
			this->lblDeliveredTitle->Name = L"lblDeliveredTitle";
			this->lblDeliveredTitle->Size = System::Drawing::Size(73, 20);
			this->lblDeliveredTitle->TabIndex = 1;
			this->lblDeliveredTitle->Text = L"Delivered";
			// 
			// lblDeliveredNumber
			// 
			this->lblDeliveredNumber->AutoSize = true;
			this->lblDeliveredNumber->Font = (gcnew System::Drawing::Font(L"Segoe UI", 17, System::Drawing::FontStyle::Bold));
			this->lblDeliveredNumber->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblDeliveredNumber->Location = System::Drawing::Point(16, 18);
			this->lblDeliveredNumber->Name = L"lblDeliveredNumber";
			this->lblDeliveredNumber->Size = System::Drawing::Size(34, 40);
			this->lblDeliveredNumber->TabIndex = 2;
			this->lblDeliveredNumber->Text = L"0";
			// 
			// pnlTransit
			// 
			this->pnlTransit->BackColor = System::Drawing::Color::White;
			this->pnlTransit->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlTransit->Controls->Add(this->lblTransitText);
			this->pnlTransit->Controls->Add(this->lblTransitTitle);
			this->pnlTransit->Controls->Add(this->lblTransitNumber);
			this->pnlTransit->Location = System::Drawing::Point(270, 105);
			this->pnlTransit->Name = L"pnlTransit";
			this->pnlTransit->Size = System::Drawing::Size(215, 105);
			this->pnlTransit->TabIndex = 1;
			// 
			// lblTransitText
			// 
			this->lblTransitText->AutoSize = true;
			this->lblTransitText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7));
			this->lblTransitText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->lblTransitText->Location = System::Drawing::Point(17, 78);
			this->lblTransitText->Name = L"lblTransitText";
			this->lblTransitText->Size = System::Drawing::Size(100, 15);
			this->lblTransitText->TabIndex = 0;
			this->lblTransitText->Text = L"Currently moving";
			// 
			// lblTransitTitle
			// 
			this->lblTransitTitle->AutoSize = true;
			this->lblTransitTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(105)));
			this->lblTransitTitle->Location = System::Drawing::Point(16, 56);
			this->lblTransitTitle->Name = L"lblTransitTitle";
			this->lblTransitTitle->Size = System::Drawing::Size(68, 20);
			this->lblTransitTitle->TabIndex = 1;
			this->lblTransitTitle->Text = L"In Transit";
			// 
			// lblTransitNumber
			// 
			this->lblTransitNumber->AutoSize = true;
			this->lblTransitNumber->Font = (gcnew System::Drawing::Font(L"Segoe UI", 17, System::Drawing::FontStyle::Bold));
			this->lblTransitNumber->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblTransitNumber->Location = System::Drawing::Point(16, 18);
			this->lblTransitNumber->Name = L"lblTransitNumber";
			this->lblTransitNumber->Size = System::Drawing::Size(34, 40);
			this->lblTransitNumber->TabIndex = 2;
			this->lblTransitNumber->Text = L"0";
			// 
			// pnlTotal
			// 
			this->pnlTotal->BackColor = System::Drawing::Color::White;
			this->pnlTotal->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlTotal->Controls->Add(this->lblTotalText);
			this->pnlTotal->Controls->Add(this->lblTotalTitle);
			this->pnlTotal->Controls->Add(this->lblTotalNumber);
			this->pnlTotal->Location = System::Drawing::Point(35, 105);
			this->pnlTotal->Name = L"pnlTotal";
			this->pnlTotal->Size = System::Drawing::Size(215, 105);
			this->pnlTotal->TabIndex = 0;
			// 
			// lblTotalText
			// 
			this->lblTotalText->AutoSize = true;
			this->lblTotalText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7));
			this->lblTotalText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->lblTotalText->Location = System::Drawing::Point(23, 78);
			this->lblTotalText->Name = L"lblTotalText";
			this->lblTotalText->Size = System::Drawing::Size(104, 15);
			this->lblTotalText->TabIndex = 0;
			this->lblTotalText->Text = L"All booked parcels";
			// 
			// lblTotalTitle
			// 
			this->lblTotalTitle->AutoSize = true;
			this->lblTotalTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(105)));
			this->lblTotalTitle->Location = System::Drawing::Point(22, 50);
			this->lblTotalTitle->Name = L"lblTotalTitle";
			this->lblTotalTitle->Size = System::Drawing::Size(111, 20);
			this->lblTotalTitle->TabIndex = 1;
			this->lblTotalTitle->Text = L"Total Deliveries";
			// 
			// lblTotalNumber
			// 
			this->lblTotalNumber->AutoSize = true;
			this->lblTotalNumber->Font = (gcnew System::Drawing::Font(L"Segoe UI", 17, System::Drawing::FontStyle::Bold));
			this->lblTotalNumber->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblTotalNumber->Location = System::Drawing::Point(22, 12);
			this->lblTotalNumber->Name = L"lblTotalNumber";
			this->lblTotalNumber->Size = System::Drawing::Size(34, 40);
			this->lblTotalNumber->TabIndex = 2;
			this->lblTotalNumber->Text = L"0";
			// 
			// lblSubtitle
			// 
			this->lblSubtitle->AutoSize = true;
			this->lblSubtitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblSubtitle->Location = System::Drawing::Point(37, 65);
			this->lblSubtitle->Name = L"lblSubtitle";
			this->lblSubtitle->Size = System::Drawing::Size(290, 20);
			this->lblSubtitle->TabIndex = 6;
			this->lblSubtitle->Text = L"Here is a quick overview of your deliveries.";
			// 
			// lblWelcome
			// 
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
			this->lblWelcome->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblWelcome->Location = System::Drawing::Point(35, 25);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(383, 41);
			this->lblWelcome->TabIndex = 7;
			this->lblWelcome->Text = L"Welcome back, Customer!";
			// 
			// CustomerDashboardDesigner
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(252)));
			this->ClientSize = System::Drawing::Size(1100, 700);
			this->Controls->Add(this->pnlMain);
			this->Controls->Add(this->pnlHeader);
			this->Controls->Add(this->pnlSidebar);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"CustomerDashboardDesigner";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CourierEase - Customer Dashboard";
			this->pnlSidebar->ResumeLayout(false);
			this->pnlSidebar->PerformLayout();
			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();
			this->pnlAvatar->ResumeLayout(false);
			this->pnlMain->ResumeLayout(false);
			this->pnlMain->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRecent))->EndInit();
			this->pnlDelivered->ResumeLayout(false);
			this->pnlDelivered->PerformLayout();
			this->pnlTransit->ResumeLayout(false);
			this->pnlTransit->PerformLayout();
			this->pnlTotal->ResumeLayout(false);
			this->pnlTotal->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion

	private:

		void Dashboard_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			LoadCustomerDetails();
			LoadDashboardData();
		}

		void BookParcel_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (customerId <= 0)
			{
				return;
			}

			BookParcelFormDesigner^ bookForm =
				gcnew BookParcelFormDesigner(
					customerId,
					customerName
				);

			System::Windows::Forms::DialogResult result =
				bookForm->ShowDialog(this);

			delete bookForm;

			if (
				result ==
				System::Windows::Forms::DialogResult::Abort
				)
			{
				this->Close();
				return;
			}

			if (
				result ==
				System::Windows::Forms::DialogResult::Retry
				)
			{
				OpenMyDeliveries();
				return;
			}

			if (
				result ==
				System::Windows::Forms::DialogResult::Ignore
				)
			{
				Profile_Click(
					nullptr,
					System::EventArgs::Empty
				);

				return;
			}

			LoadDashboardData();
		}

		void MyDeliveries_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			OpenMyDeliveries();
		}

		void ViewAll_LinkClicked(
			System::Object^ sender,
			System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
		{
			OpenMyDeliveries();
		}

		void Recent_CellContentClick(
			System::Object^ sender,
			System::Windows::Forms::DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex < 0)
			{
				return;
			}

			if (e->ColumnIndex == colAction->Index)
			{
				OpenMyDeliveries();
			}
		}

		void OpenMyDeliveries()
		{
			if (customerId <= 0)
			{
				return;
			}

			MyDeliveriesFormDesigner^ deliveriesForm =
				gcnew MyDeliveriesFormDesigner(
					customerId,
					customerName
				);

			System::Windows::Forms::DialogResult result =
				deliveriesForm->ShowDialog(this);

			delete deliveriesForm;

			if (
				result ==
				System::Windows::Forms::DialogResult::Abort
				)
			{
				this->Close();
				return;
			}

			if (
				result ==
				System::Windows::Forms::DialogResult::Retry
				)
			{
				BookParcel_Click(
					nullptr,
					System::EventArgs::Empty
				);

				return;
			}

			if (
				result ==
				System::Windows::Forms::DialogResult::Ignore
				)
			{
				Profile_Click(
					nullptr,
					System::EventArgs::Empty
				);

				return;
			}

			LoadDashboardData();
		}

		void Profile_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (customerId <= 0)
			{
				return;
			}

			CustomerProfileDesigner^ profileForm =
				gcnew CustomerProfileDesigner(
					customerId,
					customerName
				);

			System::Windows::Forms::DialogResult result =
				profileForm->ShowDialog(this);

			if (
				result ==
				System::Windows::Forms::DialogResult::Abort
				)
			{
				this->Close();
				return;
			}

			RefreshCustomerFromDatabase();
			LoadCustomerDetails();
			LoadDashboardData();
		}

		void Logout_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			System::Windows::Forms::DialogResult answer =
				System::Windows::Forms::MessageBox::Show(
					L"Are you sure you want to logout?",
					L"Logout",
					System::Windows::Forms::MessageBoxButtons::YesNo,
					System::Windows::Forms::MessageBoxIcon::Question
				);

			if (
				answer ==
				System::Windows::Forms::DialogResult::Yes
				)
			{
				this->Close();
			}
		}

		void RefreshCustomerFromDatabase()
		{
			if (customerId <= 0)
			{
				return;
			}

			try
			{
				System::Data::DataRow^ customerRow =
					CustomerRepository::GetCustomerById(
						customerId
					);

				if (customerRow != nullptr)
				{
					customerName =
						customerRow["full_name"]->ToString();
				}
			}
			catch (System::Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Unable to refresh customer information.\n\n" +
					ex->Message,
					L"Customer Error",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error
				);
			}
		}

		void LoadCustomerDetails()
		{
			if (String::IsNullOrWhiteSpace(customerName))
			{
				customerName =
					L"Customer";
			}

			lblHeaderName->Text =
				customerName;

			lblWelcome->Text =
				L"Welcome back, " +
				customerName +
				L"!";

			if (customerName->Length > 0)
			{
				lblInitial->Text =
					customerName->
					Substring(0, 1)->
					ToUpper();
			}
			else
			{
				lblInitial->Text =
					L"C";
			}
		}

		void LoadDashboardData()
		{
			if (customerId <= 0)
			{
				return;
			}

			try
			{
				int total =
					DashboardRepository::
					GetTotalDeliveries(
						customerId
					);

				int transit =
					DashboardRepository::
					GetInTransitDeliveries(
						customerId
					);

				int delivered =
					DashboardRepository::
					GetDeliveredDeliveries(
						customerId
					);

				lblTotalNumber->Text =
					total.ToString();

				lblTransitNumber->Text =
					transit.ToString();

				lblDeliveredNumber->Text =
					delivered.ToString();

				System::Data::DataTable^ recent =
					DashboardRepository::
					GetRecentDeliveries(
						customerId
					);

				dgvRecent->AutoGenerateColumns =
					false;

				dgvRecent->DataSource =
					recent;
			}
			catch (System::Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Unable to load dashboard data.\n\n" +
					ex->Message,
					L"Dashboard Error",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error
				);
			}
		}

	private:
		System::Void btnQuickBook_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			BookParcel_Click(sender, e);
		}

		System::Void btnQuickDeliveries_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			MyDeliveries_Click(sender, e);
		}

		System::Void linkViewAll_LinkClicked(
			System::Object^ sender,
			System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
		{
			ViewAll_LinkClicked(sender, e);
		}

		System::Void btnLogout_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Logout_Click(sender, e);
		}

		System::Void btnBookParcel_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			BookParcel_Click(sender, e);
		}

		System::Void btnDashboard_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Dashboard_Click(sender, e);
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
			Profile_Click(sender, e);
		}

		System::Void dgvRecent_CellContentClick(
			System::Object^ sender,
			System::Windows::Forms::DataGridViewCellEventArgs^ e)
		{
			Recent_CellContentClick(sender, e);
		}
	};
}