//2nd submission in 0(N) , 1st 0(2N) is still easy , 
class MinStack {
    stack<long long> s;
    long long minVal;

public:
    MinStack() {
        // Constructor to initialize stack and minVal
        while (!s.empty()) s.pop();
    }

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minVal = val;
        } else {
            if (val < minVal) {
                // Encode the new min value
                s.push(2LL * val - minVal);
                minVal = val;
            } else {
                s.push(val);
            }
        }
    }

    void pop() {
        if (s.empty()) return;

        if (s.top() < minVal) {
            // Restore previous minVal
            minVal = 2LL * minVal - s.top();
        }
        s.pop();
    }

    int top() {
        if (s.top() < minVal) {
            // Top is encoded
            return minVal;
        }
        return s.top();
    }

    int getMin() {
        return minVal;
    }
};
