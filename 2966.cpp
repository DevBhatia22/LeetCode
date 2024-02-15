class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        std::vector<std::vector<int>> answer;
        std::sort(nums.begin(), nums.end());
        std::vector<int> temp;
        for(int i = 0; i < nums.size(); i++){
            temp.push_back(nums[i]);
            if(temp.size() == 3){
                if(temp[0] + k >= temp[1] && temp[1] + k >= temp[2] && temp[0] + k >= temp[2]){
                    answer.push_back(temp);
                    temp.clear();
                }
                else{
                    answer.clear();
                    return answer;
                }
            }
        }
        return answer;
    }
};