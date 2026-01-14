class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double low = 1e18, high = -1e18;

        // Compute total area and y-range
        for (auto &sq : squares) {
            double y = sq[1];
            double len = sq[2];
            totalArea += len * len;
            low = min(low, y);
            high = max(high, y + len);
        }

        double target = totalArea / 2.0;

        // Binary search on y
        while (high - low > 1e-6) {
            double mid = (low + high) / 2.0;
            if (areaBelow(mid, squares) < target)
                low = mid;
            else
                high = mid;
        }

        return low;
    }

    double areaBelow(double mid, vector<vector<int>>& squares) {
        double area = 0.0;

        for (auto &sq : squares) {
            double y = sq[1];
            double len = sq[2];

            if (mid >= y + len) {
                // full square below
                area += len * len;
            } 
            else if (mid > y) {
                // partially cut square
                area += len * (mid - y);
            }
        }
        return area;
    }
};
