#ifndef LINEARNEEDLEMANWUNSCH_H
#define LINEARNEEDLEMANWUNSCH_H

#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<utility>

using namespace std;

/* Klasa posiadaj¹ca funkcjê obliczania globalnego dopasowania dwóch sekwencji algorytem Needelmana-Wunsha w pamiêci liniowej z liniow¹ kar¹ za przerwê. */

class linearNeedlemanWunsch
{
public:
	/* Konstruktor klasy.
	signs - zbór znaków, które mog¹ wyst¹piæ w sekwencjach,
	matrix - macierz podobieñstw,
	punish - kara za przerwê
	*/
	linearNeedlemanWunsch(vector<char> signs, int **matrix, int punish = -5);
	/* Oblicza maksymaln¹ ocenê dopasowania dwóch sekwencji.*/
	int calculate(string seq1, string seq2);
	/* Oblicza najlepsze dopasowanie globalne dwóch sekwencji.  */
	pair<string, string> getBackwardPath(string seq1, string seq2);


private:
	string seq1;
	string seq2;

	map<char, int> signsMap;
	int** similarityMatrix;
	int punishment;
	string best_fit_1;
	string best_fit_2;

	int getMax(int a, int b, int c);

	vector<pair<int, int> > findWaypoint(string seq1, string seq2, pair<int, int> begin);
};

#endif // LINEARNEEDLEMANWUNSCH_H