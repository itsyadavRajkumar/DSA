#include<bits/stdc++.h>

using namespace std;

int stick[10]={6,2,5,5,4,5,6,3,7,6};

int main(){

int tc;

cin >> tc;


 

while(tc--){

string no;

cin>>no;


 

int totalStick=0;

 

 

for(int i=0;i<no.length();i++){

totalStick+=stick[no[i]-48];

}


 

if(totalStick%2!=0){

cout<<7;

totalStick-=stick[7];

}


 

for(int i=0;i<totalStick/2;i++)

cout<<1;


 

cout<<endl;

 

}


 

return 0;

}
