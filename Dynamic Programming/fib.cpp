// N-th fibonacci number using Dynamic and non-dynamic approach.. 

#include "iostream"
#include "vector"
using namespace std;

long int fibb(int n){
    if(n <= 2) return 1;
    return fibb(n-1)+fibb(n-2);
} 


long int DP_fibb(int n, vector<long int>&memo){

    if(memo.size() >= n){
        return memo[n-1];
    }

    if(n <= 2) return 1;

    long int temp = DP_fibb(n-1, memo)+DP_fibb(n-2, memo);
    memo.push_back(temp);
    return temp;

}


int main(){

    // cout << fibb(50);

    vector<long int> memo;
    memo.push_back(1);
    memo.push_back(1);

    cout << DP_fibb(50, memo) << "\n";

    return 0;
}

