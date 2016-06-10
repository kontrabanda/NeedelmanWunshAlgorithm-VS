#include "stdafx.h"
#include "CppUnitTest.h"
#include "../NWA/FileParser.h"
#include "../NWA/linearNeedlemanWunsch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NWAtests
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			vector<char> characters;
			characters.push_back('A');
			characters.push_back('G');
			characters.push_back('C');
			characters.push_back('T');
			int values[4][4] = {
				{ 10, -1, -3, -4 },
				{ -1, 7, -5, -3 },
				{ -3, -5, 9, 0 },
				{ -4, -3, 0, 8 }
			};
			int** matrix = new int*[4];
			for (int i = 0; i<4; i++) {
				matrix[i] = new int[4];
				for (int j = 0; j<4; j++) {
					matrix[i][j] = values[i][j];
				}
			}
			linearNeedlemanWunsch lnw(characters, matrix, -5);
			int result = lnw.calculate("GAATTC", "GATTA");
			Assert::AreEqual(result, 25);
		}
		
		TEST_METHOD(TestMethod2)
		{
			vector<char> characters;
			characters.push_back('A');
			characters.push_back('G');
			characters.push_back('C');
			characters.push_back('T');
			int values[4][4] = {
				{10, -1, -3, -4},
				{-1, 7, -5, -3},
				{-3, -5, 9, 0},
				{-4, -3, 0, 8}
			};
			int** matrix = new int*[4];
			for (int i = 0; i<4; i++) {
				matrix[i] = new int[4];
				for (int j = 0; j<4; j++) {
					matrix[i][j] = values[i][j];	
				}
			}
			linearNeedlemanWunsch lnw(characters, matrix, -5);
			pair<string, string> path = lnw.getBackwardPath("GAATTC", "GATTA");
			Assert::AreEqual(path.first, string("GAATTC"));
			Assert::AreEqual(path.second, string("GA_TTA"));
		}

		TEST_METHOD(TestMethod3)
		{
			vector<char> characters;
			characters.push_back('A');
			characters.push_back('G');
			characters.push_back('C');
			characters.push_back('T');
			int values[4][4] = {
				{ 10, -1, -3, -4 },
				{ -1, 7, -5, -3 },
				{ -3, -5, 9, 0 },
				{ -4, -3, 0, 8 }
			};
			int** matrix = new int*[4];
			for (int i = 0; i<4; i++) {
				matrix[i] = new int[4];
				for (int j = 0; j<4; j++) {
					matrix[i][j] = values[i][j];
				}
			}
			linearNeedlemanWunsch lnw(characters, matrix, -5);
			bool exceptionThrown = false;
			try {
				int result = lnw.calculate("ABCD", "GATTA");
			}
			catch (char * e) {
				exceptionThrown = true;
			}
			Assert::AreEqual(exceptionThrown, true);
		}

	};
}