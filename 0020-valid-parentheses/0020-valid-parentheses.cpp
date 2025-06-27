class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            } else {
                if(stack.empty()) return false;  //  check here

                if((stack.top() == '(' && s[i] == ')') ||
                   (stack.top() == '{' && s[i] == '}') ||
                   (stack.top() == '[' && s[i] == ']')) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        return stack.empty();  // final check
    }
};
