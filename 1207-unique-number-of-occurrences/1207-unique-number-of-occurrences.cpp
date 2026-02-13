//by me , (better approach O(nlogn) but optimal is O(N))
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for( int i=0;i<arr.size();i++) mp[arr[i]]++;

        vector<int> temp;

        for(auto it : mp){
            temp.push_back(it.second);
        }
        
        sort(temp.begin(),temp.end());
        for(int i=1;i<temp.size();i++){
            if(temp[i-1]==temp[i]) return false;
        }

        return true;
    }
};

// Instead of sorting frequencies, just check if a frequency has been seen before.
// unordered_set<int> seen;

//         for(auto it : mp) {
//             if(seen.count(it.second))
//                 return false;
//             seen.insert(it.second);
//         }