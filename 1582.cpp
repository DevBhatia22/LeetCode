class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int answer1 = 0;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(!(mat[i][j])){
                    continue;
                }
                int count = 0;
                for(int temp = 0; temp < mat[0].size(); temp++){
                    if(mat[i][temp]){
                        count++;
                    }
                    if(count > 1){
                        break;
                    }
                }
                if(count > 1){
                    continue;
                }
                count = 0;
                for(int temp = 0; temp < mat.size(); temp++){
                    if(mat[temp][j]){
                        count++;
                    }
                    if(count > 1){
                        break;
                    }
                }
                if(count > 1){
                    continue;
                }
                answer1++;
            }
        }
        return answer1;
    }
};