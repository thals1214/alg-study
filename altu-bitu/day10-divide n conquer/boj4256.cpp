//트리
#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder, inorder_idx

//트리를 분할하여 postorder 결과를 출력하는 함수
void divide(int idx, int left, int right) {
	if (left > right) 
		return;
	int root = preorder[idx];
	int root_idx = inorder_idx[root];

	divide(idx + 1, left, root_idx - 1);
	divide(idx + (root_idx - left) + 1, right);

	cout << root << ' ';
}

int main() {
	int t, n, num;

	cin >> t;
	while (t--) {
		//입력
		cin >> n;
		preorder.assign(n, 0);
		inorder_idx.assign(n + 1, 0);

		for(int i = 0; i<n; i++)
			cin >> preorder[i];
		for (int i = 0; i < n; i++)
			cin >> inorder_idx[i];
	}
}