class ProductOfNumbers {
    vector<int> result={1}; //result array 
    int n ;
    int last_zero_idx;
public:
    ProductOfNumbers() {
        n=1;
        last_zero_idx=-1;
    }
    
    void add(int num) {
        if(num==0) last_zero_idx = n;
        if(result.back()==0) result.push_back(num);
        else result.push_back(result.back()*num);
        n++;
    }
    
    int getProduct(int k) {
        if(last_zero_idx >=n-k) return 0;
        if(result[n-k-1]==0) return result[n-1];
        else return result[n-1]/result[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */