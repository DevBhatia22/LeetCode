class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid;
        while(start <= end){
            mid = (start + end) / 2;
            std::cout<<end<<" ";
            if(nums[mid] == target){
                return true;
            }
            if(nums[start] == nums[mid] && nums[mid] == nums[end]){
                start++;
                end--;
                continue;
            }
            if(nums[mid] < nums[start]){
                if(nums[mid] <= target && nums[end] >= target){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
            else{
                if(nums[mid] >= target && nums[start] <= target){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
        }
        return false;
    }
};