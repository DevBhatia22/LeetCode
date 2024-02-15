class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid = (start + end) / 2, returner = nums.size();
        while(start <= end){
            if(nums[mid] >= target){
                returner = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            mid = (start + end) / 2;
        }
        return returner;
    }
};