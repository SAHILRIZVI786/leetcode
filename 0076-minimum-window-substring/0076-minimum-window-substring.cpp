class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);

        // Store frequency of characters in t
        for (char ch : t) {
            need[ch]++;
        }

        int i = 0, j = 0;
        int count = 0;           // number of matched characters
        int start = 0;           // starting index of answer
        int minLen = INT_MAX;

        unordered_map<char, int> mp;

        while (j < s.size()) {

            mp[s[j]]++;

            // If current character is needed and not exceeding requirement
            if (need[s[j]] > 0 && mp[s[j]] <= need[s[j]]) {
                count++;
            }

            // When all characters of t are matched
            while (count == t.size()) {

                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                mp[s[i]]--;

                // Window becomes invalid
                if (need[s[i]] > 0 && mp[s[i]] < need[s[i]]) {
                    count--;
                }

                i++;
            }

            j++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};