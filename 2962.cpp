class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long answer = 0;
        int start = 0, end = 0;
        int freq = 0, max = 0;
        bool found = false;
        while(end < nums.size()){
            if(nums[end] == max){
                freq++;
            }
            if(nums[end] > max){
                max = nums[end];
                freq = 1;
                found = false;
                answer = 0;
            }
            if(freq >= k){
                found = true;
            }
            while(start <= end && freq >= k){
                if(nums[start] == max){
                    freq--;
                }
                start++;
            }
            if(found){
                answer += start;
            }
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