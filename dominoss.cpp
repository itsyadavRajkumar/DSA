// Satish Kumar Prajapati
# include <bits/stdc++.h>
# define ll long long int
# define vi vector<int>
# define vc vector<char>
using namespace std;



int main (){
   
      int n ;
      cout << "Number of dominoes : "<<endl;
      cin >> n ;
      cout << "Sequence : " <<endl;
      vc a(n) ;
      vi v(n , 1);
      for (char &i: a){
         cin >> i ;
      }


      int count = 0 ;
      int lo = -1 , hi = -1 ;
      for (int i =0; i<n; ++i){
         if (a[i] == 'L' && v[i]==1){
            v[i] = 0;
            int tmpi = i ;
            while(tmpi>=0){
               v[tmpi--] = 0;
            }
         }
         if (a[i]=='R'){
            break;
         }
      }
      for (int i =0; i<n; ++i){
         if (a[i]=='R'){
            int tmpi = i ;
            while(a[tmpi]!='L'){
               ++tmpi ;
               if (tmpi>=n){
                  for (int j = i ; j<n; ++j ){
                     v[j] = 0;
                  }
                  break;
               }
            }
         }
      }


      for (int i=0; i<n; ++i){
         int lo = i , hi = i ;
         if (a[i]=='R' && v[i] == 1){
            lo = i ;
            int tmpi = i;
            while (a[tmpi]!= 'L'){
               tmpi ++ ;
            }
            hi = tmpi ;

            while (lo <= hi){
               if (hi-lo == 2){
                  v[hi] = 0;v[lo] = 0;
                  break;
               }
               v[hi] = 0 ; v[lo] = 0;
               hi -- ; lo ++ ;
            }
         }
      }
      int ans = 0;
      for (int i = 0; i<n; ++i){
         ans += v[i] ;
      }

 
      cout <<"Number of standing Dominoes : "<< ans << endl;
 
 
}
