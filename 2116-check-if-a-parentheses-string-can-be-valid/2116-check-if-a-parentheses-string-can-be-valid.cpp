class Solution {
public:
    bool canBeValid(string s, string locked) {

        int n = s.size();

        // Odd length can never be balanced
        if (n % 2)
            return false;

        int open = 0;

        // Left -> Right
        for (int i = 0; i < n; i++) {

            if (locked[i] == '0' || s[i] == '(')
                open++;
            else
                open--;

            if (open < 0)
                return false;
        }

        int close = 0;

        // Right -> Left
        for (int i = n - 1; i >= 0; i--) {

            if (locked[i] == '0' || s[i] == ')')
                close++;
            else
                close--;

            if (close < 0)
                return false;
        }

        return true;
    }
};