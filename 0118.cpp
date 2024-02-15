class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> vec;
        for(int i = 0; i < numRows; i++){
            std::vector<int> temp;
            if(i < 2){
                for(int j = 0; j <= i; j++){
                    temp.push_back(1);
                }
            }
            else{
                temp.push_back(1);
                for(int j = 0; j < i - 1; j++){
                    temp.push_back(vec[i - 1][j] + vec[i - 1][j + 1]);
                }
                temp.push_back(1);
            }
            vec.push_back(temp);
        }
        return vec;
    }
};