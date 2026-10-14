#pragma once

#include "RegisterFormDesigner.h"
#include "LoginFormDesigner.h"
#include "AdminLoginDesigner.h"
#include "TrackingRepository.h"

namespace CourrierEase
{
	public ref class MainForm :
		public System::Windows::Forms::Form
	{
	public:

		MainForm(void)
		{
			InitializeComponent();
		}

	protected:

		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		System::Windows::Forms::Panel^ pnlHeader;


		System::Windows::Forms::Label^ lblBrand;
		System::Windows::Forms::Label^ lblHome;
		System::Windows::Forms::Label^ lblServices;
		System::Windows::Forms::Label^ lblTrackNav;
		System::Windows::Forms::Label^ lblAbout;

		System::Windows::Forms::Button^ btnLogin;
		System::Windows::Forms::Button^ btnRegister;


		System::Windows::Forms::Label^ lblHeroTitle;
		System::Windows::Forms::Label^ lblHeroText;

		System::Windows::Forms::Button^ btnBookParcel;
		System::Windows::Forms::Button^ btnTrackHero;









		System::Windows::Forms::Panel^ pnlTracking;
		System::Windows::Forms::Label^ lblTrackTitle;
		System::Windows::Forms::TextBox^ txtTracking;
		System::Windows::Forms::Button^ btnTrackParcel;

		System::Windows::Forms::Label^ lblServicesTitle;










	private: System::Windows::Forms::PictureBox^ pictureBoxHero;
	private: System::Windows::Forms::Label^ lblStandardText;
	private: System::Windows::Forms::Label^ lblStandardTitle;
	private: System::Windows::Forms::Label^ lblExpressTitle;
	private: System::Windows::Forms::Label^ lblExpressText;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;


		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			this->lblBrand = (gcnew System::Windows::Forms::Label());
			this->lblHome = (gcnew System::Windows::Forms::Label());
			this->lblServices = (gcnew System::Windows::Forms::Label());
			this->lblTrackNav = (gcnew System::Windows::Forms::Label());
			this->lblAbout = (gcnew System::Windows::Forms::Label());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->lblHeroTitle = (gcnew System::Windows::Forms::Label());
			this->lblHeroText = (gcnew System::Windows::Forms::Label());
			this->btnBookParcel = (gcnew System::Windows::Forms::Button());
			this->btnTrackHero = (gcnew System::Windows::Forms::Button());
			this->pnlTracking = (gcnew System::Windows::Forms::Panel());
			this->lblTrackTitle = (gcnew System::Windows::Forms::Label());
			this->txtTracking = (gcnew System::Windows::Forms::TextBox());
			this->btnTrackParcel = (gcnew System::Windows::Forms::Button());
			this->lblServicesTitle = (gcnew System::Windows::Forms::Label());
			this->pictureBoxHero = (gcnew System::Windows::Forms::PictureBox());
			this->lblStandardText = (gcnew System::Windows::Forms::Label());
			this->lblStandardTitle = (gcnew System::Windows::Forms::Label());
			this->lblExpressTitle = (gcnew System::Windows::Forms::Label());
			this->lblExpressText = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pnlHeader->SuspendLayout();
			this->pnlTracking->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHero))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlHeader
			// 
			this->pnlHeader->Controls->Add(this->lblBrand);
			this->pnlHeader->Controls->Add(this->lblHome);
			this->pnlHeader->Controls->Add(this->lblServices);
			this->pnlHeader->Controls->Add(this->lblTrackNav);
			this->pnlHeader->Controls->Add(this->lblAbout);
			this->pnlHeader->Controls->Add(this->btnLogin);
			this->pnlHeader->Controls->Add(this->btnRegister);
			this->pnlHeader->Location = System::Drawing::Point(0, 0);
			this->pnlHeader->Name = L"pnlHeader";
			this->pnlHeader->Size = System::Drawing::Size(1100, 65);
			this->pnlHeader->TabIndex = 0;
			// 
			// lblBrand
			// 
			this->lblBrand->AutoSize = true;
			this->lblBrand->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			this->lblBrand->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblBrand->Location = System::Drawing::Point(12, 17);
			this->lblBrand->Name = L"lblBrand";
			this->lblBrand->Size = System::Drawing::Size(135, 30);
			this->lblBrand->TabIndex = 1;
			this->lblBrand->Text = L"CourierEase";
			// 
			// lblHome
			// 
			this->lblHome->AutoSize = true;
			this->lblHome->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblHome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->lblHome->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->lblHome->Location = System::Drawing::Point(590, 25);
			this->lblHome->Name = L"lblHome";
			this->lblHome->Size = System::Drawing::Size(46, 19);
			this->lblHome->TabIndex = 2;
			this->lblHome->Text = L"Home";
			// 
			// lblServices
			// 
			this->lblServices->AutoSize = true;
			this->lblServices->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblServices->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->lblServices->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->lblServices->Location = System::Drawing::Point(655, 25);
			this->lblServices->Name = L"lblServices";
			this->lblServices->Size = System::Drawing::Size(57, 19);
			this->lblServices->TabIndex = 3;
			this->lblServices->Text = L"Services";
			this->lblServices->Click += gcnew System::EventHandler(this, &MainForm::lblServices_Click);
			// 
			// lblTrackNav
			// 
			this->lblTrackNav->AutoSize = true;
			this->lblTrackNav->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblTrackNav->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->lblTrackNav->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->lblTrackNav->Location = System::Drawing::Point(725, 25);
			this->lblTrackNav->Name = L"lblTrackNav";
			this->lblTrackNav->Size = System::Drawing::Size(80, 19);
			this->lblTrackNav->TabIndex = 4;
			this->lblTrackNav->Text = L"Track Parcel";
			this->lblTrackNav->Click += gcnew System::EventHandler(this, &MainForm::lblTrackNav_Click);
			// 
			// lblAbout
			// 
			this->lblAbout->AutoSize = true;
			this->lblAbout->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblAbout->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->lblAbout->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->lblAbout->Location = System::Drawing::Point(815, 25);
			this->lblAbout->Name = L"lblAbout";
			this->lblAbout->Size = System::Drawing::Size(49, 19);
			this->lblAbout->TabIndex = 5;
			this->lblAbout->Text = L"Admin";
			this->lblAbout->Click += gcnew System::EventHandler(this, &MainForm::lblAbout_Click);
			// 
			// btnLogin
			// 
			this->btnLogin->BackColor = System::Drawing::Color::White;
			this->btnLogin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnLogin->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnLogin->Location = System::Drawing::Point(900, 17);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(70, 34);
			this->btnLogin->TabIndex = 0;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &MainForm::btnLogin_Click);
			// 
			// btnRegister
			// 
			this->btnRegister->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnRegister->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRegister->FlatAppearance->BorderSize = 0;
			this->btnRegister->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRegister->ForeColor = System::Drawing::Color::White;
			this->btnRegister->Location = System::Drawing::Point(980, 17);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(80, 34);
			this->btnRegister->TabIndex = 1;
			this->btnRegister->Text = L"Register";
			this->btnRegister->UseVisualStyleBackColor = false;
			this->btnRegister->Click += gcnew System::EventHandler(this, &MainForm::btnRegister_Click);
			// 
			// lblHeroTitle
			// 
			this->lblHeroTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 25, System::Drawing::FontStyle::Bold));
			this->lblHeroTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblHeroTitle->Location = System::Drawing::Point(12, 84);
			this->lblHeroTitle->Name = L"lblHeroTitle";
			this->lblHeroTitle->Size = System::Drawing::Size(480, 110);
			this->lblHeroTitle->TabIndex = 2;
			this->lblHeroTitle->Text = L"Your Parcels,\r\nDelivered with Care.";
			// 
			// lblHeroText
			// 
			this->lblHeroText->BackColor = System::Drawing::Color::WhiteSmoke;
			this->lblHeroText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblHeroText->ForeColor = System::Drawing::Color::Black;
			this->lblHeroText->Location = System::Drawing::Point(18, 210);
			this->lblHeroText->Name = L"lblHeroText";
			this->lblHeroText->Size = System::Drawing::Size(480, 50);
			this->lblHeroText->TabIndex = 3;
			this->lblHeroText->Text = L"Book deliveries, manage your parcels, and track every shipment\r\nfrom one simple d"
				L"esktop application.";
			// 
			// btnBookParcel
			// 
			this->btnBookParcel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnBookParcel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnBookParcel->FlatAppearance->BorderSize = 0;
			this->btnBookParcel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBookParcel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnBookParcel->ForeColor = System::Drawing::Color::White;
			this->btnBookParcel->Location = System::Drawing::Point(22, 286);
			this->btnBookParcel->Name = L"btnBookParcel";
			this->btnBookParcel->Size = System::Drawing::Size(115, 38);
			this->btnBookParcel->TabIndex = 2;
			this->btnBookParcel->Text = L"Book a Parcel";
			this->btnBookParcel->UseVisualStyleBackColor = false;
			this->btnBookParcel->Click += gcnew System::EventHandler(this, &MainForm::btnBookParcel_Click);
			// 
			// btnTrackHero
			// 
			this->btnTrackHero->BackColor = System::Drawing::Color::White;
			this->btnTrackHero->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnTrackHero->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnTrackHero->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTrackHero->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnTrackHero->Location = System::Drawing::Point(144, 286);
			this->btnTrackHero->Name = L"btnTrackHero";
			this->btnTrackHero->Size = System::Drawing::Size(110, 38);
			this->btnTrackHero->TabIndex = 3;
			this->btnTrackHero->Text = L"Track Parcel";
			this->btnTrackHero->UseVisualStyleBackColor = false;
			this->btnTrackHero->Click += gcnew System::EventHandler(this, &MainForm::btnTrackHero_Click);
			// 
			// pnlTracking
			// 
			this->pnlTracking->BackColor = System::Drawing::Color::White;
			this->pnlTracking->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlTracking->Controls->Add(this->lblTrackTitle);
			this->pnlTracking->Controls->Add(this->txtTracking);
			this->pnlTracking->Controls->Add(this->btnTrackParcel);
			this->pnlTracking->Location = System::Drawing::Point(22, 353);
			this->pnlTracking->Name = L"pnlTracking";
			this->pnlTracking->Size = System::Drawing::Size(511, 127);
			this->pnlTracking->TabIndex = 5;
			// 
			// lblTrackTitle
			// 
			this->lblTrackTitle->AutoSize = true;
			this->lblTrackTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblTrackTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblTrackTitle->Location = System::Drawing::Point(11, 19);
			this->lblTrackTitle->Name = L"lblTrackTitle";
			this->lblTrackTitle->Size = System::Drawing::Size(174, 28);
			this->lblTrackTitle->TabIndex = 0;
			this->lblTrackTitle->Text = L"Track Your Parcel";
			// 
			// txtTracking
			// 
			this->txtTracking->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtTracking->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtTracking->Location = System::Drawing::Point(16, 50);
			this->txtTracking->Name = L"txtTracking";
			this->txtTracking->Size = System::Drawing::Size(310, 30);
			this->txtTracking->TabIndex = 0;
			this->txtTracking->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::txtTracking_KeyDown);
			// 
			// btnTrackParcel
			// 
			this->btnTrackParcel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnTrackParcel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnTrackParcel->FlatAppearance->BorderSize = 0;
			this->btnTrackParcel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTrackParcel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnTrackParcel->ForeColor = System::Drawing::Color::White;
			this->btnTrackParcel->Location = System::Drawing::Point(332, 46);
			this->btnTrackParcel->Name = L"btnTrackParcel";
			this->btnTrackParcel->Size = System::Drawing::Size(102, 36);
			this->btnTrackParcel->TabIndex = 1;
			this->btnTrackParcel->Text = L"Track Parcel";
			this->btnTrackParcel->UseVisualStyleBackColor = false;
			this->btnTrackParcel->Click += gcnew System::EventHandler(this, &MainForm::btnTrackParcel_Click);
			// 
			// lblServicesTitle
			// 
			this->lblServicesTitle->AutoSize = true;
			this->lblServicesTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->lblServicesTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblServicesTitle->Location = System::Drawing::Point(325, 502);
			this->lblServicesTitle->Name = L"lblServicesTitle";
			this->lblServicesTitle->Size = System::Drawing::Size(268, 35);
			this->lblServicesTitle->TabIndex = 6;
			this->lblServicesTitle->Text = L"Our Delivery Services";
			// 
			// pictureBoxHero
			// 
			this->pictureBoxHero->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxHero.Image")));
			this->pictureBoxHero->Location = System::Drawing::Point(559, 84);
			this->pictureBoxHero->Name = L"pictureBoxHero";
			this->pictureBoxHero->Size = System::Drawing::Size(501, 396);
			this->pictureBoxHero->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxHero->TabIndex = 9;
			this->pictureBoxHero->TabStop = false;
			// 
			// lblStandardText
			// 
			this->lblStandardText->AutoSize = true;
			this->lblStandardText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblStandardText->Location = System::Drawing::Point(13, 47);
			this->lblStandardText->Name = L"lblStandardText";
			this->lblStandardText->Size = System::Drawing::Size(348, 20);
			this->lblStandardText->TabIndex = 2;
			this->lblStandardText->Text = L"Affordable and reliable delivery for regular parcels.";
			// 
			// lblStandardTitle
			// 
			this->lblStandardTitle->AutoSize = true;
			this->lblStandardTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->lblStandardTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblStandardTitle->Location = System::Drawing::Point(13, 15);
			this->lblStandardTitle->Name = L"lblStandardTitle";
			this->lblStandardTitle->Size = System::Drawing::Size(156, 23);
			this->lblStandardTitle->TabIndex = 1;
			this->lblStandardTitle->Text = L"Standard Delivery";
			// 
			// lblExpressTitle
			// 
			this->lblExpressTitle->AutoSize = true;
			this->lblExpressTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->lblExpressTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblExpressTitle->Location = System::Drawing::Point(13, 15);
			this->lblExpressTitle->Name = L"lblExpressTitle";
			this->lblExpressTitle->Size = System::Drawing::Size(141, 23);
			this->lblExpressTitle->TabIndex = 1;
			this->lblExpressTitle->Text = L"Express Delivery";
			// 
			// lblExpressText
			// 
			this->lblExpressText->AutoSize = true;
			this->lblExpressText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblExpressText->Location = System::Drawing::Point(13, 47);
			this->lblExpressText->Name = L"lblExpressText";
			this->lblExpressText->Size = System::Drawing::Size(284, 20);
			this->lblExpressText->TabIndex = 2;
			this->lblExpressText->Text = L"Faster delivery when your parcel is urgent.";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(22, 490);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(280, 198);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Lavender;
			this->panel1->Controls->Add(this->lblStandardTitle);
			this->panel1->Controls->Add(this->lblStandardText);
			this->panel1->Location = System::Drawing::Point(308, 564);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(371, 84);
			this->panel1->TabIndex = 11;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::LavenderBlush;
			this->panel2->Controls->Add(this->lblExpressText);
			this->panel2->Controls->Add(this->lblExpressTitle);
			this->panel2->Location = System::Drawing::Point(685, 564);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(375, 84);
			this->panel2->TabIndex = 12;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(1100, 700);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBoxHero);
			this->Controls->Add(this->pnlHeader);
			this->Controls->Add(this->lblHeroTitle);
			this->Controls->Add(this->lblHeroText);
			this->Controls->Add(this->btnBookParcel);
			this->Controls->Add(this->btnTrackHero);
			this->Controls->Add(this->pnlTracking);
			this->Controls->Add(this->lblServicesTitle);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CourierEase";
			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();
			this->pnlTracking->ResumeLayout(false);
			this->pnlTracking->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHero))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private:

		System::Void btnLogin_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			LoginFormDesigner^ loginForm =
				gcnew LoginFormDesigner();

			this->Hide();

			loginForm->ShowDialog();

			delete loginForm;

			if (!this->IsDisposed)
			{
				this->Show();
			}
		}


		System::Void btnRegister_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			RegisterFormDesigner^ registerForm =
				gcnew RegisterFormDesigner();

			this->Hide();

			registerForm->ShowDialog();

			delete registerForm;

			if (!this->IsDisposed)
			{
				this->Show();
			}
		}


		System::Void btnBookParcel_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			LoginFormDesigner^ loginForm =
				gcnew LoginFormDesigner();

			this->Hide();

			loginForm->ShowDialog();

			delete loginForm;

			if (!this->IsDisposed)
			{
				this->Show();
			}
		}


		System::Void btnTrackHero_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->txtTracking->Focus();
		}


		System::Void lblTrackNav_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->txtTracking->Focus();
		}


		System::Void lblServices_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->lblServicesTitle->Focus();
		}


		System::Void lblAbout_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			AdminLoginDesigner^ adminLogin =
				gcnew AdminLoginDesigner();

			this->Hide();

			adminLogin->ShowDialog();

			delete adminLogin;

			if (!this->IsDisposed)
			{
				this->Show();
			}
		}


		System::Void txtTracking_KeyDown(
			System::Object^ sender,
			System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyCode ==
				System::Windows::Forms::Keys::Enter)
			{
				e->SuppressKeyPress = true;
				TrackParcel();
			}
		}


		System::Void btnTrackParcel_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			TrackParcel();
		}


		void TrackParcel()
		{
			System::String^ tracking =
				this->txtTracking->Text->Trim();

			if (System::String::IsNullOrWhiteSpace(
				tracking))
			{
				this->txtTracking->Focus();

				System::Windows::Forms::MessageBox::Show(
					L"Please enter a tracking number.",
					L"Track Parcel",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Information);

				return;
			}

			try
			{
				System::Data::DataRow^ row =
					TrackingRepository::GetTrackingDetails(
						tracking);

				if (row == nullptr)
				{
					System::Windows::Forms::MessageBox::Show(
						L"No parcel was found for tracking number:\n\n" +
						tracking +
						L"\n\nPlease check the tracking number and try again.",
						L"Parcel Not Found",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Information);

					this->txtTracking->SelectAll();
					this->txtTracking->Focus();

					return;
				}

				System::String^ trackingNo =
					row["tracking_no"]->ToString();

				System::String^ receiverName =
					row["receiver_name"]->ToString();

				System::String^ receiverCity =
					row["receiver_city"]->ToString();

				System::String^ parcelType =
					row["parcel_type"]->ToString();

				System::String^ deliveryOption =
					row["delivery_option"]->ToString();

				System::String^ status =
					row["status"]->ToString();

				System::String^ charge =
					System::Convert::ToDecimal(
						row["charge"]
					).ToString("0.00");

				System::String^ createdDate =
					System::Convert::ToDateTime(
						row["created_at"]
					).ToString(
						"dd MMM yyyy hh:mm tt");

				System::String^ deliveryBoy =
					L"Not Assigned";

				if (
					row["delivery_boy"] !=
					System::DBNull::Value &&
					!System::String::IsNullOrWhiteSpace(
						row["delivery_boy"]->ToString())
					)
				{
					deliveryBoy =
						row["delivery_boy"]->ToString();
				}

				System::Data::DataTable^ history =
					TrackingRepository::GetTrackingHistory(
						trackingNo);

				System::String^ historyText =
					L"";

				if (
					history != nullptr &&
					history->Rows->Count > 0
					)
				{
					for each (
						System::Data::DataRow ^ historyRow
						in history->Rows)
					{
						System::String^ historyStatus =
							historyRow["status"]->ToString();

						System::String^ historyDate =
							System::Convert::ToDateTime(
								historyRow["changed_at"]
							).ToString(
								"dd MMM yyyy hh:mm tt"
							);

						historyText +=
							L"\n" +
							historyStatus +
							L"  -  " +
							historyDate;
					}
				}
				else
				{
					historyText =
						L"\nNo status history available.";
				}

				System::String^ message =
					L"Tracking Number: " +
					trackingNo +
					L"\n\nReceiver: " +
					receiverName +
					L"\nDestination: " +
					receiverCity +
					L"\nParcel Type: " +
					parcelType +
					L"\nDelivery Service: " +
					deliveryOption +
					L"\nDelivery Charge: Rs. " +
					charge +
					L"\n\nCurrent Status: " +
					status +
					L"\nDelivery Staff: " +
					deliveryBoy +
					L"\nBooked On: " +
					createdDate +
					L"\n\nStatus History:" +
					historyText;

				System::Windows::Forms::MessageBoxIcon icon =
					System::Windows::Forms::MessageBoxIcon::Information;

				if (
					System::String::Equals(
						status,
						L"Delivered",
						System::StringComparison::OrdinalIgnoreCase)
					)
				{
					icon =
						System::Windows::Forms::MessageBoxIcon::Information;
				}

				System::Windows::Forms::MessageBox::Show(
					message,
					L"Parcel Tracking - " +
					trackingNo,
					System::Windows::Forms::MessageBoxButtons::OK,
					icon);
			}
			catch (System::Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Unable to retrieve parcel tracking information.\n\n" +
					ex->Message,
					L"Tracking Error",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
			}
		}
	};
}