class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long answer = 0;
        int start = 0, end = 0;
        int min = -1, max = -1;
        while(end < nums.size()){
            if(nums[end] < minK || nums[end] > maxK){
                start = end + 1;
                end++;
                continue;
            }
            if(nums[end] == maxK){
                max = end;
            }
            if(nums[end] == minK){
                min = end;
            }
            answer += std::max(std::min(min, max) - start + 1, 0);
            end++;
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