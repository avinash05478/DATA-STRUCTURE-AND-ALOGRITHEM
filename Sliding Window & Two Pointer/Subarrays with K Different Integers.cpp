class Solution {
public:
    int countsubbarry(vector<int>& nums, int k) {
        map<int, int> mpp;

        int n = nums.size();
        int i = 0, j = 0, count = 0;

        while (j < n) {
            mpp[nums[j]]++;

            while (mpp.size() > k) {
                mpp[nums[i]]--;

                if (mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }

                i++;
            }

            count += (j - i + 1);
            j++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countsubbarry(nums, k) - countsubbarry(nums, k - 1);
    }
};
