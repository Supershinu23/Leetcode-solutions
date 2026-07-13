// Last updated: 14/07/2026, 00:53:07
class StockSpanner {
private:
    vector<int> vec;
public:
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        vec.push_back(price);
        return func(vec);
    }

    int func(vector<int> &vec){
        int n = vec.size();
        int ans =0;
        for(int i=n-1;i>=0;i--){
            if(vec[i]<=vec[n-1])ans++;
            else break;
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */