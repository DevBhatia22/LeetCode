class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, mid;
        while(start <= end){
            mid = (start + end) / 2;
            if(((mid > 0)?nums[mid] > nums[mid - 1]:true) && ((mid < nums.size() - 1)?nums[mid] > nums[mid + 1]:true)){
                return mid;
            }
            else if(mid == 0 || nums[mid] > nums[mid - 1]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return -1;
    }
};