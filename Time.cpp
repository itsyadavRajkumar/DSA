/*
     ContestName     =   Shinchu_itachi
   " Walking on the road not taken with my own gutts.. "
*/


#include <bits/stdc++.h>
using namespace std ;

vector<int> bit(N);
int n ;
long long sum ( int i ) {
    long long r = 0 ;

    while ( i > 0) {
        r += bit[i];
        i -= ( i & -i);
    }

    return r;
}

void update ( int i , int val ) {
    while ( i < n ) {
        bit[i] += val;
        i += (i & -i);
    }
}

void cal ( vi &a ) {
    vi b ;
    for ( auto i : a ) b.pb(2 * i);

    set <long long > st;
    st.insert( a.begin() , a.end());
    for ( auto i : b) st.insert(i);

    for ( auto i : st) cout << i << " ";
    cout << endl;

    map<long long , int> mp;



    cout << endl;

    int p = 1;
    for ( auto &i : st) mp[i] = p++;
    for ( auto i : mp) cout << i.first << " -> " << i.second << endl;
    cout << endl;
    int c = 0 ;

    for ( int i = b.size() - 1 ; i >= 0 ; i --) {
        cout << a[i] << " -> " << mp[b[i]] << " -> " << sum(mp[b[i] / 2] ) << endl;
        c += ( sum (mp[b[i] / 2 * 1LL] - 1));
        update(mp[b[i]] , 1 );
    }

    cout << c << endl;

}

void solve() {
    cin >> n ;
    vi a(  n , 0);
    fin(a)

    cout << endl;

    cal ( a );
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
