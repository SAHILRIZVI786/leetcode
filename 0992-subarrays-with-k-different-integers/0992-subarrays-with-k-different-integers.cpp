class Solution {
public:

    // Returns number of subarrays having AT MOST k distinct elements
    int atMostK(vector<int>& nums, int k) {

        unordered_map<int,int> mp;   // frequency map
        int i = 0;
        int ans = 0;

        for(int j = 0; j < nums.size(); j++) {

            // Include current element
            mp[nums[j]]++;

            // Shrink window until distinct elements <= k
            while(mp.size() > k) {

                mp[nums[i]]--;

                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);

                i++;
            }

            // All subarrays ending at j are valid
            ans += (j - i + 1);
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        // Exactly(K) = AtMost(K) - AtMost(K-1)
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};