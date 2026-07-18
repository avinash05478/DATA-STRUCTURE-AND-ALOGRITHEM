// isme hum area precompute krter rhenge sath ki sath
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea = 0;
        int n = heights.size();

        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int ele = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxarea = max(maxarea , (nse - pse - 1) * heights[ele]);
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = n;
            int ele = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();

            maxarea = max(maxarea , (nse - pse - 1) * heights[ele]);
        }
        return maxarea;
    }
};
