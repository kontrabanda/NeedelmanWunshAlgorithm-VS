#ifndef LINEARNEEDLEMANWUNSCH_H
#define LINEARNEEDLEMANWUNSCH_H

#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<utility>

using namespace std;

/* Klasa posiadaj�ca funkcj� obliczania globalnego dopasowania dw�ch sekwencji algorytem Needelmana-Wunsha w pami�ci liniowej z liniow� kar� za przerw�. */

class linearNeedlemanWunsch
{
public:
	/* Konstruktor klasy.
	signs - zb�r znak�w, kt�re mog� wyst�pi� w sekwencjach,
	matrix - macierz podobie�stw,
	punish - kara za przerw�
	*/
	linearNeedlemanWunsch(vector<char> signs, int **matrix, int punish = -5);
	/* Oblicza maksymaln� ocen� dopasowania dw�ch sekwencji.*/
	int calculate(string seq1, string seq2);
	/* Oblicza najlepsze dopasowanie globalne dw�ch sekwencji.  */
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