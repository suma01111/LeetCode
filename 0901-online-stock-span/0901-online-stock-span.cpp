class StockSpanner {
public:
    vector<int> price;
    stack<int> s;   // stores indexes

    StockSpanner() {}

    int next(int p) {
        price.push_back(p);
        int i = price.size() - 1;

        // pop all smaller or equal prices
        while (!s.empty() && price[s.top()] <= price[i]) {
            s.pop();
        }

        int span;
        if (s.empty()) {
            span = i + 1;
        } else {
            span = i - s.top();
        }

        s.push(i);
        return span;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
