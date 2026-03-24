#pragma once
#include<vector>
#include<algorithm>
#include <msclr/marshal_cppstd.h>
#include<random>
#include<list>
#include<random>
#include<string>

namespace QuizzM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic; //used for List (import from c#)

	public ref class QuizApp : public System::Windows::Forms::Form
	{
	private:

		List<String^>^ questions;
		List<List<String^>^>^ answers;
		List<int>^ correctA;
		List<int>^ index = gcnew List<int>();
		Random^ rand = gcnew Random();
	private: int seconds = 0;
	

		int current_question;
	private: System::Windows::Forms::Label^ score_lbl;

		   int score;
	private: System::Windows::Forms::Label^ time_lbl;
	private: System::Windows::Forms::Label^ current_lbl;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
		  


	public:
		QuizApp(void)
		{
			InitializeComponent();
			score = 0;
			current_question = 0;
			
			LoadQuiz();
			Random_Quiz();
			DisplayQuiz();
			
		}

		void LoadQuiz()
		{
			questions = gcnew List<String^>();
			answers = gcnew List<List<String^>^>();
			correctA = gcnew List<int>();


			questions->Add("What role does the number base play in representing the numerator in the computer?");
			List<String^>^ answerList = gcnew List<String^>();
			answerList->Add("To store programs on disk.");
			answerList->Add("To influence the type and precision with which numbers are represented.");
			answerList->Add("To set the precision of floating-point calculations.");
			answerList->Add("To determine the number of bits used for storage.");
			answers->Add(answerList);
			correctA->Add(2);

			questions->Add("What is the effect of accumulating errors in numerical calculations?");
			List<String^>^ answerList1 = gcnew List<String^>();
			answerList1->Add("The effect of reducing the complexity of calculations");
			answerList1->Add("The effect of making the result of a numerical calculation totally incorrect");
			answerList1->Add("The effect of making the results more accurate");
			answerList1->Add("The effect of removing errors from calculations");
			answers->Add(answerList1);
			correctA->Add(2);

			questions->Add("What does it mean for a computational problem to be well-conditioned?");
			List<String^>^ answerList2 = gcnew List<String^>();
			answerList2->Add("Small changes in the input data lead to small changes in the solution.");
			answerList2->Add("When the condition number is large.");
			answerList2->Add("When the input data is very precise.");
			answerList2->Add("When the algorithm used for solving is efficient.");
			answers->Add(answerList2);
			correctA->Add(1);

			questions->Add("How is the condition number of a calculation problem defined?");
			List<String^>^ answerList3 = gcnew List<String^>();
			answerList3->Add("The ratio of the absolute error in the solutions of the computational problem to the absolute error in the input data.");
			answerList3->Add("The ratio of the absolute error in the input data to the output data.");
			answerList3->Add("Measure of the sensitivity of the solution to changes in the input data.");
			answerList3->Add("The ratio between the exact solution and the solution obtained after perturbing the input data.");
			answers->Add(answerList3);
			correctA->Add(1);

			questions->Add("What does the term 'mantissa' represent in the context of floating point numbers?");
			List<String^>^ answerList4 = gcnew List<String^>();
			answerList4->Add("The exponent of the floating point number.");
			answerList4->Add("The number of bits used to represent a floating point number.");
			answerList4->Add("Fraction or significant figures of a floating point number.");
			answerList4->Add("Floating point number base.");
			answers->Add(answerList4);
			correctA->Add(3);

			questions->Add("What happens to the solutions of an ill-conditioned problem when the initial data has errors?");
			List<String^>^ answerList5 = gcnew List<String^>();
			answerList5->Add("Solutions change significantly.");
			answerList5->Add("Solutions cannot be calculated.");
			answerList5->Add("Solutions can become completely unstable.");
			answerList5->Add("Solutions change in a predictable way.");
			answers->Add(answerList5);
			correctA->Add(1);

			questions->Add("How do you determine the pivot in a matrix at step k?");
			List<String^>^ answerList6 = gcnew List<String^>();
			answerList6->Add("The element with the lowest modulo value in column k, starting from the element on the main diagonal down.");
			answerList6->Add("The element on the main diagonal of the matrix at step k.");
			answerList6->Add("The element in the last row of column k.");
			answerList6->Add("The element with the highest value in the mode of column k, starting from the element on the main diagonal down.");
			answers->Add(answerList6);
			correctA->Add(4);

			questions->Add("What is the principle of partial pivot triangulation?");
			List<String^>^ answerList7 = gcnew List<String^>();
			answerList7->Add("Search for the pivot with the largest absolute value in column k, from row k down, with row permutations if necessary.");
			answerList7->Add("Triangulation without pivoting.");
			answerList7->Add("Using the smallest element in the column as the pivot.");
			answerList7->Add("Finding the pivot only on the main diagonal.");
			answers->Add(answerList7);
			correctA->Add(1);

			questions->Add("What are representation errors in numerical computation?");
			List<String^>^ answerList8 = gcnew List<String^>();
			answerList8->Add("Inherent errors that come from the initial data of the problem.");
			answerList8->Add("Calculation errors resulting from adding or subtracting numbers.");
			answerList8->Add("Method errors due to the numerical method used.");
			answerList8->Add("Errors due to the limited possibility of representing numbers in computers.");
			answers->Add(answerList8);
			correctA->Add(4);

			questions->Add("What is the main function of the floating point number system?");
			List<String^>^ answerList9 = gcnew List<String^>();
			answerList9->Add("Storing integers with precision.");
			answerList9->Add("Performing quick arithmetic calculations.");
			answerList9->Add("Representation of complex numbers.");
			answerList9->Add("Representing real numbers in a flexible way.");
			answers->Add(answerList9);
			correctA->Add(4);

			questions->Add("What does the invertible matrix represent in a system of linear equations?");
			List<String^>^ answerList10 = gcnew List<String^>();
			answerList10->Add("A matrix whose rows are dependent.");
			answerList10->Add("A tool that allows finding a unique solution to the system of equations.");
			answerList10->Add("A matrix used to find approximate, not exact, solutions.");
			answerList10->Add("A matrix with determinant equal to zero.");
			answers->Add(answerList10);
			correctA->Add(2);

			questions->Add("What characterizes a numerically stable algorithm?");
			List<String^>^ answerList11 = gcnew List<String^>();
			answerList11->Add("Minimizes the effect of errors in input data.");
			answerList11->Add("It has a mechanism that warns when errors are large.");
			answerList11->Add("Amplifies errors in input data.");
			answerList11->Add("Leads to very different solutions even with slightly modified input data.");
			answers->Add(answerList11);
			correctA->Add(1);

			questions->Add("How is numerical derivation based on Lagrange interpolation defined?");
			List<String^>^ answerList12 = gcnew List<String^>();
			answerList12->Add("Numerical derivation by the finite difference method.");
			answerList12->Add("Numerical derivation by polynomial extrapolation.");
			answerList12->Add("Numerical derivation based on Newton interpolation.");
			answerList12->Add("Numerical derivation based on Lagrange interpolation.");
			answers->Add(answerList12);
			correctA->Add(4);

			questions->Add("What does the trapezoid rule represent in the context of numerical methods?");
			List<String^>^ answerList13 = gcnew List<String^>();
			answerList13->Add("The arithmetic mean rule.");
			answerList13->Add("Simpson's rule.");
			answerList13->Add("Trapezoid rule.");
			answerList13->Add("Rectangle rule.");
			answers->Add(answerList13);
			correctA->Add(3);

			questions->Add("What is numerical quadrature and what is its purpose?");
			List<String^>^ answerList14 = gcnew List<String^>();
			answerList14->Add("Numerical quadrature is a technique for optimizing functions.");
			answerList14->Add("Numerical quadrature is a computational method for deriving functions.");
			answerList14->Add("Numerical quadrature refers to calculating the arithmetic mean of a set of data.");
			answerList14->Add("Numerical quadrature is a calculation method for determining the value of the definite integral.");
			answers->Add(answerList14);
			correctA->Add(4);

			questions->Add("What does the trapezoid rule represent in the context of numerical methods?");
			List<String^>^ answerList15 = gcnew List<String^>();
			answerList15->Add("The arithmetic mean rule.");
			answerList15->Add("Simpson's rule.");
			answerList15->Add("Trapezoid rule.");
			answerList15->Add("Rectangle rule.");
			answers->Add(answerList15);
			correctA->Add(1);

			questions->Add("What characterizes an elementary quadrature rule?");
			List<String^>^ answerList16 = gcnew List<String^>();
			answerList16->Add("A rule that applies only to continuous functions.");
			answerList16->Add("A complex formula that requires multiple calculation steps.");
			answerList16->Add("A method that uses differentiation to approximate integrals.");
			answerList16->Add("A simple formula that approximates the values ​​of elementary integrals.");
			answers->Add(answerList16);
			correctA->Add(4);

			questions->Add("What conditions must the function f satisfy for the Cauchy problem to have a unique solution?");
			List<String^>^ answerList17 = gcnew List<String^>();
			answerList17->Add("The function f must be differentiable with respect to the argument.");
			answerList17->Add("The function f must be continuous and monotone.");
			answerList17->Add("The function f must be bounded in the considered interval.");
			answerList17->Add("The function f must be continuous and Lipschitzian with respect to the argument.");
			answers->Add(answerList17);
			correctA->Add(4);

			questions->Add("Why are cubic spline functions important in numerical derivation?");
			List<String^>^ answerList18 = gcnew List<String^>();
			answerList18->Add("Cubic spline functions are used to calculate integrals of functions.");
			answerList18->Add("Cubic spline functions improve the accuracy of derivative approximation.");
			answerList18->Add("Cubic spline functions are only important for linear interpolation.");
			answerList18->Add("Cubic spline functions have no impact on the accuracy of derivatives	.");
			answers->Add(answerList18);
			correctA->Add(2);

			questions->Add("What role do the coefficients ai, bi, ci, di play in quadrature based on interpolation with cubic spline functions?");
			List<String^>^ answerList19 = gcnew List<String^>();
			answerList19->Add("The coefficients ai, bi, ci, di are used to calculate the functional derivative.");
			answerList19->Add("The coefficients ai, bi, ci, di are used to fit the spline function to the experimental data.");
			answerList19->Add("The coefficients ai, bi, ci, di increase the accuracy of the quadrature approximation.");
			answerList19->Add("The coefficients ai, bi, ci, di only determine the interpolation points.");
			answers->Add(answerList19);
			correctA->Add(3);

			questions->Add("How do measurement errors affect the numerical derivative operation?");
			List<String^>^ answerList20 = gcnew List<String^>();
			answerList20->Add("Errors are reduced during numerical derivation.");
			answerList20->Add("Measurement errors amplify the results of numerical derivation.");
			answerList20->Add("Errors do not affect the results of numerical derivation.");
			answerList20->Add("Numerical derivation is not influenced by measurement noise.");
			answers->Add(answerList20);
			correctA->Add(2);

			questions->Add("What does the term 'spline' represent in the context of mechanics?");
			List<String^>^ answerList21 = gcnew List<String^>();
			answerList21->Add("A tool for drawing smooth curves in drawing.");
			answerList21->Add("A calculation method for determining volume.");
			answerList21->Add("A measuring tool used in construction.");
			answerList21->Add("A type of polynomial used in numerical analysis.");
			answers->Add(answerList21);
			correctA->Add(1);

			questions->Add("What is the purpose of using polynomials in spline interpolation?");
			List<String^>^ answerList22 = gcnew List<String^>();
			answerList22->Add("Polynomials are used to create smooth functions that connect at nodes	.");
			answerList22->Add("Polynomials are used to determine the maximum and minimum points of functions.");
			answerList22->Add("Polynomials are used to reduce the complexity of numerical computation.");
			answerList22->Add("Polynomials are used to obtain a linear approximation of functions.");
			answers->Add(answerList22);
			correctA->Add(1);

			questions->Add("What are spline functions and how are they formed?");
			List<String^>^ answerList23 = gcnew List<String^>();
			answerList23->Add("Spline functions are functions formed by polynomials defined on adjacent subintervals.");
			answerList23->Add("Spline functions are continuous functions that have no defined derivatives.");
			answerList23->Add("Spline functions are made up of high-degree polynomials, without restrictions on subintervals.");
			answerList23->Add("Spline functions are functions that are based on arithmetic averages between points.");
			answers->Add(answerList23);
			correctA->Add(1);

			questions->Add("Why are natural cubic spline functions considered the smoothest functions for interpolation?");
			List<String^>^ answerList24 = gcnew List<String^>();
			answerList24->Add("Natural cubic spline functions have constant curvature on intervals.");
			answerList24->Add("Natural cubic spline functions are the fastest functions for interpolation.");
			answerList24->Add("Natural cubic spline functions are the simplest functions for interpolation.");
			answerList24->Add("Natural cubic spline functions have the smallest curvature.");
			answers->Add(answerList24);
			correctA->Add(4);

			questions->Add("What role do continuity conditions play in defining spline functions?");
			List<String^>^ answerList25 = gcnew List<String^>();
			answerList25->Add("Ensures that the spline function is discontinuous at nodes.");
			answerList25->Add("Ensures smoothness and continuity of the spline function.");
			answerList25->Add("Allows the spline function to have sharp corners.");
			answerList25->Add("Determine the coefficients of the spline function.");
			answers->Add(answerList25);
			correctA->Add(2);

			questions->Add("What problem arises in the case of Lagrange interpolation and what are its consequences?");
			List<String^>^ answerList26 = gcnew List<String^>();
			answerList26->Add("Significant approximation errors.");
			answerList26->Add("Limitation of applicability depending on the type of interpolated function.");
			answerList26->Add("Increasing computational complexity.");
			answerList26->Add("Large oscillations in the interpolation polynomial.");
			answers->Add(answerList26);
			correctA->Add(1);

			questions->Add("What types of approximation can be used when f is known through a range of values?");
			List<String^>^ answerList27 = gcnew List<String^>();
			answerList27->Add("Uniform approximation and mean square approximation.");
			answerList27->Add("Approximation by extrapolation methods.");
			answerList27->Add("Approximation by polynomial regression.");
			answerList27->Add("Approximation by linear interpolation.");
			answers->Add(answerList27);
			correctA->Add(1);

			questions->Add("What is meant by overdetermined system in the context of interpolation?");
			List<String^>^ answerList28 = gcnew List<String^>();
			answerList28->Add("A system with all collinear points.");
			answerList28->Add("A system with more interpolation conditions than polynomial degrees.");
			answerList28->Add("An underdetermined system with fewer points than parameters.");
			answerList28->Add("A determined system with points equal to the degree of the polynomial.");
			answers->Add(answerList28);
			correctA->Add(2);

			questions->Add("What is uniform rounding in the context of numerical methods?");
			List<String^>^ answerList29 = gcnew List<String^>();
			answerList29->Add("Variable rounding.");
			answerList29->Add("Rounding to fixed decimals.");
			answerList29->Add("Uniform rounding.");
			answerList29->Add("Rounding to the nearest integer.");
			answers->Add(answerList29);
			correctA->Add(3);

			questions->Add("What condition must the matrix A meet for the Gauss-Seidel method to be applicable?");
			List<String^>^ answerList30 = gcnew List<String^>();
			answerList30->Add("The matrix A must be positive definite.");
			answerList30->Add("The matrix A must be diagonally dominant on the rows.");
			answerList30->Add("The matrix A must be symmetric.");
			answerList30->Add("The matrix A must have non-zero determinant.");
			answers->Add(answerList30);
			correctA->Add(2);

			questions->Add("What is meant by catastrophic omission in numerical calculations?");
			List<String^>^ answerList31 = gcnew List<String^>();
			answerList31->Add("Catastrophic omission refers to the total loss of input data.");
			answerList31->Add("Catastrophic omission refers to rounding errors in calculations.");
			answerList31->Add("Catastrophic omission refers to the use of an unstable algorithm.");
			answerList31->Add("Catastrophic omission refers to significant loss of precision in numerical calculations.");
			answers->Add(answerList31);
			correctA->Add(4);
			
		}

		void Random_Quiz()
		{
			index->Clear();

			for (int i = 0; i < questions->Count; i++)
			{
				index->Add(i);
			}

			for (int i =index->Count - 1; i > 0; i--) {
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

		void DisplayQuiz()
		{
			
			

			if (current_question >= 10)
			{
				MessageBox::Show("Quiz finished! Your score: " + score, "Quiz Completed");
				this->Close();
				return;
			}

			int contor = index[current_question];
			question_lbl->Text = questions[contor];
			int current_question1 = current_question + 1;

			List<String^>^ currentAnswer = answers[contor];
			radioButton1->Text = currentAnswer[0];	
			radioButton2->Text = currentAnswer[1];
			radioButton3->Text = currentAnswer[2];
			radioButton4->Text = currentAnswer[3];

			radioButton1->Checked = false;
			radioButton2->Checked = false;
			radioButton3->Checked = false;
			radioButton4->Checked = false;

			current_lbl->Text = current_question1.ToString();
		}

	protected:

		~QuizApp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ question_lbl;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Button^ clear_btn;
	private: System::Windows::Forms::Button^ next_btn;
private: System::Windows::Forms::Panel^ panelAnswer1;
private: System::Windows::Forms::Panel^ panelAnswer2;
private: System::Windows::Forms::Panel^ panelAnswer4;





private: System::Windows::Forms::Panel^ panelAnswer3;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:


	private:



#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QuizApp::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
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
			this->panelAnswer2 = (gcnew System::Windows::Forms::Panel());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->panelAnswer4 = (gcnew System::Windows::Forms::Panel());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->panelAnswer3 = (gcnew System::Windows::Forms::Panel());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->panelAnswer1 = (gcnew System::Windows::Forms::Panel());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->next_btn = (gcnew System::Windows::Forms::Button());
			this->clear_btn = (gcnew System::Windows::Forms::Button());
			this->question_lbl = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panelAnswer2->SuspendLayout();
			this->panelAnswer4->SuspendLayout();
			this->panelAnswer3->SuspendLayout();
			this->panelAnswer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::LightCyan;
			this->panel1->Controls->Add(this->progressBar1);
			this->panel1->Controls->Add(this->panel8);
			this->panel1->Controls->Add(this->panel7);
			this->panel1->Controls->Add(this->panel6);
			this->panel1->Controls->Add(this->panelAnswer2);
			this->panel1->Controls->Add(this->panelAnswer4);
			this->panel1->Controls->Add(this->panelAnswer3);
			this->panel1->Controls->Add(this->panelAnswer1);
			this->panel1->Controls->Add(this->next_btn);
			this->panel1->Controls->Add(this->clear_btn);
			this->panel1->Controls->Add(this->question_lbl);
			this->panel1->Location = System::Drawing::Point(38, 75);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1177, 514);
			this->panel1->TabIndex = 0;
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
			this->panel8->Location = System::Drawing::Point(992, 455);
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
			this->panel7->Location = System::Drawing::Point(941, 15);
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
			this->panel6->Size = System::Drawing::Size(133, 42);
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
			// panelAnswer2
			// 
			this->panelAnswer2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelAnswer2->BackColor = System::Drawing::Color::Azure;
			this->panelAnswer2->Controls->Add(this->radioButton2);
			this->panelAnswer2->Location = System::Drawing::Point(120, 188);
			this->panelAnswer2->Name = L"panelAnswer2";
			this->panelAnswer2->Size = System::Drawing::Size(906, 47);
			this->panelAnswer2->TabIndex = 8;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton2->Location = System::Drawing::Point(64, 3);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(133, 28);
			this->radioButton2->TabIndex = 2;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"radioButton2";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// panelAnswer4
			// 
			this->panelAnswer4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelAnswer4->BackColor = System::Drawing::Color::Azure;
			this->panelAnswer4->Controls->Add(this->radioButton4);
			this->panelAnswer4->Location = System::Drawing::Point(120, 317);
			this->panelAnswer4->Name = L"panelAnswer4";
			this->panelAnswer4->Size = System::Drawing::Size(906, 47);
			this->panelAnswer4->TabIndex = 8;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton4->Location = System::Drawing::Point(68, 3);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(133, 28);
			this->radioButton4->TabIndex = 4;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"radioButton4";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// panelAnswer3
			// 
			this->panelAnswer3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelAnswer3->BackColor = System::Drawing::Color::Azure;
			this->panelAnswer3->Controls->Add(this->radioButton3);
			this->panelAnswer3->Location = System::Drawing::Point(120, 253);
			this->panelAnswer3->Name = L"panelAnswer3";
			this->panelAnswer3->Size = System::Drawing::Size(906, 47);
			this->panelAnswer3->TabIndex = 8;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton3->Location = System::Drawing::Point(64, 3);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(133, 28);
			this->radioButton3->TabIndex = 3;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"radioButton3";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// panelAnswer1
			// 
			this->panelAnswer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelAnswer1->BackColor = System::Drawing::Color::Azure;
			this->panelAnswer1->Controls->Add(this->radioButton1);
			this->panelAnswer1->Location = System::Drawing::Point(120, 125);
			this->panelAnswer1->Name = L"panelAnswer1";
			this->panelAnswer1->Size = System::Drawing::Size(906, 47);
			this->panelAnswer1->TabIndex = 7;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(64, 3);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(133, 28);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"radioButton1";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// next_btn
			// 
			this->next_btn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->next_btn->BackColor = System::Drawing::Color::PaleTurquoise;
			this->next_btn->FlatAppearance->BorderSize = 0;
			this->next_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->next_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->next_btn->Location = System::Drawing::Point(686, 450);
			this->next_btn->Name = L"next_btn";
			this->next_btn->Size = System::Drawing::Size(149, 47);
			this->next_btn->TabIndex = 6;
			this->next_btn->Text = L"Next Question";
			this->next_btn->UseVisualStyleBackColor = false;
			this->next_btn->Click += gcnew System::EventHandler(this, &QuizApp::next_btn_Click);
			// 
			// clear_btn
			// 
			this->clear_btn->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->clear_btn->BackColor = System::Drawing::Color::PaleTurquoise;
			this->clear_btn->FlatAppearance->BorderSize = 0;
			this->clear_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->clear_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clear_btn->Location = System::Drawing::Point(242, 450);
			this->clear_btn->Name = L"clear_btn";
			this->clear_btn->Size = System::Drawing::Size(149, 47);
			this->clear_btn->TabIndex = 5;
			this->clear_btn->Text = L"Clear Answers";
			this->clear_btn->UseVisualStyleBackColor = false;
			this->clear_btn->Click += gcnew System::EventHandler(this, &QuizApp::clear_btn_Click);
			// 
			// question_lbl
			// 
			this->question_lbl->AutoSize = true;
			this->question_lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->question_lbl->Location = System::Drawing::Point(183, 59);
			this->question_lbl->Name = L"question_lbl";
			this->question_lbl->Size = System::Drawing::Size(110, 29);
			this->question_lbl->TabIndex = 0;
			this->question_lbl->Text = L"Question";
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &QuizApp::timer1_Tick);
			// 
			// QuizApp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1249, 673);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"QuizApp";
			this->Text = L"QuizApp";
			this->Load += gcnew System::EventHandler(this, &QuizApp::QuizApp_Load);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &QuizApp::QuizApp_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panelAnswer2->ResumeLayout(false);
			this->panelAnswer2->PerformLayout();
			this->panelAnswer4->ResumeLayout(false);
			this->panelAnswer4->PerformLayout();
			this->panelAnswer3->ResumeLayout(false);
			this->panelAnswer3->PerformLayout();
			this->panelAnswer1->ResumeLayout(false);
			this->panelAnswer1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void next_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		radioButton1->BackColor = System::Drawing::Color::Azure;
		radioButton2->BackColor = System::Drawing::Color::Azure;
		radioButton3->BackColor = System::Drawing::Color::Azure;
		radioButton4->BackColor = System::Drawing::Color::Azure;

		int selectAnnswer = -1;
		

		if (radioButton1->Checked) { selectAnnswer = 0;  }
		if (radioButton2->Checked) { selectAnnswer = 1;  }
		if (radioButton3->Checked) { selectAnnswer = 2;  }
		if (radioButton4->Checked) { selectAnnswer = 3;  }

		if (radioButton1->Checked == false && radioButton2->Checked == false && radioButton3->Checked == false && radioButton4->Checked == false)
		{
			MessageBox::Show("Please select an answer!", "Not answer selected!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

		}
		else
		{
	
			
			if (selectAnnswer == correctA[current_question])
			{
				score++;
				score_lbl->Text = score.ToString();
				
			}
			

			current_question++;
			DisplayQuiz();
			progressBar1->Value = current_question ;
			
		}

		

	}
	private: System::Void QuizApp_Load(System::Object^ sender, System::EventArgs^ e) {

		progressBar1->Value = 0;
		progressBar1->Maximum = 10;
		progressBar1->Minimum = 0;

		seconds = 300;
		timer1->Start();

		LoadQuiz();
		Random_Quiz();
		DisplayQuiz();
	
	}
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
	private: System::Void QuizApp_KeyDown(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == '1') radioButton1->Checked = true;
		if (e->KeyChar == '2') radioButton2->Checked = true;
		if (e->KeyChar == '3') radioButton3->Checked = true;
		if (e->KeyChar == '4') radioButton4->Checked = true;
	}
	private: System::Void clear_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		radioButton1->Checked = false;
		radioButton2->Checked = false;
		radioButton3->Checked = false;
		radioButton4->Checked = false;
	}
};
}
