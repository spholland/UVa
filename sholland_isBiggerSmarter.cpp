// Steven Holland
// COMP 370
// Assignment 4

// UVa  Problem #10131
// Is Bigger Smarter?
// In this problem we are to find the longest increasing subsequence of
// elephants in which weight is increasingand IQs are decreasing. This 
// will be done using dynamic programming.

// The answer we are trying to get is the longest possible subsequence
// in the sorted order of elephants.

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <array>

using namespace std;


// This is my struct for the elephants, storing their weight, iq, and id.
struct Elephant {
	int weight;
	int iq;
	int id;

};


// This is a weight comparison function I will use with my sort method later
bool weightCompare(Elephant A, Elephant B) {
	if (A.weight == B.weight) {
		return A.iq > B.iq;
	}
	return A.weight < B.weight;
}

// This function prints out the answer by going through the previously
// found information about the longest increasing subsequence.
void getAnswer(vector<int> &ELEOrder, vector<int> &SLength, vector<Elephant> vector) {

	int temp = 0;
	int index = -1;
	for (int i = 0; i < SLength.size(); i++) {
		if (SLength[i] > temp) {
			temp = SLength[i];
		index = i;
		}
	}
	cout << temp << endl;
	while (index != -1) {
		cout << vector[index].id << endl;
		index = ELEOrder[index];
	}
}


// My algorithm for the longest increasing subsequence 
 void longEnough(vector<int> &ELEOrder, vector<int> &SLength, vector<Elephant> vector) {

	 for (int i = vector.size() - 2; i >= 0; i--) {
		 for (int j = i + 1; j < vector.size(); j++) {
			 if ((vector[i].weight < vector[j].weight) && (vector[i].iq > vector[j].iq)) {
				 if (SLength[i] < SLength[j] + 1) {
					 ELEOrder[i] = j;
					 SLength[i] = SLength[j] + 1;
				 }
			 }
		 }
	 }
}


int main() {
	freopen("IsBSinput.txt", "r", stdin);

	int weight, iq;
	struct Elephant ELE;
	vector<int> ELEOrder;
	vector<int> SLength;
	vector<Elephant> vector;
	


	int i = 1;
	while (cin >> weight >> iq) {
		ELE.weight = weight;
		ELE.iq = iq;
		ELE.id = i;
		vector.push_back(ELE);
		i++;
	}

	sort(vector.begin(), vector.end(), weightCompare);

	for (int i = 0; i < vector.size(); i++) {
		ELEOrder.push_back(-1);
		SLength.push_back(1);
	}


	longEnough(ELEOrder, SLength, vector);
	getAnswer(ELEOrder, SLength, vector);

	// This was a test to see if the elephants were being sorted correctly.
	/*for (int i = 0; i < vector.size(); i++) {
		cout << endl << vector[i].weight << " " << vector[i].iq << " " << vector[i].id << endl;
	}*/




	return 0;
}