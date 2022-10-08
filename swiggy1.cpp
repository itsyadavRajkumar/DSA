
// quesiton link :- https://takeuforward.org/interview-experience/swiggy-interview-experience-sde-set-1/
#include <bits/stdc++.h>
using namespace std ;


void solve() {
	string s ; cin >> s;
	int n = s.size();
	int i = 0 , j = 0 , ans = 0;
	unordered_map<char , int> mp;

	for ( int i = 0 ; i < n ; i ++) {
		while ( mp[s[i]]) mp[s[j]] = 0 , j ++ ;

		ans += (  i - j + 1);
		mp[s[i]] = 1;
	}

	cout << ans;
}



inline void testcases() {
	int test = 1, testcase = 1 ;
	//cin >> test ;

	cout << setprecision(12) ;
	cerr << setprecision(8) ;
	while (test --) {
		// cout << "Case #" << testcase++ << ": ";
		solve () ;
	}
}





int main () {
	fastio();

#ifndef ONLINE_JUDGE
	// freopen("output.txt", "w", stdout);
	// freopen("input.txt", "r", stdin);
	//freopen("error.txt", "w", stderr);
#endif

	auto start = high_resolution_clock::now();

	testcases();

	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);

	cerr << "Time : " << duration.count() / 1000 ;
}
