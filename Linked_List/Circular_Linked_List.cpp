#include <iostream>
using namespace std;

class Node {
public:
	int val;
	Node *next;
	Node(int val) {
		this->val = val;
		next = nullptr;
	}
};

class Solution {
	Node *head, *tail;
	Node *create(int val, Node *head) {
		Node *newNode = new Node(val);
		if (this->head == nullptr) {
			this->head = head = newNode;
		}
		else {
			head->next = newNode;
			head = head->next;
		}
		return head;
	}
	void print(Node *head) {
		Node *temp = head;
		if (!head) return;
		do {
			cout << temp->val << ' ';
			temp = temp->next;
		}
		while (temp != head);
	}
public:
	Solution(): head(nullptr), tail(nullptr) {}
	void create(int val) {
		tail = create(val, tail);
		tail->next = head;
	}
	void print() {
		print(head);
	}
};

int main() {
	int n; cin >> n;
	Solution ob;
	for (int i = 0; i < n; ++i) {
		int val; cin >> val;
		ob.create(val);
	}
	ob.print();
	return 0;
}