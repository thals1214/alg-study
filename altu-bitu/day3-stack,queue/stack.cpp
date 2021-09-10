/* stack */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int SIZE = 10000;
int top_pointer = -1; // initial value -1
vector<int> stack_vec(SIZE);


// empty
bool empty() {
	return top_pointer == -1;
}

// full
bool full() {
	return top_pointer == SIZE - 1;
}

// push
void push(int k) {
	stack_vec[++top_pointer] = k;
}

// pop
int pop() {
	return stack_vec[top_pointer--];
}

// size
int size() {
	return top_pointer +1;
}

// top 
int top() {
	return stack_vec[top_pointer];
}



int main() {
	int n, k;
	cin >> n;

	string cmd;
	stack<int> s;


	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> k;
//			if (!full()) // library 사용시 필요없음
//				s.push(k);
			continue;
		}
		if (cmd == "pop") {
			cin >> k;
			if (empty())
				cout << -1 << "\n";
			else {
				cout << s.top() << '\n';
				s.pop();
				continue;
			}
		}

		if (cmd == "size") {
			cout << size() << '\n';
			continue;
		}
		if (cmd == "empty") {
			cout << empty() << '\n';
			continue;
		}
		if (cmd == "top") {
			if (empty())
				cout << -1 << "\n";
			else
				cout << top() << '\n';
			continue;
		}
}