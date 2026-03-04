class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stack;
        int cnt=0;

        for(char c:s){
            if(c == '(') stack.push(c);
            else{
                if(stack.empty()) cnt++; //counting ')' which are not in stack
                else stack.pop(); //if pair is made pop
            }
        }
        // Total no. of brackets needed= count + no. of '(' left in the stack
        return stack.size()+cnt; 
    }
};