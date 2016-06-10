#pragma once

#include <string>
#include <utility>
#include <fstream>
#include <vector>
#include <sstream>
#include <utility>

using namespace std;

class FileParser
{
public:
	FileParser();
	static pair<vector<char>, int **> readSimilarityMatrix(string file);
	static string readSequence(string file);
	static void saveSequences(string file, pair<string, string> sequences);
	~FileParser();
};

