class Solution {
public:
//test submit
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid;
        while(start <= end){
            mid = (start + end) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                if(nums[mid] >= nums[0]){
                    start = mid + 1;
                }
                else{
                    if(nums[nums.size() - 1] >= target){
                        start = mid + 1;
                    }
                    else{
                        end = mid - 1;
                    }
                }
                
            }
            else{
                if(nums[mid] < nums[0]){
                    end = mid - 1;
                }
                else{
                    if(nums[0] > target){
                        start = mid + 1;
                    }
                    else{
                        end = mid - 1;
                    }
                }
            }
            std::cout<<mid<<" ";
        }
        return -1;
    }
};