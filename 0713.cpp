class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0, end = 0;
        int answer = 0, product = 1;
        while(end < nums.size()){
            product *= nums[end];
            while(product >= k && start <= end){
                product /= nums[start];
                start++;
            }
            answer += end - start + 1;
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