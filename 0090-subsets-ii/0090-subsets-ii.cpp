class Solution {
public:

    vector<vector<int>> ans;
    vector<int> ds;

    void solve(int index, vector<int>& nums) {

        ans.push_back(ds);

        for(int i = index; i < nums.size(); i++) {

            if(i > index && nums[i] == nums[i-1])
                continue;

            ds.push_back(nums[i]);

            solve(i + 1, nums);

            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        solve(0, nums);

        return ans;
    }
};