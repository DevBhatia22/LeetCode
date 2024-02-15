class Solution {
public:
    int maximumCount(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        int count1 = 0, count2 = 0;
        for(int i:nums){
            if(i > 0){
                count1++;
            }
            if(i < 0){
                count2++;
            }
        }
        return std::max(count1, count2);
    }
};