#pragma once

#include "DeliveryBoyRepository.h"

namespace CourrierEase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class DeliveryBoysDesigner :
		public System::Windows::Forms::Form
	{
	public:

		DeliveryBoysDesigner(void)
		{
			selectedBoyId = 0;
			selectedBoyActive = false;

			InitializeComponent();
			LoadDeliveryBoys();
			ClearForm();
		}

	protected:

		~DeliveryBoysDesigner()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		int selectedBoyId;
		bool selectedBoyActive;

		// HEADER
		System::Windows::Forms::Panel^ pnlHeader;
		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Label^ lblSubtitle;
		System::Windows::Forms::Button^ btnBack;

		// LEFT PANEL
		System::Windows::Forms::Panel^ pnlList;
		System::Windows::Forms::Label^ lblListTitle;
		System::Windows::Forms::Button^ btnRefresh;
		System::Windows::Forms::DataGridView^ dgvDeliveryBoys;

		// RIGHT PANEL
		System::Windows::Forms::Panel^ pnlForm;
		System::Windows::Forms::Label^ lblFormTitle;
		System::Windows::Forms::Label^ lblFormDescription;

		System::Windows::Forms::Label^ lblName;
		System::Windows::Forms::TextBox^ txtName;

		System::Windows::Forms::Label^ lblPhone;
		System::Windows::Forms::TextBox^ txtPhone;

		System::Windows::Forms::Label^ lblEmail;
		System::Windows::Forms::TextBox^ txtEmail;

		System::Windows::Forms::Label^ lblVehicle;
		System::Windows::Forms::TextBox^ txtVehicle;

		System::Windows::Forms::Label^ lblStatusCaption;
		System::Windows::Forms::Label^ lblStatusValue;

		System::Windows::Forms::Button^ btnAdd;
		System::Windows::Forms::Button^ btnUpdate;
		System::Windows::Forms::Button^ btnStatus;
		System::Windows::Forms::Button^ btnClear;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->pnlHeader =
				(gcnew System::Windows::Forms::Panel());

			this->btnBack =
				(gcnew System::Windows::Forms::Button());

			this->lblSubtitle =
				(gcnew System::Windows::Forms::Label());

			this->lblTitle =
				(gcnew System::Windows::Forms::Label());

			this->pnlList =
				(gcnew System::Windows::Forms::Panel());

			this->dgvDeliveryBoys =
				(gcnew System::Windows::Forms::DataGridView());

			this->btnRefresh =
				(gcnew System::Windows::Forms::Button());

			this->lblListTitle =
				(gcnew System::Windows::Forms::Label());

			this->pnlForm =
				(gcnew System::Windows::Forms::Panel());

			this->btnClear =
				(gcnew System::Windows::Forms::Button());

			this->btnStatus =
				(gcnew System::Windows::Forms::Button());

			this->btnUpdate =
				(gcnew System::Windows::Forms::Button());

			this->btnAdd =
				(gcnew System::Windows::Forms::Button());

			this->lblStatusValue =
				(gcnew System::Windows::Forms::Label());

			this->lblStatusCaption =
				(gcnew System::Windows::Forms::Label());

			this->txtVehicle =
				(gcnew System::Windows::Forms::TextBox());

			this->lblVehicle =
				(gcnew System::Windows::Forms::Label());

			this->txtEmail =
				(gcnew System::Windows::Forms::TextBox());

			this->lblEmail =
				(gcnew System::Windows::Forms::Label());

			this->txtPhone =
				(gcnew System::Windows::Forms::TextBox());

			this->lblPhone =
				(gcnew System::Windows::Forms::Label());

			this->txtName =
				(gcnew System::Windows::Forms::TextBox());

			this->lblName =
				(gcnew System::Windows::Forms::Label());

			this->lblFormDescription =
				(gcnew System::Windows::Forms::Label());

			this->lblFormTitle =
				(gcnew System::Windows::Forms::Label());

			this->pnlHeader->SuspendLayout();
			this->pnlList->SuspendLayout();

			(cli::safe_cast<
				System::ComponentModel::ISupportInitialize^>(
					this->dgvDeliveryBoys))->BeginInit();

			this->pnlForm->SuspendLayout();
			this->SuspendLayout();

			// pnlHeader
			this->pnlHeader->BackColor =
				System::Drawing::Color::FromArgb(
					15, 23, 42);

			this->pnlHeader->Controls->Add(
				this->btnBack);

			this->pnlHeader->Controls->Add(
				this->lblSubtitle);

			this->pnlHeader->Controls->Add(
				this->lblTitle);

			this->pnlHeader->Dock =
				System::Windows::Forms::DockStyle::Top;

			this->pnlHeader->Location =
				System::Drawing::Point(0, 0);

			this->pnlHeader->Name =
				L"pnlHeader";

			this->pnlHeader->Size =
				System::Drawing::Size(1300, 90);

			this->pnlHeader->TabIndex = 0;

			// btnBack
			this->btnBack->BackColor =
				System::Drawing::Color::FromArgb(
					30, 41, 59);

			this->btnBack->FlatAppearance->BorderSize =
				0;

			this->btnBack->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnBack->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->btnBack->ForeColor =
				System::Drawing::Color::White;

			this->btnBack->Location =
				System::Drawing::Point(1160, 25);

			this->btnBack->Name =
				L"btnBack";

			this->btnBack->Size =
				System::Drawing::Size(105, 40);

			this->btnBack->TabIndex =
				2;

			this->btnBack->Text =
				L"Back";

			this->btnBack->UseVisualStyleBackColor =
				false;

			this->btnBack->Click +=
				gcnew System::EventHandler(
					this,
					&DeliveryBoysDesigner::
					btnBack_Click);

			// lblSubtitle
			this->lblSubtitle->AutoSize =
				true;

			this->lblSubtitle->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI", 9));

			this->lblSubtitle->ForeColor =
				System::Drawing::Color::FromArgb(
					203, 213, 225);

			this->lblSubtitle->Location =
				System::Drawing::Point(34, 61);

			this->lblSubtitle->Name =
				L"lblSubtitle";

			this->lblSubtitle->Size =
				System::Drawing::Size(352, 20);

			this->lblSubtitle->TabIndex =
				1;

			this->lblSubtitle->Text =
				L"Add, update and manage CourierEase delivery staff.";

			// lblTitle
			this->lblTitle->AutoSize =
				true;

			this->lblTitle->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					20,
					System::Drawing::FontStyle::Bold));

			this->lblTitle->ForeColor =
				System::Drawing::Color::White;

			this->lblTitle->Location =
				System::Drawing::Point(30, 14);

			this->lblTitle->Name =
				L"lblTitle";

			this->lblTitle->Size =
				System::Drawing::Size(237, 46);

			this->lblTitle->TabIndex =
				0;

			this->lblTitle->Text =
				L"Delivery Boys";

			// pnlList
			this->pnlList->BackColor =
				System::Drawing::Color::White;

			this->pnlList->BorderStyle =
				System::Windows::Forms::
				BorderStyle::FixedSingle;

			this->pnlList->Controls->Add(
				this->dgvDeliveryBoys);

			this->pnlList->Controls->Add(
				this->btnRefresh);

			this->pnlList->Controls->Add(
				this->lblListTitle);

			this->pnlList->Location =
				System::Drawing::Point(25, 115);

			this->pnlList->Name =
				L"pnlList";

			this->pnlList->Size =
				System::Drawing::Size(770, 570);

			this->pnlList->TabIndex =
				1;

			// dgvDeliveryBoys
			this->dgvDeliveryBoys->AllowUserToAddRows =
				false;

			this->dgvDeliveryBoys->AllowUserToDeleteRows =
				false;

			this->dgvDeliveryBoys->AllowUserToResizeRows =
				false;

			this->dgvDeliveryBoys->AutoSizeColumnsMode =
				System::Windows::Forms::
				DataGridViewAutoSizeColumnsMode::Fill;

			this->dgvDeliveryBoys->BackgroundColor =
				System::Drawing::Color::White;

			this->dgvDeliveryBoys->BorderStyle =
				System::Windows::Forms::
				BorderStyle::Fixed3D;

			this->dgvDeliveryBoys->ColumnHeadersHeightSizeMode =
				System::Windows::Forms::
				DataGridViewColumnHeadersHeightSizeMode::
				AutoSize;

			this->dgvDeliveryBoys->Location =
				System::Drawing::Point(20, 70);

			this->dgvDeliveryBoys->MultiSelect =
				false;

			this->dgvDeliveryBoys->Name =
				L"dgvDeliveryBoys";

			this->dgvDeliveryBoys->ReadOnly =
				true;

			this->dgvDeliveryBoys->RowHeadersVisible =
				false;

			this->dgvDeliveryBoys->RowHeadersWidth =
				51;

			this->dgvDeliveryBoys->SelectionMode =
				System::Windows::Forms::
				DataGridViewSelectionMode::
				FullRowSelect;

			this->dgvDeliveryBoys->Size =
				System::Drawing::Size(720, 470);

			this->dgvDeliveryBoys->TabIndex =
				2;

			this->dgvDeliveryBoys->SelectionChanged +=
				gcnew System::EventHandler(
					this,
					&DeliveryBoysDesigner::
					dgvDeliveryBoys_SelectionChanged);

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
				System::Drawing::Point(625, 15);

			this->btnRefresh->Name =
				L"btnRefresh";

			this->btnRefresh->Size =
				System::Drawing::Size(115, 38);

			this->btnRefresh->TabIndex =
				1;

			this->btnRefresh->Text =
				L"Refresh";

			this->btnRefresh->UseVisualStyleBackColor =
				false;

			this->btnRefresh->Click +=
				gcnew System::EventHandler(
					this,
					&DeliveryBoysDesigner::
					btnRefresh_Click);

			// lblListTitle
			this->lblListTitle->AutoSize =
				true;

			this->lblListTitle->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					14,
					System::Drawing::FontStyle::Bold));

			this->lblListTitle->ForeColor =
				System::Drawing::Color::FromArgb(
					15, 23, 42);

			this->lblListTitle->Location =
				System::Drawing::Point(20, 18);

			this->lblListTitle->Name =
				L"lblListTitle";

			this->lblListTitle->Size =
				System::Drawing::Size(168, 32);

			this->lblListTitle->TabIndex =
				0;

			this->lblListTitle->Text =
				L"Delivery Staff";

			// pnlForm
			this->pnlForm->BackColor =
				System::Drawing::Color::White;

			this->pnlForm->BorderStyle =
				System::Windows::Forms::
				BorderStyle::FixedSingle;

			this->pnlForm->Controls->Add(
				this->btnClear);

			this->pnlForm->Controls->Add(
				this->btnStatus);

			this->pnlForm->Controls->Add(
				this->btnUpdate);

			this->pnlForm->Controls->Add(
				this->btnAdd);

			this->pnlForm->Controls->Add(
				this->lblStatusValue);

			this->pnlForm->Controls->Add(
				this->lblStatusCaption);

			this->pnlForm->Controls->Add(
				this->txtVehicle);

			this->pnlForm->Controls->Add(
				this->lblVehicle);

			this->pnlForm->Controls->Add(
				this->txtEmail);

			this->pnlForm->Controls->Add(
				this->lblEmail);

			this->pnlForm->Controls->Add(
				this->txtPhone);

			this->pnlForm->Controls->Add(
				this->lblPhone);

			this->pnlForm->Controls->Add(
				this->txtName);

			this->pnlForm->Controls->Add(
				this->lblName);

			this->pnlForm->Controls->Add(
				this->lblFormDescription);

			this->pnlForm->Controls->Add(
				this->lblFormTitle);

			this->pnlForm->Location =
				System::Drawing::Point(820, 115);

			this->pnlForm->Name =
				L"pnlForm";

			this->pnlForm->Size =
				System::Drawing::Size(455, 570);

			this->pnlForm->TabIndex =
				2;

			// btnClear
			this->btnClear->BackColor =
				System::Drawing::Color::White;

			this->btnClear->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnClear->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->btnClear->ForeColor =
				System::Drawing::Color::FromArgb(
					51, 65, 85);

			this->btnClear->Location =
				System::Drawing::Point(235, 485);

			this->btnClear->Name =
				L"btnClear";

			this->btnClear->Size =
				System::Drawing::Size(185, 40);

			this->btnClear->TabIndex =
				15;

			this->btnClear->Text =
				L"Clear / New";

			this->btnClear->UseVisualStyleBackColor =
				false;

			this->btnClear->Click +=
				gcnew System::EventHandler(
					this,
					&DeliveryBoysDesigner::
					btnClear_Click);

			// btnStatus
			this->btnStatus->BackColor =
				System::Drawing::Color::FromArgb(
					185, 28, 28);

			this->btnStatus->FlatAppearance->BorderSize =
				0;

			this->btnStatus->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnStatus->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->btnStatus->ForeColor =
				System::Drawing::Color::White;

			this->btnStatus->Location =
				System::Drawing::Point(30, 485);

			this->btnStatus->Name =
				L"btnStatus";

			this->btnStatus->Size =
				System::Drawing::Size(185, 40);

			this->btnStatus->TabIndex =
				14;

			this->btnStatus->Text =
				L"Deactivate";

			this->btnStatus->UseVisualStyleBackColor =
				false;

			this->btnStatus->Click +=
				gcnew System::EventHandler(
					this,
					&DeliveryBoysDesigner::
					btnStatus_Click);

			// btnUpdate
			this->btnUpdate->BackColor =
				System::Drawing::Color::FromArgb(
					22, 163, 74);

			this->btnUpdate->FlatAppearance->BorderSize =
				0;

			this->btnUpdate->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnUpdate->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->btnUpdate->ForeColor =
				System::Drawing::Color::White;

			this->btnUpdate->Location =
				System::Drawing::Point(235, 430);

			this->btnUpdate->Name =
				L"btnUpdate";

			this->btnUpdate->Size =
				System::Drawing::Size(185, 40);

			this->btnUpdate->TabIndex =
				13;

			this->btnUpdate->Text =
				L"Update Staff";

			this->btnUpdate->UseVisualStyleBackColor =
				false;

			this->btnUpdate->Click +=
				gcnew System::EventHandler(
					this,
					&DeliveryBoysDesigner::
					btnUpdate_Click);

			// btnAdd
			this->btnAdd->BackColor =
				System::Drawing::Color::FromArgb(
					37, 99, 235);

			this->btnAdd->FlatAppearance->BorderSize =
				0;

			this->btnAdd->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->btnAdd->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->btnAdd->ForeColor =
				System::Drawing::Color::White;

			this->btnAdd->Location =
				System::Drawing::Point(30, 430);

			this->btnAdd->Name =
				L"btnAdd";

			this->btnAdd->Size =
				System::Drawing::Size(185, 40);

			this->btnAdd->TabIndex =
				12;

			this->btnAdd->Text =
				L"Add Staff";

			this->btnAdd->UseVisualStyleBackColor =
				false;

			this->btnAdd->Click +=
				gcnew System::EventHandler(
					this,
					&DeliveryBoysDesigner::
					btnAdd_Click);

			// lblStatusValue
			this->lblStatusValue->AutoSize =
				true;

			this->lblStatusValue->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblStatusValue->ForeColor =
				System::Drawing::Color::FromArgb(
					100, 116, 139);

			this->lblStatusValue->Location =
				System::Drawing::Point(95, 392);

			this->lblStatusValue->Name =
				L"lblStatusValue";

			this->lblStatusValue->Size =
				System::Drawing::Size(94, 20);

			this->lblStatusValue->TabIndex =
				11;

			this->lblStatusValue->Text =
				L"New Record";

			// lblStatusCaption
			this->lblStatusCaption->AutoSize =
				true;

			this->lblStatusCaption->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblStatusCaption->Location =
				System::Drawing::Point(28, 392);

			this->lblStatusCaption->Name =
				L"lblStatusCaption";

			this->lblStatusCaption->Size =
				System::Drawing::Size(57, 20);

			this->lblStatusCaption->TabIndex =
				10;

			this->lblStatusCaption->Text =
				L"Status:";

			// txtVehicle
			this->txtVehicle->Location =
				System::Drawing::Point(30, 345);

			this->txtVehicle->Name =
				L"txtVehicle";

			this->txtVehicle->Size =
				System::Drawing::Size(390, 27);

			this->txtVehicle->TabIndex =
				9;

			// lblVehicle
			this->lblVehicle->AutoSize =
				true;

			this->lblVehicle->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblVehicle->Location =
				System::Drawing::Point(28, 320);

			this->lblVehicle->Name =
				L"lblVehicle";

			this->lblVehicle->Size =
				System::Drawing::Size(87, 20);

			this->lblVehicle->TabIndex =
				8;

			this->lblVehicle->Text =
				L"Vehicle No.";

			// txtEmail
			this->txtEmail->Location =
				System::Drawing::Point(30, 275);

			this->txtEmail->Name =
				L"txtEmail";

			this->txtEmail->Size =
				System::Drawing::Size(390, 27);

			this->txtEmail->TabIndex =
				7;

			// lblEmail
			this->lblEmail->AutoSize =
				true;

			this->lblEmail->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblEmail->Location =
				System::Drawing::Point(28, 250);

			this->lblEmail->Name =
				L"lblEmail";

			this->lblEmail->Size =
				System::Drawing::Size(47, 20);

			this->lblEmail->TabIndex =
				6;

			this->lblEmail->Text =
				L"Email";

			// txtPhone
			this->txtPhone->Location =
				System::Drawing::Point(30, 205);

			this->txtPhone->Name =
				L"txtPhone";

			this->txtPhone->Size =
				System::Drawing::Size(390, 27);

			this->txtPhone->TabIndex =
				5;

			// lblPhone
			this->lblPhone->AutoSize =
				true;

			this->lblPhone->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblPhone->Location =
				System::Drawing::Point(28, 180);

			this->lblPhone->Name =
				L"lblPhone";

			this->lblPhone->Size =
				System::Drawing::Size(53, 20);

			this->lblPhone->TabIndex =
				4;

			this->lblPhone->Text =
				L"Phone";

			// txtName
			this->txtName->Location =
				System::Drawing::Point(30, 135);

			this->txtName->Name =
				L"txtName";

			this->txtName->Size =
				System::Drawing::Size(390, 27);

			this->txtName->TabIndex =
				3;

			// lblName
			this->lblName->AutoSize =
				true;

			this->lblName->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					9,
					System::Drawing::FontStyle::Bold));

			this->lblName->Location =
				System::Drawing::Point(28, 110);

			this->lblName->Name =
				L"lblName";

			this->lblName->Size =
				System::Drawing::Size(80, 20);

			this->lblName->TabIndex =
				2;

			this->lblName->Text =
				L"Full Name";

			// lblFormDescription
			this->lblFormDescription->ForeColor =
				System::Drawing::Color::FromArgb(
					100, 116, 139);

			this->lblFormDescription->Location =
				System::Drawing::Point(28, 57);

			this->lblFormDescription->Name =
				L"lblFormDescription";

			this->lblFormDescription->Size =
				System::Drawing::Size(390, 40);

			this->lblFormDescription->TabIndex =
				1;

			this->lblFormDescription->Text =
				L"Enter details to add a new delivery staff member.";

			// lblFormTitle
			this->lblFormTitle->AutoSize =
				true;

			this->lblFormTitle->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					14,
					System::Drawing::FontStyle::Bold));

			this->lblFormTitle->ForeColor =
				System::Drawing::Color::FromArgb(
					15, 23, 42);

			this->lblFormTitle->Location =
				System::Drawing::Point(25, 18);

			this->lblFormTitle->Name =
				L"lblFormTitle";

			this->lblFormTitle->Size =
				System::Drawing::Size(151, 32);

			this->lblFormTitle->TabIndex =
				0;

			this->lblFormTitle->Text =
				L"Staff Details";

			// DeliveryBoysDesigner
			this->AutoScaleDimensions =
				System::Drawing::SizeF(8, 20);

			this->AutoScaleMode =
				System::Windows::Forms::
				AutoScaleMode::Font;

			this->BackColor =
				System::Drawing::Color::FromArgb(
					248, 250, 252);

			this->ClientSize =
				System::Drawing::Size(1300, 710);

			this->Controls->Add(
				this->pnlForm);

			this->Controls->Add(
				this->pnlList);

			this->Controls->Add(
				this->pnlHeader);

			this->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI", 9));

			this->FormBorderStyle =
				System::Windows::Forms::
				FormBorderStyle::FixedSingle;

			this->MaximizeBox =
				false;

			this->Name =
				L"DeliveryBoysDesigner";

			this->StartPosition =
				System::Windows::Forms::
				FormStartPosition::CenterScreen;

			this->Text =
				L"CourierEase - Delivery Boys";

			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();

			this->pnlList->ResumeLayout(false);
			this->pnlList->PerformLayout();

			(cli::safe_cast<
				System::ComponentModel::ISupportInitialize^>(
					this->dgvDeliveryBoys))->EndInit();

			this->pnlForm->ResumeLayout(false);
			this->pnlForm->PerformLayout();

			this->ResumeLayout(false);
		}

