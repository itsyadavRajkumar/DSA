#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int val;
	Node *next, *prev;
	Node(int val) {
		this->val = val;
		next = prev = NULL;
	}
};

class Solution {
private:
	Node *head, *tail;
public:
	Solution(): head(NULL), tail(NULL) {}
private:
	Node *create(int val, Node *head) {
		Node *newNode = new Node(val);
		if (head == NULL) {
			head = newNode;
			this->head = head;
		}
		else {
			head->next = newNode;
			newNode->prev = head;
			head = head->next;
		}
		return head;
	}

	void insertAtHead(int val, Node *head) {
		Node *newNode = new Node(val);
		if (head == NULL) {
			this->head = newNode;
			return;
		}
		newNode->next = head;
		head->prev = newNode;
		this->head = newNode;
	}

	void insertAtTail(int val, Node *head) {
		if (head == NULL) {
			insertAtHead(val, head);
			return;
		}
		Node *newNode = new Node(val);
		while (head->next != NULL) {
			head = head->next;
		}
		head->next = newNode;
		newNode->prev = head;
	}

	void insertAtKPosition(int val, int k, Node *head) {
		if (k == 1) {
			insertAtHead(val, head);
			return;
		}
		Node *newNode = new Node(val);
		Node *pre = NULL;
		while (head) {
			if (k == 1) {
				pre->next = newNode;
				newNode->prev = pre;
				newNode->next = head;
				head->prev = newNode;
				return;
			}
			k--;
			pre = head;
			head = head->next;
		}
		pre->next = newNode;
		newNode->prev = pre;
	}

	void printNext(Node *head) {
		Node *temp = head;
		while (temp != NULL) {
			cout << temp->val << ' ';
			temp = temp->next;
		}
		cout << '\n';
	}

	void printPrev(Node *tail) {
		while (tail->next) tail = tail->next;
		Node *temp = tail;
		while (temp) {
			cout << temp->val << ' ';
			temp = temp->prev;
		}
		cout << '\n';
	}

	Node *reverseIterative(Node *head) {
		Node *pre = NULL, *curr = head, *nxt = head;
		while (curr != NULL) {
			nxt = curr->next;
			curr->next = pre;
			if (pre != nullptr)
				pre->prev = curr;
			pre = curr;
			curr = nxt;
		}
		return pre;
	}

	Node *reverseRecursive(Node *head) {
		if (head == NULL || head->next == NULL) return head;
		Node *restNode = reverseRecursive(head->next);
		auto nxt = head->next;
		nxt->next = head;
		head->prev = nxt;
		head->next = nullptr;
		restNode->prev = nullptr;
		return restNode;
	}

public:
	void create(int val) {
		tail = create(val, tail);
		// insertAtHead(1, head);
		// insertAtHead(2, head);
		// insertAtHead(3, head);
		// insertAtTail(4, head);
		// insertAtKPosition(8, 2, head);
		// insertAtKPosition(11, 2, head);
		// insertAtKPosition(111, 2, head);
	}

	void reverse() {
		// head = reverseIterative(head);
		head = reverseRecursive(head);
	}

	void print() {
		// printNext(head);
		printPrev(head);
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
	ob.reverse();
	ob.print();
	return 0;
}