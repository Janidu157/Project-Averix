#pragma once

#include "ParcelManagementRepository.h"
#include "EditParcelFormDesigner.h"

namespace CourrierEase
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyDeliveriesFormDesigner :
		public System::Windows::Forms::Form
	{
	public:

		MyDeliveriesFormDesigner(void)
		{
			customerId = 0;
			customerName = L"Customer";

			InitializeComponent();
		}

		MyDeliveriesFormDesigner(
			int loggedCustomerId,
			String^ loggedCustomerName)
		{
			customerId = loggedCustomerId;
			customerName = loggedCustomerName;

			InitializeComponent();

			LoadCustomerHeader();
			LoadDeliveries();
		}

	protected:

		~MyDeliveriesFormDesigner()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		int customerId;
		System::String^ customerName;

		System::Windows::Forms::Panel^ pnlSidebar;

		System::Windows::Forms::Panel^ pnlAvatar;
		System::Windows::Forms::Panel^ pnlHeader;
		System::Windows::Forms::Panel^ pnlContent;
		System::Windows::Forms::Panel^ pnlTable;

		System::Windows::Forms::Label^ lblBrand;
		System::Windows::Forms::Label^ lblCustomerSection;

		System::Windows::Forms::Button^ btnDashboard;
		System::Windows::Forms::Button^ btnBookParcel;
		System::Windows::Forms::Button^ btnMyDeliveries;
		System::Windows::Forms::Button^ btnMyProfile;
		System::Windows::Forms::Button^ btnLogout;

		System::Windows::Forms::Label^ lblHeaderTitle;
		System::Windows::Forms::Label^ lblAvatar;
		System::Windows::Forms::Label^ lblHeaderCustomer;

		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Label^ lblSubtitle;
		System::Windows::Forms::Label^ lblCount;

		System::Windows::Forms::Button^ btnRefresh;

		System::Windows::Forms::DataGridView^ dgvDeliveries;

		System::Windows::Forms::DataGridViewTextBoxColumn^ colParcelId;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colTracking;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colReceiver;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colService;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colCharge;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colStatus;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colDate;

		System::Windows::Forms::DataGridViewButtonColumn^ colView;
		System::Windows::Forms::DataGridViewButtonColumn^ colEdit;
		System::Windows::Forms::DataGridViewButtonColumn^ colCancel;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->pnlSidebar =
				(gcnew System::Windows::Forms::Panel());

			this->lblBrand =
				(gcnew System::Windows::Forms::Label());

			this->lblCustomerSection =
				(gcnew System::Windows::Forms::Label());

			this->btnDashboard =
				(gcnew System::Windows::Forms::Button());

			this->btnBookParcel =
				(gcnew System::Windows::Forms::Button());

			this->btnMyDeliveries =
				(gcnew System::Windows::Forms::Button());

			this->btnMyProfile =
				(gcnew System::Windows::Forms::Button());

			this->btnLogout =
				(gcnew System::Windows::Forms::Button());

			this->pnlAvatar =
				(gcnew System::Windows::Forms::Panel());

			this->lblAvatar =
				(gcnew System::Windows::Forms::Label());

			this->pnlHeader =
				(gcnew System::Windows::Forms::Panel());

			this->lblHeaderTitle =
				(gcnew System::Windows::Forms::Label());

			this->lblHeaderCustomer =
				(gcnew System::Windows::Forms::Label());

			this->pnlContent =
				(gcnew System::Windows::Forms::Panel());

			this->lblTitle =
				(gcnew System::Windows::Forms::Label());

			this->lblSubtitle =
				(gcnew System::Windows::Forms::Label());

			this->lblCount =
				(gcnew System::Windows::Forms::Label());

			this->btnRefresh =
				(gcnew System::Windows::Forms::Button());

			this->pnlTable =
				(gcnew System::Windows::Forms::Panel());

			this->dgvDeliveries =
				(gcnew System::Windows::Forms::DataGridView());

			this->colParcelId =
				(gcnew System::Windows::Forms::DataGridViewTextBoxColumn());

			this->colTracking =
				(gcnew System::Windows::Forms::DataGridViewTextBoxColumn());

			this->colReceiver =
				(gcnew System::Windows::Forms::DataGridViewTextBoxColumn());

			this->colService =
				(gcnew System::Windows::Forms::DataGridViewTextBoxColumn());

			this->colCharge =
				(gcnew System::Windows::Forms::DataGridViewTextBoxColumn());

			this->colStatus =
				(gcnew System::Windows::Forms::DataGridViewTextBoxColumn());

			this->colDate =
				(gcnew System::Windows::Forms::DataGridViewTextBoxColumn());

			this->colView =
				(gcnew System::Windows::Forms::DataGridViewButtonColumn());

			this->colEdit =
				(gcnew System::Windows::Forms::DataGridViewButtonColumn());

			this->colCancel =
				(gcnew System::Windows::Forms::DataGridViewButtonColumn());

			this->pnlSidebar->SuspendLayout();
			this->pnlAvatar->SuspendLayout();
			this->pnlHeader->SuspendLayout();
			this->pnlContent->SuspendLayout();
			this->pnlTable->SuspendLayout();

			(cli::safe_cast<
				System::ComponentModel::ISupportInitialize^>(
					this->dgvDeliveries))->BeginInit();

			this->SuspendLayout();

			// pnlSidebar

			this->pnlSidebar->BackColor =
				System::Drawing::Color::FromArgb(
					15,
					23,
					42);

			this->pnlSidebar->Controls->Add(
				this->lblBrand);

			this->pnlSidebar->Controls->Add(
				this->lblCustomerSection);

			this->pnlSidebar->Controls->Add(
				this->btnDashboard);

			this->pnlSidebar->Controls->Add(
				this->btnBookParcel);

			this->pnlSidebar->Controls->Add(
				this->btnMyDeliveries);

			this->pnlSidebar->Controls->Add(
				this->btnMyProfile);

			this->pnlSidebar->Controls->Add(
				this->btnLogout);

			this->pnlSidebar->Dock =
				System::Windows::Forms::DockStyle::Left;

			this->pnlSidebar->Location =
				System::Drawing::Point(0, 0);

			this->pnlSidebar->Name =
				L"pnlSidebar";

			this->pnlSidebar->Size =
				System::Drawing::Size(205, 700);

			this->pnlSidebar->TabIndex = 0;

			// lblBrand

			this->lblBrand->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					12,
					System::Drawing::FontStyle::Bold));

			this->lblBrand->ForeColor =
				System::Drawing::Color::White;

			this->lblBrand->Location =
				System::Drawing::Point(24, 21);

			this->lblBrand->Name =
				L"lblBrand";

			this->lblBrand->Size =
				System::Drawing::Size(130, 28);

			this->lblBrand->TabIndex = 1;

			this->lblBrand->Text =
				L"CourierEase";

			// lblCustomerSection

			this->lblCustomerSection->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					8));

			this->lblCustomerSection->ForeColor =
				System::Drawing::Color::FromArgb(
					148,
					163,
					184);

			this->lblCustomerSection->Location =
				System::Drawing::Point(25, 70);

			this->lblCustomerSection->Name =
				L"lblCustomerSection";

			this->lblCustomerSection->Size =
				System::Drawing::Size(130, 20);

			this->lblCustomerSection->TabIndex = 2;

			this->lblCustomerSection->Text =
				L"CUSTOMER";

			// btnDashboard

			this->btnDashboard->BackColor =
				System::Drawing::Color::FromArgb(
					15,
					23,
					42);

			this->btnDashboard->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->btnDashboard->FlatAppearance->BorderSize = 0;

			this->btnDashboard->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnDashboard->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9));

			this->btnDashboard->ForeColor =
				System::Drawing::Color::White;

			this->btnDashboard->Location =
				System::Drawing::Point(20, 100);

			this->btnDashboard->Name =
				L"btnDashboard";

			this->btnDashboard->Size =
				System::Drawing::Size(165, 38);

			this->btnDashboard->TabIndex = 0;

			this->btnDashboard->Text =
				L"Dashboard";

			this->btnDashboard->TextAlign =
				System::Drawing::ContentAlignment::MiddleLeft;

			this->btnDashboard->UseVisualStyleBackColor =
				false;

			this->btnDashboard->Click +=
				gcnew System::EventHandler(
					this,
					&MyDeliveriesFormDesigner::
					btnDashboard_Click);

			// btnBookParcel

			this->btnBookParcel->BackColor =
				System::Drawing::Color::FromArgb(
					15,
					23,
					42);

			this->btnBookParcel->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->btnBookParcel->FlatAppearance->BorderSize =
				0;

			this->btnBookParcel->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnBookParcel->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9));

			this->btnBookParcel->ForeColor =
				System::Drawing::Color::White;

			this->btnBookParcel->Location =
				System::Drawing::Point(20, 143);

			this->btnBookParcel->Name =
				L"btnBookParcel";

			this->btnBookParcel->Size =
				System::Drawing::Size(165, 38);

			this->btnBookParcel->TabIndex = 1;

			this->btnBookParcel->Text =
				L"Book Parcel";

			this->btnBookParcel->TextAlign =
				System::Drawing::ContentAlignment::MiddleLeft;

			this->btnBookParcel->UseVisualStyleBackColor =
				false;

			this->btnBookParcel->Click +=
				gcnew System::EventHandler(
					this,
					&MyDeliveriesFormDesigner::
					btnBookParcel_Click);

			// btnMyDeliveries

			this->btnMyDeliveries->BackColor =
				System::Drawing::Color::FromArgb(
					37,
					99,
					235);

			this->btnMyDeliveries->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->btnMyDeliveries->FlatAppearance->BorderSize =
				0;

			this->btnMyDeliveries->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnMyDeliveries->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9));

			this->btnMyDeliveries->ForeColor =
				System::Drawing::Color::White;

			this->btnMyDeliveries->Location =
				System::Drawing::Point(20, 186);

			this->btnMyDeliveries->Name =
				L"btnMyDeliveries";

			this->btnMyDeliveries->Size =
				System::Drawing::Size(165, 38);

			this->btnMyDeliveries->TabIndex = 2;

			this->btnMyDeliveries->Text =
				L"My Deliveries";

			this->btnMyDeliveries->TextAlign =
				System::Drawing::ContentAlignment::MiddleLeft;

			this->btnMyDeliveries->UseVisualStyleBackColor =
				false;

			this->btnMyDeliveries->Click +=
				gcnew System::EventHandler(
					this,
					&MyDeliveriesFormDesigner::
					btnMyDeliveries_Click);

			// btnMyProfile

			this->btnMyProfile->BackColor =
				System::Drawing::Color::FromArgb(
					15,
					23,
					42);

			this->btnMyProfile->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->btnMyProfile->FlatAppearance->BorderSize =
				0;

			this->btnMyProfile->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnMyProfile->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9));

			this->btnMyProfile->ForeColor =
				System::Drawing::Color::White;

			this->btnMyProfile->Location =
				System::Drawing::Point(20, 229);

			this->btnMyProfile->Name =
				L"btnMyProfile";

			this->btnMyProfile->Size =
				System::Drawing::Size(165, 38);

			this->btnMyProfile->TabIndex = 3;

			this->btnMyProfile->Text =
				L"My Profile";

			this->btnMyProfile->TextAlign =
				System::Drawing::ContentAlignment::MiddleLeft;

			this->btnMyProfile->UseVisualStyleBackColor =
				false;

			this->btnMyProfile->Click +=
				gcnew System::EventHandler(
					this,
					&MyDeliveriesFormDesigner::
					btnMyProfile_Click);

			// btnLogout

			this->btnLogout->BackColor =
				System::Drawing::Color::FromArgb(
					15,
					23,
					42);

			this->btnLogout->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->btnLogout->FlatAppearance->BorderSize =
				0;

			this->btnLogout->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnLogout->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9));

			this->btnLogout->ForeColor =
				System::Drawing::Color::FromArgb(
					248,
					113,
					113);

			this->btnLogout->Location =
				System::Drawing::Point(20, 630);

			this->btnLogout->Name =
				L"btnLogout";

			this->btnLogout->Size =
				System::Drawing::Size(165, 38);

			this->btnLogout->TabIndex = 4;

			this->btnLogout->Text =
				L"Logout";

			this->btnLogout->TextAlign =
				System::Drawing::ContentAlignment::MiddleLeft;

			this->btnLogout->UseVisualStyleBackColor =
				false;

			this->btnLogout->Click +=
				gcnew System::EventHandler(
					this,
					&MyDeliveriesFormDesigner::
					btnLogout_Click);

			// pnlAvatar

			this->pnlAvatar->BackColor =
				System::Drawing::Color::FromArgb(
					239,
					246,
					255);

			this->pnlAvatar->Controls->Add(
				this->lblAvatar);

			this->pnlAvatar->Location =
				System::Drawing::Point(745, 17);

			this->pnlAvatar->Name =
				L"pnlAvatar";

			this->pnlAvatar->Size =
				System::Drawing::Size(35, 35);

			this->pnlAvatar->TabIndex = 1;

			// lblAvatar

			this->lblAvatar->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblAvatar->ForeColor =
				System::Drawing::Color::FromArgb(
					37,
					99,
					235);

			this->lblAvatar->Location =
				System::Drawing::Point(0, 7);

			this->lblAvatar->Name =
				L"lblAvatar";

			this->lblAvatar->Size =
				System::Drawing::Size(35, 22);

			this->lblAvatar->TabIndex = 0;

			this->lblAvatar->Text =
				L"C";

			this->lblAvatar->TextAlign =
				System::Drawing::ContentAlignment::MiddleCenter;

			// pnlHeader

			this->pnlHeader->BackColor =
				System::Drawing::Color::White;

			this->pnlHeader->Controls->Add(
				this->lblHeaderTitle);

			this->pnlHeader->Controls->Add(
				this->pnlAvatar);

			this->pnlHeader->Controls->Add(
				this->lblHeaderCustomer);

			this->pnlHeader->Location =
				System::Drawing::Point(205, 0);

			this->pnlHeader->Name =
				L"pnlHeader";

			this->pnlHeader->Size =
				System::Drawing::Size(895, 70);

			this->pnlHeader->TabIndex = 1;

			// lblHeaderTitle

			this->lblHeaderTitle->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					12,
					System::Drawing::FontStyle::Bold));

			this->lblHeaderTitle->ForeColor =
				System::Drawing::Color::FromArgb(
					15,
					23,
					42);

			this->lblHeaderTitle->Location =
				System::Drawing::Point(30, 22);

			this->lblHeaderTitle->Name =
				L"lblHeaderTitle";

			this->lblHeaderTitle->Size =
				System::Drawing::Size(180, 30);

			this->lblHeaderTitle->TabIndex = 0;

			this->lblHeaderTitle->Text =
				L"My Deliveries";

			// lblHeaderCustomer

			this->lblHeaderCustomer->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblHeaderCustomer->ForeColor =
				System::Drawing::Color::FromArgb(
					15,
					23,
					42);

			this->lblHeaderCustomer->Location =
				System::Drawing::Point(790, 24);

			this->lblHeaderCustomer->Name =
				L"lblHeaderCustomer";

			this->lblHeaderCustomer->Size =
				System::Drawing::Size(95, 25);

			this->lblHeaderCustomer->TabIndex = 2;

			this->lblHeaderCustomer->Text =
				L"Customer";

			// pnlContent

			this->pnlContent->BackColor =
				System::Drawing::Color::FromArgb(
					248,
					250,
					252);

			this->pnlContent->Controls->Add(
				this->lblTitle);

			this->pnlContent->Controls->Add(
				this->lblSubtitle);

			this->pnlContent->Controls->Add(
				this->lblCount);

			this->pnlContent->Controls->Add(
				this->btnRefresh);

			this->pnlContent->Controls->Add(
				this->pnlTable);

			this->pnlContent->Location =
				System::Drawing::Point(205, 70);

			this->pnlContent->Name =
				L"pnlContent";

			this->pnlContent->Size =
				System::Drawing::Size(895, 630);

			this->pnlContent->TabIndex = 2;

			// lblTitle

			this->lblTitle->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					20,
					System::Drawing::FontStyle::Bold));

			this->lblTitle->ForeColor =
				System::Drawing::Color::FromArgb(
					15,
					23,
					42);

			this->lblTitle->Location =
				System::Drawing::Point(35, 30);

			this->lblTitle->Name =
				L"lblTitle";

			this->lblTitle->Size =
				System::Drawing::Size(300, 48);

			this->lblTitle->TabIndex = 0;

			this->lblTitle->Text =
				L"My Deliveries";

			// lblSubtitle

			this->lblSubtitle->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9));

			this->lblSubtitle->ForeColor =
				System::Drawing::Color::FromArgb(
					100,
					116,
					139);

			this->lblSubtitle->Location =
				System::Drawing::Point(38, 78);

			this->lblSubtitle->Name =
				L"lblSubtitle";

			this->lblSubtitle->Size =
				System::Drawing::Size(400, 25);

			this->lblSubtitle->TabIndex = 1;

			this->lblSubtitle->Text =
				L"View and manage all your parcel bookings.";

			// lblCount

			this->lblCount->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblCount->ForeColor =
				System::Drawing::Color::FromArgb(
					51,
					65,
					85);

			this->lblCount->Location =
				System::Drawing::Point(38, 118);

			this->lblCount->Name =
				L"lblCount";

			this->lblCount->Size =
				System::Drawing::Size(200, 25);

			this->lblCount->TabIndex = 2;

			this->lblCount->Text =
				L"0 deliveries";

			// btnRefresh

			this->btnRefresh->BackColor =
				System::Drawing::Color::White;

			this->btnRefresh->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->btnRefresh->FlatAppearance->BorderColor =
				System::Drawing::Color::FromArgb(
					37,
					99,
					235);

			this->btnRefresh->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnRefresh->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9));

			this->btnRefresh->ForeColor =
				System::Drawing::Color::FromArgb(
					37,
					99,
					235);

			this->btnRefresh->Location =
				System::Drawing::Point(745, 105);

			this->btnRefresh->Name =
				L"btnRefresh";

			this->btnRefresh->Size =
				System::Drawing::Size(105, 36);

			this->btnRefresh->TabIndex = 0;

			this->btnRefresh->Text =
				L"Refresh";

			this->btnRefresh->UseVisualStyleBackColor =
				false;

			this->btnRefresh->Click +=
				gcnew System::EventHandler(
					this,
					&MyDeliveriesFormDesigner::
					btnRefresh_Click);

			// pnlTable

			this->pnlTable->BackColor =
				System::Drawing::Color::White;

			this->pnlTable->BorderStyle =
				System::Windows::Forms::BorderStyle::FixedSingle;

			this->pnlTable->Controls->Add(
				this->dgvDeliveries);

			this->pnlTable->Location =
				System::Drawing::Point(35, 155);

			this->pnlTable->Name =
				L"pnlTable";

			this->pnlTable->Size =
				System::Drawing::Size(815, 430);

			this->pnlTable->TabIndex = 3;

			// dgvDeliveries

			this->dgvDeliveries->AllowUserToAddRows =
				false;

			this->dgvDeliveries->AllowUserToDeleteRows =
				false;

			this->dgvDeliveries->AllowUserToResizeRows =
				false;

			this->dgvDeliveries->AutoGenerateColumns =
				false;

			this->dgvDeliveries->BackgroundColor =
				System::Drawing::Color::White;

			this->dgvDeliveries->BorderStyle =
				System::Windows::Forms::BorderStyle::None;

			this->dgvDeliveries->CellBorderStyle =
				System::Windows::Forms::
				DataGridViewCellBorderStyle::SingleHorizontal;

			this->dgvDeliveries->ColumnHeadersHeight =
				42;

			this->dgvDeliveries->ColumnHeadersHeightSizeMode =
				System::Windows::Forms::
				DataGridViewColumnHeadersHeightSizeMode::
				DisableResizing;

			this->dgvDeliveries->Columns->AddRange(
				gcnew cli::array<
				System::Windows::Forms::
				DataGridViewColumn^>(10)
			{
				this->colParcelId,
					this->colTracking,
					this->colReceiver,
					this->colService,
					this->colCharge,
					this->colStatus,
					this->colDate,
					this->colView,
					this->colEdit,
					this->colCancel
			});

			this->dgvDeliveries->Dock =
				System::Windows::Forms::DockStyle::Fill;

			this->dgvDeliveries->EnableHeadersVisualStyles =
				false;

			this->dgvDeliveries->GridColor =
				System::Drawing::Color::FromArgb(
					226,
					232,
					240);

			this->dgvDeliveries->Location =
				System::Drawing::Point(0, 0);

			this->dgvDeliveries->MultiSelect =
				false;

			this->dgvDeliveries->Name =
				L"dgvDeliveries";

			this->dgvDeliveries->ReadOnly =
				true;

			this->dgvDeliveries->RowHeadersVisible =
				false;

			this->dgvDeliveries->RowHeadersWidth =
				51;

			this->dgvDeliveries->RowTemplate->Height =
				45;

			this->dgvDeliveries->SelectionMode =
				System::Windows::Forms::
				DataGridViewSelectionMode::
				FullRowSelect;

			this->dgvDeliveries->Size =
				System::Drawing::Size(813, 428);

			this->dgvDeliveries->TabIndex = 0;

			this->dgvDeliveries->CellContentClick +=
				gcnew System::Windows::Forms::
				DataGridViewCellEventHandler(
					this,
					&MyDeliveriesFormDesigner::
					dgvDeliveries_CellContentClick);

			// colParcelId

			this->colParcelId->DataPropertyName =
				L"parcel_id";

			this->colParcelId->HeaderText =
				L"Parcel ID";

			this->colParcelId->Name =
				L"colParcelId";

			this->colParcelId->ReadOnly =
				true;

			this->colParcelId->Visible =
				false;

			// colTracking

			this->colTracking->DataPropertyName =
				L"tracking_no";

			this->colTracking->HeaderText =
				L"Tracking No.";

			this->colTracking->MinimumWidth =
				6;

			this->colTracking->Name =
				L"colTracking";

			this->colTracking->ReadOnly =
				true;

			this->colTracking->Width =
				120;

			// colReceiver

			this->colReceiver->DataPropertyName =
				L"receiver_name";

			this->colReceiver->HeaderText =
				L"Receiver";

			this->colReceiver->MinimumWidth =
				6;

			this->colReceiver->Name =
				L"colReceiver";

			this->colReceiver->ReadOnly =
				true;

			this->colReceiver->Width =
				110;

			// colService

			this->colService->DataPropertyName =
				L"delivery_option";

			this->colService->HeaderText =
				L"Service";

			this->colService->MinimumWidth =
				6;

			this->colService->Name =
				L"colService";

			this->colService->ReadOnly =
				true;

			this->colService->Width =
				80;

			// colCharge

			this->colCharge->DataPropertyName =
				L"charge";

			this->colCharge->HeaderText =
				L"Charge";

			this->colCharge->MinimumWidth =
				6;

			this->colCharge->Name =
				L"colCharge";

			this->colCharge->ReadOnly =
				true;

			this->colCharge->Width =
				80;

			// colStatus

			this->colStatus->DataPropertyName =
				L"status";

			this->colStatus->HeaderText =
				L"Status";

			this->colStatus->MinimumWidth =
				6;

			this->colStatus->Name =
				L"colStatus";

			this->colStatus->ReadOnly =
				true;

			this->colStatus->Width =
				100;

			// colDate

			this->colDate->DataPropertyName =
				L"created_at";

			this->colDate->HeaderText =
				L"Date";

			this->colDate->MinimumWidth =
				6;

			this->colDate->Name =
				L"colDate";

			this->colDate->ReadOnly =
				true;

			this->colDate->Width =
				110;

			// colView

			this->colView->HeaderText =
				L"";

			this->colView->MinimumWidth =
				6;

			this->colView->Name =
				L"colView";

			this->colView->ReadOnly =
				true;

			this->colView->Text =
				L"View";

			this->colView->UseColumnTextForButtonValue =
				true;

			this->colView->Width =
				65;

			// colEdit

			this->colEdit->HeaderText =
				L"";

			this->colEdit->MinimumWidth =
				6;

			this->colEdit->Name =
				L"colEdit";

			this->colEdit->ReadOnly =
				true;

			this->colEdit->Text =
				L"Edit";

			this->colEdit->UseColumnTextForButtonValue =
				true;

			this->colEdit->Width =
				65;

			// colCancel

			this->colCancel->HeaderText =
				L"";

			this->colCancel->MinimumWidth =
				6;

			this->colCancel->Name =
				L"colCancel";

			this->colCancel->ReadOnly =
				true;

			this->colCancel->Text =
				L"Cancel";

			this->colCancel->UseColumnTextForButtonValue =
				true;

			this->colCancel->Width =
				70;

			// MyDeliveriesFormDesigner

			this->AutoScaleDimensions =
				System::Drawing::SizeF(8, 20);

			this->AutoScaleMode =
				System::Windows::Forms::
				AutoScaleMode::Font;

			this->BackColor =
				System::Drawing::Color::FromArgb(
					248,
					250,
					252);

			this->ClientSize =
				System::Drawing::Size(1100, 700);

			this->Controls->Add(
				this->pnlContent);

			this->Controls->Add(
				this->pnlHeader);

			this->Controls->Add(
				this->pnlSidebar);

			this->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9));

			this->FormBorderStyle =
				System::Windows::Forms::
				FormBorderStyle::FixedSingle;

			this->MaximizeBox =
				false;

			this->Name =
				L"MyDeliveriesFormDesigner";

			this->StartPosition =
				System::Windows::Forms::
				FormStartPosition::CenterScreen;

			this->Text =
				L"CourierEase - My Deliveries";

			this->pnlSidebar->ResumeLayout(false);

			this->pnlAvatar->ResumeLayout(false);

			this->pnlHeader->ResumeLayout(false);

			this->pnlContent->ResumeLayout(false);

			this->pnlTable->ResumeLayout(false);

			(cli::safe_cast<
				System::ComponentModel::ISupportInitialize^>(
					this->dgvDeliveries))->EndInit();

			this->ResumeLayout(false);
		}

