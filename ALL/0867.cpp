class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        std::vector<std::vector<int>> answer;
        for(int i = 0; i < matrix[0].size(); i++){
            std::vector<int> temp;
            for(int j = 0; j < matrix.size(); j++){
                temp.push_back(matrix[j][i]);
            }
            answer.push_back(temp);
        }
        return answer;
    }
};