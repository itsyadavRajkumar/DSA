#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll >
#define vi vector<int >
#define N 1e6
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

class Tree {
public:
	int data;
	vector<Tree *> children;
	Tree(int data) {
		this->data = data;
	}
};

Tree *createTree() {
	int rootData; cin >> rootData;
	Tree* root = new Tree(rootData);
	queue<Tree* > pendingRoot;
	pendingRoot.push(root);
	while (!pendingRoot.empty()) {
		int numChildren; cin >> numChildren;
		Tree* front = pendingRoot.front();
		pendingRoot.pop();
		for (int i = 0; i < numChildren; ++i) {
			int childrenData; cin >> childrenData;
			Tree* child = new Tree(childrenData);
			front->children.pb(child);
			pendingRoot.push(child);
		}
	}
	return root;
}

void printTree(Tree* root) {
	if (root == NULL) return;
	cout << root->data << " : ";
	for (int i = 0; i < root -> children.size(); ++i) {
		cout << root->children[i]->data << ' ';
	}
	cout << '\n';
	for (int i = 0; i < root->children.size() ; ++i) {
		printTree(root->children[i]);
	}
}

// 1
// 3
// 2 3 4
// 1 5
// 1 6
// 1 7
// 0 0 0

int main() {
	fast;
	Tree* root = createTree();
	printTree(root);
	return 0;
}