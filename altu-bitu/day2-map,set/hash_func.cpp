#include <iostream>
#include <vector>

using namespace std;
const int MAX_SIZE = 3;

// bucket
vector<vector<pair<string,int>>> bucket;

// hash function
int hashFunc(string str) {
	int key = 0;
	for (int i = 0; i < str.size(); i++)
		key += (str[i] - 'a') * i;
	return key % MAX_SIZE;

}

void printHash() {
	for (int i = 0; i < MAX_SIZE; i++) {
		cout << "[" << i << "]";
		for(int j = 0; j< bucket[i].size();j++)
			cout << "-> ( " << bucket[i][j].first << ' ' << bucket[i][j].second << " ) ";
		cout << '\n';
	}
}

int findScore(string name) {
	int key = hashFunc(name);
	for (int i = 0; i < bucket[key].size(); i++) {
		if (bucket[key][i].first == name)
			return bucket[key][i].second;
	}
	return -1; // 일치 데이터 없음
}
int main() {
	// input
	vector<pair<string, int>> student;
	student.push_back(make_pair("lee", 42)); //-> student.emplae_back("lee",42) 
	student.push_back(make_pair("kim", 180));
	student.push_back(make_pair("lim", 75));
	student.push_back(make_pair("park", 88));

	// 연산
	bucket.assign(MAX_SIZE, vector<pair<string, int>>(0));
	for (int i = 0; i < student.size(); i++) {
		int key = hashFunc(student[i].first);
		bucket[key].push_back(student[i]);
	}
	printHash();

	string target = "lim";
	int score = findScore(target);

	if (score == -1)
		cout << "No Such Data \n";
	else
		cout << "Score of " << target << " : " << score << '\n';


}