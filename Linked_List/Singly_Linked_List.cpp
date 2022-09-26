#include <iostream>
using namespace std;

class Node {
public:
	int val;
	Node *Next;
	Node(int val) {
		this->val = val;
		Next = NULL;
	}
};

class Body {
private:
	Node *head, *tail;

	// Pure Virtual Function
	virtual void printInterative(Node* head) = 0;
	virtual void printRecursive(Node* head) = 0;
	virtual Node* reverseIterative(Node *head) = 0;
	virtual Node* reverseRecursive(Node *head) = 0;
	virtual Node* create(int val, Node **head, Node *tail) = 0;
	virtual Node* deleteIterative(Node *head) = 0;
public:
	Body(): head(NULL), tail(NULL) {}
	void create(int val) {
		tail = create(val, &head, tail);
	}
	void print() {
		printInterative(head);
	}
	void reverse() {
		// head = reverseIterative(head);
		head = reverseRecursive(head);
	}
};

class Solution: public Body {
private:
	Node *create(int val, Node **head, Node *tail) {
		Node *newNode = new Node(val);
		if (*head == nullptr) {
			*head = newNode;
			tail = newNode;
		}
		else {
			tail->Next = newNode;
			tail = tail->Next;
		}
		return tail;
	}

	void printInterative(Node *head) {
		while (head) {
			cout << head->val << ' ';
			head = head->Next;
		}
		cout << '\n';
	}

	void printRecursive(Node *head) {
		if (!head) return;
		cout << head->val << ' ';
		printRecursive(head->Next);
	}

	Node *reverseIterative(Node *head) {
		Node *curr = head, *pre = NULL, *nxt = head;
		while (curr) {
			nxt = curr->Next;
			curr->Next = pre;
			pre = curr;
			curr = nxt;
		}
		return pre;
	}

	Node *reverseRecursive(Node *head) {
		if (head == NULL || head->Next == nullptr) return head;
		Node *restNode = reverseRecursive(head->Next);
		head->Next->Next = head;
		head->Next = nullptr;
		return restNode;
	}

	Node *deleteIterative(Node *head) {}
};

int main() {
	int n; cin >> n;
	Body *ob = new Solution();
	for (int i = 0; i < n; ++i) {
		int val; cin >> val;
		ob->create(val);
	}
	ob->print();
	ob->reverse();
	ob->print();
	return 0;
}