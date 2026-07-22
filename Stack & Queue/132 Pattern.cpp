class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int second = INT_MIN;

        for(int i = nums.size() - 1; i >= 0; i--) { // We traverse the array from back side because we wan to fullfill the condition i < j < k...

            if(nums[i] < second) // If i found the nums[i] < nums[k] i did not check futher this is my valid answer...
                return true;

            while(!st.empty() && nums[i] > st.top()) {
                second = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};
