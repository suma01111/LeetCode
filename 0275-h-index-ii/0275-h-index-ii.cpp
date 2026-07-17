class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (citations[mid] >= n - mid)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return n - low;
    }
};

// Key Observation

// Suppose we're at index mid.

// There are n - mid papers from mid to n-1.
// If citations[mid] >= n - mid, then an h-index of n - mid is possible.
// We try to find an even earlier index (smaller mid) to maximize the h-index.
// Binary Search
// Condition
// citations[mid] >= n - mid
// True → possible answer, move left.
// False → need more citations, move right.