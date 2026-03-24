#pragma once
#include"QuizApp.h"
#include"Quizz2.h"


namespace QuizzM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class MyForm : public System::Windows::Forms::Form
	{

		bool menue = false;
		int menuwith = 100;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Button^ button2;

	public:
		MyForm(void)
		{
			InitializeComponent();

		}



	protected:

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ verify_btn;
	private: System::Windows::Forms::Button^ quizz_btn;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


	private:



#pragma region Windows Form Designer generated code


		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->verify_btn = (gcnew System::Windows::Forms::Button());
			this->quizz_btn = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::CadetBlue;
			this->label1->Location = System::Drawing::Point(357, 133);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(181, 39);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome!";
			// 
			// verify_btn
			// 
			this->verify_btn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->verify_btn->BackColor = System::Drawing::Color::PaleTurquoise;
			this->verify_btn->FlatAppearance->BorderSize = 0;
			this->verify_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->verify_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->verify_btn->Location = System::Drawing::Point(494, 260);
			this->verify_btn->Name = L"verify_btn";
			this->verify_btn->Size = System::Drawing::Size(119, 47);
			this->verify_btn->TabIndex = 1;
			this->verify_btn->Text = L"Quiz type 2";
			this->verify_btn->UseVisualStyleBackColor = false;
			this->verify_btn->Click += gcnew System::EventHandler(this, &MyForm::verify_btn_Click);
			// 
			// quizz_btn
			// 
			this->quizz_btn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->quizz_btn->BackColor = System::Drawing::Color::PaleTurquoise;
			this->quizz_btn->FlatAppearance->BorderSize = 0;
			this->quizz_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->quizz_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->quizz_btn->Location = System::Drawing::Point(261, 260);
			this->quizz_btn->Name = L"quizz_btn";
			this->quizz_btn->Size = System::Drawing::Size(129, 47);
			this->quizz_btn->TabIndex = 2;
			this->quizz_btn->Text = L"Quizz type 1";
			this->quizz_btn->UseVisualStyleBackColor = false;
			this->quizz_btn->Click += gcnew System::EventHandler(this, &MyForm::quizz_btn_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel1->Controls->Add(this->label2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 457);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(929, 51);
			this->panel1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(300, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(313, 24);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Copyright © All rights reserved  -Edy";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Azure;
			this->panel2->Controls->Add(this->pictureBox4);
			this->panel2->Controls->Add(this->pictureBox3);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(100, 457);
			this->panel2->TabIndex = 4;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(21, 348);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(60, 60);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &MyForm::pictureBox3_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(21, 247);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(60, 60);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(21, 145);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(60, 60);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button2->BackColor = System::Drawing::Color::MintCream;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(398, 385);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 33);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Contact";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.InitialImage")));
			this->pictureBox4->Location = System::Drawing::Point(12, 29);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(80, 70);
			this->pictureBox4->TabIndex = 7;
			this->pictureBox4->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightCyan;
			this->ClientSize = System::Drawing::Size(929, 508);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->quizz_btn);
			this->Controls->Add(this->verify_btn);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void verify_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		Quizz2^ quizz2 = gcnew Quizz2();
		quizz2->Show();
	}
	private: System::Void quizz_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (quizz_btn->Enabled == false)
		{
			MessageBox::Show("Complete capchta to start!", "Please complete captcha!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			QuizApp^ quiz = gcnew QuizApp();
			quiz->Show();
		}
	}
	private: System::Void verify_lbl_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (menue)
		{
			for (int i = panel2->Width; i >= 0; i -= 10)
			{
				panel2->Width = i;
				Application::DoEvents();
				System::Threading::Thread::Sleep(10);
			}
			menue = false;
		}
		else
		{
			for (int i = 0; i < menuwith; i += 10)
			{
				panel2->Width = i;
				Application::DoEvents();
				System::Threading::Thread::Sleep(10);
			}
			menue = true;
		}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ url = "https://www.linkedin.com/in/eduard-merticariu-0535522b6/";
		System::Diagnostics::Process::Start(url);
	}
	private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ url = "https://www.instagram.com/edy_merticariu/";
		System::Diagnostics::Process::Start(url);
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ number = "+40755343535";// here must be a real number
		System::String^ message = "https://wa.me/" + number;

		System::Diagnostics::Process::Start(message);
	}
	};
};
