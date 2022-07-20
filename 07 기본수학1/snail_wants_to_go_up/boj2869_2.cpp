#include <iostream>
using namespace std;

int main() {
	int A, B, V;
	cin >> A >> B >> V;

	// don't use iterative methods 
	int cnt = 1;
	cnt += (V - A) / (A - B);
	if (((V - A) % (A - B)) != 0) cnt++;
	
	cout << cnt;

}