#pragma endregion

	private:

		void LoadDeliveryBoys()
		{
			try
			{
				DataTable^ table =
					DeliveryBoyRepository::
					GetAllDeliveryBoys();

				dgvDeliveryBoys->DataSource =
					table;

				FormatGrid();
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

		void FormatGrid()
		{
			if (dgvDeliveryBoys->Columns[
				L"boy_id"] != nullptr)
			{
				dgvDeliveryBoys->Columns[
					L"boy_id"]->Visible =
					false;
			}

			if (dgvDeliveryBoys->Columns[
				L"created_at"] != nullptr)
			{
				dgvDeliveryBoys->Columns[
					L"created_at"]->Visible =
					false;
			}

			if (dgvDeliveryBoys->Columns[
				L"full_name"] != nullptr)
			{
				dgvDeliveryBoys->Columns[
					L"full_name"]->HeaderText =
					L"Full Name";
			}

			if (dgvDeliveryBoys->Columns[
				L"phone"] != nullptr)
			{
				dgvDeliveryBoys->Columns[
					L"phone"]->HeaderText =
					L"Phone";
			}

			if (dgvDeliveryBoys->Columns[
				L"email"] != nullptr)
			{
				dgvDeliveryBoys->Columns[
					L"email"]->HeaderText =
					L"Email";
			}

			if (dgvDeliveryBoys->Columns[
				L"vehicle_no"] != nullptr)
			{
				dgvDeliveryBoys->Columns[
					L"vehicle_no"]->HeaderText =
					L"Vehicle No.";
			}

			if (dgvDeliveryBoys->Columns[
				L"is_active"] != nullptr)
			{
				dgvDeliveryBoys->Columns[
					L"is_active"]->HeaderText =
					L"Active";
			}
		}

		void ClearForm()
		{
			selectedBoyId = 0;
			selectedBoyActive = false;

			txtName->Clear();
			txtPhone->Clear();
			txtEmail->Clear();
			txtVehicle->Clear();

			lblStatusValue->Text =
				L"New Record";

			lblStatusValue->ForeColor =
				System::Drawing::Color::FromArgb(
					100, 116, 139);

			btnAdd->Enabled =
				true;

			btnUpdate->Enabled =
				false;

			btnStatus->Enabled =
				false;

			btnStatus->Text =
				L"Deactivate";

			btnStatus->BackColor =
				System::Drawing::Color::FromArgb(
					185, 28, 28);

			lblFormDescription->Text =
				L"Enter details to add a new delivery staff member.";

			if (dgvDeliveryBoys->Rows->Count > 0)
			{
				dgvDeliveryBoys->ClearSelection();
			}

			txtName->Focus();
		}

		bool ValidateForm()
		{
			String^ name =
				txtName->Text->Trim();

			String^ phone =
				txtPhone->Text->Trim();

			String^ email =
				txtEmail->Text->Trim();

			String^ vehicle =
				txtVehicle->Text->Trim();

			if (String::IsNullOrWhiteSpace(name) ||
				String::IsNullOrWhiteSpace(phone) ||
				String::IsNullOrWhiteSpace(email) ||
				String::IsNullOrWhiteSpace(vehicle))
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Please complete all delivery staff details.",
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Warning);

				return false;
			}

			if (name->Length > 60)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Full name cannot exceed 60 characters.",
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Warning);

				txtName->Focus();
				return false;
			}

			if (phone->Length > 15)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Phone number cannot exceed 15 characters.",
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Warning);

				txtPhone->Focus();
				return false;
			}

			if (!email->Contains(L"@") ||
				!email->Contains(L"."))
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Please enter a valid email address.",
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Warning);

				txtEmail->Focus();
				return false;
			}

			if (email->Length > 100)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Email cannot exceed 100 characters.",
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Warning);

				txtEmail->Focus();
				return false;
			}

			if (vehicle->Length > 20)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Vehicle number cannot exceed 20 characters.",
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Warning);

				txtVehicle->Focus();
				return false;
			}

			return true;
		}

		void DeliveryBoySelectionChanged(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (dgvDeliveryBoys->CurrentRow ==
				nullptr ||
				dgvDeliveryBoys->SelectedRows->Count ==
				0)
			{
				return;
			}

			Object^ idValue =
				dgvDeliveryBoys->CurrentRow->
				Cells[L"boy_id"]->Value;

			if (idValue == nullptr ||
				idValue == DBNull::Value)
			{
				return;
			}

			selectedBoyId =
				Convert::ToInt32(idValue);

			try
			{
				DataRow^ row =
					DeliveryBoyRepository::
					GetDeliveryBoyById(
						selectedBoyId);

				if (row == nullptr)
				{
					return;
				}

				txtName->Text =
					row[L"full_name"]->ToString();

				txtPhone->Text =
					row[L"phone"]->ToString();

				txtEmail->Text =
					row[L"email"]->ToString();

				txtVehicle->Text =
					row[L"vehicle_no"]->ToString();

				selectedBoyActive =
					Convert::ToInt32(
						row[L"is_active"]) == 1;

				if (selectedBoyActive)
				{
					lblStatusValue->Text =
						L"Active";

					lblStatusValue->ForeColor =
						System::Drawing::Color::
						FromArgb(
							22, 163, 74);

					btnStatus->Text =
						L"Deactivate";

					btnStatus->BackColor =
						System::Drawing::Color::
						FromArgb(
							185, 28, 28);
				}
				else
				{
					lblStatusValue->Text =
						L"Inactive";

					lblStatusValue->ForeColor =
						System::Drawing::Color::
						FromArgb(
							185, 28, 28);

					btnStatus->Text =
						L"Activate";

					btnStatus->BackColor =
						System::Drawing::Color::
						FromArgb(
							22, 163, 74);
				}

				btnAdd->Enabled =
					false;

				btnUpdate->Enabled =
					true;

				btnStatus->Enabled =
					true;

				lblFormDescription->Text =
					L"Edit the selected delivery staff member.";
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Unable to load delivery staff details.\n\n" +
						ex->Message,
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Error);
			}
		}

		void Add_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (!ValidateForm())
			{
				return;
			}

			try
			{
				String^ name =
					txtName->Text->Trim();

				String^ phone =
					txtPhone->Text->Trim();

				String^ email =
					txtEmail->Text->Trim();

				String^ vehicle =
					txtVehicle->Text->Trim();

				if (DeliveryBoyRepository::
					EmailExists(
						email,
						0))
				{
					System::Windows::Forms::
						MessageBox::Show(
							L"A delivery staff member with this email "
							L"already exists.",
							L"CourierEase",
							System::Windows::Forms::
							MessageBoxButtons::OK,
							System::Windows::Forms::
							MessageBoxIcon::Warning);

					txtEmail->Focus();
					return;
				}

				bool success =
					DeliveryBoyRepository::
					CreateDeliveryBoy(
						name,
						phone,
						email,
						vehicle);

				if (success)
				{
					System::Windows::Forms::
						MessageBox::Show(
							L"Delivery staff added successfully.",
							L"CourierEase",
							System::Windows::Forms::
							MessageBoxButtons::OK,
							System::Windows::Forms::
							MessageBoxIcon::Information);

					LoadDeliveryBoys();
					ClearForm();
				}
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Unable to add delivery staff.\n\n" +
						ex->Message,
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Error);
			}
		}

		void Update_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (selectedBoyId <= 0)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Please select a delivery staff member first.",
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Warning);

				return;
			}

			if (!ValidateForm())
			{
				return;
			}

			try
			{
				String^ name =
					txtName->Text->Trim();

				String^ phone =
					txtPhone->Text->Trim();

				String^ email =
					txtEmail->Text->Trim();

				String^ vehicle =
					txtVehicle->Text->Trim();

				if (DeliveryBoyRepository::
					EmailExists(
						email,
						selectedBoyId))
				{
					System::Windows::Forms::
						MessageBox::Show(
							L"Another delivery staff member already "
							L"uses this email address.",
							L"CourierEase",
							System::Windows::Forms::
							MessageBoxButtons::OK,
							System::Windows::Forms::
							MessageBoxIcon::Warning);

					txtEmail->Focus();
					return;
				}

				bool success =
					DeliveryBoyRepository::
					UpdateDeliveryBoy(
						selectedBoyId,
						name,
						phone,
						email,
						vehicle);

				if (success)
				{
					System::Windows::Forms::
						MessageBox::Show(
							L"Delivery staff updated successfully.",
							L"CourierEase",
							System::Windows::Forms::
							MessageBoxButtons::OK,
							System::Windows::Forms::
							MessageBoxIcon::Information);

					LoadDeliveryBoys();
					ClearForm();
				}
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Unable to update delivery staff.\n\n" +
						ex->Message,
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Error);
			}
		}

		void Status_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (selectedBoyId <= 0)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Please select a delivery staff member first.",
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Warning);

				return;
			}

			try
			{
				if (selectedBoyActive)
				{
					if (DeliveryBoyRepository::
						HasActiveDeliveries(
							selectedBoyId))
					{
						System::Windows::Forms::
							MessageBox::Show(
								L"This delivery staff member still has "
								L"an active delivery and cannot be "
								L"deactivated.",
								L"CourierEase",
								System::Windows::Forms::
								MessageBoxButtons::OK,
								System::Windows::Forms::
								MessageBoxIcon::Warning);

						return;
					}
				}

				String^ action =
					selectedBoyActive
					? L"deactivate"
					: L"activate";

				System::Windows::Forms::
					DialogResult result =
					System::Windows::Forms::
					MessageBox::Show(
						L"Are you sure you want to " +
						action +
						L" this delivery staff member?",
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

				bool newStatus =
					!selectedBoyActive;

				bool success =
					DeliveryBoyRepository::
					SetDeliveryBoyActiveStatus(
						selectedBoyId,
						newStatus);

				if (success)
				{
					String^ message =
						newStatus
						? L"Delivery staff activated successfully."
						: L"Delivery staff deactivated successfully.";

					System::Windows::Forms::
						MessageBox::Show(
							message,
							L"CourierEase",
							System::Windows::Forms::
							MessageBoxButtons::OK,
							System::Windows::Forms::
							MessageBoxIcon::Information);

					LoadDeliveryBoys();
					ClearForm();
				}
			}
			catch (Exception^ ex)
			{
				System::Windows::Forms::
					MessageBox::Show(
						L"Unable to change delivery staff status.\n\n" +
						ex->Message,
						L"CourierEase",
						System::Windows::Forms::
						MessageBoxButtons::OK,
						System::Windows::Forms::
						MessageBoxIcon::Error);
			}
		}

		void Refresh_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			LoadDeliveryBoys();
			ClearForm();
		}

		void Clear_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			ClearForm();
		}

		void Back_Click(
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

		System::Void btnAdd_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Add_Click(sender, e);
		}

		System::Void btnUpdate_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Update_Click(sender, e);
		}

		System::Void btnStatus_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Status_Click(sender, e);
		}

		System::Void btnClear_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Clear_Click(sender, e);
		}

		System::Void btnBack_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			Back_Click(sender, e);
		}

		System::Void dgvDeliveryBoys_SelectionChanged(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			DeliveryBoySelectionChanged(
				sender,
				e);
		}
	};
}