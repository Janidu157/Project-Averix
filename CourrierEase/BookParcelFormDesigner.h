#pragma once

#include "Parcel.h"
#include "ParcelRepository.h"
#include "DeliveryService.h"

namespace CourrierEase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class BookParcelFormDesigner : public System::Windows::Forms::Form
	{
	public:
		BookParcelFormDesigner(void)
		{
			customerId = 0;
			customerName = L"Customer";
			currentCharge = 0;

			InitializeComponent();

			cmbParcelType->SelectedIndex = 0;
			cmbDeliveryOption->SelectedIndex = 0;
			UpdateSummary();
		}

		BookParcelFormDesigner(int id, String^ name)
		{
			customerId = id;
			customerName = name;
			currentCharge = 0;

			InitializeComponent();

			cmbParcelType->SelectedIndex = 0;
			cmbDeliveryOption->SelectedIndex = 0;

			LoadCustomerDetails();
			UpdateSummary();
		}

	protected:
		~BookParcelFormDesigner()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		int customerId;
		String^ customerName;
		double currentCharge;

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
		System::Windows::Forms::Label^ lblHeading;
		System::Windows::Forms::Label^ lblSubtitle;

		System::Windows::Forms::Panel^ pnlFormCard;

		System::Windows::Forms::Label^ lblReceiverSection;
		System::Windows::Forms::Label^ lblReceiverName;
		System::Windows::Forms::TextBox^ txtReceiverName;
		System::Windows::Forms::Label^ lblReceiverPhone;
		System::Windows::Forms::TextBox^ txtReceiverPhone;
		System::Windows::Forms::Label^ lblReceiverAddress;
		System::Windows::Forms::TextBox^ txtReceiverAddress;
		System::Windows::Forms::Label^ lblReceiverCity;
		System::Windows::Forms::TextBox^ txtReceiverCity;
		System::Windows::Forms::Panel^ lineReceiver;

		System::Windows::Forms::Label^ lblParcelSection;
		System::Windows::Forms::Label^ lblDescription;
		System::Windows::Forms::TextBox^ txtDescription;
		System::Windows::Forms::Label^ lblWeight;
		System::Windows::Forms::TextBox^ txtWeight;
		System::Windows::Forms::Label^ lblParcelType;
		System::Windows::Forms::ComboBox^ cmbParcelType;
		System::Windows::Forms::Label^ lblDeclaredValue;
		System::Windows::Forms::TextBox^ txtDeclaredValue;
		System::Windows::Forms::Panel^ lineParcel;

		System::Windows::Forms::Label^ lblDeliverySection;
		System::Windows::Forms::Label^ lblPickupAddress;
		System::Windows::Forms::TextBox^ txtPickupAddress;
		System::Windows::Forms::Label^ lblDeliveryOption;
		System::Windows::Forms::ComboBox^ cmbDeliveryOption;
		System::Windows::Forms::Label^ lblTrackingInfo;

		System::Windows::Forms::Panel^ pnlSummary;
		System::Windows::Forms::Label^ lblSummaryTitle;
		System::Windows::Forms::Label^ lblSummaryServiceTitle;
		System::Windows::Forms::Label^ lblSummaryService;
		System::Windows::Forms::Label^ lblSummaryWeightTitle;
		System::Windows::Forms::Label^ lblSummaryWeight;
		System::Windows::Forms::Label^ lblSummaryValueTitle;
		System::Windows::Forms::Label^ lblSummaryValue;
		System::Windows::Forms::Panel^ lineSummary;
		System::Windows::Forms::Label^ lblEstimated;
		System::Windows::Forms::Label^ lblSummaryCharge;
		System::Windows::Forms::Label^ lblChargeInfo;

		System::Windows::Forms::Button^ btnBook;
		System::Windows::Forms::Button^ btnCancel;

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
			this->lblHeading = (gcnew System::Windows::Forms::Label());
			this->lblSubtitle = (gcnew System::Windows::Forms::Label());
			this->pnlFormCard = (gcnew System::Windows::Forms::Panel());
			this->lblReceiverSection = (gcnew System::Windows::Forms::Label());
			this->lblReceiverName = (gcnew System::Windows::Forms::Label());
			this->txtReceiverName = (gcnew System::Windows::Forms::TextBox());
			this->lblReceiverPhone = (gcnew System::Windows::Forms::Label());
			this->txtReceiverPhone = (gcnew System::Windows::Forms::TextBox());
			this->lblReceiverAddress = (gcnew System::Windows::Forms::Label());
			this->txtReceiverAddress = (gcnew System::Windows::Forms::TextBox());
			this->lblReceiverCity = (gcnew System::Windows::Forms::Label());
			this->txtReceiverCity = (gcnew System::Windows::Forms::TextBox());
			this->lineReceiver = (gcnew System::Windows::Forms::Panel());
			this->lblParcelSection = (gcnew System::Windows::Forms::Label());
			this->lblDescription = (gcnew System::Windows::Forms::Label());
			this->txtDescription = (gcnew System::Windows::Forms::TextBox());
			this->lblWeight = (gcnew System::Windows::Forms::Label());
			this->txtWeight = (gcnew System::Windows::Forms::TextBox());
			this->lblParcelType = (gcnew System::Windows::Forms::Label());
			this->cmbParcelType = (gcnew System::Windows::Forms::ComboBox());
			this->lblDeclaredValue = (gcnew System::Windows::Forms::Label());
			this->txtDeclaredValue = (gcnew System::Windows::Forms::TextBox());
			this->lineParcel = (gcnew System::Windows::Forms::Panel());
			this->lblDeliverySection = (gcnew System::Windows::Forms::Label());
			this->lblPickupAddress = (gcnew System::Windows::Forms::Label());
			this->txtPickupAddress = (gcnew System::Windows::Forms::TextBox());
			this->lblDeliveryOption = (gcnew System::Windows::Forms::Label());
			this->cmbDeliveryOption = (gcnew System::Windows::Forms::ComboBox());
			this->lblTrackingInfo = (gcnew System::Windows::Forms::Label());
			this->pnlSummary = (gcnew System::Windows::Forms::Panel());
			this->lblSummaryTitle = (gcnew System::Windows::Forms::Label());
			this->lblSummaryServiceTitle = (gcnew System::Windows::Forms::Label());
			this->lblSummaryService = (gcnew System::Windows::Forms::Label());
			this->lblSummaryWeightTitle = (gcnew System::Windows::Forms::Label());
			this->lblSummaryWeight = (gcnew System::Windows::Forms::Label());
			this->lblSummaryValueTitle = (gcnew System::Windows::Forms::Label());
			this->lblSummaryValue = (gcnew System::Windows::Forms::Label());
			this->lineSummary = (gcnew System::Windows::Forms::Panel());
			this->lblEstimated = (gcnew System::Windows::Forms::Label());
			this->lblSummaryCharge = (gcnew System::Windows::Forms::Label());
			this->lblChargeInfo = (gcnew System::Windows::Forms::Label());
			this->btnBook = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->pnlSidebar->SuspendLayout();
			this->pnlHeader->SuspendLayout();
			this->pnlAvatar->SuspendLayout();
			this->pnlMain->SuspendLayout();
			this->pnlFormCard->SuspendLayout();
			this->pnlSummary->SuspendLayout();
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
			this->btnDashboard->Click += gcnew System::EventHandler(this, &BookParcelFormDesigner::btnDashboard_Click);
			// 
			// btnBookParcel
			// 
			this->btnBookParcel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
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
			this->btnBookParcel->Click += gcnew System::EventHandler(this, &BookParcelFormDesigner::btnBookParcel_Click);
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
			this->btnMyDeliveries->Click += gcnew System::EventHandler(this, &BookParcelFormDesigner::btnMyDeliveries_Click);
			// 
			// btnMyProfile
			// 
			this->btnMyProfile->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
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
			this->btnMyProfile->Click += gcnew System::EventHandler(this, &BookParcelFormDesigner::btnMyProfile_Click);
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
			this->btnLogout->Click += gcnew System::EventHandler(this, &BookParcelFormDesigner::btnLogout_Click);
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
			this->lblPageTitle->Size = System::Drawing::Size(124, 28);
			this->lblPageTitle->TabIndex = 0;
			this->lblPageTitle->Text = L"Book Parcel";
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
			this->pnlMain->Controls->Add(this->lblHeading);
			this->pnlMain->Controls->Add(this->lblSubtitle);
			this->pnlMain->Controls->Add(this->pnlFormCard);
			this->pnlMain->Controls->Add(this->pnlSummary);
			this->pnlMain->Controls->Add(this->btnBook);
			this->pnlMain->Controls->Add(this->btnCancel);
			this->pnlMain->Location = System::Drawing::Point(190, 65);
			this->pnlMain->Name = L"pnlMain";
			this->pnlMain->Size = System::Drawing::Size(910, 635);
			this->pnlMain->TabIndex = 2;
			// 
			// lblHeading
			// 
			this->lblHeading->AutoSize = true;
			this->lblHeading->Font = (gcnew System::Drawing::Font(L"Segoe UI", 17, System::Drawing::FontStyle::Bold));
			this->lblHeading->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblHeading->Location = System::Drawing::Point(35, 22);
			this->lblHeading->Name = L"lblHeading";
			this->lblHeading->Size = System::Drawing::Size(203, 40);
			this->lblHeading->TabIndex = 0;
			this->lblHeading->Text = L"Book a Parcel";
			// 
			// lblSubtitle
			// 
			this->lblSubtitle->AutoSize = true;
			this->lblSubtitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblSubtitle->Location = System::Drawing::Point(37, 62);
			this->lblSubtitle->Name = L"lblSubtitle";
			this->lblSubtitle->Size = System::Drawing::Size(353, 20);
			this->lblSubtitle->TabIndex = 1;
			this->lblSubtitle->Text = L"Enter the receiver, parcel and delivery details below.";
			// 
			// pnlFormCard
			// 
			this->pnlFormCard->BackColor = System::Drawing::Color::White;
			this->pnlFormCard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlFormCard->Controls->Add(this->lblReceiverSection);
			this->pnlFormCard->Controls->Add(this->lblReceiverName);
			this->pnlFormCard->Controls->Add(this->txtReceiverName);
			this->pnlFormCard->Controls->Add(this->lblReceiverPhone);
			this->pnlFormCard->Controls->Add(this->txtReceiverPhone);
			this->pnlFormCard->Controls->Add(this->lblReceiverAddress);
			this->pnlFormCard->Controls->Add(this->txtReceiverAddress);
			this->pnlFormCard->Controls->Add(this->lblReceiverCity);
			this->pnlFormCard->Controls->Add(this->txtReceiverCity);
			this->pnlFormCard->Controls->Add(this->lineReceiver);
			this->pnlFormCard->Controls->Add(this->lblParcelSection);
			this->pnlFormCard->Controls->Add(this->lblDescription);
			this->pnlFormCard->Controls->Add(this->txtDescription);
			this->pnlFormCard->Controls->Add(this->lblWeight);
			this->pnlFormCard->Controls->Add(this->txtWeight);
			this->pnlFormCard->Controls->Add(this->lblParcelType);
			this->pnlFormCard->Controls->Add(this->cmbParcelType);
			this->pnlFormCard->Controls->Add(this->lblDeclaredValue);
			this->pnlFormCard->Controls->Add(this->txtDeclaredValue);
			this->pnlFormCard->Controls->Add(this->lineParcel);
			this->pnlFormCard->Controls->Add(this->lblDeliverySection);
			this->pnlFormCard->Controls->Add(this->lblPickupAddress);
			this->pnlFormCard->Controls->Add(this->txtPickupAddress);
			this->pnlFormCard->Controls->Add(this->lblDeliveryOption);
			this->pnlFormCard->Controls->Add(this->cmbDeliveryOption);
			this->pnlFormCard->Controls->Add(this->lblTrackingInfo);
			this->pnlFormCard->Location = System::Drawing::Point(35, 90);
			this->pnlFormCard->Name = L"pnlFormCard";
			this->pnlFormCard->Size = System::Drawing::Size(570, 490);
			this->pnlFormCard->TabIndex = 2;
			// 
			// lblReceiverSection
			// 
			this->lblReceiverSection->AutoSize = true;
			this->lblReceiverSection->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->lblReceiverSection->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblReceiverSection->Location = System::Drawing::Point(22, 18);
			this->lblReceiverSection->Name = L"lblReceiverSection";
			this->lblReceiverSection->Size = System::Drawing::Size(137, 23);
			this->lblReceiverSection->TabIndex = 0;
			this->lblReceiverSection->Text = L"Receiver Details";
			// 
			// lblReceiverName
			// 
			this->lblReceiverName->AutoSize = true;
			this->lblReceiverName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7, System::Drawing::FontStyle::Bold));
			this->lblReceiverName->Location = System::Drawing::Point(22, 55);
			this->lblReceiverName->Name = L"lblReceiverName";
			this->lblReceiverName->Size = System::Drawing::Size(93, 15);
			this->lblReceiverName->TabIndex = 1;
			this->lblReceiverName->Text = L"Receiver Name";
			// 
			// txtReceiverName
			// 
			this->txtReceiverName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtReceiverName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->txtReceiverName->Location = System::Drawing::Point(22, 77);
			this->txtReceiverName->Name = L"txtReceiverName";
			this->txtReceiverName->Size = System::Drawing::Size(250, 27);
			this->txtReceiverName->TabIndex = 0;
			// 
			// lblReceiverPhone
			// 
			this->lblReceiverPhone->AutoSize = true;
			this->lblReceiverPhone->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7, System::Drawing::FontStyle::Bold));
			this->lblReceiverPhone->Location = System::Drawing::Point(295, 55);
			this->lblReceiverPhone->Name = L"lblReceiverPhone";
			this->lblReceiverPhone->Size = System::Drawing::Size(95, 15);
			this->lblReceiverPhone->TabIndex = 2;
			this->lblReceiverPhone->Text = L"Receiver Phone";
			// 
			// txtReceiverPhone
			// 
			this->txtReceiverPhone->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtReceiverPhone->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->txtReceiverPhone->Location = System::Drawing::Point(295, 77);
			this->txtReceiverPhone->Name = L"txtReceiverPhone";
			this->txtReceiverPhone->Size = System::Drawing::Size(250, 27);
			this->txtReceiverPhone->TabIndex = 1;
			// 
			// lblReceiverAddress
			// 
			this->lblReceiverAddress->AutoSize = true;
			this->lblReceiverAddress->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7, System::Drawing::FontStyle::Bold));
			this->lblReceiverAddress->Location = System::Drawing::Point(22, 118);
			this->lblReceiverAddress->Name = L"lblReceiverAddress";
			this->lblReceiverAddress->Size = System::Drawing::Size(104, 15);
			this->lblReceiverAddress->TabIndex = 3;
			this->lblReceiverAddress->Text = L"Receiver Address";
			// 
			// txtReceiverAddress
			// 
			this->txtReceiverAddress->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtReceiverAddress->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->txtReceiverAddress->Location = System::Drawing::Point(22, 140);
			this->txtReceiverAddress->Name = L"txtReceiverAddress";
			this->txtReceiverAddress->Size = System::Drawing::Size(340, 27);
			this->txtReceiverAddress->TabIndex = 2;
			// 
			// lblReceiverCity
			// 
			this->lblReceiverCity->AutoSize = true;
			this->lblReceiverCity->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7, System::Drawing::FontStyle::Bold));
			this->lblReceiverCity->Location = System::Drawing::Point(385, 118);
			this->lblReceiverCity->Name = L"lblReceiverCity";
			this->lblReceiverCity->Size = System::Drawing::Size(81, 15);
			this->lblReceiverCity->TabIndex = 4;
			this->lblReceiverCity->Text = L"Receiver City";
			// 
			// txtReceiverCity
			// 
			this->txtReceiverCity->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtReceiverCity->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->txtReceiverCity->Location = System::Drawing::Point(385, 140);
			this->txtReceiverCity->Name = L"txtReceiverCity";
			this->txtReceiverCity->Size = System::Drawing::Size(160, 27);
			this->txtReceiverCity->TabIndex = 3;
			// 
			// lineReceiver
			// 
			this->lineReceiver->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->lineReceiver->Location = System::Drawing::Point(22, 185);
			this->lineReceiver->Name = L"lineReceiver";
			this->lineReceiver->Size = System::Drawing::Size(523, 1);
			this->lineReceiver->TabIndex = 5;
			// 
			// lblParcelSection
			// 
			this->lblParcelSection->AutoSize = true;
			this->lblParcelSection->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->lblParcelSection->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblParcelSection->Location = System::Drawing::Point(22, 200);
			this->lblParcelSection->Name = L"lblParcelSection";
			this->lblParcelSection->Size = System::Drawing::Size(118, 23);
			this->lblParcelSection->TabIndex = 6;
			this->lblParcelSection->Text = L"Parcel Details";
			// 
			// lblDescription
			// 
			this->lblDescription->AutoSize = true;
			this->lblDescription->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7, System::Drawing::FontStyle::Bold));
			this->lblDescription->Location = System::Drawing::Point(22, 237);
			this->lblDescription->Name = L"lblDescription";
			this->lblDescription->Size = System::Drawing::Size(71, 15);
			this->lblDescription->TabIndex = 7;
			this->lblDescription->Text = L"Description";
			// 
			// txtDescription
			// 
			this->txtDescription->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtDescription->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->txtDescription->Location = System::Drawing::Point(22, 259);
			this->txtDescription->Name = L"txtDescription";
			this->txtDescription->Size = System::Drawing::Size(250, 27);
			this->txtDescription->TabIndex = 4;
			// 
			// lblWeight
			// 
			this->lblWeight->AutoSize = true;
			this->lblWeight->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7, System::Drawing::FontStyle::Bold));
			this->lblWeight->Location = System::Drawing::Point(295, 237);
			this->lblWeight->Name = L"lblWeight";
			this->lblWeight->Size = System::Drawing::Size(73, 15);
			this->lblWeight->TabIndex = 8;
			this->lblWeight->Text = L"Weight (kg)";
			// 
			// txtWeight
			// 
			this->txtWeight->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtWeight->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->txtWeight->Location = System::Drawing::Point(295, 259);
			this->txtWeight->Name = L"txtWeight";
			this->txtWeight->Size = System::Drawing::Size(110, 27);
			this->txtWeight->TabIndex = 5;
			this->txtWeight->TextChanged += gcnew System::EventHandler(this, &BookParcelFormDesigner::SummaryChanged);
			// 
			// lblParcelType
			// 
			this->lblParcelType->AutoSize = true;
			this->lblParcelType->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7, System::Drawing::FontStyle::Bold));
			this->lblParcelType->Location = System::Drawing::Point(425, 237);
			this->lblParcelType->Name = L"lblParcelType";
			this->lblParcelType->Size = System::Drawing::Size(70, 15);
			this->lblParcelType->TabIndex = 9;
			this->lblParcelType->Text = L"Parcel Type";
			// 
			// cmbParcelType
			// 
			this->cmbParcelType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbParcelType->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->cmbParcelType->FormattingEnabled = true;
			this->cmbParcelType->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Document", L"Package", L"Fragile", L"Other" });
			this->cmbParcelType->Location = System::Drawing::Point(425, 259);
			this->cmbParcelType->Name = L"cmbParcelType";
			this->cmbParcelType->Size = System::Drawing::Size(120, 28);
			this->cmbParcelType->TabIndex = 6;
			// 
			// lblDeclaredValue
			// 
			this->lblDeclaredValue->AutoSize = true;
			this->lblDeclaredValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7, System::Drawing::FontStyle::Bold));
			this->lblDeclaredValue->Location = System::Drawing::Point(22, 300);
			this->lblDeclaredValue->Name = L"lblDeclaredValue";
			this->lblDeclaredValue->Size = System::Drawing::Size(123, 15);
			this->lblDeclaredValue->TabIndex = 10;
			this->lblDeclaredValue->Text = L"Declared Value (LKR)";
			// 
			// txtDeclaredValue
			// 
			this->txtDeclaredValue->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtDeclaredValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->txtDeclaredValue->Location = System::Drawing::Point(22, 322);
			this->txtDeclaredValue->Name = L"txtDeclaredValue";
			this->txtDeclaredValue->Size = System::Drawing::Size(250, 27);
			this->txtDeclaredValue->TabIndex = 7;
			this->txtDeclaredValue->Text = L"0";
			this->txtDeclaredValue->TextChanged += gcnew System::EventHandler(this, &BookParcelFormDesigner::SummaryChanged);
			// 
			// lineParcel
			// 
			this->lineParcel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->lineParcel->Location = System::Drawing::Point(22, 365);
			this->lineParcel->Name = L"lineParcel";
			this->lineParcel->Size = System::Drawing::Size(523, 1);
			this->lineParcel->TabIndex = 11;
			// 
			// lblDeliverySection
			// 
			this->lblDeliverySection->AutoSize = true;
			this->lblDeliverySection->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->lblDeliverySection->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblDeliverySection->Location = System::Drawing::Point(22, 380);
			this->lblDeliverySection->Name = L"lblDeliverySection";
			this->lblDeliverySection->Size = System::Drawing::Size(137, 23);
			this->lblDeliverySection->TabIndex = 12;
			this->lblDeliverySection->Text = L"Delivery Details";
			// 
			// lblPickupAddress
			// 
			this->lblPickupAddress->AutoSize = true;
			this->lblPickupAddress->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7, System::Drawing::FontStyle::Bold));
			this->lblPickupAddress->Location = System::Drawing::Point(22, 417);
			this->lblPickupAddress->Name = L"lblPickupAddress";
			this->lblPickupAddress->Size = System::Drawing::Size(91, 15);
			this->lblPickupAddress->TabIndex = 13;
			this->lblPickupAddress->Text = L"Pickup Address";
			// 
			// txtPickupAddress
			// 
			this->txtPickupAddress->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPickupAddress->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->txtPickupAddress->Location = System::Drawing::Point(22, 439);
			this->txtPickupAddress->Name = L"txtPickupAddress";
			this->txtPickupAddress->Size = System::Drawing::Size(340, 27);
			this->txtPickupAddress->TabIndex = 8;
			// 
			// lblDeliveryOption
			// 
			this->lblDeliveryOption->AutoSize = true;
			this->lblDeliveryOption->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7, System::Drawing::FontStyle::Bold));
			this->lblDeliveryOption->Location = System::Drawing::Point(385, 417);
			this->lblDeliveryOption->Name = L"lblDeliveryOption";
			this->lblDeliveryOption->Size = System::Drawing::Size(95, 15);
			this->lblDeliveryOption->TabIndex = 14;
			this->lblDeliveryOption->Text = L"Delivery Option";
			// 
			// cmbDeliveryOption
			// 
			this->cmbDeliveryOption->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbDeliveryOption->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->cmbDeliveryOption->FormattingEnabled = true;
			this->cmbDeliveryOption->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Standard", L"Express" });
			this->cmbDeliveryOption->Location = System::Drawing::Point(385, 439);
			this->cmbDeliveryOption->Name = L"cmbDeliveryOption";
			this->cmbDeliveryOption->Size = System::Drawing::Size(160, 28);
			this->cmbDeliveryOption->TabIndex = 9;
			this->cmbDeliveryOption->SelectedIndexChanged += gcnew System::EventHandler(this, &BookParcelFormDesigner::SummaryChanged);
			// 
			// lblTrackingInfo
			// 
			this->lblTrackingInfo->AutoSize = true;
			this->lblTrackingInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7));
			this->lblTrackingInfo->ForeColor = System::Drawing::Color::Black;
			this->lblTrackingInfo->Location = System::Drawing::Point(22, 470);
			this->lblTrackingInfo->Name = L"lblTrackingInfo";
			this->lblTrackingInfo->Size = System::Drawing::Size(342, 15);
			this->lblTrackingInfo->TabIndex = 15;
			this->lblTrackingInfo->Text = L"Tracking number will be generated automatically after booking.";
			// 
			// pnlSummary
			// 
			this->pnlSummary->BackColor = System::Drawing::Color::White;
			this->pnlSummary->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlSummary->Controls->Add(this->lblSummaryTitle);
			this->pnlSummary->Controls->Add(this->lblSummaryServiceTitle);
			this->pnlSummary->Controls->Add(this->lblSummaryService);
			this->pnlSummary->Controls->Add(this->lblSummaryWeightTitle);
			this->pnlSummary->Controls->Add(this->lblSummaryWeight);
			this->pnlSummary->Controls->Add(this->lblSummaryValueTitle);
			this->pnlSummary->Controls->Add(this->lblSummaryValue);
			this->pnlSummary->Controls->Add(this->lineSummary);
			this->pnlSummary->Controls->Add(this->lblEstimated);
			this->pnlSummary->Controls->Add(this->lblSummaryCharge);
			this->pnlSummary->Controls->Add(this->lblChargeInfo);
			this->pnlSummary->Location = System::Drawing::Point(625, 90);
			this->pnlSummary->Name = L"pnlSummary";
			this->pnlSummary->Size = System::Drawing::Size(250, 290);
			this->pnlSummary->TabIndex = 3;
			// 
			// lblSummaryTitle
			// 
			this->lblSummaryTitle->AutoSize = true;
			this->lblSummaryTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->lblSummaryTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblSummaryTitle->Location = System::Drawing::Point(18, 20);
			this->lblSummaryTitle->Name = L"lblSummaryTitle";
			this->lblSummaryTitle->Size = System::Drawing::Size(160, 23);
			this->lblSummaryTitle->TabIndex = 0;
			this->lblSummaryTitle->Text = L"Booking Summary";
			// 
			// lblSummaryServiceTitle
			// 
			this->lblSummaryServiceTitle->AutoSize = true;
			this->lblSummaryServiceTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblSummaryServiceTitle->Location = System::Drawing::Point(18, 65);
			this->lblSummaryServiceTitle->Name = L"lblSummaryServiceTitle";
			this->lblSummaryServiceTitle->Size = System::Drawing::Size(56, 20);
			this->lblSummaryServiceTitle->TabIndex = 1;
			this->lblSummaryServiceTitle->Text = L"Service";
			// 
			// lblSummaryService
			// 
			this->lblSummaryService->AutoSize = true;
			this->lblSummaryService->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblSummaryService->Location = System::Drawing::Point(155, 65);
			this->lblSummaryService->Name = L"lblSummaryService";
			this->lblSummaryService->Size = System::Drawing::Size(70, 19);
			this->lblSummaryService->TabIndex = 2;
			this->lblSummaryService->Text = L"Standard";
			// 
			// lblSummaryWeightTitle
			// 
			this->lblSummaryWeightTitle->AutoSize = true;
			this->lblSummaryWeightTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblSummaryWeightTitle->Location = System::Drawing::Point(18, 105);
			this->lblSummaryWeightTitle->Name = L"lblSummaryWeightTitle";
			this->lblSummaryWeightTitle->Size = System::Drawing::Size(56, 20);
			this->lblSummaryWeightTitle->TabIndex = 3;
			this->lblSummaryWeightTitle->Text = L"Weight";
			// 
			// lblSummaryWeight
			// 
			this->lblSummaryWeight->AutoSize = true;
			this->lblSummaryWeight->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblSummaryWeight->Location = System::Drawing::Point(155, 105);
			this->lblSummaryWeight->Name = L"lblSummaryWeight";
			this->lblSummaryWeight->Size = System::Drawing::Size(15, 19);
			this->lblSummaryWeight->TabIndex = 4;
			this->lblSummaryWeight->Text = L"-";
			// 
			// lblSummaryValueTitle
			// 
			this->lblSummaryValueTitle->AutoSize = true;
			this->lblSummaryValueTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblSummaryValueTitle->Location = System::Drawing::Point(18, 145);
			this->lblSummaryValueTitle->Name = L"lblSummaryValueTitle";
			this->lblSummaryValueTitle->Size = System::Drawing::Size(109, 20);
			this->lblSummaryValueTitle->TabIndex = 5;
			this->lblSummaryValueTitle->Text = L"Declared Value";
			// 
			// lblSummaryValue
			// 
			this->lblSummaryValue->AutoSize = true;
			this->lblSummaryValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblSummaryValue->Location = System::Drawing::Point(155, 145);
			this->lblSummaryValue->Name = L"lblSummaryValue";
			this->lblSummaryValue->Size = System::Drawing::Size(15, 19);
			this->lblSummaryValue->TabIndex = 6;
			this->lblSummaryValue->Text = L"-";
			// 
			// lineSummary
			// 
			this->lineSummary->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->lineSummary->Location = System::Drawing::Point(18, 185);
			this->lineSummary->Name = L"lineSummary";
			this->lineSummary->Size = System::Drawing::Size(212, 1);
			this->lineSummary->TabIndex = 7;
			// 
			// lblEstimated
			// 
			this->lblEstimated->AutoSize = true;
			this->lblEstimated->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblEstimated->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(105)));
			this->lblEstimated->Location = System::Drawing::Point(18, 205);
			this->lblEstimated->Name = L"lblEstimated";
			this->lblEstimated->Size = System::Drawing::Size(126, 19);
			this->lblEstimated->TabIndex = 8;
			this->lblEstimated->Text = L"Estimated Charge";
			// 
			// lblSummaryCharge
			// 
			this->lblSummaryCharge->AutoSize = true;
			this->lblSummaryCharge->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
			this->lblSummaryCharge->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->lblSummaryCharge->Location = System::Drawing::Point(18, 225);
			this->lblSummaryCharge->Name = L"lblSummaryCharge";
			this->lblSummaryCharge->Size = System::Drawing::Size(129, 37);
			this->lblSummaryCharge->TabIndex = 9;
			this->lblSummaryCharge->Text = L"LKR 0.00";
			// 
			// lblChargeInfo
			// 
			this->lblChargeInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7));
			this->lblChargeInfo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lblChargeInfo->Location = System::Drawing::Point(18, 260);
			this->lblChargeInfo->Name = L"lblChargeInfo";
			this->lblChargeInfo->Size = System::Drawing::Size(215, 30);
			this->lblChargeInfo->TabIndex = 10;
			this->lblChargeInfo->Text = L"Charge is calculated from the selected\r\ndelivery option and parcel weight.";
			// 
			// btnBook
			// 
			this->btnBook->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnBook->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnBook->FlatAppearance->BorderSize = 0;
			this->btnBook->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBook->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnBook->ForeColor = System::Drawing::Color::White;
			this->btnBook->Location = System::Drawing::Point(625, 395);
			this->btnBook->Name = L"btnBook";
			this->btnBook->Size = System::Drawing::Size(250, 42);
			this->btnBook->TabIndex = 10;
			this->btnBook->Text = L"Book Parcel";
			this->btnBook->UseVisualStyleBackColor = false;
			this->btnBook->Click += gcnew System::EventHandler(this, &BookParcelFormDesigner::btnBook_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->BackColor = System::Drawing::Color::White;
			this->btnCancel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnCancel->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(203)),
				static_cast<System::Int32>(static_cast<System::Byte>(213)), static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->btnCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
				static_cast<System::Int32>(static_cast<System::Byte>(105)));
			this->btnCancel->Location = System::Drawing::Point(625, 450);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(250, 38);
			this->btnCancel->TabIndex = 11;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = false;
			this->btnCancel->Click += gcnew System::EventHandler(this, &BookParcelFormDesigner::btnCancel_Click);
			// 
			// BookParcelFormDesigner
			// 
			this->AcceptButton = this->btnBook;
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
			this->Name = L"BookParcelFormDesigner";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CourierEase - Book Parcel";
			this->pnlSidebar->ResumeLayout(false);
			this->pnlSidebar->PerformLayout();
			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();
			this->pnlAvatar->ResumeLayout(false);
			this->pnlMain->ResumeLayout(false);
			this->pnlMain->PerformLayout();
			this->pnlFormCard->ResumeLayout(false);
			this->pnlFormCard->PerformLayout();
			this->pnlSummary->ResumeLayout(false);
			this->pnlSummary->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion

	private:

		void LoadCustomerDetails()
		{
			if (String::IsNullOrWhiteSpace(customerName))
			{
				customerName = L"Customer";
			}

			lblHeaderName->Text = customerName;

			String^ name = customerName->Trim();

			if (name->Length > 0)
			{
				lblInitial->Text =
					name->Substring(0, 1)->ToUpper();
			}
		}

		void UpdateSummary()
		{
			String^ service = L"Standard";

			if (cmbDeliveryOption->SelectedItem != nullptr)
			{
				service =
					cmbDeliveryOption->SelectedItem->ToString();
			}

			lblSummaryService->Text = service;

			double weight = 0;

			bool validWeight =
				Double::TryParse(
					txtWeight->Text,
					weight);

			if (!validWeight || weight <= 0)
			{
				lblSummaryWeight->Text = L"-";
				currentCharge = 0;
				lblSummaryCharge->Text = L"LKR 0.00";
			}
			else
			{
				lblSummaryWeight->Text =
					weight.ToString(L"0.00") + L" kg";

				DeliveryService^ serviceObject;

				if (service == L"Express")
				{
					serviceObject =
						gcnew ExpressDelivery();
				}
				else
				{
					serviceObject =
						gcnew StandardDelivery();
				}

				currentCharge =
					serviceObject->CalculateCharge(weight);

				lblSummaryCharge->Text =
					L"LKR " +
					currentCharge.ToString(L"N2");
			}

			double value = 0;

			if (
				Double::TryParse(
					txtDeclaredValue->Text,
					value)
				&& value > 0)
			{
				lblSummaryValue->Text =
					L"LKR " +
					value.ToString(L"N2");
			}
			else
			{
				lblSummaryValue->Text = L"-";
			}
		}

		void SummaryChanged(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			UpdateSummary();
		}

		void Book_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (
				String::IsNullOrWhiteSpace(txtReceiverName->Text) ||
				String::IsNullOrWhiteSpace(txtReceiverPhone->Text) ||
				String::IsNullOrWhiteSpace(txtReceiverAddress->Text) ||
				String::IsNullOrWhiteSpace(txtReceiverCity->Text) ||
				String::IsNullOrWhiteSpace(txtDescription->Text) ||
				String::IsNullOrWhiteSpace(txtWeight->Text) ||
				String::IsNullOrWhiteSpace(txtPickupAddress->Text))
			{
				MessageBox::Show(
					L"Please complete all required fields.",
					L"Book Parcel",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);

				return;
			}

			String^ phone =
				txtReceiverPhone->Text->Trim();

			if (
				phone->Length < 9 ||
				phone->Length > 15)
			{
				MessageBox::Show(
					L"Please enter a valid receiver phone number.",
					L"Book Parcel",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);

				return;
			}

			double weight = 0;

			if (
				!Double::TryParse(
					txtWeight->Text,
					weight)
				|| weight <= 0)
			{
				MessageBox::Show(
					L"Please enter a valid parcel weight.",
					L"Book Parcel",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);

				return;
			}

			double declaredValue = 0;

			if (!String::IsNullOrWhiteSpace(
				txtDeclaredValue->Text))
			{
				if (
					!Double::TryParse(
						txtDeclaredValue->Text,
						declaredValue)
					|| declaredValue < 0)
				{
					MessageBox::Show(
						L"Please enter a valid declared value.",
						L"Book Parcel",
						MessageBoxButtons::OK,
						MessageBoxIcon::Warning);

					return;
				}
			}

			if (cmbParcelType->SelectedItem == nullptr)
			{
				MessageBox::Show(
					L"Please select a parcel type.",
					L"Book Parcel",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);

				return;
			}

			if (cmbDeliveryOption->SelectedItem == nullptr)
			{
				MessageBox::Show(
					L"Please select a delivery option.",
					L"Book Parcel",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);

				return;
			}

			UpdateSummary();

			try
			{
				Parcel^ parcel =
					gcnew Parcel();

				parcel->CustomerId =
					customerId;

				parcel->TrackingNo =
					ParcelRepository::GenerateTrackingNumber();

				parcel->ReceiverName =
					txtReceiverName->Text->Trim();

				parcel->ReceiverPhone =
					phone;

				parcel->ReceiverAddress =
					txtReceiverAddress->Text->Trim();

				parcel->ReceiverCity =
					txtReceiverCity->Text->Trim();

				parcel->Description =
					txtDescription->Text->Trim();

				parcel->WeightKg =
					weight;

				parcel->ParcelType =
					cmbParcelType->SelectedItem->ToString();

				parcel->DeclaredValue =
					declaredValue;

				String^ service =
					cmbDeliveryOption->SelectedItem->ToString();

				bool created =
					ParcelRepository::CreateParcel(
						parcel,
						service,
						currentCharge,
						txtPickupAddress->Text->Trim());

				if (created)
				{
					MessageBox::Show(
						L"Parcel booked successfully!\n\n"
						L"Tracking Number: " +
						parcel->TrackingNo +
						L"\n\nService: " +
						service +
						L"\nCharge: LKR " +
						currentCharge.ToString(L"N2"),
						L"Booking Successful",
						MessageBoxButtons::OK,
						MessageBoxIcon::Information);

					this->DialogResult =
						System::Windows::Forms::DialogResult::OK;

					this->Close();
				}
			}
			catch (MySqlException^ ex)
			{
				MessageBox::Show(
					L"Database error:\n" +
					ex->Message,
					L"Database Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(
					L"An error occurred:\n" +
					ex->Message,
					L"CourierEase",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
			}
		}

		void Dashboard_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->Close();
		}

		void Logout_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			System::Windows::Forms::DialogResult result =
				MessageBox::Show(
					L"Are you sure you want to logout?",
					L"Logout",
					MessageBoxButtons::YesNo,
					MessageBoxIcon::Question);

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
		System::Void btnBook_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Book_Click(sender, e);
		}

		System::Void btnCancel_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Dashboard_Click(sender, e);
		}

		System::Void btnMyProfile_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->DialogResult =
				System::Windows::Forms::DialogResult::Ignore;

			this->Close();
		}

		System::Void btnLogout_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Logout_Click(sender, e);
		}

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
		}

		System::Void btnMyDeliveries_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->DialogResult =
				System::Windows::Forms::DialogResult::Retry;

			this->Close();
		}
	};
}