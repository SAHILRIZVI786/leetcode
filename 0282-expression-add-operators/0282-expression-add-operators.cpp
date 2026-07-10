//will understand it completely later
class Solution {
public:
    vector<string> ans;

    void solve(string &num, int target, int index,
               string expr, long long eval, long long prev) {

        if(index == num.size()) {
            if(eval == target)
                ans.push_back(expr);
            return;
        }

        for(int i = index; i < num.size(); i++) {

            if(i > index && num[index] == '0')
                break;

            string part = num.substr(index, i - index + 1);
            long long curr = stoll(part);

            if(index == 0) {
                solve(num, target, i + 1,
                      part, curr, curr);
            }
            else {

                solve(num, target, i + 1,
                      expr + "+" + part,
                      eval + curr,
                      curr);

                solve(num, target, i + 1,
                      expr + "-" + part,
                      eval - curr,
                      -curr);

                solve(num, target, i + 1,
                      expr + "*" + part,
                      eval - prev + prev * curr,
                      prev * curr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        solve(num, target, 0, "", 0, 0);

        return ans;
    }
};