#pragma endregion

	private:

		void LoadCustomerHeader()
		{
			if (System::String::IsNullOrWhiteSpace(
				customerName))
			{
				customerName = L"Customer";
			}

			this->lblHeaderCustomer->Text =
				customerName;

			System::String^ cleanName =
				customerName->Trim();

			if (cleanName->Length > 0)
			{
				this->lblAvatar->Text =
					cleanName->
					Substring(0, 1)->
					ToUpper();
			}
			else
			{
				this->lblAvatar->Text =
					L"C";
			}
		}

		void LoadDeliveries()
		{
			if (customerId <= 0)
			{
				this->lblCount->Text =
					L"0 deliveries";

				this->dgvDeliveries->DataSource =
					nullptr;

				return;
			}

			try
			{
				System::Data::DataTable^ table =
					ParcelManagementRepository::
					GetCustomerParcels(
						customerId);

				this->dgvDeliveries->
					AutoGenerateColumns =
					false;

				this->dgvDeliveries->DataSource =
					table;

				int count =
					table->Rows->Count;

				if (count == 1)
				{
					this->lblCount->Text =
						L"1 delivery";
				}
				else
				{
					this->lblCount->Text =
						count.ToString() +
						L" deliveries";
				}

				UpdateActionButtons();
			}
			catch (System::Exception^ ex)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Unable to load your deliveries.\n\n" +
						ex->Message,
						L"Database Error",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Error);
			}
		}

		void UpdateActionButtons()
		{
			for each (
				System::Windows::Forms::
				DataGridViewRow ^ row
				in this->dgvDeliveries->Rows)
			{
				if (row->IsNewRow)
				{
					continue;
				}

				System::Object^ statusValue =
					row->Cells[
						L"colStatus"]->Value;

				if (statusValue == nullptr ||
					statusValue ==
					System::DBNull::Value)
				{
					continue;
				}

				System::String^ status =
					statusValue->ToString();

				System::Windows::Forms::
					DataGridViewButtonCell^ editCell =
					dynamic_cast<
					System::Windows::Forms::
					DataGridViewButtonCell^>(
						row->Cells[
							L"colEdit"]);

				System::Windows::Forms::
					DataGridViewButtonCell^ cancelCell =
					dynamic_cast<
					System::Windows::Forms::
					DataGridViewButtonCell^>(
						row->Cells[
							L"colCancel"]);

				if (status ==
					L"Order Placed")
				{
					if (editCell != nullptr)
					{
						editCell->Value =
							L"Edit";
					}

					if (cancelCell != nullptr)
					{
						cancelCell->Value =
							L"Cancel";
					}
				}
				else
				{
					if (editCell != nullptr)
					{
						editCell->Value =
							L"-";
					}

					if (cancelCell != nullptr)
					{
						cancelCell->Value =
							L"-";
					}
				}
			}
		}

		void Refresh_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			LoadDeliveries();
		}

		void Deliveries_CellContentClick(
			System::Object^ sender,
			System::Windows::Forms::
			DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex < 0 ||
				e->ColumnIndex < 0)
			{
				return;
			}

			System::Windows::Forms::
				DataGridViewRow^ row =
				this->dgvDeliveries->
				Rows[e->RowIndex];

			System::Object^ parcelValue =
				row->Cells[
					L"colParcelId"]->Value;

			if (parcelValue == nullptr ||
				parcelValue ==
				System::DBNull::Value)
			{
				return;
			}

			int selectedParcelId =
				System::Convert::ToInt32(
					parcelValue);

			System::String^ columnName =
				this->dgvDeliveries->
				Columns[
					e->ColumnIndex]->
				Name;

					if (columnName ==
						L"colView")
					{
						ViewParcel(
							selectedParcelId);

						return;
					}

					if (columnName ==
						L"colEdit")
					{
						EditParcel(
							selectedParcelId,
							row);

						return;
					}

					if (columnName ==
						L"colCancel")
					{
						CancelParcel(
							selectedParcelId,
							row);

						return;
					}
		}

		void ViewParcel(
			int selectedParcelId)
		{
			try
			{
				System::Data::DataRow^ row =
					ParcelManagementRepository::
					GetParcelById(
						selectedParcelId,
						customerId);

				if (row == nullptr)
				{
					System::Windows::Forms::
						MessageBox::Show(
							L"Parcel could not be found.",
							L"CourierEase",
							System::Windows::Forms::
							MessageBoxButtons::OK,
							System::Windows::Forms::
							MessageBoxIcon::Warning);

					return;
				}

				System::String^ details =
					L"Tracking No.: " +
					row["tracking_no"]->
					ToString() +

					L"\n\nReceiver: " +
					row["receiver_name"]->
					ToString() +

					L"\nPhone: " +
					row["receiver_phone"]->
					ToString() +

					L"\nAddress: " +
					row["receiver_address"]->
					ToString() +

					L"\nCity: " +
					row["receiver_city"]->
					ToString() +

					L"\n\nDescription: " +
					row["description"]->
					ToString() +

					L"\nParcel Type: " +
					row["parcel_type"]->
					ToString() +

					L"\nWeight: " +
					row["weight_kg"]->
					ToString() +
					L" kg" +

					L"\nDeclared Value: LKR " +
					row["declared_value"]->
					ToString() +

					L"\n\nDelivery: " +
					row["delivery_option"]->
					ToString() +

					L"\nCharge: LKR " +
					row["charge"]->
					ToString() +

					L"\nPickup Address: " +
					row["pickup_address"]->
					ToString() +

					L"\nStatus: " +
					row["status"]->
					ToString();

				System::Windows::Forms::
					MessageBox::Show(
						details,
						L"Parcel Details",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Information);
			}
			catch (System::Exception^ ex)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Unable to load parcel details.\n\n" +
						ex->Message,
						L"Database Error",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Error);
			}
		}

		void EditParcel(
			int selectedParcelId,
			System::Windows::Forms::
			DataGridViewRow^ selectedRow)
		{
			System::Object^ statusValue =
				selectedRow->Cells[
					L"colStatus"]->Value;

			if (statusValue == nullptr ||
				statusValue ==
				System::DBNull::Value)
			{
				return;
			}

			System::String^ status =
				statusValue->ToString();

			if (status !=
				L"Order Placed")
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"This parcel can no longer be edited.\n\n"
						L"Only parcels with the status "
						L"\"Order Placed\" can be edited.",
						L"Edit Parcel",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Information);

				return;
			}

			EditParcelFormDesigner^ editForm =
				gcnew EditParcelFormDesigner(
					selectedParcelId,
					customerId);

			System::Windows::Forms::
				DialogResult result =
				editForm->ShowDialog(
					this);

			delete editForm;

			if (result ==
				System::Windows::Forms::
				DialogResult::OK)
			{
				LoadDeliveries();
			}
		}

		void CancelParcel(
			int selectedParcelId,
			System::Windows::Forms::
			DataGridViewRow^ selectedRow)
		{
			System::Object^ statusValue =
				selectedRow->Cells[
					L"colStatus"]->Value;

			if (statusValue == nullptr ||
				statusValue ==
				System::DBNull::Value)
			{
				return;
			}

			System::String^ status =
				statusValue->ToString();

			if (status !=
				L"Order Placed")
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"This parcel can no longer be cancelled.\n\n"
						L"Only parcels with the status "
						L"\"Order Placed\" can be cancelled.",
						L"Cancel Parcel",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Information);

				return;
			}

			System::Windows::Forms::
				DialogResult answer =
				System::Windows::Forms::
				MessageBox::Show(
					L"Are you sure you want to cancel this parcel?\n\n"
					L"This action will remove the parcel booking.",
					L"Cancel Parcel",
					System::Windows::Forms::
					MessageBoxButtons::YesNo,
					System::Windows::Forms::
					MessageBoxIcon::Warning);

			if (answer !=
				System::Windows::Forms::
				DialogResult::Yes)
			{
				return;
			}

			try
			{
				bool deleted =
					ParcelManagementRepository::
					DeleteParcel(
						selectedParcelId,
						customerId);

				if (!deleted)
				{
					System::Windows::Forms::
						MessageBox::Show(
							L"The parcel could not be cancelled.\n\n"
							L"It may already have entered the delivery process.",
							L"Cancel Failed",
							System::Windows::Forms::
							MessageBoxButtons::OK,
							System::Windows::Forms::
							MessageBoxIcon::Warning);

					LoadDeliveries();

					return;
				}

				System::Windows::Forms::
					MessageBox::Show(
						L"Parcel cancelled successfully.",
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Information);

				LoadDeliveries();
			}
			catch (System::Exception^ ex)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Unable to cancel the parcel.\n\n" +
						ex->Message,
						L"Database Error",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Error);
			}
		}

		void Dashboard_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->DialogResult =
				System::Windows::Forms::
				DialogResult::OK;

			this->Close();
		}

		void BookParcel_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->DialogResult =
				System::Windows::Forms::
				DialogResult::Retry;

			this->Close();
		}

		void Profile_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->DialogResult =
				System::Windows::Forms::
				DialogResult::Ignore;

			this->Close();
		}

		void Logout_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			System::Windows::Forms::
				DialogResult answer =
				System::Windows::Forms::
				MessageBox::Show(
					L"Are you sure you want to log out?",
					L"Logout",
					System::Windows::Forms::
					MessageBoxButtons::YesNo,
					System::Windows::Forms::
					MessageBoxIcon::Question);

			if (answer ==
				System::Windows::Forms::
				DialogResult::Yes)
			{
				this->DialogResult =
					System::Windows::Forms::
					DialogResult::Abort;

				this->Close();
			}
		}

	private:

		System::Void btnRefresh_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Refresh_Click(
				sender,
				e);
		}

		System::Void btnMyProfile_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Profile_Click(
				sender,
				e);
		}

		System::Void btnBookParcel_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			BookParcel_Click(
				sender,
				e);
		}

		System::Void btnDashboard_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Dashboard_Click(
				sender,
				e);
		}

		System::Void btnLogout_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Logout_Click(
				sender,
				e);
		}

		System::Void btnMyDeliveries_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			LoadDeliveries();
		}

		System::Void dgvDeliveries_CellContentClick(
			System::Object^ sender,
			System::Windows::Forms::
			DataGridViewCellEventArgs^ e)
		{
			Deliveries_CellContentClick(
				sender,
				e);
		}
	};
}