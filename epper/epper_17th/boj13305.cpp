/* average */
#include <iostream>
#include <vector>

using namespace std;
/* ans가 20억 초과할 수 있음 -> longlong 자료형 사용 */
long long solution(int n, int distance[], int price[]) {
	long long min_price = price[0];
	long long ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (min_price > price[i]) min_price = price[i];
		ans += min_price * distance[i];
	}
	return ans;
}
int main() {
	int n;
	int distance[100000] = { 0 };
	int price[100000] = { 0 };
	int i;
	long long ans = 0;

	cin >> n;

	for (i = 0; i < n - 1; i++) 
		cin >> distance[i];
	for (i = 0; i < n ; i++)
		cin >> price[i];

	ans = solution(n, distance, price);
	cout << ans;
}
