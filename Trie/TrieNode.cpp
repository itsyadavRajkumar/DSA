#include <iostream>
using namespace std;

class TrieNode
{
public:
	char data;
	TrieNode **children;
	bool isTerminal;
	TrieNode(char data)
	{
		this->data = data;
		children = new TrieNode*[26];
		for (int i = 0; i < 26; ++i)
		{
			children[i] = '\0';
		}
		isTerminal = false;
	}
	~TrieNode();
};

class Trie
{
	TrieNode* root;
public:
	Trie()
	{
		root = new TrieNode('\0');
	}
	void InsertWord(TrieNode *root, string word)
	{
		// Base Case
		if (word.size() == 0)
		{
			root->isTerminal = true;
			return;
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if (root->children[index] != NULL)
		{
			child = root->children[index];
		}
		else
		{
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}

		// Recursive Call
		InsertWord(child, word.substr(1));
	}

	void InsertWord(string word)
	{
		InsertWord(root, word);
	}

	void Print()
	{

	}

	bool Search(TrieNode *root, string word)
	{
		if (word.size() == 0)
		{
			return root->isTerminal == true;
		}
		int index = word[0] - 97;
		if (root->children[index] != NULL)
		{
			if (Search(root->children[index], word.substr(1)))
				return true;
			else
				return false;
		}
		else return false;
	}

	bool Search(string word)
	{
		return Search(root, word);
	}

	bool Delete(TrieNode *root, string word)
	{
		if (word.size() == 0)
		{
			if (root->isTerminal == true)
			{
				root->isTerminal = false;

				return true;
			}
			else return false;
		}
		int index = word[0] - 97;
		TrieNode *child = root->children[index];
		if (child != NULL)
		{
			if (Delete(child, word.substr(1)))
			{
				TrieNode *check = new TrieNode(index + 'a');
				if (check == child)
				{
					// TrieNode *temp = root->children;
					root->children = NULL;
					// delete child;
				}
				return true;
			}
			else return false;
		}
		else return false;
	}

	void Delete(string word)
	{
		if (Delete(root, word))
			cout << "Done!!!\n";
		else
			cout << "Not Found\n";
	}
};

int main() {
	Trie ob;
	int t = 1; cin >> t;
	while (t--) {
		string word; cin >> word;
		ob.InsertWord(word);
	}
	cin >> t;
	while (t--) {
		string Search; cin >> Search;
		cout << ob.Search(Search) << '\n';
	}
	cin >> t;
	while (t--) {
		string Search; cin >> Search;
		ob.Delete(Search);
	}
	return 0;
}