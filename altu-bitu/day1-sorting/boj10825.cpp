#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct info {
	string name;
	int korean, english, math;
};

// 비교함수 bad
bool cmp(const info& i1, const info& i2) {
	if (i1.korean == i2.korean) {
		if (i1.english == i2.english) {
			if (i1.math == i2.math)
				return i1.name < i2.name;
			return i1.math > i2.math;
		}
		return i1.english < i2.english;
	}
	return i1.korean > i2.korean;
}

bool cmpAdv(const info& i1, const info& i2) {
	if (i1.korean != i2.korean) // 국어 점수가 다르다면 감소하는 순서
		return i1.korean > i2.korean;
	if (i1.english != i2.english) // 영어 점수가 다르다면 증가하는 순서
		return i1.english < i2.english;
	if (i1.math != i2.math) // 수학 점수가 다르다면 감소하는 순서
		return i1.math > i2.math;
	return i1.name < i2.name;
}
int main() {
	int n;
	vector<info> student;

	cin >> n;
	student.assign(n, {});
	for (int i = 0; i < n; i++)
		cin >> student[i].name >> student[i].korean >> student[i].english >> student[i].math;

	sort(student.begin(), student.end(), cmpAdv);

	for (int i = 0; i < n; i++) {
		cout << student[i].name << "\n";
	}

}