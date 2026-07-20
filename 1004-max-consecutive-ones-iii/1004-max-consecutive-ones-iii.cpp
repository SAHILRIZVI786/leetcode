class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxl = 0;
        int count0 = 0;
        int i = 0, j = 0;

        while (j < nums.size()) {

            if (nums[j] == 0)
                count0++;

            while (count0 > k) {
                if (nums[i] == 0)
                    count0--;
                i++;
            }

            maxl = max(maxl, j - i + 1);

            j++;
        }

        return maxl;
    }
};