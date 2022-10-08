// this is a simple program for finding the bit differece between the all the subset pairs that can be formed of an array // asked in amazon interview

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int ans( vector <int> & arr , int n) {
    int cnt , res = 0 ;

    for ( int i = 0 ; i < n ; i ++) {
        cnt = 0;

        for ( int j = 0 ; j < n ; j++) {
            if ( arr[j] & (1 << i)) cnt++;
            cout << cnt << " ";
        }

        cout << endl;

        res += 2 * cnt * ( n - cnt);
        res %= mod ;
    }

    return res;
}

int main() {
    int n ; cin >> n;

    vector <int> arr ( n + 1 , 0);

    for ( int i = 0 ; i < n ; i++ ) {
        cin >> arr[i];
    }


    cout << ans( arr , n );

}
