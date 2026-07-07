class Solution {
public:

    void solve(int open, int close, int n,
               string &curr, vector<string> &ans) {

        // Valid string formed
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Add '(' if available
        if (open < n) {
            curr.push_back('(');
            solve(open + 1, close, n, curr, ans);
            curr.pop_back();     // Backtrack
        }

        // Add ')' only if it won't make string invalid
        if (close < open) {
            curr.push_back(')');
            solve(open, close + 1, n, curr, ans);
            curr.pop_back();     // Backtrack
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string curr = "";

        solve(0, 0, n, curr, ans);

        return ans;
    }
};