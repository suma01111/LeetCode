class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, maxLen = 0;
        unordered_map<int, int> mp; //fruits[i], freq

        for (int r=0;r<fruits.size();r++) {
            mp[fruits[r]]++; 

            while (mp.size()>2) { //IMPPP, if map have more than size2, move l
                mp[fruits[l]]--; //decrease freq of l from map then down l++

                if (mp[fruits[l]]==0) //if freq==0, erase from MAP
                    mp.erase(fruits[l]);

                l++;
            }

            maxLen=max(maxLen,r-l+1);
        }

        return maxLen;
    }
};