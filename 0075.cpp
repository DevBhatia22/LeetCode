class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int hih = nums.size() - 1;
        while(mid <= hih){
            if(nums[mid] == 0){
                std::swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                std::swap(nums[mid], nums[hih]);
                hih--;
            }
        }
    }
};