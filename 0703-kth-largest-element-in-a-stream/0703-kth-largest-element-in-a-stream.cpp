class KthLargest {
public:
    //min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;//intializing constructor,store k for use in other func like add()
        for(int &x : nums) {
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size() > k)
            pq.pop();
        
        return pq.top();
    }
};

//TC = O(N log K)

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */