class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;

        for (int HH = 0; HH <= 11; HH++) {
            for (int MM = 0; MM <= 59; MM++) {

                if (__builtin_popcount(HH) + __builtin_popcount(MM) == turnedOn) {

                    string hour = to_string(HH);
                    string min;

                    if (MM < 10)
                        min = "0" + to_string(MM);
                    else
                        min = to_string(MM);

                    res.push_back(hour + ":" + min);
                }
            }
        }

        return res;
    }
};
