#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace NWA;


[STAThread]
void Main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	NWA::MyForm form;
	Application::Run(%form);
}

System::Void MyForm::btnCount_Click(System::Object^  sender, System::EventArgs^  e) {

	try {
		std::string seq1 = msclr::interop::marshal_as<std::string>(this->seq1->Text);
		std::string seq2 = msclr::interop::marshal_as<std::string>(this->seq2->Text);
		if (this->matrixFileInput->Text == "")
			throw "No similarity matrix";
		if (this->punishmentInput->Text == "")
			throw "No punishment value";
		std::pair<std::vector<char>, int **> matrix = FileParser::readSimilarityMatrix(msclr::interop::marshal_as<std::string>(this->matrixFileInput->Text));
		int punishment = Convert::ToInt32(this->punishmentInput->Text);
		clock_t t;
		if (this->checkBoxGPU->Checked) {

		}
		else {
			linearNeedlemanWunsch lnw(matrix.first, matrix.second, -5);
			t = clock();
			int result = lnw.calculate(seq1, seq2);
			t = clock() - t;
			float elapsedTime = ((float)t) / CLOCKS_PER_SEC;
			this->labelResult->Text = Convert::ToString(result);
			this->labelTime->Text = Convert::ToString(elapsedTime) + " s";
		}
	}
	catch (char * e) {
		MessageBox::Show(msclr::interop::marshal_as<System::String^>(e));
	}
}

System::Void MyForm::buttonFileSeq1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		std::string file = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
		std::string seq = FileParser::readSequence(file);
		this->seq1->Text = msclr::interop::marshal_as<System::String^>(seq);
	}
}

System::Void MyForm::buttonFileSeq2_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		std::string file = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
		std::string seq = FileParser::readSequence(file);
		this->seq2->Text = msclr::interop::marshal_as<System::String^>(seq);
	}
}

System::Void MyForm::buttonMatrixFile_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->matrixFileInput->Text = openFileDialog1->FileName;
	}
}