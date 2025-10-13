class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        
        for (auto &word : words) {
            if (result.empty()) {
                result.push_back(word);
            } else {
                string prev = result.back();
                
                // sort both to check if they are anagrams
                string sortedPrev = prev, sortedCurr = word;
                sort(sortedPrev.begin(), sortedPrev.end());
                sort(sortedCurr.begin(), sortedCurr.end());
                
                // only push if not anagrams
                if (sortedPrev != sortedCurr)
                    result.push_back(word);
            }
        }
        
        return result;
    }
};