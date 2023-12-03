class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        std::ios::sync_with_stdio(false);
        std::stack<int> s1;
        std::stack<int> s2;
        s1.push(0);
        int size_of_array=prices.size();
        for(int i=size_of_array-1;i>=0;i--){
            int x=prices[i];
            while(!s1.empty()){
                if(s1.top()<=prices[i]){
                    prices[i]-=s1.top();
                    break;
                }
                s2.push(s1.top());
                s1.pop();
            }
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            s1.push(x);
        }
        return prices;
    }
};