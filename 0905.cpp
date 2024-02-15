class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int start;
        int i = 0;
        while(i < nums.size() && ! (nums[i] % 2)){
            i++;
        }
        start = i;
        int end = start + 1;
        while(end < nums.size()){
            if(nums[end] % 2 == 0){
                swap(nums[start], nums[end]);
                start++;
                end++;
            }
            else{
                end++;
            }
        }
        
        return nums;
        
    }
};