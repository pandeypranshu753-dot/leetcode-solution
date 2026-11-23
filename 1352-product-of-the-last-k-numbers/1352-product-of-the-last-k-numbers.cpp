class ProductOfNumbers {
public:
   vector<int>ans;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        ans.push_back(num);
        
    }
    
    int getProduct(int k) {
        int n=ans.size();
        int prod=1;
        for(int i=n-k;i<n;i++){
            prod*=ans[i];
           // return prod;
        }
        return prod;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */