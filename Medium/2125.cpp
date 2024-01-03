class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        std::vector<std::vector<int>> vec;
        std::unordered_map<int, int> map1;
        for(int i:nums){
            map1[i]++;
            if(map1[i] > vec.size()){
                std::vector<int> temp;
                vec.push_back(temp);
            }
            vec[map1[i] - 1].push_back(i);
        }
        return vec;
    }
};