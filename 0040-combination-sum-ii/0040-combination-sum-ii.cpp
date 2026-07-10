class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ds;

    void solve(int index, int target, vector<int>& candidates) {

        if(target == 0) {
            ans.push_back(ds);
            return;
        }

        for(int i = index; i < candidates.size(); i++) {

            // Skip duplicates at the same recursion level
            if(i > index && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no need to check further
            if(candidates[i] > target)
                break;

            ds.push_back(candidates[i]);

            // Move to next index (each element can be used only once)
            solve(i + 1, target - candidates[i], candidates);

            // Backtrack
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        solve(0, target, candidates);

        return ans;
    }
};