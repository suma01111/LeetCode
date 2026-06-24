// A subarray is interesting if:
// (count of elements where nums[i] % modulo == k) % modulo == k
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums,int modulo,int k) {

        unordered_map<int, long long> mp;
        mp[0] = 1;

        long long ans =0;
        int prefix=0;

        for (int num : nums) {
            if (num % modulo == k)
                prefix++;

            int curr=prefix%modulo;

            int need = (curr - k + modulo) % modulo;

            ans += mp[need];

            mp[curr]++;
        }

        return ans;
    }
};

/*
Create a binary array conceptually:

val = (nums[i] % modulo == k) ? 1 : 0;

Let:

prefix = number of such elements seen so far

For a subarray [l..r]:

(prefix[r] - prefix[l-1]) % modulo == k

Rearrange:

prefix[l-1] % modulo
=
(prefix[r] - k + modulo) % modulo

So while traversing:

Let curr = prefix % modulo.
We need previous prefixes with remainder:
need = (curr - k + modulo) % modulo;

Use a hashmap to count remainders.
*/