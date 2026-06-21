class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        //remember these 3 in all if-else cases, that whether we have to change or not
        long long number=0;
        long long result=0;
        int sign=1;

        for(int i=0;i<s.size();i++){

            if(isdigit(s[i])){
                number= (10*number) +(s[i]-'0');
            }
            else if(s[i]=='+'){
                result += sign*number;
                number=0;
                sign=1;
            }
            else if(s[i]=='-'){
                result += sign*number;
                number=0;
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
                number=0;
            }
            else if(s[i]==')'){
                result += sign*number; 
                number=0;
                int top=st.top();  st.pop();
                result *= top; //multiple sign first , which was present in stack
                top=st.top();  st.pop();
                result += top; //adding result which is present in stack
            }
        }

        result += (sign*number);
        return (int)result;
    }
};