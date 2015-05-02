// Steven Holland
// COMP 370
// Assignment 7

//UVa #572 Oil Deposits

// To solve this problem I used a resursive flood-fill algorithm.

#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

char graph[105][105];
list <int> location;


void floodFill() {
	int column = location.front();
	location.pop_front();
	int row = location.front();
	location.pop_front();
	graph[row][column] = '*';

	// Check diagonal top left
	if (graph[row - 1][column - 1] == '@') {
		location.push_front(row - 1);
		location.push_front(column - 1);
	}

	// Check up
	if (graph[row - 1][column] == '@') {
		location.push_front(row - 1);
		location.push_front(column);
	}

	// Check diagonal top right
	if (graph[row - 1][column + 1] == '@') {
		location.push_front(row - 1);
		location.push_front(column + 1);
	}

	// Check right
	if (graph[row][column + 1] == '@') {
		location.push_front(row);
		location.push_front(column + 1);
	}

	// Check diagonal bottom right
	if (graph[row + 1][column + 1] == '@') {
		location.push_front(row + 1);
		location.push_front(column + 1);
	}

	// Check down
	if (graph[row + 1][column] == '@') {
		location.push_front(row + 1);
		location.push_front(column);
	}

	//Check diagonal bottom left
	if (graph[row + 1][column - 1] == '@') {
		location.push_front(row + 1);
		location.push_front(column - 1);
	}

	// Check left
	if (graph[row][column - 1] == '@') {
		location.push_front(row);
		location.push_front(column - 1);
	}

}


int main() {

	freopen("in.txt", "r", stdin);

	int m, n;

	while (cin >> m >> n) {
		if (m == 0) {
			return 0;
		}

		// Initialize the graph
		location.clear();
		int i, j;
		for (i = 0; i < 105; i++){
			for (j = 0; j < 105; j++) {
				graph[i][j] = '.';
			}
		}

		// Get all the input for the graph
		for (i = 1; i <= m; i++) {
			for (j = 1; j <= n; j++) {
				cin >> graph[i][j];
			}
		}

		// Recursive step
		int result = 0;
		for (i = 1; i <= m; i++) {
			for (j = 1; j <= n; j++) {
				if (graph[i][j] == '@') {
					result++;
					location.push_front(i);
					location.push_front(j);
					while (location.size()) {
						floodFill();
					}
				}
			}
		}

		cout << result << endl;
	}
	return 0;
}