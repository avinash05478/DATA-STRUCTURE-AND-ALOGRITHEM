class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        mini = INT_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }

    void pop() {
        if (st.top() < mini) {
            mini = 2LL * mini - st.top();
        }
        st.pop();
    }

    int top() {
        if (st.top() < mini)
            return mini;

        return st.top();
    }

    int getMin() {
        return mini;
    }
};
