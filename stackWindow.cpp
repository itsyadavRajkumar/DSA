// An efficient C++ program to find
// maximum of all minimums of
// windows of different sizes
#include <bits/stdc++.h>
#include<stack>
using namespace std;


int MOD = 1000000007;
void printMaxOfMin(vector<int> &arr, int n) {

	vector<int> left(n, -1), right(n, n);
	// for every i find the Next smaller element to left and right

	// Left
	stack<int> st;
	for (int i = 0; i < n; i++) {
		while (st.size() && arr[i] < arr[st.top()]) st.pop();
		if (st.size()) left[i] = i - st.top();
		else left[i] = i + 1;
		st.push(i);
	}

	while (st.size()) st.pop();

	// Right
	for (int i = n - 1; i >= 0; i--) {
		while (st.size() && arr[i] <= arr[st.top()]) st.pop();
		if (st.size()) right[i] = st.top() - i;
		else right[i] = n - i;
		st.push(i);
	}

	for ( auto i : right) cout << i << " ";
	cout << endl;
	for ( auto i : left) cout << i << " "; cout << endl;
	// for(int i=0; i<n; i++) cout << left[i] << " : " << right[i] << endl;

	// for each i, contribution is (Left * Right) * Element

	int res = 0;
	for (int i = 0; i < n; i++) {
		long long prod = (left[i] * right[i]) % MOD;
		prod = (prod * arr[i]) % MOD;
		res = (res + prod) % MOD;
	}


	cout << res;
}

// Driver program
int main() {
	int t , n ; cin >> t >> n ;

	while ( t-- > 0 ) {
		vector<int> arr( n , 0 );
		for ( int i = 0 ; i < n ; i ++) cin >> arr[i];

		printMaxOfMin(arr, n);
	}
	return 0;
}
