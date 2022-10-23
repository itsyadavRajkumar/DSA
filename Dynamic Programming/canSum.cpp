// return if target sum can be generated using elements of the array.. same elements can be used again...

#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

// normal recursive approach...
bool can_Sum(int target, vector<int> arr){

    if(target == 0) return true;
    if(target < 0) return false;

    for(int i=0; i<arr.size(); i++){
        int newTarget = target - arr[i];
        
        if(can_Sum(newTarget, arr)) return true;
    }

    return false;

}

// DP recursive approach...
bool DP_canSum(int target, vector<int> arr, unordered_map<int, bool> &memo){

    if(memo.find(target) != memo.end()){
        return memo[target];
    }


    if(target == 0) return true;
    if(target < 0) return false;

    for(int i=0; i<arr.size(); i++){
        int newTarget = target - arr[i];
        
        if(DP_canSum(newTarget, arr, memo)){
            memo[target] = true;
            return true;
        } 
    }   

    memo[target] = false;
    return false;

}



int main(){

    unordered_map<int, bool> memo;
    vector<int> vec{7,14};

    // cout << can_Sum(400, vec);
    cout << DP_canSum(400, vec, memo);

    
}