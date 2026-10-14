#pragma once

#include "Customer.h"
#include "CustomerRepository.h"
#include "PasswordHasher.h"

namespace CourrierEase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class RegisterFormDesigner : public System::Windows::Forms::Form
	{
	public:
		RegisterFormDesigner(void)
		{
			InitializeComponent();
		}

	protected:
		~RegisterFormDesigner()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Panel^ pnlHeader;

		System::Windows::Forms::Label^ lblBrand;
		System::Windows::Forms::Label^ lblBack;

		System::Windows::Forms::Panel^ pnlInfo;


		System::Windows::Forms::Label^ lblInfoTitle;
		System::Windows::Forms::Label^ lblInfoText;
		System::Windows::Forms::Label^ lblFeatures;
		System::Windows::Forms::Label^ lblCustomerOnly;

		System::Windows::Forms::Panel^ pnlRegister;
		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Label^ lblSubtitle;

		System::Windows::Forms::Label^ lblFullName;
		System::Windows::Forms::TextBox^ txtFullName;

		System::Windows::Forms::Label^ lblPhone;
		System::Windows::Forms::TextBox^ txtPhone;

		System::Windows::Forms::Label^ lblEmail;
		System::Windows::Forms::TextBox^ txtEmail;

		System::Windows::Forms::Label^ lblAddress;
		System::Windows::Forms::TextBox^ txtAddress;

		System::Windows::Forms::Label^ lblPassword;
		System::Windows::Forms::TextBox^ txtPassword;

		System::Windows::Forms::Label^ lblConfirmPassword;
		System::Windows::Forms::TextBox^ txtConfirmPassword;

		System::Windows::Forms::CheckBox^ chkShowPassword;

		System::Windows::Forms::Button^ btnRegister;

		System::Windows::Forms::Label^ lblLine;
		System::Windows::Forms::Label^ lblHaveAccount;
		System::Windows::Forms::LinkLabel^ linkLogin;
		System::Windows::Forms::Label^ lblPrivacy;
	private: System::Windows::Forms::PictureBox^ Regimg;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterFormDesigner::typeid));
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			this->lblBrand = (gcnew System::Windows::Forms::Label());
			this->lblBack = (gcnew System::Windows::Forms::Label());
			this->pnlInfo = (gcnew System::Windows::Forms::Panel());
			this->lblInfoTitle = (gcnew System::Windows::Forms::Label());
			this->lblInfoText = (gcnew System::Windows::Forms::Label());
			this->lblFeatures = (gcnew System::Windows::Forms::Label());
			this->lblCustomerOnly = (gcnew System::Windows::Forms::Label());
			this->pnlRegister = (gcnew System::Windows::Forms::Panel());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblSubtitle = (gcnew System::Windows::Forms::Label());
			this->lblFullName = (gcnew System::Windows::Forms::Label());
			this->txtFullName = (gcnew System::Windows::Forms::TextBox());
			this->lblPhone = (gcnew System::Windows::Forms::Label());
			this->txtPhone = (gcnew System::Windows::Forms::TextBox());
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->lblAddress = (gcnew System::Windows::Forms::Label());
			this->txtAddress = (gcnew System::Windows::Forms::TextBox());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblConfirmPassword = (gcnew System::Windows::Forms::Label());
			this->txtConfirmPassword = (gcnew System::Windows::Forms::TextBox());
			this->chkShowPassword = (gcnew System::Windows::Forms::CheckBox());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->lblLine = (gcnew System::Windows::Forms::Label());
			this->lblHaveAccount = (gcnew System::Windows::Forms::Label());
			this->linkLogin = (gcnew System::Windows::Forms::LinkLabel());
			this->lblPrivacy = (gcnew System::Windows::Forms::Label());
			this->Regimg = (gcnew System::Windows::Forms::PictureBox());
			this->pnlHeader->SuspendLayout();
			this->pnlInfo->SuspendLayout();
			this->pnlRegister->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Regimg))->BeginInit();
			this->SuspendLayout();
			// 
			// pnlHeader
			// 
			this->pnlHeader->BackColor = System::Drawing::Color::White;
			this->pnlHeader->Controls->Add(this->lblBrand);
			this->pnlHeader->Controls->Add(this->lblBack);
			this->pnlHeader->Location = System::Drawing::Point(0, 0);
			this->pnlHeader->Name = L"pnlHeader";
			this->pnlHeader->Size = System::Drawing::Size(1100, 65);
			this->pnlHeader->TabIndex = 0;
			// 
			// lblBrand
			// 
			this->lblBrand->AutoSize = true;
			this->lblBrand->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblBrand->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblBrand->Location = System::Drawing::Point(12, 15);
			this->lblBrand->Name = L"lblBrand";
			this->lblBrand->Size = System::Drawing::Size(123, 28);
			this->lblBrand->TabIndex = 1;
			this->lblBrand->Text = L"CourierEase";
			// 
			// lblBack
			// 
			this->lblBack->AutoSize = true;
			this->lblBack->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblBack->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblBack->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->lblBack->Location = System::Drawing::Point(930, 24);
			this->lblBack->Name = L"lblBack";
			this->lblBack->Size = System::Drawing::Size(122, 19);
			this->lblBack->TabIndex = 2;
			this->lblBack->Text = L"<  Back to Home";
			this->lblBack->Click += gcnew System::EventHandler(this, &RegisterFormDesigner::lblBack_Click);
			// 
			// pnlInfo
			// 
			this->pnlInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pnlInfo->Controls->Add(this->Regimg);
			this->pnlInfo->Controls->Add(this->lblInfoTitle);
			this->pnlInfo->Controls->Add(this->lblInfoText);
			this->pnlInfo->Controls->Add(this->lblFeatures);
			this->pnlInfo->Controls->Add(this->lblCustomerOnly);
			this->pnlInfo->Location = System::Drawing::Point(100, 100);
			this->pnlInfo->Name = L"pnlInfo";
			this->pnlInfo->Size = System::Drawing::Size(300, 520);
			this->pnlInfo->TabIndex = 1;
			// 
			// lblInfoTitle
			// 
			this->lblInfoTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->lblInfoTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblInfoTitle->Location = System::Drawing::Point(35, 165);
			this->lblInfoTitle->Name = L"lblInfoTitle";
			this->lblInfoTitle->Size = System::Drawing::Size(230, 40);
			this->lblInfoTitle->TabIndex = 1;
			this->lblInfoTitle->Text = L"Create your account";
			this->lblInfoTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblInfoText
			// 
			this->lblInfoText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblInfoText->Location = System::Drawing::Point(35, 215);
			this->lblInfoText->Name = L"lblInfoText";
			this->lblInfoText->Size = System::Drawing::Size(230, 60);
			this->lblInfoText->TabIndex = 2;
			this->lblInfoText->Text = L"Register as a customer to book parcels,\r\nmanage deliveries and track progress.";
			this->lblInfoText->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// lblFeatures
			// 
			this->lblFeatures->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblFeatures->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblFeatures->Location = System::Drawing::Point(55, 305);
			this->lblFeatures->Name = L"lblFeatures";
			this->lblFeatures->Size = System::Drawing::Size(200, 120);
			this->lblFeatures->TabIndex = 3;
			this->lblFeatures->Text = L"  Quick parcel booking\r\n\r\n  Delivery tracking\r\n\r\n  Delivery history";
			// 
			// lblCustomerOnly
			// 
			this->lblCustomerOnly->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblCustomerOnly->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->lblCustomerOnly->Location = System::Drawing::Point(50, 465);
			this->lblCustomerOnly->Name = L"lblCustomerOnly";
			this->lblCustomerOnly->Size = System::Drawing::Size(200, 25);
			this->lblCustomerOnly->TabIndex = 4;
			this->lblCustomerOnly->Text = L"Customer registration only";
			this->lblCustomerOnly->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pnlRegister
			// 
			this->pnlRegister->BackColor = System::Drawing::Color::White;
			this->pnlRegister->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlRegister->Controls->Add(this->lblTitle);
			this->pnlRegister->Controls->Add(this->lblSubtitle);
			this->pnlRegister->Controls->Add(this->lblFullName);
			this->pnlRegister->Controls->Add(this->txtFullName);
			this->pnlRegister->Controls->Add(this->lblPhone);
			this->pnlRegister->Controls->Add(this->txtPhone);
			this->pnlRegister->Controls->Add(this->lblEmail);
			this->pnlRegister->Controls->Add(this->txtEmail);
			this->pnlRegister->Controls->Add(this->lblAddress);
			this->pnlRegister->Controls->Add(this->txtAddress);
			this->pnlRegister->Controls->Add(this->lblPassword);
			this->pnlRegister->Controls->Add(this->txtPassword);
			this->pnlRegister->Controls->Add(this->lblConfirmPassword);
			this->pnlRegister->Controls->Add(this->txtConfirmPassword);
			this->pnlRegister->Controls->Add(this->chkShowPassword);
			this->pnlRegister->Controls->Add(this->btnRegister);
			this->pnlRegister->Controls->Add(this->lblLine);
			this->pnlRegister->Controls->Add(this->lblHaveAccount);
			this->pnlRegister->Controls->Add(this->linkLogin);
			this->pnlRegister->Controls->Add(this->lblPrivacy);
			this->pnlRegister->Location = System::Drawing::Point(490, 100);
			this->pnlRegister->Name = L"pnlRegister";
			this->pnlRegister->Size = System::Drawing::Size(500, 520);
			this->pnlRegister->TabIndex = 2;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
			this->lblTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblTitle->Location = System::Drawing::Point(35, 20);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(344, 37);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"Create Customer Account";
			// 
			// lblSubtitle
			// 
			this->lblSubtitle->AutoSize = true;
			this->lblSubtitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblSubtitle->Location = System::Drawing::Point(36, 58);
			this->lblSubtitle->Name = L"lblSubtitle";
			this->lblSubtitle->Size = System::Drawing::Size(244, 20);
			this->lblSubtitle->TabIndex = 1;
			this->lblSubtitle->Text = L"Enter your details below to register.";
			// 
			// lblFullName
			// 
			this->lblFullName->AutoSize = true;
			this->lblFullName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblFullName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblFullName->Location = System::Drawing::Point(35, 92);
			this->lblFullName->Name = L"lblFullName";
			this->lblFullName->Size = System::Drawing::Size(76, 19);
			this->lblFullName->TabIndex = 2;
			this->lblFullName->Text = L"Full Name";
			// 
			// txtFullName
			// 
			this->txtFullName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtFullName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtFullName->Location = System::Drawing::Point(35, 112);
			this->txtFullName->Name = L"txtFullName";
			this->txtFullName->Size = System::Drawing::Size(430, 30);
			this->txtFullName->TabIndex = 0;
			// 
			// lblPhone
			// 
			this->lblPhone->AutoSize = true;
			this->lblPhone->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblPhone->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblPhone->Location = System::Drawing::Point(35, 157);
			this->lblPhone->Name = L"lblPhone";
			this->lblPhone->Size = System::Drawing::Size(110, 19);
			this->lblPhone->TabIndex = 3;
			this->lblPhone->Text = L"Phone Number";
			// 
			// txtPhone
			// 
			this->txtPhone->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPhone->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtPhone->Location = System::Drawing::Point(35, 177);
			this->txtPhone->Name = L"txtPhone";
			this->txtPhone->Size = System::Drawing::Size(205, 30);
			this->txtPhone->TabIndex = 1;
			// 
			// lblEmail
			// 
			this->lblEmail->AutoSize = true;
			this->lblEmail->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblEmail->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblEmail->Location = System::Drawing::Point(260, 157);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(103, 19);
			this->lblEmail->TabIndex = 4;
			this->lblEmail->Text = L"Email Address";
			// 
			// txtEmail
			// 
			this->txtEmail->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtEmail->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtEmail->Location = System::Drawing::Point(260, 177);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(205, 30);
			this->txtEmail->TabIndex = 2;
			// 
			// lblAddress
			// 
			this->lblAddress->AutoSize = true;
			this->lblAddress->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblAddress->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblAddress->Location = System::Drawing::Point(35, 222);
			this->lblAddress->Name = L"lblAddress";
			this->lblAddress->Size = System::Drawing::Size(63, 19);
			this->lblAddress->TabIndex = 5;
			this->lblAddress->Text = L"Address";
			// 
			// txtAddress
			// 
			this->txtAddress->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtAddress->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtAddress->Location = System::Drawing::Point(35, 242);
			this->txtAddress->Name = L"txtAddress";
			this->txtAddress->Size = System::Drawing::Size(430, 30);
			this->txtAddress->TabIndex = 3;
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblPassword->Location = System::Drawing::Point(35, 287);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(73, 19);
			this->lblPassword->TabIndex = 6;
			this->lblPassword->Text = L"Password";
			// 
			// txtPassword
			// 
			this->txtPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtPassword->Location = System::Drawing::Point(35, 307);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(205, 30);
			this->txtPassword->TabIndex = 4;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// lblConfirmPassword
			// 
			this->lblConfirmPassword->AutoSize = true;
			this->lblConfirmPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblConfirmPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblConfirmPassword->Location = System::Drawing::Point(260, 287);
			this->lblConfirmPassword->Name = L"lblConfirmPassword";
			this->lblConfirmPassword->Size = System::Drawing::Size(131, 19);
			this->lblConfirmPassword->TabIndex = 7;
			this->lblConfirmPassword->Text = L"Confirm Password";
			// 
			// txtConfirmPassword
			// 
			this->txtConfirmPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtConfirmPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtConfirmPassword->Location = System::Drawing::Point(260, 307);
			this->txtConfirmPassword->Name = L"txtConfirmPassword";
			this->txtConfirmPassword->Size = System::Drawing::Size(205, 30);
			this->txtConfirmPassword->TabIndex = 5;
			this->txtConfirmPassword->UseSystemPasswordChar = true;
			// 
			// chkShowPassword
			// 
			this->chkShowPassword->AutoSize = true;
			this->chkShowPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7));
			this->chkShowPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->chkShowPassword->Location = System::Drawing::Point(35, 343);
			this->chkShowPassword->Name = L"chkShowPassword";
			this->chkShowPassword->Size = System::Drawing::Size(116, 19);
			this->chkShowPassword->TabIndex = 6;
			this->chkShowPassword->Text = L"Show passwords";
			this->chkShowPassword->UseVisualStyleBackColor = true;
			this->chkShowPassword->CheckedChanged += gcnew System::EventHandler(this, &RegisterFormDesigner::chkShowPassword_CheckedChanged);
			// 
			// btnRegister
			// 
			this->btnRegister->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnRegister->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRegister->FlatAppearance->BorderSize = 0;
			this->btnRegister->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRegister->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnRegister->ForeColor = System::Drawing::Color::White;
			this->btnRegister->Location = System::Drawing::Point(35, 370);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(430, 42);
			this->btnRegister->TabIndex = 7;
			this->btnRegister->Text = L"Create Account";
			this->btnRegister->UseVisualStyleBackColor = false;
			this->btnRegister->Click += gcnew System::EventHandler(this, &RegisterFormDesigner::btnRegister_Click);
			// 
			// lblLine
			// 
			this->lblLine->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->lblLine->Location = System::Drawing::Point(35, 435);
			this->lblLine->Name = L"lblLine";
			this->lblLine->Size = System::Drawing::Size(430, 1);
			this->lblLine->TabIndex = 8;
			// 
			// lblHaveAccount
			// 
			this->lblHaveAccount->AutoSize = true;
			this->lblHaveAccount->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblHaveAccount->Location = System::Drawing::Point(145, 455);
			this->lblHaveAccount->Name = L"lblHaveAccount";
			this->lblHaveAccount->Size = System::Drawing::Size(178, 20);
			this->lblHaveAccount->TabIndex = 9;
			this->lblHaveAccount->Text = L"Already have an account\?";
			// 
			// linkLogin
			// 
			this->linkLogin->AutoSize = true;
			this->linkLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->linkLogin->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->linkLogin->Location = System::Drawing::Point(330, 456);
			this->linkLogin->Name = L"linkLogin";
			this->linkLogin->Size = System::Drawing::Size(46, 19);
			this->linkLogin->TabIndex = 8;
			this->linkLogin->TabStop = true;
			this->linkLogin->Text = L"Login";
			this->linkLogin->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &RegisterFormDesigner::linkLogin_LinkClicked);
			// 
			// lblPrivacy
			// 
			this->lblPrivacy->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7));
			this->lblPrivacy->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->lblPrivacy->Location = System::Drawing::Point(65, 490);
			this->lblPrivacy->Name = L"lblPrivacy";
			this->lblPrivacy->Size = System::Drawing::Size(370, 20);
			this->lblPrivacy->TabIndex = 10;
			this->lblPrivacy->Text = L"Your account details are used only for CourierEase delivery management.";
			this->lblPrivacy->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Regimg
			// 
			this->Regimg->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Regimg.Image")));
			this->Regimg->Location = System::Drawing::Point(46, 4);
			this->Regimg->Name = L"Regimg";
			this->Regimg->Size = System::Drawing::Size(209, 158);
			this->Regimg->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->Regimg->TabIndex = 5;
			this->Regimg->TabStop = false;
			// 
			// RegisterFormDesigner
			// 
			this->AcceptButton = this->btnRegister;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(252)));
			this->ClientSize = System::Drawing::Size(1100, 700);
			this->Controls->Add(this->pnlHeader);
			this->Controls->Add(this->pnlInfo);
			this->Controls->Add(this->pnlRegister);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"RegisterFormDesigner";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CourierEase - Customer Registration";
			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();
			this->pnlInfo->ResumeLayout(false);
			this->pnlRegister->ResumeLayout(false);
			this->pnlRegister->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Regimg))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion

	private:

		void btnRegister_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			String^ fullName =
				txtFullName->Text->Trim();

			String^ phone =
				txtPhone->Text->Trim();

			String^ email =
				txtEmail->Text->Trim();

			String^ address =
				txtAddress->Text->Trim();

			String^ password =
				txtPassword->Text;

			String^ confirmPassword =
				txtConfirmPassword->Text;

			if (
				String::IsNullOrWhiteSpace(fullName) ||
				String::IsNullOrWhiteSpace(phone) ||
				String::IsNullOrWhiteSpace(email) ||
				String::IsNullOrWhiteSpace(address) ||
				String::IsNullOrWhiteSpace(password) ||
				String::IsNullOrWhiteSpace(confirmPassword)
				)
			{
				MessageBox::Show(
					L"Please complete all fields.",
					L"Registration",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);

				return;
			}

			if (
				!email->Contains(L"@") ||
				!email->Contains(L".")
				)
			{
				MessageBox::Show(
					L"Please enter a valid email address.",
					L"Registration",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);

				return;
			}

			if (
				phone->Length < 9 ||
				phone->Length > 15
				)
			{
				MessageBox::Show(
					L"Please enter a valid phone number.",
					L"Registration",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);

				return;
			}

			if (password->Length < 6)
			{
				MessageBox::Show(
					L"Password must contain at least 6 characters.",
					L"Registration",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);

				return;
			}

			if (password != confirmPassword)
			{
				MessageBox::Show(
					L"Passwords do not match.",
					L"Registration",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);

				return;
			}

			try
			{
				Customer^ customer =
					gcnew Customer();

				customer->FullName =
					fullName;

				customer->Phone =
					phone;

				customer->Email =
					email;

				customer->Address =
					address;

				String^ passwordHash =
					PasswordHasher::HashPassword(
						password
					);

				bool success =
					CustomerRepository::CreateCustomer(
						customer,
						passwordHash
					);

				if (success)
				{
					MessageBox::Show(
						L"Account created successfully!",
						L"CourierEase",
						MessageBoxButtons::OK,
						MessageBoxIcon::Information
					);

					ClearForm();
				}
				else
				{
					MessageBox::Show(
						L"Account could not be created.",
						L"CourierEase",
						MessageBoxButtons::OK,
						MessageBoxIcon::Error
					);
				}
			}
			catch (MySqlException^ ex)
			{
				if (ex->Number == 1062)
				{
					MessageBox::Show(
						L"An account with this email already exists.",
						L"Registration",
						MessageBoxButtons::OK,
						MessageBoxIcon::Warning
					);
				}
				else
				{
					MessageBox::Show(
						L"Unable to create the account. "
						L"Please check the database connection.",
						L"Database Error",
						MessageBoxButtons::OK,
						MessageBoxIcon::Error
					);
				}
			}
			catch (Exception^)
			{
				MessageBox::Show(
					L"An unexpected error occurred.",
					L"CourierEase",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
			}
		}


		void chkShowPassword_CheckedChanged(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			bool hidePassword =
				!chkShowPassword->Checked;

			txtPassword->UseSystemPasswordChar =
				hidePassword;

			txtConfirmPassword->UseSystemPasswordChar =
				hidePassword;
		}


		void lblBack_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->Close();
		}


		void linkLogin_LinkClicked(
			System::Object^ sender,
			System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
		{
			this->Close();
		}


		void ClearForm()
		{
			txtFullName->Clear();
			txtPhone->Clear();
			txtEmail->Clear();
			txtAddress->Clear();
			txtPassword->Clear();
			txtConfirmPassword->Clear();

			chkShowPassword->Checked =
				false;

			txtFullName->Focus();
		}
	};
}