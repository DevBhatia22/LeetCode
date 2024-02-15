class Solution {
public:
    void help(std::vector<int>& candidate, int target, int index, std::vector<std::vector<int>>& vec, std::vector<int> temp){
        if(target < 0 || index >= candidate.size()){
            return;
        }

        else if(target == 0){
            vec.push_back(temp);
            return;
        }
        
        help(candidate, target, index + 1, vec, temp);
        temp.push_back(candidate[index]);
        help(candidate, target - candidate[index], index, vec, temp);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> vec;
        std::vector<int> temp;
        help(candidates, target, 0, vec, temp);
        return vec;
    }
};