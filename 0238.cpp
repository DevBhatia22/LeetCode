class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int multiplier = nums[0];
        std::vector<int> answer(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            answer[i] *= multiplier;
            multiplier *= nums[i];
        }
        multiplier = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; i--){
            answer[i] *= multiplier;
            multiplier *= nums[i];
        }
        return answer;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();