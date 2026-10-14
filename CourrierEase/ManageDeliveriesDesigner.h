#pragma once

#include "AdminDeliveryRepository.h"

namespace CourrierEase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ManageDeliveriesDesigner :
		public System::Windows::Forms::Form
	{
	public:

		ManageDeliveriesDesigner(void)
		{
			adminId = 0;
			selectedDeliveryId = 0;

			InitializeComponent();
			LoadStatusOptions();
			LoadDeliveryBoys();
			LoadDeliveries();
		}

		ManageDeliveriesDesigner(int loggedAdminId)
		{
			adminId = loggedAdminId;
			selectedDeliveryId = 0;

			InitializeComponent();
			LoadStatusOptions();
			LoadDeliveryBoys();
			LoadDeliveries();
		}

	protected:

		~ManageDeliveriesDesigner()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		int adminId;
		int selectedDeliveryId;

		// HEADER
		System::Windows::Forms::Panel^ pnlHeader;
		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Label^ lblSubtitle;
		System::Windows::Forms::Button^ btnClose;

		// GRID
		System::Windows::Forms::Panel^ pnlGridArea;
		System::Windows::Forms::Label^ lblDeliveries;
		System::Windows::Forms::Button^ btnRefresh;
		System::Windows::Forms::DataGridView^ dgvDeliveries;

		// DETAILS
		System::Windows::Forms::Panel^ pnlDetails;
		System::Windows::Forms::Label^ lblDetailsTitle;

		System::Windows::Forms::Label^ lblTrackingCaption;
		System::Windows::Forms::Label^ lblTrackingValue;

		System::Windows::Forms::Label^ lblCustomerCaption;
		System::Windows::Forms::Label^ lblCustomerValue;

		System::Windows::Forms::Label^ lblReceiverCaption;
		System::Windows::Forms::Label^ lblReceiverValue;

		System::Windows::Forms::Label^ lblCityCaption;
		System::Windows::Forms::Label^ lblCityValue;

		System::Windows::Forms::Label^ lblCurrentStatusCaption;
		System::Windows::Forms::Label^ lblCurrentStatusValue;

		System::Windows::Forms::Label^ lblBoyCaption;
		System::Windows::Forms::Label^ lblBoyValue;

		// MANAGEMENT
		System::Windows::Forms::Label^ lblAssignTitle;
		System::Windows::Forms::Label^ lblSelectBoy;
		System::Windows::Forms::ComboBox^ cmbDeliveryBoy;
		System::Windows::Forms::Button^ btnAssignBoy;
		System::Windows::Forms::Button^ btnRemoveBoy;

		System::Windows::Forms::Label^ lblStatusTitle;
		System::Windows::Forms::Label^ lblSelectStatus;
		System::Windows::Forms::ComboBox^ cmbStatus;
		System::Windows::Forms::Button^ btnUpdateStatus;

		// HISTORY
		System::Windows::Forms::Label^ lblHistoryTitle;
		System::Windows::Forms::DataGridView^ dgvHistory;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->pnlHeader =
				(gcnew System::Windows::Forms::Panel());

			this->btnClose =
				(gcnew System::Windows::Forms::Button());

			this->lblSubtitle =
				(gcnew System::Windows::Forms::Label());

			this->lblTitle =
				(gcnew System::Windows::Forms::Label());

			this->pnlGridArea =
				(gcnew System::Windows::Forms::Panel());

			this->dgvDeliveries =
				(gcnew System::Windows::Forms::DataGridView());

			this->btnRefresh =
				(gcnew System::Windows::Forms::Button());

			this->lblDeliveries =
				(gcnew System::Windows::Forms::Label());

			this->pnlDetails =
				(gcnew System::Windows::Forms::Panel());

			this->dgvHistory =
				(gcnew System::Windows::Forms::DataGridView());

			this->lblHistoryTitle =
				(gcnew System::Windows::Forms::Label());

			this->btnUpdateStatus =
				(gcnew System::Windows::Forms::Button());

			this->cmbStatus =
				(gcnew System::Windows::Forms::ComboBox());

			this->lblSelectStatus =
				(gcnew System::Windows::Forms::Label());

			this->lblStatusTitle =
				(gcnew System::Windows::Forms::Label());

			this->btnRemoveBoy =
				(gcnew System::Windows::Forms::Button());

			this->btnAssignBoy =
				(gcnew System::Windows::Forms::Button());

			this->cmbDeliveryBoy =
				(gcnew System::Windows::Forms::ComboBox());

			this->lblSelectBoy =
				(gcnew System::Windows::Forms::Label());

			this->lblAssignTitle =
				(gcnew System::Windows::Forms::Label());

			this->lblBoyValue =
				(gcnew System::Windows::Forms::Label());

			this->lblBoyCaption =
				(gcnew System::Windows::Forms::Label());

			this->lblCurrentStatusValue =
				(gcnew System::Windows::Forms::Label());

			this->lblCurrentStatusCaption =
				(gcnew System::Windows::Forms::Label());

			this->lblCityValue =
				(gcnew System::Windows::Forms::Label());

			this->lblCityCaption =
				(gcnew System::Windows::Forms::Label());

			this->lblReceiverValue =
				(gcnew System::Windows::Forms::Label());

			this->lblReceiverCaption =
				(gcnew System::Windows::Forms::Label());

			this->lblCustomerValue =
				(gcnew System::Windows::Forms::Label());

			this->lblCustomerCaption =
				(gcnew System::Windows::Forms::Label());

			this->lblTrackingValue =
				(gcnew System::Windows::Forms::Label());

			this->lblTrackingCaption =
				(gcnew System::Windows::Forms::Label());

			this->lblDetailsTitle =
				(gcnew System::Windows::Forms::Label());

			this->pnlHeader->SuspendLayout();
			this->pnlGridArea->SuspendLayout();

			(cli::safe_cast<
				System::ComponentModel::ISupportInitialize^>(
					this->dgvDeliveries))->BeginInit();

			this->pnlDetails->SuspendLayout();

			(cli::safe_cast<
				System::ComponentModel::ISupportInitialize^>(
					this->dgvHistory))->BeginInit();

			this->SuspendLayout();

			// pnlHeader
			this->pnlHeader->BackColor =
				System::Drawing::Color::FromArgb(15, 23, 42);

			this->pnlHeader->Controls->Add(this->btnClose);
			this->pnlHeader->Controls->Add(this->lblSubtitle);
			this->pnlHeader->Controls->Add(this->lblTitle);

			this->pnlHeader->Dock =
				System::Windows::Forms::DockStyle::Top;

			this->pnlHeader->Location =
				System::Drawing::Point(0, 0);

			this->pnlHeader->Name = L"pnlHeader";

			this->pnlHeader->Size =
				System::Drawing::Size(1380, 90);

			this->pnlHeader->TabIndex = 0;

			// btnClose
			this->btnClose->BackColor =
				System::Drawing::Color::FromArgb(30, 41, 59);

			this->btnClose->FlatAppearance->BorderSize = 0;

			this->btnClose->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnClose->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->btnClose->ForeColor =
				System::Drawing::Color::White;

			this->btnClose->Location =
				System::Drawing::Point(1240, 25);

			this->btnClose->Name = L"btnClose";

			this->btnClose->Size =
				System::Drawing::Size(105, 40);

			this->btnClose->TabIndex = 2;

			this->btnClose->Text = L"Back";

			this->btnClose->UseVisualStyleBackColor = false;

			this->btnClose->Click +=
				gcnew System::EventHandler(
					this,
					&ManageDeliveriesDesigner::
					btnClose_Click);

			// lblSubtitle
			this->lblSubtitle->AutoSize = true;

			this->lblSubtitle->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9));

			this->lblSubtitle->ForeColor =
				System::Drawing::Color::FromArgb(
					203, 213, 225);

			this->lblSubtitle->Location =
				System::Drawing::Point(34, 61);

			this->lblSubtitle->Name =
				L"lblSubtitle";

			this->lblSubtitle->Size =
				System::Drawing::Size(370, 20);

			this->lblSubtitle->TabIndex = 1;

			this->lblSubtitle->Text =
				L"View deliveries, assign staff and update delivery status.";

			// lblTitle
			this->lblTitle->AutoSize = true;

			this->lblTitle->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					20,
					System::Drawing::FontStyle::Bold));

			this->lblTitle->ForeColor =
				System::Drawing::Color::White;

			this->lblTitle->Location =
				System::Drawing::Point(30, 15);

			this->lblTitle->Name = L"lblTitle";

			this->lblTitle->Size =
				System::Drawing::Size(314, 46);

			this->lblTitle->TabIndex = 0;

			this->lblTitle->Text =
				L"Manage Deliveries";

			// pnlGridArea
			this->pnlGridArea->BackColor =
				System::Drawing::Color::White;

			this->pnlGridArea->BorderStyle =
				System::Windows::Forms::
				BorderStyle::FixedSingle;

			this->pnlGridArea->Controls->Add(
				this->dgvDeliveries);

			this->pnlGridArea->Controls->Add(
				this->btnRefresh);

			this->pnlGridArea->Controls->Add(
				this->lblDeliveries);

			this->pnlGridArea->Location =
				System::Drawing::Point(25, 115);

			this->pnlGridArea->Name =
				L"pnlGridArea";

			this->pnlGridArea->Size =
				System::Drawing::Size(820, 650);

			this->pnlGridArea->TabIndex = 1;

			// dgvDeliveries
			this->dgvDeliveries->AllowUserToAddRows =
				false;

			this->dgvDeliveries->AllowUserToDeleteRows =
				false;

			this->dgvDeliveries->AllowUserToResizeRows =
				false;

			this->dgvDeliveries->AutoSizeColumnsMode =
				System::Windows::Forms::
				DataGridViewAutoSizeColumnsMode::Fill;

			this->dgvDeliveries->BackgroundColor =
				System::Drawing::Color::White;

			this->dgvDeliveries->BorderStyle =
				System::Windows::Forms::
				BorderStyle::Fixed3D;

			this->dgvDeliveries->ColumnHeadersHeightSizeMode =
				System::Windows::Forms::
				DataGridViewColumnHeadersHeightSizeMode::
				AutoSize;

			this->dgvDeliveries->Location =
				System::Drawing::Point(20, 70);

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

			this->dgvDeliveries->SelectionMode =
				System::Windows::Forms::
				DataGridViewSelectionMode::
				FullRowSelect;

			this->dgvDeliveries->Size =
				System::Drawing::Size(770, 550);

			this->dgvDeliveries->TabIndex =
				2;

			this->dgvDeliveries->SelectionChanged +=
				gcnew System::EventHandler(
					this,
					&ManageDeliveriesDesigner::
					dgvDeliveries_SelectionChanged);

			// btnRefresh
			this->btnRefresh->BackColor =
				System::Drawing::Color::FromArgb(
					37, 99, 235);

			this->btnRefresh->FlatAppearance->BorderSize =
				0;

			this->btnRefresh->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnRefresh->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->btnRefresh->ForeColor =
				System::Drawing::Color::White;

			this->btnRefresh->Location =
				System::Drawing::Point(680, 15);

			this->btnRefresh->Name =
				L"btnRefresh";

			this->btnRefresh->Size =
				System::Drawing::Size(110, 36);

			this->btnRefresh->TabIndex =
				1;

			this->btnRefresh->Text =
				L"Refresh";

			this->btnRefresh->UseVisualStyleBackColor =
				false;

			this->btnRefresh->Click +=
				gcnew System::EventHandler(
					this,
					&ManageDeliveriesDesigner::
					btnRefresh_Click);

			// lblDeliveries
			this->lblDeliveries->AutoSize =
				true;

			this->lblDeliveries->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					14,
					System::Drawing::FontStyle::Bold));

			this->lblDeliveries->ForeColor =
				System::Drawing::Color::FromArgb(
					15, 23, 42);

			this->lblDeliveries->Location =
				System::Drawing::Point(20, 17);

			this->lblDeliveries->Name =
				L"lblDeliveries";

			this->lblDeliveries->Size =
				System::Drawing::Size(164, 32);

			this->lblDeliveries->TabIndex =
				0;

			this->lblDeliveries->Text =
				L"All Deliveries";

			// pnlDetails
			this->pnlDetails->AutoScroll =
				true;

			this->pnlDetails->BackColor =
				System::Drawing::Color::White;

			this->pnlDetails->BorderStyle =
				System::Windows::Forms::
				BorderStyle::FixedSingle;

			this->pnlDetails->Controls->Add(
				this->dgvHistory);

			this->pnlDetails->Controls->Add(
				this->lblHistoryTitle);

			this->pnlDetails->Controls->Add(
				this->btnUpdateStatus);

			this->pnlDetails->Controls->Add(
				this->cmbStatus);

			this->pnlDetails->Controls->Add(
				this->lblSelectStatus);

			this->pnlDetails->Controls->Add(
				this->lblStatusTitle);

			this->pnlDetails->Controls->Add(
				this->btnRemoveBoy);

			this->pnlDetails->Controls->Add(
				this->btnAssignBoy);

			this->pnlDetails->Controls->Add(
				this->cmbDeliveryBoy);

			this->pnlDetails->Controls->Add(
				this->lblSelectBoy);

			this->pnlDetails->Controls->Add(
				this->lblAssignTitle);

			this->pnlDetails->Controls->Add(
				this->lblBoyValue);

			this->pnlDetails->Controls->Add(
				this->lblBoyCaption);

			this->pnlDetails->Controls->Add(
				this->lblCurrentStatusValue);

			this->pnlDetails->Controls->Add(
				this->lblCurrentStatusCaption);

			this->pnlDetails->Controls->Add(
				this->lblCityValue);

			this->pnlDetails->Controls->Add(
				this->lblCityCaption);

			this->pnlDetails->Controls->Add(
				this->lblReceiverValue);

			this->pnlDetails->Controls->Add(
				this->lblReceiverCaption);

			this->pnlDetails->Controls->Add(
				this->lblCustomerValue);

			this->pnlDetails->Controls->Add(
				this->lblCustomerCaption);

			this->pnlDetails->Controls->Add(
				this->lblTrackingValue);

			this->pnlDetails->Controls->Add(
				this->lblTrackingCaption);

			this->pnlDetails->Controls->Add(
				this->lblDetailsTitle);

			this->pnlDetails->Location =
				System::Drawing::Point(865, 115);

			this->pnlDetails->Name =
				L"pnlDetails";

			this->pnlDetails->Size =
				System::Drawing::Size(490, 650);

			this->pnlDetails->TabIndex =
				2;

			// dgvHistory
			this->dgvHistory->AllowUserToAddRows =
				false;

			this->dgvHistory->AllowUserToDeleteRows =
				false;

			this->dgvHistory->AutoSizeColumnsMode =
				System::Windows::Forms::
				DataGridViewAutoSizeColumnsMode::Fill;

			this->dgvHistory->BackgroundColor =
				System::Drawing::Color::White;

			this->dgvHistory->ColumnHeadersHeightSizeMode =
				System::Windows::Forms::
				DataGridViewColumnHeadersHeightSizeMode::
				AutoSize;

			this->dgvHistory->Location =
				System::Drawing::Point(25, 590);

			this->dgvHistory->Name =
				L"dgvHistory";

			this->dgvHistory->ReadOnly =
				true;

			this->dgvHistory->RowHeadersVisible =
				false;

			this->dgvHistory->RowHeadersWidth =
				51;

			this->dgvHistory->SelectionMode =
				System::Windows::Forms::
				DataGridViewSelectionMode::
				FullRowSelect;

			this->dgvHistory->Size =
				System::Drawing::Size(425, 180);

			this->dgvHistory->TabIndex =
				23;

			// lblHistoryTitle
			this->lblHistoryTitle->AutoSize =
				true;

			this->lblHistoryTitle->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					11,
					System::Drawing::FontStyle::Bold));

			this->lblHistoryTitle->ForeColor =
				System::Drawing::Color::FromArgb(
					15, 23, 42);

			this->lblHistoryTitle->Location =
				System::Drawing::Point(20, 555);

			this->lblHistoryTitle->Name =
				L"lblHistoryTitle";

			this->lblHistoryTitle->Size =
				System::Drawing::Size(138, 25);

			this->lblHistoryTitle->TabIndex =
				22;

			this->lblHistoryTitle->Text =
				L"Status History";

			// btnUpdateStatus
			this->btnUpdateStatus->BackColor =
				System::Drawing::Color::FromArgb(
					22, 163, 74);

			this->btnUpdateStatus->FlatAppearance->BorderSize =
				0;

			this->btnUpdateStatus->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnUpdateStatus->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->btnUpdateStatus->ForeColor =
				System::Drawing::Color::White;

			this->btnUpdateStatus->Location =
				System::Drawing::Point(310, 493);

			this->btnUpdateStatus->Name =
				L"btnUpdateStatus";

			this->btnUpdateStatus->Size =
				System::Drawing::Size(140, 34);

			this->btnUpdateStatus->TabIndex =
				21;

			this->btnUpdateStatus->Text =
				L"Update";

			this->btnUpdateStatus->UseVisualStyleBackColor =
				false;

			this->btnUpdateStatus->Click +=
				gcnew System::EventHandler(
					this,
					&ManageDeliveriesDesigner::
					btnUpdateStatus_Click);

			// cmbStatus
			this->cmbStatus->DropDownStyle =
				System::Windows::Forms::
				ComboBoxStyle::DropDownList;

			this->cmbStatus->FormattingEnabled =
				true;

			this->cmbStatus->Location =
				System::Drawing::Point(25, 495);

			this->cmbStatus->Name =
				L"cmbStatus";

			this->cmbStatus->Size =
				System::Drawing::Size(270, 28);

			this->cmbStatus->TabIndex =
				20;

			// lblSelectStatus
			this->lblSelectStatus->AutoSize =
				true;

			this->lblSelectStatus->Location =
				System::Drawing::Point(22, 468);

			this->lblSelectStatus->Name =
				L"lblSelectStatus";

			this->lblSelectStatus->Size =
				System::Drawing::Size(91, 20);

			this->lblSelectStatus->TabIndex =
				19;

			this->lblSelectStatus->Text =
				L"Select status";

			// lblStatusTitle
			this->lblStatusTitle->AutoSize =
				true;

			this->lblStatusTitle->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					11,
					System::Drawing::FontStyle::Bold));

			this->lblStatusTitle->ForeColor =
				System::Drawing::Color::FromArgb(
					15, 23, 42);

			this->lblStatusTitle->Location =
				System::Drawing::Point(20, 430);

			this->lblStatusTitle->Name =
				L"lblStatusTitle";

			this->lblStatusTitle->Size =
				System::Drawing::Size(215, 25);

			this->lblStatusTitle->TabIndex =
				18;

			this->lblStatusTitle->Text =
				L"Update Delivery Status";

			// btnRemoveBoy
			this->btnRemoveBoy->BackColor =
				System::Drawing::Color::White;

			this->btnRemoveBoy->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnRemoveBoy->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->btnRemoveBoy->ForeColor =
				System::Drawing::Color::FromArgb(
					185, 28, 28);

			this->btnRemoveBoy->Location =
				System::Drawing::Point(245, 365);

			this->btnRemoveBoy->Name =
				L"btnRemoveBoy";

			this->btnRemoveBoy->Size =
				System::Drawing::Size(205, 38);

			this->btnRemoveBoy->TabIndex =
				17;

			this->btnRemoveBoy->Text =
				L"Remove Staff";

			this->btnRemoveBoy->UseVisualStyleBackColor =
				false;

			this->btnRemoveBoy->Click +=
				gcnew System::EventHandler(
					this,
					&ManageDeliveriesDesigner::
					btnRemoveBoy_Click);

			// btnAssignBoy
			this->btnAssignBoy->BackColor =
				System::Drawing::Color::FromArgb(
					37, 99, 235);

			this->btnAssignBoy->FlatAppearance->BorderSize =
				0;

			this->btnAssignBoy->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnAssignBoy->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->btnAssignBoy->ForeColor =
				System::Drawing::Color::White;

			this->btnAssignBoy->Location =
				System::Drawing::Point(25, 365);

			this->btnAssignBoy->Name =
				L"btnAssignBoy";

			this->btnAssignBoy->Size =
				System::Drawing::Size(205, 38);

			this->btnAssignBoy->TabIndex =
				16;

			this->btnAssignBoy->Text =
				L"Assign Staff";

			this->btnAssignBoy->UseVisualStyleBackColor =
				false;

			this->btnAssignBoy->Click +=
				gcnew System::EventHandler(
					this,
					&ManageDeliveriesDesigner::
					btnAssignBoy_Click);

			// cmbDeliveryBoy
			this->cmbDeliveryBoy->DropDownStyle =
				System::Windows::Forms::
				ComboBoxStyle::DropDownList;

			this->cmbDeliveryBoy->FormattingEnabled =
				true;

			this->cmbDeliveryBoy->Location =
				System::Drawing::Point(25, 327);

			this->cmbDeliveryBoy->Name =
				L"cmbDeliveryBoy";

			this->cmbDeliveryBoy->Size =
				System::Drawing::Size(425, 28);

			this->cmbDeliveryBoy->TabIndex =
				15;

			// lblSelectBoy
			this->lblSelectBoy->AutoSize =
				true;

			this->lblSelectBoy->Location =
				System::Drawing::Point(22, 300);

			this->lblSelectBoy->Name =
				L"lblSelectBoy";

			this->lblSelectBoy->Size =
				System::Drawing::Size(134, 20);

			this->lblSelectBoy->TabIndex =
				14;

			this->lblSelectBoy->Text =
				L"Select delivery boy";

			// lblAssignTitle
			this->lblAssignTitle->AutoSize =
				true;

			this->lblAssignTitle->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					11,
					System::Drawing::FontStyle::Bold));

			this->lblAssignTitle->ForeColor =
				System::Drawing::Color::FromArgb(
					15, 23, 42);

			this->lblAssignTitle->Location =
				System::Drawing::Point(20, 260);

			this->lblAssignTitle->Name =
				L"lblAssignTitle";

			this->lblAssignTitle->Size =
				System::Drawing::Size(195, 25);

			this->lblAssignTitle->TabIndex =
				13;

			this->lblAssignTitle->Text =
				L"Assign Delivery Staff";

			// lblBoyValue
			this->lblBoyValue->Location =
				System::Drawing::Point(145, 215);

			this->lblBoyValue->Name =
				L"lblBoyValue";

			this->lblBoyValue->Size =
				System::Drawing::Size(305, 24);

			this->lblBoyValue->TabIndex =
				12;

			this->lblBoyValue->Text =
				L"Not Assigned";

			// lblBoyCaption
			this->lblBoyCaption->AutoSize =
				true;

			this->lblBoyCaption->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblBoyCaption->Location =
				System::Drawing::Point(22, 215);

			this->lblBoyCaption->Name =
				L"lblBoyCaption";

			this->lblBoyCaption->Size =
				System::Drawing::Size(102, 20);

			this->lblBoyCaption->TabIndex =
				11;

			this->lblBoyCaption->Text =
				L"Delivery Boy:";

			// lblCurrentStatusValue
			this->lblCurrentStatusValue->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblCurrentStatusValue->ForeColor =
				System::Drawing::Color::FromArgb(
					37, 99, 235);

			this->lblCurrentStatusValue->Location =
				System::Drawing::Point(145, 185);

			this->lblCurrentStatusValue->Name =
				L"lblCurrentStatusValue";

			this->lblCurrentStatusValue->Size =
				System::Drawing::Size(305, 24);

			this->lblCurrentStatusValue->TabIndex =
				10;

			this->lblCurrentStatusValue->Text =
				L"-";

			// lblCurrentStatusCaption
			this->lblCurrentStatusCaption->AutoSize =
				true;

			this->lblCurrentStatusCaption->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblCurrentStatusCaption->Location =
				System::Drawing::Point(22, 185);

			this->lblCurrentStatusCaption->Name =
				L"lblCurrentStatusCaption";

			this->lblCurrentStatusCaption->Size =
				System::Drawing::Size(57, 20);

			this->lblCurrentStatusCaption->TabIndex =
				9;

			this->lblCurrentStatusCaption->Text =
				L"Status:";

			// lblCityValue
			this->lblCityValue->Location =
				System::Drawing::Point(145, 155);

			this->lblCityValue->Name =
				L"lblCityValue";

			this->lblCityValue->Size =
				System::Drawing::Size(305, 24);

			this->lblCityValue->TabIndex =
				8;

			this->lblCityValue->Text =
				L"-";

			// lblCityCaption
			this->lblCityCaption->AutoSize =
				true;

			this->lblCityCaption->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblCityCaption->Location =
				System::Drawing::Point(22, 155);

			this->lblCityCaption->Name =
				L"lblCityCaption";

			this->lblCityCaption->Size =
				System::Drawing::Size(40, 20);

			this->lblCityCaption->TabIndex =
				7;

			this->lblCityCaption->Text =
				L"City:";

			// lblReceiverValue
			this->lblReceiverValue->Location =
				System::Drawing::Point(145, 125);

			this->lblReceiverValue->Name =
				L"lblReceiverValue";

			this->lblReceiverValue->Size =
				System::Drawing::Size(305, 24);

			this->lblReceiverValue->TabIndex =
				6;

			this->lblReceiverValue->Text =
				L"-";

			// lblReceiverCaption
			this->lblReceiverCaption->AutoSize =
				true;

			this->lblReceiverCaption->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblReceiverCaption->Location =
				System::Drawing::Point(22, 125);

			this->lblReceiverCaption->Name =
				L"lblReceiverCaption";

			this->lblReceiverCaption->Size =
				System::Drawing::Size(73, 20);

			this->lblReceiverCaption->TabIndex =
				5;

			this->lblReceiverCaption->Text =
				L"Receiver:";

			// lblCustomerValue
			this->lblCustomerValue->Location =
				System::Drawing::Point(145, 95);

			this->lblCustomerValue->Name =
				L"lblCustomerValue";

			this->lblCustomerValue->Size =
				System::Drawing::Size(305, 24);

			this->lblCustomerValue->TabIndex =
				4;

			this->lblCustomerValue->Text =
				L"-";

			// lblCustomerCaption
			this->lblCustomerCaption->AutoSize =
				true;

			this->lblCustomerCaption->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblCustomerCaption->Location =
				System::Drawing::Point(22, 95);

			this->lblCustomerCaption->Name =
				L"lblCustomerCaption";

			this->lblCustomerCaption->Size =
				System::Drawing::Size(82, 20);

			this->lblCustomerCaption->TabIndex =
				3;

			this->lblCustomerCaption->Text =
				L"Customer:";

			// lblTrackingValue
			this->lblTrackingValue->Location =
				System::Drawing::Point(145, 65);

			this->lblTrackingValue->Name =
				L"lblTrackingValue";

			this->lblTrackingValue->Size =
				System::Drawing::Size(305, 24);

			this->lblTrackingValue->TabIndex =
				2;

			this->lblTrackingValue->Text =
				L"-";

			// lblTrackingCaption
			this->lblTrackingCaption->AutoSize =
				true;

			this->lblTrackingCaption->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblTrackingCaption->Location =
				System::Drawing::Point(22, 65);

			this->lblTrackingCaption->Name =
				L"lblTrackingCaption";

			this->lblTrackingCaption->Size =
				System::Drawing::Size(97, 20);

			this->lblTrackingCaption->TabIndex =
				1;

			this->lblTrackingCaption->Text =
				L"Tracking No:";

			// lblDetailsTitle
			this->lblDetailsTitle->AutoSize =
				true;

			this->lblDetailsTitle->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					14,
					System::Drawing::FontStyle::Bold));

			this->lblDetailsTitle->ForeColor =
				System::Drawing::Color::FromArgb(
					15, 23, 42);

			this->lblDetailsTitle->Location =
				System::Drawing::Point(20, 17);

			this->lblDetailsTitle->Name =
				L"lblDetailsTitle";

			this->lblDetailsTitle->Size =
				System::Drawing::Size(194, 32);

			this->lblDetailsTitle->TabIndex =
				0;

			this->lblDetailsTitle->Text =
				L"Delivery Details";

			// ManageDeliveriesDesigner
			this->AutoScaleDimensions =
				System::Drawing::SizeF(8, 20);

			this->AutoScaleMode =
				System::Windows::Forms::
				AutoScaleMode::Font;

			this->BackColor =
				System::Drawing::Color::FromArgb(
					248, 250, 252);

			this->ClientSize =
				System::Drawing::Size(1380, 790);

			this->Controls->Add(
				this->pnlDetails);

			this->Controls->Add(
				this->pnlGridArea);

			this->Controls->Add(
				this->pnlHeader);

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
				L"ManageDeliveriesDesigner";

			this->StartPosition =
				System::Windows::Forms::
				FormStartPosition::CenterScreen;

			this->Text =
				L"CourierEase - Manage Deliveries";

			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();

			this->pnlGridArea->ResumeLayout(false);
			this->pnlGridArea->PerformLayout();

			(cli::safe_cast<
				System::ComponentModel::ISupportInitialize^>(
					this->dgvDeliveries))->EndInit();

			this->pnlDetails->ResumeLayout(false);
			this->pnlDetails->PerformLayout();

			(cli::safe_cast<
				System::ComponentModel::ISupportInitialize^>(
					this->dgvHistory))->EndInit();

			this->ResumeLayout(false);
		}

