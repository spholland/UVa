// Steven Holland
// COMP 370
// Assignment 5

// UVa Problem #10130 SuperSale
// This is a great example of the knapsack problem we discussed in class this week. This
// problem is looking for the maximum value of some items when given a maximum amount of
// weight a person can hold.
// To solve this problem I used dynamic programming with a 2D vector called "graph" to 
// demonstrate the easiest way I know how to solve the knapsack problem.

// Steps:
// 1. Initialize the 2D vector and populate the first column
// 2. Find the maximum knapsack value
// 3. Print out the max value and move onto the next case

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


// Enumeration declaration
enum Type {
	VALUE,
	COST
};

// My vectors to store values for the items, people involved, and the graph
// used in knapsack calculation
vector<vector<int> > items;
vector <int> group;
vector<vector<int> > graph;

int Cap = 0;

// This method will initialize the graph using a temporary vector "row"
// and pushing it to our 2D vector "graph", initializing all elements to 0.
void initGraph() {
	for (int i = 0; i < Cap; i++) {
		vector<int> row;
		for (int j = 0; j < items.size(); j++) {
			row.push_back(0);
		}
		graph.push_back(row);
	}
}

// This method will calculate the maximun knapsack value
void maxKnap() {
	for (int column = 0; column < items.size(); column++) {
		for (int row = 0; row < Cap; row++) {
			if (column == 0) {
				if (items[column][COST] <= (row + 1)) {
					graph[row][column] = items[column][VALUE];
				}
			}
			else {
				int ls = 0, rs = 0;
				ls = graph[row][column - 1];
				if (items[column][COST] <= (row + 1)) {
					if (row >= items[column][COST]) {
						rs = items[column][VALUE] + graph[row - items[column][COST]][column - 1];
					}
					else {
						rs = items[column][VALUE];
					}
				}
				graph[row][column] = max(ls, rs);
			}
		}
	}
}


// My main method.
int main() {
	freopen("SaleInput.txt", "r", stdin);
	int t, n, p, w, g, mw;
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		items.clear();
		group.clear();
		graph.clear();

		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> p >> w;
			vector<int> row;
			row.push_back(p);
			row.push_back(w);
			items.push_back(row);
		}

		cin >> g;
		for (int k = 0; k < g; k++) {
			cin >> mw;
			Cap = max(mw, Cap);
			group.push_back(mw);
		}

		initGraph();
		int Knap = 0;
		maxKnap();
		for (int q = 0; q < g; g++) {
			Knap += graph[group[q] - 1][items.size() - 1];
		}
		cout << Knap << endl;
	}


	return 0;
}