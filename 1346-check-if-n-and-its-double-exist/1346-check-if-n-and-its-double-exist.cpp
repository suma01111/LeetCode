class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;

        for (int x : arr) {
            if (s.find(2 * x) != s.end()) 
                return true;

            if (x % 2 == 0 && s.find(x / 2) != s.end()) 
                return true;

            s.insert(x);
        }
        return false;
    }
};
