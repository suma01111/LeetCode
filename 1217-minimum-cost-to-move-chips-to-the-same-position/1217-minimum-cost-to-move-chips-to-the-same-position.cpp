class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;

        for (int p : position) {
            if (p % 2)
                odd++;
            else
                even++;
        }

        return min(odd, even);
    }
};

/*
Key Observation

    Moving by ±2 costs 0.
    So:
    Odd → Odd = Free
    Even → Even = Free
    Odd → Even = Costs 1
    Even → Odd = Costs 1

Therefore, the actual values don't matter—only whether a position is odd or even.

Idea
There are only two possible final choices:
Move every chip to an even position.
All even chips move for free.
Every odd chip costs 1.
Cost = number of odd chips
Move every chip to an odd position.
All odd chips move for free.
Every even chip costs 1.

Cost = number of even chips
Answer: min(oddCount, evenCount)
*/