class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for(i = nums.size() - 1; i > -1; i--){
            if(i == 0){
                std::sort(nums.begin(), nums.end());
                return;
            }
            if(nums[i] > nums[i - 1]){
                int k = i;
                for(int j = i; j < nums.size(); j++){
                    if(nums[j] > nums[i - 1] && nums[j] < nums[k]){
                        k = j;
                    }
                }
                std::swap(nums[k], nums[i - 1]);
                std::sort(nums.begin() + i, nums.end());
                return;
            }
        }
    }
};