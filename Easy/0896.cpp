class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() == 1){
            return true;
        }
        int i = 0;
        while(i < nums.size() - 1 && nums[i] == nums[i + 1]){
            i++;
        }
        if(i < nums.size() - 1 && nums[i] > nums[i + 1]){
            while(i < nums.size() - 1 && nums[i] >= nums[i + 1]){
                i++;
            }
            if(i >= nums.size() - 1){
                return true;
            }
            return false;
        }
        else{
            while(i < nums.size() - 1 && nums[i] <= nums[i + 1]){
                i++;
            }
            if(i == nums.size() - 1){
                return true;
            }
            return false;
        }
    }
};