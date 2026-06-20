/*
Monotonic Stack?
Need Previous Smaller and Next Smaller for every index.
*/
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s; //stack contain indexes
        int n=arr.size();
        int sum=0;
        const int MOD = 1e9 + 7;

        vector<int> nse(n);
        vector<int> pse(n);

        //step1: Next Smallest Element
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();

            if(s.empty()) nse[i]=n;
            else nse[i]=s.top();

            s.push(i);
        }
        for(int i=0;i<n;i++) cout<<nse[i]<<endl;

        //step2: empty stack for pse
        while(!s.empty()) s.pop();


        //step3:Previous Smaller element,REMEMBER this will handle DUPLICATE ALSO
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i]) s.pop();//imp no=,avoid duplicate

            if(s.empty()) pse[i]=-1;
            else pse[i]=s.top();

            s.push(i);
        }

        //step 4: cal
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            long long contribution =(((1LL * arr[i] * left) % MOD) * right)%MOD;

            ans = (ans + contribution) % MOD;
        }

        return (int)ans;
    }
};