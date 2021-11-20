// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	unordered_map<int, bool> mp;
	string temp = "";
	void calculate(string s, int i, vector<string> &res) {
		if (i == s.size())
			res.push_back(temp);
		else
		{
			for (int j = 0; j < s.size(); ++j)
			{
				if (!mp[j])
				{
					mp[j] = true;
					temp.push_back(s[j]);
					calculate(s, i + 1, res);
					mp[j] = false;
					temp.pop_back();
				}
			}
		}
	}
public:
	vector<string> find_permutation(string S)
	{
		// Code here there
		vector<string> res;
		sort(S.begin(), S.end());
		calculate(S, 0, res);
		return res;
	}
};



// { Driver Code Starts.
int main() {

	string S;
	cin >> S;
	Solution ob;
	vector<string> ans = ob.find_permutation(S);
	for (auto i : ans)
	{
		cout << i << " ";
	}
	cout << "\n";
	return 0;
}
// } Driver Code Ends