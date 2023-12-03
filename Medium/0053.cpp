class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = nums[0];
        for(int i:nums){
            if(sum < 0){
                sum = 0;
            }
            sum += i;
            if(max < sum){
                max = sum;
            }
        }
        return max;
    }
};