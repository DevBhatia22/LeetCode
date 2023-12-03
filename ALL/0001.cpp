class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> temp;
        temp = nums;
        sort(nums.begin(), nums.end());
        int p1 = 0, p2 = nums.size() - 1;
        while(p1 != p2){
            if(nums[p1] + nums[p2] == target){
                break;
            }
            else if(nums[p1] + nums[p2] > target){
                p2--;
                continue;
            }
            p1++;
        }
        std::vector<int> answer;
        for(int i = 0; i < nums.size(); i++){
            if(temp[i] == nums[p1] || temp[i] == nums[p2]){
                answer.push_back(i);
            }
        }
        return answer;
    }
};