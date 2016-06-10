#pragma once
#include <msclr\marshal_cppstd.h>
#include <string>
#include <vector>
#include <utility>
#include "FileParser.h"
#include "linearNeedlemanWunsch.h"
#include <time.h>

namespace NWA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MaskedTextBox^  seq1;
	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::MaskedTextBox^  seq2;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::CheckBox^  checkBoxGPU;
	private: System::Windows::Forms::Button^  btnCount;
	private: System::Windows::Forms::MaskedTextBox^  punishmentInput;



	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::MaskedTextBox^  matrixFileInput;
	private: System::Windows::Forms::Button^  buttonMatrixFile;


	private: System::Windows::Forms::Button^  buttonFileSeq1;
	private: System::Windows::Forms::Button^  buttonFileSeq2;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  labelTime;







	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  labelResult;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  resultFileBtn;
	private: System::Windows::Forms::MaskedTextBox^  resultFileInput;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->seq1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->seq2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBoxGPU = (gcnew System::Windows::Forms::CheckBox());
			this->btnCount = (gcnew System::Windows::Forms::Button());
			this->punishmentInput = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->matrixFileInput = (gcnew System::Windows::Forms::MaskedTextBox());
			this->buttonMatrixFile = (gcnew System::Windows::Forms::Button());
			this->buttonFileSeq1 = (gcnew System::Windows::Forms::Button());
			this->buttonFileSeq2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->labelTime = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->labelResult = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->resultFileBtn = (gcnew System::Windows::Forms::Button());
			this->resultFileInput = (gcnew System::Windows::Forms::MaskedTextBox());
			this->SuspendLayout();
			// 
			// seq1
			// 
			this->seq1->Location = System::Drawing::Point(82, 12);
			this->seq1->Name = L"seq1";
			this->seq1->Size = System::Drawing::Size(100, 20);
			this->seq1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Squence 1";
			// 
			// seq2
			// 
			this->seq2->Location = System::Drawing::Point(82, 38);
			this->seq2->Name = L"seq2";
			this->seq2->Size = System::Drawing::Size(100, 20);
			this->seq2->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Sequence 2";
			// 
			// checkBoxGPU
			// 
			this->checkBoxGPU->AutoSize = true;
			this->checkBoxGPU->Location = System::Drawing::Point(11, 71);
			this->checkBoxGPU->Name = L"checkBoxGPU";
			this->checkBoxGPU->Size = System::Drawing::Size(101, 17);
			this->checkBoxGPU->TabIndex = 4;
			this->checkBoxGPU->Text = L"GPU computing";
			this->checkBoxGPU->UseVisualStyleBackColor = true;
			// 
			// btnCount
			// 
			this->btnCount->Location = System::Drawing::Point(10, 148);
			this->btnCount->Name = L"btnCount";
			this->btnCount->Size = System::Drawing::Size(267, 23);
			this->btnCount->TabIndex = 5;
			this->btnCount->Text = L"Count";
			this->btnCount->UseVisualStyleBackColor = true;
			this->btnCount->Click += gcnew System::EventHandler(this, &MyForm::btnCount_Click);
			// 
			// punishmentInput
			// 
			this->punishmentInput->Location = System::Drawing::Point(75, 98);
			this->punishmentInput->Name = L"punishmentInput";
			this->punishmentInput->Size = System::Drawing::Size(32, 20);
			this->punishmentInput->TabIndex = 6;
			this->punishmentInput->Text = L"-5";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 101);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"punishment";
			// 
			// matrixFileInput
			// 
			this->matrixFileInput->Location = System::Drawing::Point(96, 122);
			this->matrixFileInput->Name = L"matrixFileInput";
			this->matrixFileInput->Size = System::Drawing::Size(100, 20);
			this->matrixFileInput->TabIndex = 8;
			// 
			// buttonMatrixFile
			// 
			this->buttonMatrixFile->Location = System::Drawing::Point(202, 120);
			this->buttonMatrixFile->Name = L"buttonMatrixFile";
			this->buttonMatrixFile->Size = System::Drawing::Size(75, 23);
			this->buttonMatrixFile->TabIndex = 9;
			this->buttonMatrixFile->Text = L"From file";
			this->buttonMatrixFile->UseVisualStyleBackColor = true;
			this->buttonMatrixFile->Click += gcnew System::EventHandler(this, &MyForm::buttonMatrixFile_Click);
			// 
			// buttonFileSeq1
			// 
			this->buttonFileSeq1->Location = System::Drawing::Point(188, 12);
			this->buttonFileSeq1->Name = L"buttonFileSeq1";
			this->buttonFileSeq1->Size = System::Drawing::Size(75, 23);
			this->buttonFileSeq1->TabIndex = 10;
			this->buttonFileSeq1->Text = L"From file";
			this->buttonFileSeq1->UseVisualStyleBackColor = true;
			this->buttonFileSeq1->Click += gcnew System::EventHandler(this, &MyForm::buttonFileSeq1_Click);
			// 
			// buttonFileSeq2
			// 
			this->buttonFileSeq2->Location = System::Drawing::Point(188, 36);
			this->buttonFileSeq2->Name = L"buttonFileSeq2";
			this->buttonFileSeq2->Size = System::Drawing::Size(75, 23);
			this->buttonFileSeq2->TabIndex = 11;
			this->buttonFileSeq2->Text = L"From file";
			this->buttonFileSeq2->UseVisualStyleBackColor = true;
			this->buttonFileSeq2->Click += gcnew System::EventHandler(this, &MyForm::buttonFileSeq2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(317, 21);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Time";
			// 
			// labelTime
			// 
			this->labelTime->AutoSize = true;
			this->labelTime->Location = System::Drawing::Point(359, 21);
			this->labelTime->Name = L"labelTime";
			this->labelTime->Size = System::Drawing::Size(16, 13);
			this->labelTime->TabIndex = 13;
			this->labelTime->Text = L"---";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(13, 129);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(77, 13);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Similarity matrix";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(317, 46);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 13);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Result";
			// 
			// labelResult
			// 
			this->labelResult->AutoSize = true;
			this->labelResult->Location = System::Drawing::Point(359, 46);
			this->labelResult->Name = L"labelResult";
			this->labelResult->Size = System::Drawing::Size(16, 13);
			this->labelResult->TabIndex = 20;
			this->labelResult->Text = L"---";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// resultFileBtn
			// 
			this->resultFileBtn->Location = System::Drawing::Point(300, 74);
			this->resultFileBtn->Name = L"resultFileBtn";
			this->resultFileBtn->Size = System::Drawing::Size(75, 23);
			this->resultFileBtn->TabIndex = 21;
			this->resultFileBtn->Text = L"Result file";
			this->resultFileBtn->UseVisualStyleBackColor = true;
			this->resultFileBtn->Click += gcnew System::EventHandler(this, &MyForm::resultFileBtn_Click);
			// 
			// resultFileInput
			// 
			this->resultFileInput->Location = System::Drawing::Point(390, 74);
			this->resultFileInput->Name = L"resultFileInput";
			this->resultFileInput->Size = System::Drawing::Size(100, 20);
			this->resultFileInput->TabIndex = 22;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(521, 186);
			this->Controls->Add(this->resultFileInput);
			this->Controls->Add(this->resultFileBtn);
			this->Controls->Add(this->labelResult);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->labelTime);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->buttonFileSeq2);
			this->Controls->Add(this->buttonFileSeq1);
			this->Controls->Add(this->buttonMatrixFile);
			this->Controls->Add(this->matrixFileInput);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->punishmentInput);
			this->Controls->Add(this->btnCount);
			this->Controls->Add(this->checkBoxGPU);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->seq2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->seq1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btnCount_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void buttonFileSeq1_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void buttonFileSeq2_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void buttonMatrixFile_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void resultFileBtn_Click(System::Object^  sender, System::EventArgs^  e);
};
}
