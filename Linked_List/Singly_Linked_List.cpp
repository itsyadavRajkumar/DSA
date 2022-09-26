#include <iostream>
using namespace std;

class Node {
public:
	int val;
	Node *next;
	Node(int val) {
		this->val = val;
		next = NULL;
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
	virtual Node* deleteIterative(Node *head, int k) = 0;
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
	void Delete(int k) {
		head = deleteIterative(head, k);
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
			tail->next = newNode;
			tail = tail->next;
		}
		return tail;
	}

	void printInterative(Node *head) {
		while (head) {
			cout << head->val << ' ';
			head = head->next;
		}
		cout << '\n';
	}

	void printRecursive(Node *head) {
		if (!head) return;
		cout << head->val << ' ';
		printRecursive(head->next);
	}

	Node *reverseIterative(Node *head) {
		Node *curr = head, *pre = NULL, *nxt = head;
		while (curr) {
			nxt = curr->next;
			curr->next = pre;
			pre = curr;
			curr = nxt;
		}
		return pre;
	}

	Node *reverseRecursive(Node *head) {
		if (head == NULL || head->next == nullptr) return head;
		Node *restNode = reverseRecursive(head->next);
		head->next->next = head;
		head->next = nullptr;
		return restNode;
	}

	Node *deleteIterative(Node *head, int k) {
		if (head == NULL) return head;
		if (k == 1) {
			Node *pre = head;
			head = head->next;
			delete pre;
			return head;
		}
		Node *pre = NULL, *curr = head;
		while (curr != nullptr) {
			if (k == 1) {
				pre->next = curr->next;
				delete curr;
				return head;
			}
			k--;
			pre = curr;
			curr = curr->next;
		}
		return head;
	}
};

int main() {
	int n; cin >> n;
	Body *ob = new Solution();
	for (int i = 0; i < n; ++i) {
		int val; cin >> val;
		ob->create(val);
	}
	ob->print();
	// ob->reverse();
	ob->Delete(2); // enter > 0
	ob->print();
	return 0;
}