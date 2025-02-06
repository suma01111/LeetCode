class Solution {
    int nC2(int n){
        return n*(n-1)/2;
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        int cnt=0;
        int n = nums.size();
        unordered_map<int,int> freq;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                freq[nums[i]*nums[j]]++; //2*3=6, map 6-> 1(freq)
            }
        }

                for(auto[product,frequency]: freq)
                    cnt += 8*nC2(frequency);

        return cnt;
    }
};

//auto[product,frequency]: freq mean:
// int product = pair.first;         // Extract the key (product)
//     int frequency = pair.second;      // Extract the value (frequency)