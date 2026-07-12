class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int hash[256];
        int l = 0, r = 0;
        long long  maxi = 0;

        for (int i = 0; i < 256; i++) {
            hash[i] = -1;
        }

        while (r < n) {
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }
            long long len = r - l + 1;
            maxi = max(maxi, len);

            hash[s[r]] = r;
            r++;
        }

        return maxi;
    }
};
