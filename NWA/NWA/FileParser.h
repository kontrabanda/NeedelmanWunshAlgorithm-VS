#pragma once

#include <string>
#include <utility>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class FileParser
{
public:
	FileParser();
	static pair<vector<char>, int **> readSimilarityMatrix(string file);
	static string readSequence(string file);
	~FileParser();
};

