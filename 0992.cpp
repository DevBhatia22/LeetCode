class Solution {
public:
    int atmostCal(std::vector<int> nums, int k){
        int start = 0, end = 0;
        std::vector<int> map(nums.size() + 1, 0);
        int currentCount = 0;
        int answer = 0;
        while(end < nums.size()){
            if(map[nums[end]] == 0){
                currentCount++;
            }
            map[nums[end]]++;
            while(start <= end && currentCount > k){
                map[nums[start]]--;
                if(!map[nums[start]]){
                    currentCount--;
                }
                start++;
            }
            answer += end - start + 1;
            end++;
        }
        return answer;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostCal(nums, k) - atmostCal(nums, k - 1);
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();