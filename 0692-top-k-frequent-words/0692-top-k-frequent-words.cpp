class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)
                return a.second > b.second;   // lexicographically smaller comes first
            return a.first < b.first;         // higher frequency comes first
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;

        for (string &word : words)
            mp[word]++;

        priority_queue<pair<int, string>,
                       vector<pair<int, string>>,
                       cmp> pq;

        for (auto &x : mp)
            pq.push({x.second, x.first});

        vector<string> ans;

        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};