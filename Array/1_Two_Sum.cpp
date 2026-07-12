class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int> mpp;
        for(int i = 0; i < nums.size(); i++){
            int a = nums[i];
            int check = target - a;
            if(mpp.find(check) != mpp.end()){
                return {mpp[check] , i};
            }
            mpp[a] = i;
        }
        return {-1 , -1};
    }
};


