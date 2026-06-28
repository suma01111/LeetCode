//For 3 equal parts,Each Part Sum = S / 3

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int totalSum = 0;

        for (int num : arr)
            totalSum += num;

        if (totalSum % 3 != 0)
            return false;

        int target = totalSum / 3;
        int runningSum = 0;
        int count = 0;

        for (int num : arr) {
            runningSum += num;

            if (runningSum == target) {
                count++;
                runningSum = 0;
            }
        }

        return count >= 3;
    }
};