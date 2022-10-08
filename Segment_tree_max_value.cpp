/*----
        |\   |   | /
        | \  |   |/     code created by SINCHU_ITACHI
        |  \ |   |\    "Fal ka kya hain Ache Karmas krtey raho , Fal market se le lena"
        |   \|   | \                                                                    -------*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/math/constants/constants.hpp>
// using namespace boost::multiprecision;
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define ll          long long
#define fn0         for(int i=0 ; i<n  ; ++i)
#define fe0         for(int i=0 ; i<=n ; ++i)
#define fn1         for(int i=1 ; i<n  ; ++i)
#define fe1         for(int i=1 ; i<=n ; ++i)
#define forci(x)    for(auto &c:x)
#define forco(x)    for(auto c:x)
#define scn(x)      scanf("%lld",&x);
#define pb          push_back
#define set_bit(x)  __builtin_popcountll(x)
#define mod         1000000007
#define all(x)      (x).begin(), (x).end()
#define dll(x)      (x).begin(), (x).end(),greater<int>()
#define endl        "\n"
const int MAX = 1e5 + 7;
const int MAXG = 10;

// vector<int> arr(MAX);
// vector<int> sg (4*MAX);
int arr[MAX];
int sg[MAX];


void fast_io() {
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

}



void build(int root , int low , int high) {
      if (low == high) {
            sg[root] = arr[low];
            return ;
      }

      int mid = (low + high) / 2 ;
      build(2 * root + 1 , low , mid);
      build(2 * root + 2 , mid + 1, high);

      sg[root] = max(sg[2 * root + 1] , sg[2 * root + 2]);
}

int query(int root , int low, int high ,  int l , int r) {
      if (low >= l && high <= r) return sg[root];
      if (high < l || low > r) return INT_MIN;
      int mid = (low + high) / 2;
      int left = query(2 * root + 1, low , mid , l , r);
      int right = query(2 * root + 2, mid + 1, high, l, r);
      return max(left, right);
}

void solve() {
      int n, k; cin >> n >> k;
      for (int i = 1; i <= n; i++) cin >> arr[i];
      build(1 , 1 , n);
      for (int i = 1; i <= n; i++)
            cout << sg[i] << " ";
      ;
      cout << endl;
      // int q;cin>>q;
      for (int i = 1; i + k - 1 <= n; i += 1) {

            cout << query(1, 1, n, i  , i + k - 1  ) << endl;
      }
}

signed main() {
      fast_io();
      int t = 1;
      // cin>>t;
      while (t--)
            solve();
      return 0;
}
