class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for (string s : ops) {
            if (s == "+") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.push(x);
                st.push(x + y);
            } else if (s == "D") {
                st.push(st.top() * 2);
            } else if (s == "C") {
                st.pop();
            } else {
                st.push(stoi(s));
            }
        }
        int result = 0;
        while (st.size()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};