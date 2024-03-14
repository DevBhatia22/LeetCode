class Solution {
public:
    int atmostSubarrays(std::vector<int>& nums, int goal){
        int end = 0, start = 0, sum = 0, answer = 0;
        while(end < nums.size()){
            sum += nums[end];
            while(sum > goal && start <= end){
                sum -= nums[start];
                start++;
            }
            answer += end - start + 1;
            end++;
        }
        return answer;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostSubarrays(nums, goal) - atmostSubarrays(nums, goal - 1);
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();