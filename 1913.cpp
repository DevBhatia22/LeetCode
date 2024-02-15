class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max = 0, max_ = 0, min = INT_MAX, min_ = INT_MAX;
        for(int i:nums){
            if(i >= max){
                max_ = max;
                max = i;
            }
            else if(i > max_){
                max_ = i;
            }
            if(i <= min){
                min_ = min;
                min = i;
            }
            else if(i < min_){
                min_ = i;
            }
        }
        return (max * max_) - (min * min_);
    }
};