class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        long long leftsum = 0, rightsum = 0, maxsum = INT_MIN;

        for (int i = 0; i < k; i++) {
            leftsum += cardPoints[i];
            maxsum = leftsum;
        }

        int rightind = n - 1;
        for (int i = k - 1; i >= 0; i--) {
            leftsum -= cardPoints[i];
            rightsum += cardPoints[rightind];
            rightind--;

            maxsum = max(maxsum, leftsum + rightsum);
        }
        return maxsum;
    }
};
