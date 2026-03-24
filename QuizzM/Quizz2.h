#pragma once
#include<algorithm>
#include<random>
#include<vector>	

namespace QuizzM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;


	public ref class Quizz2 : public System::Windows::Forms::Form
	{
	public:

		List<String^>^ questions = gcnew List<String^>();
		List<String^>^ answers = gcnew List<String^>();
		List<String^>^ hints = gcnew List<String^>();
		String^ filePath = "intrebari2.txt";

		List<int>^ index = gcnew List<int>();
		Random^ rand = gcnew Random();
		int partscore = 0;
		bool hintuse;
		int seconds = 0;
		double	 score = 0;
		int hintcount = 0;

	private: System::Windows::Forms::Button^ button1;
	public:


		int currentQ;

		Quizz2(void)
		{
			InitializeComponent();
			LoadQuestionsAndAnswers(questions, answers, filePath);
			Random_Quiz();
			ShowQuizz();
		}

		void LoadQuestionsAndAnswers(List<String^>^ questions, List<String^>^ answers, String^ filePath) {
			if (!File::Exists(filePath)) {
				Console::WriteLine("Fișierul nu a fost găsit: " + filePath);
				return;
			}

			StreamReader^ sr = gcnew StreamReader(filePath);

			while (!sr->EndOfStream) {
				// 1. Citește o linie pentru întrebare
				String^ question = sr->ReadLine();

				// Dacă e linie goală, continuăm să citim până găsim ceva
				if (String::IsNullOrWhiteSpace(question)) {
					continue;
				}

				// 2. Citește o linie pentru răspuns
				if (sr->EndOfStream) {
					// Nu mai există linie pentru răspuns, ieșim
					break;
				}
				String^ answer = sr->ReadLine();

				if (sr->EndOfStream) {
					// Nu mai există linie pentru răspuns, ieșim
					break;
				}
				String^ hint = sr->ReadLine();
				

				// Adăugăm în liste
				questions->Add(question);
				answers->Add(answer);
				hints->Add(hint);

				// 3. Dacă mai există o linie (linia goală separatoare), o citim (ca să "consumăm" linia)
				if (!sr->EndOfStream) {
					String^ separatorLine = sr->ReadLine();
					// Această linie, de obicei, e goală. O ignorăm.
				}
			}

			sr->Close();
		}

		void Random_Quiz()
		{
			index->Clear();

			for (int i = 0; i < questions->Count; i++)
			{
				index->Add(i);
			}

			for (int i = index->Count - 1; i > 0; i--) {
				int j = rand->Next(0, i + 1); // Get a random index from 0 to i
				// Swap selectedIndexes[i] and selectedIndexes[j]
				int temp = index[i];
				index[i] = index[j];
				index[j] = temp;
			}

			// Keep only the first 10 questions
			while (index->Count > 10) {
				index->RemoveAt(index->Count - 1);
			}

		}


		array<System::String^>^ SplitWords(System::String^ input) {
			return input->ToLower()->Split(gcnew array<wchar_t>{' ', ',', '.', '!', '?'}, System::StringSplitOptions::RemoveEmptyEntries);
		}

		double ComputeScore(System::String^ userAnswer, System::String^ correctAnswer) {
			array<System::String^>^ userWords = SplitWords(userAnswer);
			array<System::String^>^ correctWords = SplitWords(correctAnswer);

			if (correctWords->Length == 0) return 100.0; // Dacă nu există răspuns corect, dăm 100%

			int correctCount = 0;
			for each(System::String ^ word in userWords) {
				for each(System::String ^ correctWord in correctWords) {
					if (word == correctWord) {
						correctCount++;
						break; // Evităm dublarea scorului
					}
				}
			}

			return ((double)correctCount / correctWords->Length) * 10.0;
		}

		void ShowQuizz()
		{
			if (currentQ >= 10)
			{
				MessageBox::Show("Quiz finished! Your score: " + score, "Quiz Completed");
				this->Close();
				return;
				
			}
			else
			{
				int contor = index[currentQ];
				question_lbl->Text = questions[contor];
			}

			int current_question1 = currentQ + 1;
			current_lbl->Text = current_question1.ToString();
		}

	protected:

		~Quizz2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ current_lbl;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ time_lbl;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ score_lbl;
	private: System::Windows::Forms::Panel^ panelAnswer4;
	private: System::Windows::Forms::TextBox^ AnswerTextBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ next_btn;
	private: System::Windows::Forms::Button^ clear_btn;
	private: System::Windows::Forms::Label^ question_lbl;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:



#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->current_lbl = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->time_lbl = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->score_lbl = (gcnew System::Windows::Forms::Label());
			this->panelAnswer4 = (gcnew System::Windows::Forms::Panel());
			this->AnswerTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->next_btn = (gcnew System::Windows::Forms::Button());
			this->clear_btn = (gcnew System::Windows::Forms::Button());
			this->question_lbl = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panelAnswer4->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::LightCyan;
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->progressBar1);
			this->panel1->Controls->Add(this->panel8);
			this->panel1->Controls->Add(this->panel7);
			this->panel1->Controls->Add(this->panel6);
			this->panel1->Controls->Add(this->panelAnswer4);
			this->panel1->Controls->Add(this->next_btn);
			this->panel1->Controls->Add(this->clear_btn);
			this->panel1->Controls->Add(this->question_lbl);
			this->panel1->Location = System::Drawing::Point(49, 79);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1150, 514);
			this->panel1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button1->BackColor = System::Drawing::Color::PaleTurquoise;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(449, 426);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(149, 47);
			this->button1->TabIndex = 19;
			this->button1->Text = L"Get hint";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Quizz2::button1_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->progressBar1->BackColor = System::Drawing::Color::LightCyan;
			this->progressBar1->ForeColor = System::Drawing::Color::Cyan;
			this->progressBar1->Location = System::Drawing::Point(377, 34);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(359, 23);
			this->progressBar1->TabIndex = 18;
			// 
			// panel8
			// 
			this->panel8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->panel8->BackColor = System::Drawing::Color::MintCream;
			this->panel8->Controls->Add(this->label4);
			this->panel8->Controls->Add(this->current_lbl);
			this->panel8->Location = System::Drawing::Point(961, 451);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(159, 42);
			this->panel8->TabIndex = 17;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(16, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 24);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Question:";
			// 
			// current_lbl
			// 
			this->current_lbl->AutoSize = true;
			this->current_lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->current_lbl->Location = System::Drawing::Point(118, 9);
			this->current_lbl->Name = L"current_lbl";
			this->current_lbl->Size = System::Drawing::Size(20, 24);
			this->current_lbl->TabIndex = 12;
			this->current_lbl->Text = L"0";
			// 
			// panel7
			// 
			this->panel7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->panel7->BackColor = System::Drawing::Color::MintCream;
			this->panel7->Controls->Add(this->label2);
			this->panel7->Controls->Add(this->time_lbl);
			this->panel7->Location = System::Drawing::Point(921, 15);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(210, 42);
			this->panel7->TabIndex = 16;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(3, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 24);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Time:";
			// 
			// time_lbl
			// 
			this->time_lbl->AutoSize = true;
			this->time_lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->time_lbl->Location = System::Drawing::Point(67, 9);
			this->time_lbl->Name = L"time_lbl";
			this->time_lbl->Size = System::Drawing::Size(20, 24);
			this->time_lbl->TabIndex = 13;
			this->time_lbl->Text = L"0";
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::MintCream;
			this->panel6->Controls->Add(this->label1);
			this->panel6->Controls->Add(this->score_lbl);
			this->panel6->Location = System::Drawing::Point(25, 15);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(162, 42);
			this->panel6->TabIndex = 15;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(14, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 24);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Score:";
			// 
			// score_lbl
			// 
			this->score_lbl->AutoSize = true;
			this->score_lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->score_lbl->Location = System::Drawing::Point(96, 9);
			this->score_lbl->Name = L"score_lbl";
			this->score_lbl->Size = System::Drawing::Size(20, 24);
			this->score_lbl->TabIndex = 10;
			this->score_lbl->Text = L"0";
			// 
			// panelAnswer4
			// 
			this->panelAnswer4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelAnswer4->BackColor = System::Drawing::Color::Azure;
			this->panelAnswer4->Controls->Add(this->AnswerTextBox);
			this->panelAnswer4->Controls->Add(this->label3);
			this->panelAnswer4->Location = System::Drawing::Point(68, 190);
			this->panelAnswer4->Name = L"panelAnswer4";
			this->panelAnswer4->Size = System::Drawing::Size(1009, 130);
			this->panelAnswer4->TabIndex = 8;
			// 
			// AnswerTextBox
			// 
			this->AnswerTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->AnswerTextBox->BackColor = System::Drawing::Color::White;
			this->AnswerTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->AnswerTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AnswerTextBox->Location = System::Drawing::Point(125, 52);
			this->AnswerTextBox->Name = L"AnswerTextBox";
			this->AnswerTextBox->Size = System::Drawing::Size(837, 35);
			this->AnswerTextBox->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(20, 52);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(99, 29);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Answer:";
			// 
			// next_btn
			// 
			this->next_btn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->next_btn->BackColor = System::Drawing::Color::PaleTurquoise;
			this->next_btn->FlatAppearance->BorderSize = 0;
			this->next_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->next_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->next_btn->Location = System::Drawing::Point(709, 426);
			this->next_btn->Name = L"next_btn";
			this->next_btn->Size = System::Drawing::Size(149, 47);
			this->next_btn->TabIndex = 6;
			this->next_btn->Text = L"Next Question";
			this->next_btn->UseVisualStyleBackColor = false;
			this->next_btn->Click += gcnew System::EventHandler(this, &Quizz2::next_btn_Click);
			// 
			// clear_btn
			// 
			this->clear_btn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->clear_btn->BackColor = System::Drawing::Color::PaleTurquoise;
			this->clear_btn->FlatAppearance->BorderSize = 0;
			this->clear_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->clear_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clear_btn->Location = System::Drawing::Point(184, 426);
			this->clear_btn->Name = L"clear_btn";
			this->clear_btn->Size = System::Drawing::Size(149, 47);
			this->clear_btn->TabIndex = 5;
			this->clear_btn->Text = L"Clear Answers";
			this->clear_btn->UseVisualStyleBackColor = false;
			this->clear_btn->Click += gcnew System::EventHandler(this, &Quizz2::clear_btn_Click);
			// 
			// question_lbl
			// 
			this->question_lbl->AutoSize = true;
			this->question_lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->question_lbl->Location = System::Drawing::Point(179, 103);
			this->question_lbl->Name = L"question_lbl";
			this->question_lbl->Size = System::Drawing::Size(110, 29);
			this->question_lbl->TabIndex = 0;
			this->question_lbl->Text = L"Question";
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Quizz2::timer1_Tick);
			// 
			// Quizz2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1249, 673);
			this->Controls->Add(this->panel1);
			this->Name = L"Quizz2";
			this->Text = L"Quizz2";
			this->Load += gcnew System::EventHandler(this, &Quizz2::Quizz2_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panelAnswer4->ResumeLayout(false);
			this->panelAnswer4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (seconds > 0)
		{
			seconds--;
			int minutes = seconds / 60;
			int sec = seconds % 60;
			time_lbl->Text = "Minutes: " + minutes + ":" + (sec < 10 ? "0" : "") + sec;
		}
		else
		{
			timer1->Stop();
			MessageBox::Show("Your score is:" + score, "Time expired!", MessageBoxButtons::OK, MessageBoxIcon::Stop);
			this->Close();
		}
	}

	private: System::Void Quizz2_Load(System::Object^ sender, System::EventArgs^ e) {

		progressBar1->Value = 0;
		progressBar1->Maximum = 10;
		progressBar1->Minimum = 0;

		LoadQuestionsAndAnswers(questions, answers, filePath);
		Random_Quiz();
		ShowQuizz();


		seconds = 300;
		timer1->Start();
	}


	private: System::Void clear_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		AnswerTextBox->Text = "";
	}


	private: System::Void next_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		System::String^ answerUser = AnswerTextBox->Text->Trim()->ToLower();
		int qindex = index[currentQ];
		System::String^ correctA = answers[qindex]->Trim()->ToLower();

		score = ComputeScore(answerUser, correctA);


		if (answerUser == "") MessageBox::Show("No answer!", "Please answer to the question!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		else if (score >= 80)
		{
			currentQ++;
			score_lbl->Text = score.ToString("F2");
			AnswerTextBox->Clear();
			ShowQuizz();
		}
		else if (score >0)
		{
			currentQ++;
			score_lbl->Text = score.ToString("F2");
			AnswerTextBox->Clear();
			ShowQuizz();
		}
		else
		{
			currentQ++;
			AnswerTextBox->Clear();
			ShowQuizz();
		}
		
		progressBar1->Value = currentQ;
		
	};
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (hintcount > 3) MessageBox::Show("No more hints!", "You used all hints!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		int qindex = index[currentQ];
		if (hints[qindex] != "")
		{
			MessageBox::Show(hints[qindex], "Hint");
			hints[qindex] = "";	
			hintcount++;
			hintuse = true;
		}

		if (hintcount >= 3)
		{
			button1->Enabled = false;
		}
		else
		{
			MessageBox::Show("You already used the hint for this question!", "Hint");
		}
	}
};
}