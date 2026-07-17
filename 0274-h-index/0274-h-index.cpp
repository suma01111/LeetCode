// Sort the citations in descending order.
// Check each paper one by one.
// If the i-th paper (0-based) has at least i+1 citations, then h = i+1 is possible.
// Otherwise, stop.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());

        int h = 0;

        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i + 1)
                h++;
            else
                break;
        }

        return h;
    }
};