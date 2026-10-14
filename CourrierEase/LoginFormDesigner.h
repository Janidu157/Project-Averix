#pragma once

#include "CustomerRepository.h"
#include "PasswordHasher.h"
#include "RegisterFormDesigner.h"
#include "CustomerDashboardDesigner.h"

using namespace MySql::Data::MySqlClient;

namespace CourrierEase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginFormDesigner
	/// </summary>
	public ref class LoginFormDesigner : public System::Windows::Forms::Form
	{
	public:
		LoginFormDesigner(void)
		{
			InitializeComponent();
		}

	protected:
		~LoginFormDesigner()
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


		System::Windows::Forms::Label^ lblWelcome;
		System::Windows::Forms::Label^ lblInfo;
		System::Windows::Forms::Label^ lblFeature1;
		System::Windows::Forms::Label^ lblFeature2;
		System::Windows::Forms::Label^ lblFeature3;

		System::Windows::Forms::Panel^ pnlLoginCard;
		System::Windows::Forms::Label^ lblLoginTitle;
		System::Windows::Forms::Label^ lblLoginSubtitle;

		System::Windows::Forms::Label^ lblEmail;
		System::Windows::Forms::TextBox^ txtEmail;

		System::Windows::Forms::Label^ lblPassword;
		System::Windows::Forms::TextBox^ txtPassword;
		System::Windows::Forms::Button^ btnShowPassword;

		System::Windows::Forms::CheckBox^ chkRemember;
		System::Windows::Forms::LinkLabel^ linkForgotPassword;

		System::Windows::Forms::Button^ btnLogin;

		System::Windows::Forms::Panel^ pnlDivider;

		System::Windows::Forms::Label^ lblNoAccount;
		System::Windows::Forms::LinkLabel^ linkRegister;

		System::Windows::Forms::Label^ lblBottomText;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginFormDesigner::typeid));
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			this->lblBack = (gcnew System::Windows::Forms::Label());
			this->lblBrand = (gcnew System::Windows::Forms::Label());
			this->pnlInfo = (gcnew System::Windows::Forms::Panel());
			this->lblFeature3 = (gcnew System::Windows::Forms::Label());
			this->lblFeature2 = (gcnew System::Windows::Forms::Label());
			this->lblFeature1 = (gcnew System::Windows::Forms::Label());
			this->lblInfo = (gcnew System::Windows::Forms::Label());
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->pnlLoginCard = (gcnew System::Windows::Forms::Panel());
			this->lblBottomText = (gcnew System::Windows::Forms::Label());
			this->linkRegister = (gcnew System::Windows::Forms::LinkLabel());
			this->lblNoAccount = (gcnew System::Windows::Forms::Label());
			this->pnlDivider = (gcnew System::Windows::Forms::Panel());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->linkForgotPassword = (gcnew System::Windows::Forms::LinkLabel());
			this->chkRemember = (gcnew System::Windows::Forms::CheckBox());
			this->btnShowPassword = (gcnew System::Windows::Forms::Button());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->lblLoginSubtitle = (gcnew System::Windows::Forms::Label());
			this->lblLoginTitle = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pnlHeader->SuspendLayout();
			this->pnlInfo->SuspendLayout();
			this->pnlLoginCard->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pnlHeader
			// 
			this->pnlHeader->BackColor = System::Drawing::Color::White;
			this->pnlHeader->Controls->Add(this->lblBack);
			this->pnlHeader->Controls->Add(this->lblBrand);
			this->pnlHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlHeader->Location = System::Drawing::Point(0, 0);
			this->pnlHeader->Name = L"pnlHeader";
			this->pnlHeader->Size = System::Drawing::Size(1100, 65);
			this->pnlHeader->TabIndex = 0;
			// 
			// lblBack
			// 
			this->lblBack->AutoSize = true;
			this->lblBack->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblBack->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblBack->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->lblBack->Location = System::Drawing::Point(930, 25);
			this->lblBack->Name = L"lblBack";
			this->lblBack->Size = System::Drawing::Size(122, 19);
			this->lblBack->TabIndex = 2;
			this->lblBack->Text = L"<  Back to Home";
			this->lblBack->Click += gcnew System::EventHandler(this, &LoginFormDesigner::lblBack_Click);
			// 
			// lblBrand
			// 
			this->lblBrand->AutoSize = true;
			this->lblBrand->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			this->lblBrand->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblBrand->Location = System::Drawing::Point(12, 15);
			this->lblBrand->Name = L"lblBrand";
			this->lblBrand->Size = System::Drawing::Size(135, 30);
			this->lblBrand->TabIndex = 1;
			this->lblBrand->Text = L"CourierEase";
			// 
			// pnlInfo
			// 
			this->pnlInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pnlInfo->Controls->Add(this->pictureBox1);
			this->pnlInfo->Controls->Add(this->lblFeature3);
			this->pnlInfo->Controls->Add(this->lblFeature2);
			this->pnlInfo->Controls->Add(this->lblFeature1);
			this->pnlInfo->Controls->Add(this->lblInfo);
			this->pnlInfo->Controls->Add(this->lblWelcome);
			this->pnlInfo->Location = System::Drawing::Point(100, 110);
			this->pnlInfo->Name = L"pnlInfo";
			this->pnlInfo->Size = System::Drawing::Size(350, 450);
			this->pnlInfo->TabIndex = 1;
			// 
			// lblFeature3
			// 
			this->lblFeature3->AutoSize = true;
			this->lblFeature3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblFeature3->Location = System::Drawing::Point(75, 390);
			this->lblFeature3->Name = L"lblFeature3";
			this->lblFeature3->Size = System::Drawing::Size(178, 20);
			this->lblFeature3->TabIndex = 5;
			this->lblFeature3->Text = L"View your delivery history";
			// 
			// lblFeature2
			// 
			this->lblFeature2->AutoSize = true;
			this->lblFeature2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblFeature2->Location = System::Drawing::Point(75, 350);
			this->lblFeature2->Name = L"lblFeature2";
			this->lblFeature2->Size = System::Drawing::Size(160, 20);
			this->lblFeature2->TabIndex = 4;
			this->lblFeature2->Text = L"Track delivery progress";
			// 
			// lblFeature1
			// 
			this->lblFeature1->AutoSize = true;
			this->lblFeature1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblFeature1->Location = System::Drawing::Point(75, 310);
			this->lblFeature1->Name = L"lblFeature1";
			this->lblFeature1->Size = System::Drawing::Size(181, 20);
			this->lblFeature1->TabIndex = 3;
			this->lblFeature1->Text = L"Book and manage parcels";
			this->lblFeature1->Click += gcnew System::EventHandler(this, &LoginFormDesigner::lblFeature1_Click);
			// 
			// lblInfo
			// 
			this->lblInfo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblInfo->Location = System::Drawing::Point(40, 237);
			this->lblInfo->Name = L"lblInfo";
			this->lblInfo->Size = System::Drawing::Size(280, 50);
			this->lblInfo->TabIndex = 2;
			this->lblInfo->Text = L"Sign in to manage your parcels and follow\r\nyour deliveries with CourierEase.";
			this->lblInfo->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// lblWelcome
			// 
			this->lblWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 17, System::Drawing::FontStyle::Bold));
			this->lblWelcome->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblWelcome->Location = System::Drawing::Point(30, 180);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(290, 40);
			this->lblWelcome->TabIndex = 1;
			this->lblWelcome->Text = L"Welcome back!";
			this->lblWelcome->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pnlLoginCard
			// 
			this->pnlLoginCard->BackColor = System::Drawing::Color::White;
			this->pnlLoginCard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlLoginCard->Controls->Add(this->lblBottomText);
			this->pnlLoginCard->Controls->Add(this->linkRegister);
			this->pnlLoginCard->Controls->Add(this->lblNoAccount);
			this->pnlLoginCard->Controls->Add(this->pnlDivider);
			this->pnlLoginCard->Controls->Add(this->btnLogin);
			this->pnlLoginCard->Controls->Add(this->linkForgotPassword);
			this->pnlLoginCard->Controls->Add(this->chkRemember);
			this->pnlLoginCard->Controls->Add(this->btnShowPassword);
			this->pnlLoginCard->Controls->Add(this->txtPassword);
			this->pnlLoginCard->Controls->Add(this->lblPassword);
			this->pnlLoginCard->Controls->Add(this->txtEmail);
			this->pnlLoginCard->Controls->Add(this->lblEmail);
			this->pnlLoginCard->Controls->Add(this->lblLoginSubtitle);
			this->pnlLoginCard->Controls->Add(this->lblLoginTitle);
			this->pnlLoginCard->Location = System::Drawing::Point(545, 110);
			this->pnlLoginCard->Name = L"pnlLoginCard";
			this->pnlLoginCard->Size = System::Drawing::Size(420, 450);
			this->pnlLoginCard->TabIndex = 2;
			// 
			// lblBottomText
			// 
			this->lblBottomText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7));
			this->lblBottomText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(184)));
			this->lblBottomText->Location = System::Drawing::Point(55, 415);
			this->lblBottomText->Name = L"lblBottomText";
			this->lblBottomText->Size = System::Drawing::Size(310, 20);
			this->lblBottomText->TabIndex = 9;
			this->lblBottomText->Text = L"Secure access to your CourierEase account.";
			this->lblBottomText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// linkRegister
			// 
			this->linkRegister->AutoSize = true;
			this->linkRegister->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->linkRegister->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->linkRegister->Location = System::Drawing::Point(267, 380);
			this->linkRegister->Name = L"linkRegister";
			this->linkRegister->Size = System::Drawing::Size(67, 20);
			this->linkRegister->TabIndex = 8;
			this->linkRegister->TabStop = true;
			this->linkRegister->Text = L"Register";
			this->linkRegister->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginFormDesigner::linkRegister_LinkClicked);
			// 
			// lblNoAccount
			// 
			this->lblNoAccount->AutoSize = true;
			this->lblNoAccount->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblNoAccount->Location = System::Drawing::Point(100, 380);
			this->lblNoAccount->Name = L"lblNoAccount";
			this->lblNoAccount->Size = System::Drawing::Size(163, 20);
			this->lblNoAccount->TabIndex = 7;
			this->lblNoAccount->Text = L"Don\'t have an account\?";
			// 
			// pnlDivider
			// 
			this->pnlDivider->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->pnlDivider->Location = System::Drawing::Point(40, 360);
			this->pnlDivider->Name = L"pnlDivider";
			this->pnlDivider->Size = System::Drawing::Size(340, 1);
			this->pnlDivider->TabIndex = 6;
			// 
			// btnLogin
			// 
			this->btnLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnLogin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnLogin->FlatAppearance->BorderSize = 0;
			this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnLogin->ForeColor = System::Drawing::Color::White;
			this->btnLogin->Location = System::Drawing::Point(40, 300);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(340, 40);
			this->btnLogin->TabIndex = 5;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &LoginFormDesigner::btnLogin_Click);
			// 
			// linkForgotPassword
			// 
			this->linkForgotPassword->AutoSize = true;
			this->linkForgotPassword->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->linkForgotPassword->Location = System::Drawing::Point(270, 266);
			this->linkForgotPassword->Name = L"linkForgotPassword";
			this->linkForgotPassword->Size = System::Drawing::Size(127, 20);
			this->linkForgotPassword->TabIndex = 4;
			this->linkForgotPassword->TabStop = true;
			this->linkForgotPassword->Text = L"Forgot password\?";
			this->linkForgotPassword->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginFormDesigner::linkForgotPassword_LinkClicked);
			// 
			// chkRemember
			// 
			this->chkRemember->AutoSize = true;
			this->chkRemember->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(116)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->chkRemember->Location = System::Drawing::Point(40, 265);
			this->chkRemember->Name = L"chkRemember";
			this->chkRemember->Size = System::Drawing::Size(129, 24);
			this->chkRemember->TabIndex = 3;
			this->chkRemember->Text = L"Remember me";
			this->chkRemember->UseVisualStyleBackColor = true;
			// 
			// btnShowPassword
			// 
			this->btnShowPassword->BackColor = System::Drawing::Color::White;
			this->btnShowPassword->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnShowPassword->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnShowPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->btnShowPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->btnShowPassword->Location = System::Drawing::Point(315, 214);
			this->btnShowPassword->Name = L"btnShowPassword";
			this->btnShowPassword->Size = System::Drawing::Size(65, 31);
			this->btnShowPassword->TabIndex = 2;
			this->btnShowPassword->Text = L"Show";
			this->btnShowPassword->UseVisualStyleBackColor = false;
			this->btnShowPassword->Click += gcnew System::EventHandler(this, &LoginFormDesigner::btnShowPassword_Click);
			// 
			// txtPassword
			// 
			this->txtPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtPassword->Location = System::Drawing::Point(40, 215);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(275, 30);
			this->txtPassword->TabIndex = 1;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblPassword->Location = System::Drawing::Point(40, 190);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(73, 19);
			this->lblPassword->TabIndex = 4;
			this->lblPassword->Text = L"Password";
			// 
			// txtEmail
			// 
			this->txtEmail->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtEmail->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtEmail->Location = System::Drawing::Point(40, 140);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(340, 30);
			this->txtEmail->TabIndex = 0;
			// 
			// lblEmail
			// 
			this->lblEmail->AutoSize = true;
			this->lblEmail->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblEmail->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblEmail->Location = System::Drawing::Point(40, 115);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(135, 19);
			this->lblEmail->TabIndex = 2;
			this->lblEmail->Text = L"Email or Username";
			// 
			// lblLoginSubtitle
			// 
			this->lblLoginSubtitle->AutoSize = true;
			this->lblLoginSubtitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(116)), static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->lblLoginSubtitle->Location = System::Drawing::Point(42, 78);
			this->lblLoginSubtitle->Name = L"lblLoginSubtitle";
			this->lblLoginSubtitle->Size = System::Drawing::Size(262, 20);
			this->lblLoginSubtitle->TabIndex = 1;
			this->lblLoginSubtitle->Text = L"Enter your account details to continue.";
			// 
			// lblLoginTitle
			// 
			this->lblLoginTitle->AutoSize = true;
			this->lblLoginTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 17, System::Drawing::FontStyle::Bold));
			this->lblLoginTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->lblLoginTitle->Location = System::Drawing::Point(40, 35);
			this->lblLoginTitle->Name = L"lblLoginTitle";
			this->lblLoginTitle->Size = System::Drawing::Size(301, 40);
			this->lblLoginTitle->TabIndex = 0;
			this->lblLoginTitle->Text = L"Login to CourierEase";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(70, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(214, 176);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// LoginFormDesigner
			// 
			this->AcceptButton = this->btnLogin;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(252)));
			this->ClientSize = System::Drawing::Size(1100, 650);
			this->Controls->Add(this->pnlLoginCard);
			this->Controls->Add(this->pnlInfo);
			this->Controls->Add(this->pnlHeader);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"LoginFormDesigner";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CourierEase - Login";
			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();
			this->pnlInfo->ResumeLayout(false);
			this->pnlInfo->PerformLayout();
			this->pnlLoginCard->ResumeLayout(false);
			this->pnlLoginCard->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion

	private:

		System::Void btnShowPassword_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (this->txtPassword->UseSystemPasswordChar)
			{
				this->txtPassword->UseSystemPasswordChar = false;
				this->btnShowPassword->Text = L"Hide";
			}
			else
			{
				this->txtPassword->UseSystemPasswordChar = true;
				this->btnShowPassword->Text = L"Show";
			}
		}


		System::Void lblBack_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			this->Close();
		}


		System::Void linkRegister_LinkClicked(
			System::Object^ sender,
			System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
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


		System::Void linkForgotPassword_LinkClicked(
			System::Object^ sender,
			System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
		{
			System::Windows::Forms::MessageBox::Show(
				L"Password recovery is not available yet.",
				L"Forgot Password",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Information
			);
		}


		System::Void btnLogin_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			System::String^ email =
				this->txtEmail->Text->Trim();

			System::String^ password =
				this->txtPassword->Text;

			if (
				System::String::IsNullOrWhiteSpace(email)
				||
				System::String::IsNullOrWhiteSpace(password)
				)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Please enter your email and password.",
					L"Login",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Warning
				);

				return;
			}

			try
			{
				int customerId = 0;
				System::String^ fullName = L"";
				System::String^ passwordHash = L"";

				bool found =
					CustomerRepository::GetCustomerLogin(
						email,
						customerId,
						fullName,
						passwordHash
					);

				if (!found)
				{
					System::Windows::Forms::MessageBox::Show(
						L"Invalid email or password.",
						L"Login Failed",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Warning
					);

					return;
				}

				bool passwordCorrect =
					PasswordHasher::VerifyPassword(
						password,
						passwordHash
					);

				if (!passwordCorrect)
				{
					System::Windows::Forms::MessageBox::Show(
						L"Invalid email or password.",
						L"Login Failed",
						System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Warning
					);

					return;
				}

				CustomerDashboardDesigner^ dashboard =
					gcnew CustomerDashboardDesigner(
						customerId,
						fullName
					);

				this->Hide();
				dashboard->ShowDialog();
				this->Close();
			}
			catch (MySqlException^)
			{
				System::Windows::Forms::MessageBox::Show(
					L"Unable to connect to the database.",
					L"Database Error",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error
				);
			}
			catch (System::Exception^ ex)
			{
				System::Windows::Forms::MessageBox::Show(
					L"An unexpected error occurred.\n\n" +
					ex->Message,
					L"CourierEase",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error
				);
			}
		}

	private:
		System::Void lblFeature1_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
		}
	};
}