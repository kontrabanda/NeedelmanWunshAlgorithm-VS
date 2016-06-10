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

		std::string file = msclr::interop::marshal_as<std::string>(this->seq1->Text);
		std::string sequence1 = FileParser::readSequence(file);
		file = msclr::interop::marshal_as<std::string>(this->seq2->Text);
		std::string sequence2 = FileParser::readSequence(file);
		if (this->matrixFileInput->Text == "")
			throw "No similarity matrix";
		if (this->punishmentInput->Text == "")
			throw "No punishment value";
		if (sequence1 == "" || sequence1 == "")
			throw "Empty sequences";
		std::pair<std::vector<char>, int **> matrix = FileParser::readSimilarityMatrix(msclr::interop::marshal_as<std::string>(this->matrixFileInput->Text));
		int punishment = Convert::ToInt32(this->punishmentInput->Text);
		clock_t t;
		pair<string, string> path;
		int result = 0;
		float elapsedTime = 0;
		if (this->checkBoxGPU->Checked) {

		}
		else {
			linearNeedlemanWunsch lnw(matrix.first, matrix.second, -5);
			t = clock();
			result = lnw.calculate(sequence1, sequence2);
			path = lnw.getBackwardPath(sequence1, sequence2);
			t = clock() - t;
		}
		elapsedTime = ((float)t) / CLOCKS_PER_SEC;
		this->labelResult->Text = Convert::ToString(result);
		this->labelTime->Text = Convert::ToString(elapsedTime) + " s";
		FileParser::saveSequences(msclr::interop::marshal_as<std::string>(this->resultFileInput->Text), path);
	}
	catch (char * e) {
		MessageBox::Show(msclr::interop::marshal_as<System::String^>(e));
	}
}

System::Void MyForm::buttonFileSeq1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->seq1->Text = openFileDialog1->FileName;
	}
}

System::Void MyForm::buttonFileSeq2_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->seq2->Text = openFileDialog1->FileName;
	}
}

System::Void MyForm::buttonMatrixFile_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->matrixFileInput->Text = openFileDialog1->FileName;
	}
}

System::Void MyForm::resultFileBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->resultFileInput->Text = openFileDialog1->FileName;
	}
}