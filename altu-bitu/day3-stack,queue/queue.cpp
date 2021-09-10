#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 10001; // circular queue -> 1 additional space needed

int front_pointer = 0, rear_pointer = 0;
vector<int> queue_vec(SIZE);

bool empty() {
	return front_pointer == rear_pointer;
}

bool full() {
	return (rear_pointer + 1) % SIZE == front_pointer;
}

void push(int k) {
	rear_pointer = (rear_pointer + 1) % SIZE;
	queue_vec[rear_pointer] = k;
}

int pop() {
	front_pointer = (front_pointer + 1) % SIZE;
	return queue_vec[front_pointer];
}

int size() {
	// rear = 1 front = 2
	int tmp = (rear_pointer - front_pointer);
	if (tmp < 0)
		tmp += SIZE;
	return tmp;
}

int front() {
	int tmp = (front_pointer + 1) % SIZE;
	return queue_vec[tmp];
}

int back() {
	return queue_vec[rear_pointer];
}

int main() {
	int n, k;
	string cmd;

	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> k;
		}
	}
}