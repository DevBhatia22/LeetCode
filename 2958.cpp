class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        int start = 0, end = 0;
        int answer = 0;
        while(end < nums.size()){
            map[nums[end]]++;
            while(map[nums[end]] > k){
                map[nums[start]]--;
                start++;
            }
            answer = std::max(answer, end - start + 1);
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