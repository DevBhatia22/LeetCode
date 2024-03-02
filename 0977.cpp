class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int prev = -1, curr = 0;
        while(curr < nums.size() && nums[curr] < 0){
            curr++;
        }
        prev = curr - 1;
        std::vector<int> answer(nums.size(), 0);
        int temp = 0;
        while(prev > -1 && curr < nums.size()){
            if(std::abs(nums[prev]) < nums[curr]){
                answer[temp] = nums[prev] * nums[prev];
                prev--;
            }
            else{
                answer[temp] = nums[curr] * nums[curr];
                curr++;
            }
            temp++;
        }
        while(prev > -1){
            answer[temp] = nums[prev] * nums[prev];
            prev--;
            temp++;
        }
        while(curr < nums.size()){
            answer[temp] = nums[curr] * nums[curr];
            curr++;
            temp++;
        }
        return answer;
    }
};