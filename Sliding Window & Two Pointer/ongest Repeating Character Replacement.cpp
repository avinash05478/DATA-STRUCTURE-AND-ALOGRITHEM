class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;

        int l = 0;
        int maxfreq = 0;
        int maxlen = 0;

        for (int r = 0; r < s.length(); r++) {
            mpp[s[r]]++;

            maxfreq = max(maxfreq, mpp[s[r]]);

            if ((r - l + 1) - maxfreq > k) {
                mpp[s[l]]--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};
