class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])continue;      //to remove any duplicate at the first number
            int target=-nums[i];
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[j]+nums[k];
                if(sum<target)j++;
                else if(sum>target)k--;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<nums.size()-1 && nums[j]==nums[j+1])j++;      //remove duplicate in the 2nd number
                    while(k>0 && nums[k]==nums[k-1])k--;                        //remove duplicate in the 3rd number
                    j++,k--;
                }
            }
        }
        return ans;
    }
};
