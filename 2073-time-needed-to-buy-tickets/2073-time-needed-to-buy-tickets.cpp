class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for (int i = 0; i < tickets.size(); i++)
            q.push(i); //queue store index 

        int time = 0;

        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            tickets[idx]--;
            time++;

            if (tickets[idx] == 0) {
                if (idx == k)
                    return time;
            } else {
                q.push(idx);
            }
        }

        return time;
    }
};

/*
| Time | Queue Before | Person Buying | Tickets After | Queue After                |
| ---- | ------------ | ------------- | ------------- | -------------------------- |
| 0    | [0,1,2]      | -             | [2,3,2]       | [0,1,2]                    |
| 1    | [0,1,2]      | 0             | [1,3,2]       | [1,2,0]                    |
| 2    | [1,2,0]      | 1             | [1,2,2]       | [2,0,1]                    |
| 3    | [2,0,1]      | 2             | [1,2,1]       | [0,1,2]                    |
| 4    | [0,1,2]      | 0             | [0,2,1]       | [1,2]                      |
| 5    | [1,2]        | 1             | [0,1,1]       | [2,1]                      |
| 6    | [2,1]        | 2             | [0,1,0]       | Stop (person `k` finished) |

*/