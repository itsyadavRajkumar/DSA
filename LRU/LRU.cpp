#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
	int key, val;
	Node *next, *prev;
	Node(int key, int val) {
		this->key = key;
		this->val = val;
		next = prev = nullptr;
	}
};

class Solution {
	Node *head, *tail;
	int capacity;
	unordered_map<int, Node*> hashMap;
public:
	Solution(int capacity) {
		head = new Node(-1, -1);
		tail = new Node(-1, -1);
		this->capacity = capacity;
		head->next = tail;
		tail->prev = head;
	}
	void addNode(int key, int val) {
		Node *nxt = head->next;
		Node *newNode = new Node(key, val);
		newNode->next = nxt;
		nxt->prev = newNode;
		newNode->prev = head;
		head->next = newNode;
		hashMap[key] = newNode;
	}

	void deleteNode(Node *delNode) {
		Node *pre = delNode->prev;
		Node *nxt = delNode->next;
		pre->next = nxt;
		nxt->prev = pre;
		hashMap.erase(delNode->key);
		delete delNode;
	}

	void put(int key, int val) {
		if (hashMap.find(key) != hashMap.end()) {
			Node *delNode = hashMap[key];
			hashMap.erase(key);
			deleteNode(delNode);
		}
		if (size()) {
			Node *delNode = tail->prev;
			deleteNode(delNode);
		}
		addNode(key, val);
	}

	int get(int key) {
		int res = -1;
		if (hashMap.find(key) != hashMap.end()) {
			Node *resNode = hashMap[key];
			res = resNode->val;
			deleteNode(resNode);
			addNode(key, res);
		}
		return res;
	}

	bool size() {
		return capacity == hashMap.size();
	}
};

int main() {

	return 0;
}