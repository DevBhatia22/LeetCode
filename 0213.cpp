class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums[0];
        }
        int prev1 = 0, prev2 = nums[0];
        int answer1 = 0, answer2 = 0;
        for(int i = 1; i < nums.size() - 1; i++){
            int temp = std::max(prev1 + nums[i], prev2);
            prev1 = prev2;
            prev2 = temp;
        }
        answer1 = prev2;
        prev1 = 0;
        prev2 = nums[1];
        for(int i = 2; i < nums.size(); i++){
            int temp = std::max(prev1 + nums[i], prev2);
            prev1 = prev2;
            prev2 = temp;
        }
        answer2 = prev2;
        return std::max(answer1, answer2);
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();