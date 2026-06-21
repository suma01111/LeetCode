class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long num = 0;
        char sign = '+';

        for (int i = 0; i < s.size(); i++) {

            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            if ((!isdigit(s[i]) && s[i] != ' ') || i==s.size()-1) { //' ' for spacing in st

                if (sign == '+')
                    st.push(num);

                else if (sign == '-')
                    st.push(-num);

                else if (sign == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                }

                else if (sign == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }

                sign = s[i];
                num = 0;
            }
        }

        int ans = 0;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};