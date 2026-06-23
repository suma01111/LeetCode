class Solution {
public:

    vector<string> ans;

    void solve(string &num,
               int target,
               int idx,
               string path,
               long long value,
               long long prev)
    {

        if(idx == num.size())
        {
            if(value == target)
                ans.push_back(path);

            return;
        }

        for(int i=idx;i<num.size();i++)
        {

            // leading zero
            if(i > idx && num[idx]=='0')
                break;

            string currStr = num.substr(idx, i-idx+1);

            long long curr = stoll(currStr);

            // first number
            if(idx == 0)
            {
                solve(num,
                      target,
                      i+1,
                      currStr,
                      curr,
                      curr);
            }
            else
            {
                // +

                solve(num,
                      target,
                      i+1,
                      path + "+" + currStr,
                      value + curr,
                      curr);

                // -

                solve(num,
                      target,
                      i+1,
                      path + "-" + currStr,
                      value - curr,
                      -curr);

                // *

                solve(num,
                      target,
                      i+1,
                      path + "*" + currStr,
                      value - prev + prev*curr, //IMP
                      prev*curr);
            }
        }
    }

    vector<string> addOperators(string num, int target)
    {

        solve(num,
              target,
              0,
              "",
              0,
              0);

        return ans;
    }
};