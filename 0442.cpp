class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::vector<int> answer;
        for(int i = 0; i < nums.size(); i++){
            if(nums[std::abs(nums[i]) - 1] < 0){
                answer.push_back(std::abs(nums[i]));
            }
            nums[std::abs(nums[i]) - 1] *= -1;
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