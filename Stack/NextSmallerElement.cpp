#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> prevSmaller(vector<int> &A)
{
	int n = A.size();
	vector<int > res(n, -1);
	stack<int> s;
	for (int i = 0; i < n; ++i)
	{
		while (!s.empty() && A[s.top()] >= A[i])
		{
			s.pop();
		}
		if (!s.empty() && A[s.top()] < A[i])
		{
			res[i] = A[s.top()];
		}
		s.push(i);
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}
	return 0;
}