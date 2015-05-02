// Steven Holland
// COMP 370
// Assignment 4

// UVa  Problem #10131
// Is Bigger Smarter?
// In this problem we are to find the longest increasing subsequence of
// elephants in which weight is increasingand IQs are decreasing. This 
// will be done using dynamic programming.

// The answer we are trying to get is the longest possible subsequence
// in the sorted order of elephants. To do this I created a structure
// to store each of the elephant's weight, IQ, and ID. I then sorted the 
// elephants by increasing weight in a vector. I used a vector because
// it seemed like the easiest way to asses the problem due to the ability
// of a vector to be easily modified. To find the longest increasing 
// subequence of elephants, I used two loops. This allowed me to loop 
// through the elephants starting at the end and going backwards while 
// checking any previous subsequences found to find the longest one. If
// a longer sequence is found, it will update and continue until the loop
// has reached the beginning of the vector of elephants. I then outputted
// the previously found longest increasing subsequence information, including
// the total amount of the sequence and the elephant IDs associated with it.



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
// found information about the longest increasing subsequence. I started
// with an index of -1 because that doesn't relate to an element in the 
// vector.
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
// Here I loop the amount of times as the size of the vector, backwards starting
// at the end of the vector while checking for appropriate weight and iq
// distribution. I two vecctors ELEOrder and SLength to keep track of the final
// elephant order and sequence length. 
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

// In this main function I initialize all my variables, get the
// elephant information, and then sort the elephants by increasing
// weight. I then call methods to find the longest increasing
// subsequence and output the final answer and IDs of all the
// elephants included.
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