#pragma endregion

	private:

		void LoadStatusOptions()
		{
			cmbStatus->Items->Clear();

			cmbStatus->Items->Add(
				L"Order Placed");

			cmbStatus->Items->Add(
				L"In Transit");

			cmbStatus->Items->Add(
				L"Delivered");

			cmbStatus->SelectedIndex = 0;
		}

		void LoadDeliveryBoys()
		{
			try
			{
				DataTable^ table =
					AdminDeliveryRepository::
					GetActiveDeliveryBoys();

				cmbDeliveryBoy->DataSource =
					nullptr;

				if (table->Rows->Count == 0)
				{
					cmbDeliveryBoy->Items->Clear();
					return;
				}

				table->Columns->Add(
					L"display_text",
					String::typeid);

				for each (DataRow ^ row in table->Rows)
				{
					row[L"display_text"] =
						row[L"full_name"]->ToString()
						+ L" - "
						+ row[L"vehicle_no"]->ToString();
				}

				cmbDeliveryBoy->DisplayMember =
					L"display_text";

				cmbDeliveryBoy->ValueMember =
					L"boy_id";

				cmbDeliveryBoy->DataSource =
					table;
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Unable to load delivery staff.\n\n" +
						ex->Message,
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Error);
			}
		}

		void LoadDeliveries()
		{
			try
			{
				selectedDeliveryId = 0;

				DataTable^ table =
					AdminDeliveryRepository::
					GetAllDeliveries();

				dgvDeliveries->DataSource =
					table;

				HideGridColumns();

				if (dgvDeliveries->Rows->Count > 0)
				{
					dgvDeliveries->Rows[0]->Selected =
						true;

					LoadSelectedDelivery();
				}
				else
				{
					ClearDetails();
				}
			}
			catch (Exception^ ex)
			{
				ClearDetails();

				System::Windows::Forms::
					MessageBox::Show(
						L"Unable to load deliveries.\n\n" +
						ex->Message,
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Error);
			}
		}

		void HideGridColumns()
		{
			if (dgvDeliveries->Columns[
				L"delivery_id"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"delivery_id"]->Visible = false;
			}

			if (dgvDeliveries->Columns[
				L"parcel_id"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"parcel_id"]->Visible = false;
			}

			if (dgvDeliveries->Columns[
				L"boy_id"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"boy_id"]->Visible = false;
			}

			if (dgvDeliveries->Columns[
				L"customer_phone"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"customer_phone"]->Visible = false;
			}

			if (dgvDeliveries->Columns[
				L"receiver_phone"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"receiver_phone"]->Visible = false;
			}

			if (dgvDeliveries->Columns[
				L"receiver_address"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"receiver_address"]->Visible = false;
			}

			if (dgvDeliveries->Columns[
				L"description"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"description"]->Visible = false;
			}

			if (dgvDeliveries->Columns[
				L"pickup_address"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"pickup_address"]->Visible = false;
			}

			if (dgvDeliveries->Columns[
				L"vehicle_no"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"vehicle_no"]->Visible = false;
			}

			if (dgvDeliveries->Columns[
				L"created_at"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"created_at"]->Visible = false;
			}

			if (dgvDeliveries->Columns[
				L"tracking_no"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"tracking_no"]->HeaderText =
					L"Tracking No";
			}

			if (dgvDeliveries->Columns[
				L"customer_name"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"customer_name"]->HeaderText =
					L"Customer";
			}

			if (dgvDeliveries->Columns[
				L"receiver_name"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"receiver_name"]->HeaderText =
					L"Receiver";
			}

			if (dgvDeliveries->Columns[
				L"receiver_city"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"receiver_city"]->HeaderText =
					L"City";
			}

			if (dgvDeliveries->Columns[
				L"delivery_option"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"delivery_option"]->HeaderText =
					L"Service";
			}

			if (dgvDeliveries->Columns[
				L"delivery_boy"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"delivery_boy"]->HeaderText =
					L"Delivery Boy";
			}

			if (dgvDeliveries->Columns[
				L"weight_kg"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"weight_kg"]->HeaderText =
					L"Weight";
			}

			if (dgvDeliveries->Columns[
				L"parcel_type"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"parcel_type"]->HeaderText =
					L"Type";
			}

			if (dgvDeliveries->Columns[
				L"charge"] != nullptr)
			{
				dgvDeliveries->Columns[
					L"charge"]->HeaderText =
					L"Charge";
			}
		}

		void LoadSelectedDelivery()
		{
			if (dgvDeliveries->CurrentRow ==
				nullptr)
			{
				ClearDetails();
				return;
			}

			Object^ idValue =
				dgvDeliveries->CurrentRow->
				Cells[L"delivery_id"]->Value;

			if (idValue == nullptr ||
				idValue == DBNull::Value)
			{
				ClearDetails();
				return;
			}

			selectedDeliveryId =
				Convert::ToInt32(idValue);

			try
			{
				DataRow^ row =
					AdminDeliveryRepository::
					GetDeliveryById(
						selectedDeliveryId);

				if (row == nullptr)
				{
					ClearDetails();
					return;
				}

				lblTrackingValue->Text =
					row[L"tracking_no"]->ToString();

				lblCustomerValue->Text =
					row[L"customer_name"]->ToString();

				lblReceiverValue->Text =
					row[L"receiver_name"]->ToString();

				lblCityValue->Text =
					row[L"receiver_city"]->ToString();

				lblCurrentStatusValue->Text =
					row[L"status"]->ToString();

				if (row[L"delivery_boy"] ==
					DBNull::Value)
				{
					lblBoyValue->Text =
						L"Not Assigned";
				}
				else
				{
					lblBoyValue->Text =
						row[L"delivery_boy"]->
						ToString();

					if (row[L"vehicle_no"] !=
						DBNull::Value)
					{
						lblBoyValue->Text +=
							L" - " +
							row[L"vehicle_no"]->
							ToString();
					}
				}

				String^ currentStatus =
					row[L"status"]->ToString();

				int statusIndex =
					cmbStatus->Items->
					IndexOf(currentStatus);

				if (statusIndex >= 0)
				{
					cmbStatus->SelectedIndex =
						statusIndex;
				}

				LoadStatusHistory();
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Unable to load delivery details.\n\n" +
						ex->Message,
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Error);
			}
		}

		void LoadStatusHistory()
		{
			if (selectedDeliveryId <= 0)
			{
				dgvHistory->DataSource = nullptr;
				return;
			}

			try
			{
				DataTable^ table =
					AdminDeliveryRepository::
					GetStatusHistory(
						selectedDeliveryId);

				dgvHistory->DataSource =
					table;

				if (dgvHistory->Columns[
					L"history_id"] != nullptr)
				{
					dgvHistory->Columns[
						L"history_id"]->Visible =
						false;
				}

				if (dgvHistory->Columns[
					L"status"] != nullptr)
				{
					dgvHistory->Columns[
						L"status"]->HeaderText =
						L"Status";
				}

				if (dgvHistory->Columns[
					L"changed_at"] != nullptr)
				{
					dgvHistory->Columns[
						L"changed_at"]->HeaderText =
						L"Changed At";
				}

				if (dgvHistory->Columns[
					L"changed_by"] != nullptr)
				{
					dgvHistory->Columns[
						L"changed_by"]->HeaderText =
						L"Changed By";
				}
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Unable to load status history.\n\n" +
						ex->Message,
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Error);
			}
		}

		void ClearDetails()
		{
			selectedDeliveryId = 0;

			lblTrackingValue->Text = L"-";
			lblCustomerValue->Text = L"-";
			lblReceiverValue->Text = L"-";
			lblCityValue->Text = L"-";
			lblCurrentStatusValue->Text = L"-";
			lblBoyValue->Text = L"Not Assigned";

			dgvHistory->DataSource = nullptr;
		}

		void DeliverySelectionChanged(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (dgvDeliveries->CurrentRow !=
				nullptr)
			{
				LoadSelectedDelivery();
			}
		}

		void Refresh_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			LoadDeliveryBoys();
			LoadDeliveries();
		}

		void AssignBoy_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (selectedDeliveryId <= 0)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Please select a delivery first.",
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Warning);

				return;
			}

			if (cmbDeliveryBoy->SelectedValue ==
				nullptr)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"No active delivery staff is available.",
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Warning);

				return;
			}

			try
			{
				int boyId =
					Convert::ToInt32(
						cmbDeliveryBoy->
						SelectedValue);

				bool success =
					AdminDeliveryRepository::
					AssignDeliveryBoy(
						selectedDeliveryId,
						boyId);

				if (success)
				{
					System::Windows::Forms::
						MessageBox::Show(
							L"Delivery staff assigned successfully.",
							L"CourierEase",
							System::Windows::Forms::
							MessageBoxButtons::OK,
							System::Windows::Forms::
							MessageBoxIcon::Information);

					LoadDeliveries();
				}
				else
				{
					System::Windows::Forms::
						MessageBox::Show(
							L"Unable to assign delivery staff.",
							L"CourierEase",
							System::Windows::Forms::
							MessageBoxButtons::OK,
							System::Windows::Forms::
							MessageBoxIcon::Warning);
				}
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Unable to assign delivery staff.\n\n" +
						ex->Message,
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Error);
			}
		}

		void RemoveBoy_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (selectedDeliveryId <= 0)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Please select a delivery first.",
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Warning);

				return;
			}

			System::Windows::Forms::DialogResult result =
				System::Windows::Forms::
				MessageBox::Show(
					L"Remove the assigned delivery staff?",
					L"CourierEase",
					System::Windows::Forms::
					MessageBoxButtons::YesNo,
					System::Windows::Forms::
					MessageBoxIcon::Question);

			if (result !=
				System::Windows::Forms::
				DialogResult::Yes)
			{
				return;
			}

			try
			{
				bool success =
					AdminDeliveryRepository::
					RemoveDeliveryBoy(
						selectedDeliveryId);

				if (success)
				{
					System::Windows::Forms::
						MessageBox::Show(
							L"Delivery staff removed successfully.",
							L"CourierEase",
							System::Windows::Forms::
							MessageBoxButtons::OK,
							System::Windows::Forms::
							MessageBoxIcon::Information);

					LoadDeliveries();
				}
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Unable to remove delivery staff.\n\n" +
						ex->Message,
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Error);
			}
		}

		void UpdateStatus_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (selectedDeliveryId <= 0)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Please select a delivery first.",
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Warning);

				return;
			}

			if (cmbStatus->SelectedItem ==
				nullptr)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Please select a delivery status.",
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Warning);

				return;
			}

			String^ newStatus =
				cmbStatus->SelectedItem->
				ToString();

			if (newStatus == L"In Transit" &&
				lblBoyValue->Text ==
				L"Not Assigned")
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Assign delivery staff before changing "
						L"the status to In Transit.",
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Warning);

				return;
			}

			try
			{
				bool success =
					AdminDeliveryRepository::
					UpdateDeliveryStatus(
						selectedDeliveryId,
						newStatus,
						adminId);

				if (success)
				{
					System::Windows::Forms::
						MessageBox::Show(
							L"Delivery status updated successfully.",
							L"CourierEase",
							System::Windows::Forms::
							MessageBoxButtons::OK,
							System::Windows::Forms::
							MessageBoxIcon::Information);

					LoadDeliveries();
				}
				else
				{
					System::Windows::Forms::
						MessageBox::Show(
							L"Unable to update delivery status.",
							L"CourierEase",
							System::Windows::Forms::
							MessageBoxButtons::OK,
							System::Windows::Forms::
							MessageBoxIcon::Warning);
				}
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Unable to update delivery status.\n\n" +
						ex->Message,
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Error);
			}
		}

		void Close_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->DialogResult =
				System::Windows::Forms::
				DialogResult::OK;

			this->Close();
		}

	private:

		System::Void btnRefresh_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Refresh_Click(sender, e);
		}

		System::Void btnClose_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Close_Click(sender, e);
		}

		System::Void btnAssignBoy_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			AssignBoy_Click(sender, e);
		}

		System::Void btnRemoveBoy_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			RemoveBoy_Click(sender, e);
		}

		System::Void btnUpdateStatus_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			UpdateStatus_Click(sender, e);
		}

		System::Void dgvDeliveries_SelectionChanged(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			DeliverySelectionChanged(sender, e);
		}
	};
}