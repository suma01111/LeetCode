class KthLargest {
public:
    //min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    int Kth;

    KthLargest(int k, vector<int>& nums) {
        Kth =k; //intializing constructor,store k for use in other func like add()
        for(int &x : nums) {
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size() > Kth)
            pq.pop();
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */