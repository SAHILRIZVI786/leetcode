class Solution {
public:
  vector<vector<int>>ans;
  vector<int>curr;
    void solve(int i,vector<vector<int>>&ans,vector<int>&curr,vector<int>&nums){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
        //take
        curr.push_back(nums[i]);
        solve(i+1,ans,curr,nums);
        //not take
        curr.pop_back();
        solve(i+1,ans,curr,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        solve(0,ans,curr,nums);
        return ans;
    }
};