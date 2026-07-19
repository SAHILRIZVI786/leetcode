using ll = long long;

class Solution {
public:

    ll Maxs(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        // Previous Greater Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            if (!st.empty())
                left[i] = st.top();

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            if (!st.empty())
                right[i] = st.top();

            st.push(i);
        }

        ll sum = 0;

        for (int i = 0; i < n; i++) {
            ll leftCount = i - left[i];
            ll rightCount = right[i] - i;
            sum += 1LL * nums[i] * leftCount * rightCount;
        }

        return sum;
    }

    ll Mins(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            if (!st.empty())
                left[i] = st.top();

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            if (!st.empty())
                right[i] = st.top();

            st.push(i);
        }

        ll sum = 0;

        for (int i = 0; i < n; i++) {
            ll leftCount = i - left[i];
            ll rightCount = right[i] - i;
            sum += 1LL * nums[i] * leftCount * rightCount;
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return Maxs(nums) - Mins(nums);
    }
};