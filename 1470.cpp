class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        std::vector<int> answer(n*2, 0);
        for(int i = 0; i < n; i++){
            answer[2 * i] = nums[i];
            answer[2 * i + 1] = nums[n + i];
        }
        return answer;
    }
};