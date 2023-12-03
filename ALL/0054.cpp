class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> answer;
        int rs,re,cs,ce;
        rs = 0;
        cs = 0;
        re = matrix.size() - 1;
        ce = matrix[0].size() - 1;
        int r = 0;
        int c = 0;
        while(rs <= re && cs <= ce){
            for(c = cs; c <= ce; c++){
                answer.push_back(matrix[r][c]);
            }
            rs++;
            c--;
            for(r = rs; r <= re; r++){
                answer.push_back(matrix[r][c]);
            }
            ce--;
            r--;
            if(rs <= re){
                for(c = ce; c >= cs; c--){
                    answer.push_back(matrix[r][c]);
                }
                re--;
                c++;
            }
            if(cs <= ce){
                for(r = re; r >= rs; r--){
                    answer.push_back(matrix[r][c]);
                }
                cs++;
                r++;
            }
        }
        return answer;
    }
};