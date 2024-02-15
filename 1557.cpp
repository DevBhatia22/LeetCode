class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        std::vector<int> answer;
        std::vector<int> map(n, 1);
        for(std::vector<int> i:edges){
            map[i[1]] = 0;
        }
        for(int i = 0; i < n; i++){
            if(map[i]){
                answer.push_back(i);
            }
        }
        return answer;
    }
};