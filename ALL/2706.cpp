class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int least = INT_MAX;
        int least_ = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] <= least){
                least_ = least;
                least = prices[i];
            }
            else if(prices[i] < least_){
                least_ = prices[i];
            }
        }
        if(least + least_ <= money){
            return money - (least + least_);
        }
        else{
            return money;
        }
    }
};