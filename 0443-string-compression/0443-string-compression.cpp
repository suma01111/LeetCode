class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0, index = 0;

        while (i < n) {
            char curr = chars[i];
            int count = 0;

            // count frequency
            while (i < n && chars[i] == curr) {
                i++;
                count++;
            }

            // write character
            chars[index++] = curr;

            // write count if >1
            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[index++] = c;
                }
            }
        }

        return index;
    }
};