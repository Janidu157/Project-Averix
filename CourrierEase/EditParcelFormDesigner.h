#pragma once

#include "ParcelManagementRepository.h"
#include "DeliveryService.h"

namespace CourrierEase
{
	public ref class EditParcelFormDesigner :
		public System::Windows::Forms::Form
	{
	public:

		EditParcelFormDesigner(void)
		{
			parcelId = 0;
			customerId = 0;

			InitializeComponent();
		}

		EditParcelFormDesigner(
			int selectedParcelId,
			int loggedCustomerId)
		{
			parcelId = selectedParcelId;
			customerId = loggedCustomerId;

			InitializeComponent();
			LoadParcelData();
		}

	protected:

		~EditParcelFormDesigner()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		int parcelId;
		int customerId;

		System::Windows::Forms::Panel^ pnlHeader;


		System::Windows::Forms::Label^ lblBrand;
		System::Windows::Forms::Label^ lblHeaderTitle;
		System::Windows::Forms::Label^ lblBack;

		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Label^ lblSubtitle;

		System::Windows::Forms::Panel^ pnlForm;

		System::Windows::Forms::Label^ lblTrackingCaption;
		System::Windows::Forms::Label^ lblTrackingNo;

		System::Windows::Forms::Label^ lblReceiverName;
		System::Windows::Forms::TextBox^ txtReceiverName;

		System::Windows::Forms::Label^ lblReceiverPhone;
		System::Windows::Forms::TextBox^ txtReceiverPhone;

		System::Windows::Forms::Label^ lblReceiverAddress;
		System::Windows::Forms::TextBox^ txtReceiverAddress;

		System::Windows::Forms::Label^ lblReceiverCity;
		System::Windows::Forms::TextBox^ txtReceiverCity;

		System::Windows::Forms::Label^ lblDescription;
		System::Windows::Forms::TextBox^ txtDescription;

		System::Windows::Forms::Label^ lblWeight;
		System::Windows::Forms::TextBox^ txtWeight;

		System::Windows::Forms::Label^ lblParcelType;
		System::Windows::Forms::ComboBox^ cmbParcelType;

		System::Windows::Forms::Label^ lblDeclaredValue;
		System::Windows::Forms::TextBox^ txtDeclaredValue;

		System::Windows::Forms::Label^ lblDeliveryOption;
		System::Windows::Forms::ComboBox^ cmbDeliveryOption;

		System::Windows::Forms::Label^ lblPickupAddress;
		System::Windows::Forms::TextBox^ txtPickupAddress;

		System::Windows::Forms::Panel^ pnlCharge;

		System::Windows::Forms::Label^ lblChargeTitle;
		System::Windows::Forms::Label^ lblCharge;

		System::Windows::Forms::Label^ lblEditNotice;

		System::Windows::Forms::Button^ btnSave;
		System::Windows::Forms::Button^ btnCancel;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			this->lblBrand = (gcnew System::Windows::Forms::Label());
			this->lblHeaderTitle = (gcnew System::Windows::Forms::Label());
			this->lblBack = (gcnew System::Windows::Forms::Label());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblSubtitle = (gcnew System::Windows::Forms::Label());
			this->pnlForm = (gcnew System::Windows::Forms::Panel());
			this->lblTrackingCaption = (gcnew System::Windows::Forms::Label());
			this->lblTrackingNo = (gcnew System::Windows::Forms::Label());
			this->lblReceiverName = (gcnew System::Windows::Forms::Label());
			this->txtReceiverName = (gcnew System::Windows::Forms::TextBox());
			this->lblReceiverPhone = (gcnew System::Windows::Forms::Label());
			this->txtReceiverPhone = (gcnew System::Windows::Forms::TextBox());
			this->lblReceiverAddress = (gcnew System::Windows::Forms::Label());
			this->txtReceiverAddress = (gcnew System::Windows::Forms::TextBox());
			this->lblReceiverCity = (gcnew System::Windows::Forms::Label());
			this->txtReceiverCity = (gcnew System::Windows::Forms::TextBox());
			this->lblDescription = (gcnew System::Windows::Forms::Label());
			this->txtDescription = (gcnew System::Windows::Forms::TextBox());
			this->lblWeight = (gcnew System::Windows::Forms::Label());
			this->txtWeight = (gcnew System::Windows::Forms::TextBox());
			this->lblParcelType = (gcnew System::Windows::Forms::Label());
			this->cmbParcelType = (gcnew System::Windows::Forms::ComboBox());
			this->lblDeclaredValue = (gcnew System::Windows::Forms::Label());
			this->txtDeclaredValue = (gcnew System::Windows::Forms::TextBox());
			this->lblDeliveryOption = (gcnew System::Windows::Forms::Label());
			this->cmbDeliveryOption = (gcnew System::Windows::Forms::ComboBox());
			this->lblPickupAddress = (gcnew System::Windows::Forms::Label());
			this->txtPickupAddress = (gcnew System::Windows::Forms::TextBox());
			this->pnlCharge = (gcnew System::Windows::Forms::Panel());
			this->lblChargeTitle = (gcnew System::Windows::Forms::Label());
			this->lblCharge = (gcnew System::Windows::Forms::Label());
			this->lblEditNotice = (gcnew System::Windows::Forms::Label());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->pnlHeader->SuspendLayout();
			this->pnlForm->SuspendLayout();
			this->pnlCharge->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlHeader
			// 
			this->pnlHeader->BackColor = System::Drawing::Color::White;
			this->pnlHeader->Controls->Add(this->lblBrand);
			this->pnlHeader->Controls->Add(this->lblHeaderTitle);
			this->pnlHeader->Controls->Add(this->lblBack);
			this->pnlHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlHeader->Location = System::Drawing::Point(0, 0);
			this->pnlHeader->Name = L"pnlHeader";
			this->pnlHeader->Size = System::Drawing::Size(1000, 70);
			this->pnlHeader->TabIndex = 0;
			// 
			// lblBrand
			// 
			this->lblBrand->AutoSize = true;
			this->lblBrand->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblBrand->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblBrand->Location = System::Drawing::Point(12, 17);
			this->lblBrand->Name = L"lblBrand";
			this->lblBrand->Size = System::Drawing::Size(123, 28);
			this->lblBrand->TabIndex = 1;
			this->lblBrand->Text = L"CourierEase";
			// 
			// lblHeaderTitle
			// 
			this->lblHeaderTitle->AutoSize = true;
			this->lblHeaderTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->lblHeaderTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblHeaderTitle->Location = System::Drawing::Point(430, 23);
			this->lblHeaderTitle->Name = L"lblHeaderTitle";
			this->lblHeaderTitle->Size = System::Drawing::Size(105, 25);
			this->lblHeaderTitle->TabIndex = 2;
			this->lblHeaderTitle->Text = L"Edit Parcel";
			// 
			// lblBack
			// 
			this->lblBack->AutoSize = true;
			this->lblBack->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblBack->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblBack->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->lblBack->Location = System::Drawing::Point(860, 25);
			this->lblBack->Name = L"lblBack";
			this->lblBack->Size = System::Drawing::Size(57, 20);
			this->lblBack->TabIndex = 3;
			this->lblBack->Text = L"< Back";
			this->lblBack->Click += gcnew System::EventHandler(this, &EditParcelFormDesigner::lblBack_Click);
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblTitle->Location = System::Drawing::Point(65, 100);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(187, 46);
			this->lblTitle->TabIndex = 1;
			this->lblTitle->Text = L"Edit Parcel";
			// 
			// lblSubtitle
			// 
			this->lblSubtitle->AutoSize = true;
			this->lblSubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblSubtitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblSubtitle->Location = System::Drawing::Point(68, 148);
			this->lblSubtitle->Name = L"lblSubtitle";
			this->lblSubtitle->Size = System::Drawing::Size(374, 20);
			this->lblSubtitle->TabIndex = 2;
			this->lblSubtitle->Text = L"Update the parcel information before it enters delivery.";
			// 
			// pnlForm
			// 
			this->pnlForm->BackColor = System::Drawing::Color::White;
			this->pnlForm->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlForm->Controls->Add(this->lblTrackingCaption);
			this->pnlForm->Controls->Add(this->lblTrackingNo);
			this->pnlForm->Controls->Add(this->lblReceiverName);
			this->pnlForm->Controls->Add(this->txtReceiverName);
			this->pnlForm->Controls->Add(this->lblReceiverPhone);
			this->pnlForm->Controls->Add(this->txtReceiverPhone);
			this->pnlForm->Controls->Add(this->lblReceiverAddress);
			this->pnlForm->Controls->Add(this->txtReceiverAddress);
			this->pnlForm->Controls->Add(this->lblReceiverCity);
			this->pnlForm->Controls->Add(this->txtReceiverCity);
			this->pnlForm->Controls->Add(this->lblDescription);
			this->pnlForm->Controls->Add(this->txtDescription);
			this->pnlForm->Controls->Add(this->lblWeight);
			this->pnlForm->Controls->Add(this->txtWeight);
			this->pnlForm->Controls->Add(this->lblParcelType);
			this->pnlForm->Controls->Add(this->cmbParcelType);
			this->pnlForm->Controls->Add(this->lblDeclaredValue);
			this->pnlForm->Controls->Add(this->txtDeclaredValue);
			this->pnlForm->Controls->Add(this->lblDeliveryOption);
			this->pnlForm->Controls->Add(this->cmbDeliveryOption);
			this->pnlForm->Controls->Add(this->lblPickupAddress);
			this->pnlForm->Controls->Add(this->txtPickupAddress);
			this->pnlForm->Controls->Add(this->pnlCharge);
			this->pnlForm->Controls->Add(this->lblEditNotice);
			this->pnlForm->Controls->Add(this->btnSave);
			this->pnlForm->Controls->Add(this->btnCancel);
			this->pnlForm->Location = System::Drawing::Point(70, 190);
			this->pnlForm->Name = L"pnlForm";
			this->pnlForm->Size = System::Drawing::Size(860, 600);
			this->pnlForm->TabIndex = 3;
			// 
			// lblTrackingCaption
			// 
			this->lblTrackingCaption->AutoSize = true;
			this->lblTrackingCaption->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblTrackingCaption->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblTrackingCaption->Location = System::Drawing::Point(30, 25);
			this->lblTrackingCaption->Name = L"lblTrackingCaption";
			this->lblTrackingCaption->Size = System::Drawing::Size(97, 20);
			this->lblTrackingCaption->TabIndex = 0;
			this->lblTrackingCaption->Text = L"Tracking No.";
			// 
			// lblTrackingNo
			// 
			this->lblTrackingNo->AutoSize = true;
			this->lblTrackingNo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->lblTrackingNo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->lblTrackingNo->Location = System::Drawing::Point(145, 23);
			this->lblTrackingNo->Name = L"lblTrackingNo";
			this->lblTrackingNo->Size = System::Drawing::Size(17, 23);
			this->lblTrackingNo->TabIndex = 1;
			this->lblTrackingNo->Text = L"-";
			// 
			// lblReceiverName
			// 
			this->lblReceiverName->AutoSize = true;
			this->lblReceiverName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblReceiverName->Location = System::Drawing::Point(30, 70);
			this->lblReceiverName->Name = L"lblReceiverName";
			this->lblReceiverName->Size = System::Drawing::Size(114, 20);
			this->lblReceiverName->TabIndex = 2;
			this->lblReceiverName->Text = L"Receiver Name";
			// 
			// txtReceiverName
			// 
			this->txtReceiverName->Location = System::Drawing::Point(30, 95);
			this->txtReceiverName->MaxLength = 60;
			this->txtReceiverName->Name = L"txtReceiverName";
			this->txtReceiverName->Size = System::Drawing::Size(385, 27);
			this->txtReceiverName->TabIndex = 0;
			// 
			// lblReceiverPhone
			// 
			this->lblReceiverPhone->AutoSize = true;
			this->lblReceiverPhone->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblReceiverPhone->Location = System::Drawing::Point(445, 70);
			this->lblReceiverPhone->Name = L"lblReceiverPhone";
			this->lblReceiverPhone->Size = System::Drawing::Size(116, 20);
			this->lblReceiverPhone->TabIndex = 3;
			this->lblReceiverPhone->Text = L"Receiver Phone";
			// 
			// txtReceiverPhone
			// 
			this->txtReceiverPhone->Location = System::Drawing::Point(445, 95);
			this->txtReceiverPhone->MaxLength = 15;
			this->txtReceiverPhone->Name = L"txtReceiverPhone";
			this->txtReceiverPhone->Size = System::Drawing::Size(380, 27);
			this->txtReceiverPhone->TabIndex = 1;
			// 
			// lblReceiverAddress
			// 
			this->lblReceiverAddress->AutoSize = true;
			this->lblReceiverAddress->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblReceiverAddress->Location = System::Drawing::Point(30, 145);
			this->lblReceiverAddress->Name = L"lblReceiverAddress";
			this->lblReceiverAddress->Size = System::Drawing::Size(129, 20);
			this->lblReceiverAddress->TabIndex = 4;
			this->lblReceiverAddress->Text = L"Receiver Address";
			// 
			// txtReceiverAddress
			// 
			this->txtReceiverAddress->Location = System::Drawing::Point(30, 170);
			this->txtReceiverAddress->MaxLength = 150;
			this->txtReceiverAddress->Name = L"txtReceiverAddress";
			this->txtReceiverAddress->Size = System::Drawing::Size(520, 27);
			this->txtReceiverAddress->TabIndex = 2;
			// 
			// lblReceiverCity
			// 
			this->lblReceiverCity->AutoSize = true;
			this->lblReceiverCity->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblReceiverCity->Location = System::Drawing::Point(575, 145);
			this->lblReceiverCity->Name = L"lblReceiverCity";
			this->lblReceiverCity->Size = System::Drawing::Size(99, 20);
			this->lblReceiverCity->TabIndex = 5;
			this->lblReceiverCity->Text = L"Receiver City";
			// 
			// txtReceiverCity
			// 
			this->txtReceiverCity->Location = System::Drawing::Point(575, 170);
			this->txtReceiverCity->MaxLength = 50;
			this->txtReceiverCity->Name = L"txtReceiverCity";
			this->txtReceiverCity->Size = System::Drawing::Size(250, 27);
			this->txtReceiverCity->TabIndex = 3;
			// 
			// lblDescription
			// 
			this->lblDescription->AutoSize = true;
			this->lblDescription->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblDescription->Location = System::Drawing::Point(30, 220);
			this->lblDescription->Name = L"lblDescription";
			this->lblDescription->Size = System::Drawing::Size(89, 20);
			this->lblDescription->TabIndex = 6;
			this->lblDescription->Text = L"Description";
			// 
			// txtDescription
			// 
			this->txtDescription->Location = System::Drawing::Point(30, 245);
			this->txtDescription->MaxLength = 120;
			this->txtDescription->Name = L"txtDescription";
			this->txtDescription->Size = System::Drawing::Size(795, 27);
			this->txtDescription->TabIndex = 4;
			// 
			// lblWeight
			// 
			this->lblWeight->AutoSize = true;
			this->lblWeight->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblWeight->Location = System::Drawing::Point(30, 295);
			this->lblWeight->Name = L"lblWeight";
			this->lblWeight->Size = System::Drawing::Size(93, 20);
			this->lblWeight->TabIndex = 7;
			this->lblWeight->Text = L"Weight (kg)";
			// 
			// txtWeight
			// 
			this->txtWeight->Location = System::Drawing::Point(30, 320);
			this->txtWeight->Name = L"txtWeight";
			this->txtWeight->Size = System::Drawing::Size(235, 27);
			this->txtWeight->TabIndex = 5;
			this->txtWeight->TextChanged += gcnew System::EventHandler(this, &EditParcelFormDesigner::txtWeight_TextChanged);
			// 
			// lblParcelType
			// 
			this->lblParcelType->AutoSize = true;
			this->lblParcelType->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblParcelType->Location = System::Drawing::Point(295, 295);
			this->lblParcelType->Name = L"lblParcelType";
			this->lblParcelType->Size = System::Drawing::Size(88, 20);
			this->lblParcelType->TabIndex = 8;
			this->lblParcelType->Text = L"Parcel Type";
			// 
			// cmbParcelType
			// 
			this->cmbParcelType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbParcelType->FormattingEnabled = true;
			this->cmbParcelType->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Document", L"Package", L"Fragile", L"Other" });
			this->cmbParcelType->Location = System::Drawing::Point(295, 320);
			this->cmbParcelType->Name = L"cmbParcelType";
			this->cmbParcelType->Size = System::Drawing::Size(235, 28);
			this->cmbParcelType->TabIndex = 6;
			// 
			// lblDeclaredValue
			// 
			this->lblDeclaredValue->AutoSize = true;
			this->lblDeclaredValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblDeclaredValue->Location = System::Drawing::Point(560, 295);
			this->lblDeclaredValue->Name = L"lblDeclaredValue";
			this->lblDeclaredValue->Size = System::Drawing::Size(156, 20);
			this->lblDeclaredValue->TabIndex = 9;
			this->lblDeclaredValue->Text = L"Declared Value (LKR)";
			// 
			// txtDeclaredValue
			// 
			this->txtDeclaredValue->Location = System::Drawing::Point(560, 320);
			this->txtDeclaredValue->Name = L"txtDeclaredValue";
			this->txtDeclaredValue->Size = System::Drawing::Size(265, 27);
			this->txtDeclaredValue->TabIndex = 7;
			// 
			// lblDeliveryOption
			// 
			this->lblDeliveryOption->AutoSize = true;
			this->lblDeliveryOption->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblDeliveryOption->Location = System::Drawing::Point(30, 370);
			this->lblDeliveryOption->Name = L"lblDeliveryOption";
			this->lblDeliveryOption->Size = System::Drawing::Size(119, 20);
			this->lblDeliveryOption->TabIndex = 10;
			this->lblDeliveryOption->Text = L"Delivery Option";
			// 
			// cmbDeliveryOption
			// 
			this->cmbDeliveryOption->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbDeliveryOption->FormattingEnabled = true;
			this->cmbDeliveryOption->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Standard", L"Express" });
			this->cmbDeliveryOption->Location = System::Drawing::Point(30, 395);
			this->cmbDeliveryOption->Name = L"cmbDeliveryOption";
			this->cmbDeliveryOption->Size = System::Drawing::Size(235, 28);
			this->cmbDeliveryOption->TabIndex = 8;
			this->cmbDeliveryOption->SelectedIndexChanged += gcnew System::EventHandler(this, &EditParcelFormDesigner::cmbDeliveryOption_SelectedIndexChanged);
			// 
			// lblPickupAddress
			// 
			this->lblPickupAddress->AutoSize = true;
			this->lblPickupAddress->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblPickupAddress->Location = System::Drawing::Point(295, 370);
			this->lblPickupAddress->Name = L"lblPickupAddress";
			this->lblPickupAddress->Size = System::Drawing::Size(116, 20);
			this->lblPickupAddress->TabIndex = 11;
			this->lblPickupAddress->Text = L"Pickup Address";
			// 
			// txtPickupAddress
			// 
			this->txtPickupAddress->Location = System::Drawing::Point(295, 395);
			this->txtPickupAddress->MaxLength = 150;
			this->txtPickupAddress->Name = L"txtPickupAddress";
			this->txtPickupAddress->Size = System::Drawing::Size(530, 27);
			this->txtPickupAddress->TabIndex = 9;
			// 
			// pnlCharge
			// 
			this->pnlCharge->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pnlCharge->Controls->Add(this->lblChargeTitle);
			this->pnlCharge->Controls->Add(this->lblCharge);
			this->pnlCharge->Location = System::Drawing::Point(30, 450);
			this->pnlCharge->Name = L"pnlCharge";
			this->pnlCharge->Size = System::Drawing::Size(250, 60);
			this->pnlCharge->TabIndex = 12;
			// 
			// lblChargeTitle
			// 
			this->lblChargeTitle->AutoSize = true;
			this->lblChargeTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->lblChargeTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblChargeTitle->Location = System::Drawing::Point(15, 8);
			this->lblChargeTitle->Name = L"lblChargeTitle";
			this->lblChargeTitle->Size = System::Drawing::Size(106, 19);
			this->lblChargeTitle->TabIndex = 0;
			this->lblChargeTitle->Text = L"Delivery Charge";
			// 
			// lblCharge
			// 
			this->lblCharge->AutoSize = true;
			this->lblCharge->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblCharge->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->lblCharge->Location = System::Drawing::Point(15, 28);
			this->lblCharge->Name = L"lblCharge";
			this->lblCharge->Size = System::Drawing::Size(95, 28);
			this->lblCharge->TabIndex = 1;
			this->lblCharge->Text = L"LKR 0.00";
			// 
			// lblEditNotice
			// 
			this->lblEditNotice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->lblEditNotice->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblEditNotice->Location = System::Drawing::Point(310, 450);
			this->lblEditNotice->Name = L"lblEditNotice";
			this->lblEditNotice->Size = System::Drawing::Size(515, 55);
			this->lblEditNotice->TabIndex = 13;
			this->lblEditNotice->Text = L"Only parcels with the status \"Order Placed\" can be edited. The delivery charge is"
				L" recalculated when the weight or delivery option changes.";
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
			this->btnSave->Location = System::Drawing::Point(635, 535);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(190, 40);
			this->btnSave->TabIndex = 10;
			this->btnSave->Text = L"Save Changes";
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &EditParcelFormDesigner::btnSave_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->BackColor = System::Drawing::Color::White;
			this->btnCancel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnCancel->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)),
				static_cast<System::Int32>(static_cast<System::Byte>(163)), static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->btnCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->btnCancel->Location = System::Drawing::Point(500, 535);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(120, 40);
			this->btnCancel->TabIndex = 11;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = false;
			this->btnCancel->Click += gcnew System::EventHandler(this, &EditParcelFormDesigner::btnCancel_Click);
			// 
			// EditParcelFormDesigner
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(252)));
			this->ClientSize = System::Drawing::Size(1000, 830);
			this->Controls->Add(this->pnlHeader);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->lblSubtitle);
			this->Controls->Add(this->pnlForm);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"EditParcelFormDesigner";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"CourierEase - Edit Parcel";
			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();
			this->pnlForm->ResumeLayout(false);
			this->pnlForm->PerformLayout();
			this->pnlCharge->ResumeLayout(false);
			this->pnlCharge->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private:

		void LoadParcelData()
		{
			try
			{
				System::Data::DataRow^ row =
					ParcelManagementRepository::GetParcelById(
						parcelId,
						customerId);

				if (row == nullptr)
				{
					System::Windows::Forms::MessageBox::Show(
						L"Parcel could not be found.",
						L"Edit Parcel",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Warning);

					this->Close();
					return;
				}

				this->lblTrackingNo->Text =
					row["tracking_no"]->ToString();

				this->txtReceiverName->Text =
					row["receiver_name"]->ToString();

				this->txtReceiverPhone->Text =
					row["receiver_phone"]->ToString();

				this->txtReceiverAddress->Text =
					row["receiver_address"]->ToString();

				this->txtReceiverCity->Text =
					row["receiver_city"]->ToString();

				this->txtDescription->Text =
					row["description"]->ToString();

				this->txtWeight->Text =
					System::String::Format(
						L"{0:0.00}",
						row["weight_kg"]);

				this->cmbParcelType->Text =
					row["parcel_type"]->ToString();

				this->txtDeclaredValue->Text =
					System::String::Format(
						L"{0:0.00}",
						row["declared_value"]);

				this->cmbDeliveryOption->Text =
					row["delivery_option"]->ToString();

				this->txtPickupAddress->Text =
					row["pickup_address"]->ToString();

				System::String^ status =
					row["status"]->ToString();

				bool canEdit =
					status == L"Order Placed";

				SetEditingEnabled(canEdit);

				if (!canEdit)
				{
					this->lblEditNotice->ForeColor =
						System::Drawing::Color::FromArgb(
							220,
							38,
							38);

					this->lblEditNotice->Text =
						L"This parcel can no longer be edited because "
						L"its current status is \"" +
						status +
						L"\".";
				}

				UpdateCharge();
			}
			catch (System::Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Unable to load parcel information.\n\n" +
					ex->Message,
					L"Database Error",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
			}
		}

		void SetEditingEnabled(bool enabled)
		{
			this->txtReceiverName->Enabled = enabled;
			this->txtReceiverPhone->Enabled = enabled;
			this->txtReceiverAddress->Enabled = enabled;
			this->txtReceiverCity->Enabled = enabled;
			this->txtDescription->Enabled = enabled;
			this->txtWeight->Enabled = enabled;
			this->cmbParcelType->Enabled = enabled;
			this->txtDeclaredValue->Enabled = enabled;
			this->cmbDeliveryOption->Enabled = enabled;
			this->txtPickupAddress->Enabled = enabled;
			this->btnSave->Enabled = enabled;
		}

		void ChargeInput_Changed(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			UpdateCharge();
		}

		double CalculateCurrentCharge()
		{
			double weight = 0.0;

			if (!System::Double::TryParse(
				this->txtWeight->Text->Trim(),
				weight))
			{
				return 0.0;
			}

			if (weight <= 0)
			{
				return 0.0;
			}

			System::String^ option =
				this->cmbDeliveryOption->Text;

			DeliveryService^ service = nullptr;

			if (option == L"Standard")
			{
				service =
					gcnew StandardDelivery();
			}
			else if (option == L"Express")
			{
				service =
					gcnew ExpressDelivery();
			}
			else
			{
				return 0.0;
			}

			return service->CalculateCharge(weight);
		}

		void UpdateCharge()
		{
			double charge =
				CalculateCurrentCharge();

			this->lblCharge->Text =
				System::String::Format(
					L"LKR {0:N2}",
					charge);
		}

		bool ValidateInputs(
			double% weight,
			double% declaredValue)
		{
			if (
				System::String::IsNullOrWhiteSpace(
					this->txtReceiverName->Text) ||
				System::String::IsNullOrWhiteSpace(
					this->txtReceiverPhone->Text) ||
				System::String::IsNullOrWhiteSpace(
					this->txtReceiverAddress->Text) ||
				System::String::IsNullOrWhiteSpace(
					this->txtReceiverCity->Text) ||
				System::String::IsNullOrWhiteSpace(
					this->txtDescription->Text) ||
				System::String::IsNullOrWhiteSpace(
					this->txtPickupAddress->Text))
			{
				System::Windows::Forms::MessageBox::Show(
					L"Please complete all required fields.",
					L"Validation",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Warning);

				return false;
			}

			if (this->cmbParcelType->SelectedIndex < 0)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Please select a parcel type.",
					L"Validation",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Warning);

				this->cmbParcelType->Focus();
				return false;
			}

			if (this->cmbDeliveryOption->SelectedIndex < 0)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Please select a delivery option.",
					L"Validation",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Warning);

				this->cmbDeliveryOption->Focus();
				return false;
			}

			if (
				!System::Double::TryParse(
					this->txtWeight->Text->Trim(),
					weight) ||
				weight <= 0)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Please enter a valid parcel weight greater than 0.",
					L"Validation",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Warning);

				this->txtWeight->Focus();
				return false;
			}

			if (
				!System::Double::TryParse(
					this->txtDeclaredValue->Text->Trim(),
					declaredValue) ||
				declaredValue < 0)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Please enter a valid declared value.",
					L"Validation",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Warning);

				this->txtDeclaredValue->Focus();
				return false;
			}

			return true;
		}

		void Save_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			double weight = 0.0;
			double declaredValue = 0.0;

			if (!ValidateInputs(
				weight,
				declaredValue))
			{
				return;
			}

			double charge =
				CalculateCurrentCharge();

			try
			{
				bool updated =
					ParcelManagementRepository::UpdateParcel(
						parcelId,
						customerId,
						this->txtReceiverName->Text->Trim(),
						this->txtReceiverPhone->Text->Trim(),
						this->txtReceiverAddress->Text->Trim(),
						this->txtReceiverCity->Text->Trim(),
						this->txtDescription->Text->Trim(),
						weight,
						this->cmbParcelType->Text,
						declaredValue,
						this->cmbDeliveryOption->Text,
						charge,
						this->txtPickupAddress->Text->Trim());

				if (!updated)
				{
					System::Windows::Forms::MessageBox::Show(
						L"The parcel could not be updated. "
						L"Only parcels with the status "
						L"\"Order Placed\" can be edited.",
						L"Update Failed",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Warning);

					return;
				}

				System::Windows::Forms::MessageBox::Show(
					L"Parcel updated successfully.",
					L"CourierEase",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Information);

				this->DialogResult =
					System::Windows::Forms::DialogResult::OK;

				this->Close();
			}
			catch (System::Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Unable to update the parcel.\n\n" +
					ex->Message,
					L"Database Error",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
			}
		}

		void Cancel_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->DialogResult =
				System::Windows::Forms::DialogResult::Cancel;

			this->Close();
		}

	private:

		System::Void lblBack_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Cancel_Click(sender, e);
		}

		System::Void btnSave_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Save_Click(sender, e);
		}

		System::Void btnCancel_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Cancel_Click(sender, e);
		}

		System::Void txtWeight_TextChanged(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			ChargeInput_Changed(sender, e);
		}

		System::Void cmbDeliveryOption_SelectedIndexChanged(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			ChargeInput_Changed(sender, e);
		}
	};
}