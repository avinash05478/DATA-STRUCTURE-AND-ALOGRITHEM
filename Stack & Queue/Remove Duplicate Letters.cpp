class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();

        vector<bool> checkchar(26, false);
        vector<int> lastind(26);
        string ans;

        for (int i = 0; i < n; i++) {
            lastind[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (checkchar[ch - 'a'] == true) {
                continue;
            }
            while (ans.length() > 0 && ans.back() > ch &&
                   lastind[ans.back() - 'a'] > i) {
                checkchar[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(ch);
            checkchar[ch - 'a'] = true;
        }

        return ans;
    }
};
