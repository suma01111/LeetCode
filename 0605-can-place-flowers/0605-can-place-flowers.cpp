class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int size = flowerbed.size();

        for (int i = 0; i < size; i++) {
            // check left plot
            bool leftEmpty =
                (i == 0 || flowerbed[i - 1] == 0);
            // check right plot
            bool rightEmpty =
                (i == size - 1 || flowerbed[i + 1] == 0);

            // current plot empty and both neighbors empty
            if (flowerbed[i] == 0 && leftEmpty && rightEmpty) {

                // plant flower
                flowerbed[i] = 1;

                n--;

                // if all flowers planted
                if (n == 0)
                    return true;
            }
        }

        return n <= 0;
    }
};