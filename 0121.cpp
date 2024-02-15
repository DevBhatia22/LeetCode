class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        int lol = 0;
        int p1 = 0, p2 = 0;
        while(p2 < prices.size()){
            if(prices[p2] < prices[p1]){
                p1 = p2;
            }
            else{
                lol = prices[p2] - prices[p1];
                if(answer < lol){
                    answer = lol;
                }
                p2++;
            }
        }
        return answer;
    }
};