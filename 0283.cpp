class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, i_ = i;
        
        for(i = 0; i < nums.size(); i++){
            if(nums[i]!=0){
                nums[i_] = nums[i];
                i_++;
            }
        }
        for(i_; i_< nums.size(); i_++){
            nums[i_] = 0;
        }
    }
};