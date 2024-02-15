class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int total = 0;
        int j;
        for(j = 0; j < nums.size(); j++){
            if(nums[j] == val){
                i++;
            }
            else{
                nums[j - i] = nums[j];
                total++;
            }
        }
        return total;
    }
};