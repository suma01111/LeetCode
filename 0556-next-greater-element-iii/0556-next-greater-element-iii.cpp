class Solution {
public:
    int nextGreaterElement(int num) {
        vector<int> arr;

        // converting n into array
        while(num > 0){
            int dig = num % 10;
            arr.push_back(dig);
            num = num / 10;
        }

        // FIX 1: reverse to get correct order
        reverse(arr.begin(), arr.end());

        // Next permutation logic
        int idx = -1;
        int n = arr.size();

        for(int i = n - 2; i >= 0; i--){
            if(arr[i] < arr[i + 1]){
                idx = i;
                break;
            }
        }

        if(idx == -1) return -1;

        for(int i = n - 1; i >= 0; i--){
            if(arr[i] > arr[idx]){
                swap(arr[i], arr[idx]);
                break;
            }
        }

        reverse(arr.begin() + idx + 1, arr.end());

        // FIX 2: safe number construction
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum = sum * 10 + arr[i];
        }

        // FIX 3: overflow check
        if(sum > INT_MAX) return -1;

        return (int)sum;
    }
};