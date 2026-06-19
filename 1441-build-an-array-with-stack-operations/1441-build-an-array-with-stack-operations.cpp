class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int stream = 1;

        for (int i = 0; i < target.size(); i++) {
//When stream < target[i], there may be multiple numbers to skip before reaching target[i]
            while (stream < target[i]) {
                ans.push_back("Push");
                ans.push_back("Pop");
                stream++;
            }

            ans.push_back("Push");
            stream++;
        }

        return ans;
    }
};

/*
| Stream Number | Target Needed | Operation | Stack         |
| ------------- | ------------- | --------- | ------------- |
| 1             | 1             | Push      | [1]           |
| 2             | 3             | Push, Pop | [1]           |
| 3             | 3             | Push      | [1,3]         |
| 4             | 4             | Push      | [1,3,4]       |
| 5             | 6             | Push, Pop | [1,3,4]       |
| 6             | 6             | Push      | [1,3,4,6]     |
| 7             | 8             | Push, Pop | [1,3,4,6]     |
| 8             | 8             | Push      | [1,3,4,6,8]   |
| 9             | 9             | Push      | [1,3,4,6,8,9] |

*/