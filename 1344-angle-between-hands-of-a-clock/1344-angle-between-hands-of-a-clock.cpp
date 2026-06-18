class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min_angle = 6* minutes;
        double h_angle = 30*(hour %12) + 0.5*minutes;

        double ans = min(abs(h_angle-min_angle), 360-(abs(h_angle - min_angle)));
        return ans;
    }
};