#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000

using namespace std;

// driver function to sort the 2D matrix
// on basis of a particular column;

bool sort_second_col(const vector<int>& v1, const vector<int>& v2) {
	return v1[1] < v2[1];
}

int main() {
	int N;
	cin >> N;

	// vector array ¼±¾ð 
	vector <vector<int>> arr(N, vector<int>(2, 0));
	for(int i = 0 ; i< N; i++)
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	// sorting on basis of 2nd column
	sort(arr.begin(), arr.end(), sort_second_col);
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
		
	

}