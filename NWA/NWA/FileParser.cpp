#include "FileParser.h"



FileParser::FileParser()
{
}


FileParser::~FileParser()
{
}

pair<vector<char>, int **> FileParser::readSimilarityMatrix(string file) {
	vector<char> signs;
	int** matrix;
	std::fstream f;
	f.open(file, std::ios::in);
	if (f.good())
	{
		string line;
		getline(f, line);
		stringstream ss(line); // Insert the string into a stream
		char s;
		while (ss >> s)
			signs.push_back(s);
		int size = signs.size();
		matrix = new int*[size];
		int i = 0;
		while (!f.eof())
		{
			matrix[i] = new int[size];
			getline(f, line);
			stringstream ss(line); // Insert the string into a stream
			string s;
			int j = 0;
			while (ss >> s) {
				matrix[i][j] = stoi(s);
				j++;
			} 
			i++;
		}
		f.close();
	}
	else {
		throw "Cannot open file";
	}
	return make_pair(signs, matrix);
}

string FileParser::readSequence(string file) {
	string sequence;
	std::fstream f;
	f.open(file, std::ios::out);
	if (f.good())
	{
		getline(f, sequence);
		f.close();
	}
	else {
		throw "Cannot open file";
	}
	return sequence;

}