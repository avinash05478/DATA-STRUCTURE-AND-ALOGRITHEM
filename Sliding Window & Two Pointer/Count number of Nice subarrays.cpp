class Solution {
public:
    int atmost(vector<int>& nums, int goal) {
        int l = 0, r = 0, sum = 0, maxi = 0;
        int n = nums.size();

        while (r < n) {
            sum += (nums[r] % 2);

            while(sum > goal) {
                sum -= (nums[l] % 2);
                l++;
            }
            maxi += r - l + 1;
            r++;
        }
        return maxi;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};
