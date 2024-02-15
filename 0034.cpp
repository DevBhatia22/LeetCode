class Solution {
public:
//test submit
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid, answer1 = -1, answer2 = -1;
        while(start <= end){
            mid = (start + end) / 2;
            if(nums[mid] == target){
                answer1 = mid;
                end = mid - 1;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        start = 0;
        end = nums.size() - 1;
        while(start <= end){
            mid = (start + end) / 2;
            if(nums[mid] == target){
                answer2 = mid;
                start = mid + 1;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        std::vector<int> answer;
        answer.push_back(answer1);
        answer.push_back(answer2);
        return answer;
    }
};