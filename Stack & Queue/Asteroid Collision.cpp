class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        list<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && st.back() > 0 && asteroids[i] < 0 &&
                   st.back() < abs(asteroids[i])) {
                st.pop_back();
            }

            if (!st.empty() && st.back() > 0 && asteroids[i] < 0 &&
                st.back() == abs(asteroids[i])) {
                st.pop_back();
            }
            else if (!st.empty() && st.back() > 0 && asteroids[i] < 0 &&
                     st.back() > abs(asteroids[i])) {
                continue;
            }
            else {
                st.push_back(asteroids[i]);
            }
        }

        return vector<int>(st.begin(), st.end());
    }
};
