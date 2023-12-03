class Solution {
public:
    void Help(std::vector<int> &nums, std::vector<std::vector<int>> &answers, int index, std::vector<int> temp){
        if(index >= nums.size()){
            sort(temp.begin(), temp.end());
            for(auto i:answers){
                if(i == temp){
                    return;
                }
            }
            answers.push_back(temp);
            return;
        }
        Help(nums, answers, index + 1, temp);
        temp.push_back(nums[index]);
        Help(nums, answers, index + 1, temp);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<std::vector<int>> answer;
        std::vector<int> temp;
        Help(nums, answer, 0, temp);
        return answer;
    }
};