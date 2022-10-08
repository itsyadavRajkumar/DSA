//This code is written by Satish Kumar
//Read the Question prompt - description 

# include <bits/stdc++.h>
# define ll long long int
# define vc vector <char>
# define vvc vector <vc>
# define vi vector <int>
# define pb push_back
using namespace std;


bool checkface(int x , int y , vvc a){
  int b[26] = {0} ;
  if(x+1 >= a.size() || y+1>a[0].size()){
    return 0;
  }
  b[a[x][y]-'a'] += 1;
  b[a[x][y+1]-'a'] += 1;
  b[a[x+1][y]-'a'] += 1;
  b[a[x+1][y+1]-'a'] += 1;
  
  if(b['f'-'a'] == 1 &&
     b['a'-'a'] == 1 &&
     b['c'-'a'] == 1 &&
     b['e'-'a'] == 1 )
    return 1;
  return 0;
}

int tile(vvc &a){
  int count = 0;
  for(int i=0; i<a.size(); ++i){
    for(int j=0; j<a[i].size(); ++j){
      if(a[i][j] == 'f' ||
         a[i][j] == 'a' ||
         a[i][j] == 'c' ||
         a[i][j] == 'e' ){
        count += checkface(i , j , a);
      }
    }
  }
  return count ;
}



int main(){
  
  int n , m ;
  cin >> n >> m;
  vvc a(n , vc(m)) ;
  
  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      cin >> a[i][j] ;
    }
  }
 
  cout << tile (a) << endl ;
  
}
