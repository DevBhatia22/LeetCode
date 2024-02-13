class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> adjacent(n, std::vector<int>());
        std::vector<int> indegree(n, 0);
        for(std::vector<int> i:edges){
            adjacent[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        std::queue<int> queue;
        std::vector<std::vector<int>> answer(n, std::vector<int>());
        for(int i = 0; i < n; i++){
            if(!indegree[i]){
                queue.push(i);
            }
        }
        while(!queue.empty()){
            int temp = queue.front();
            for(int i:adjacent[temp]){
                for(int j:answer[temp]){
                    bool temp1 = true;
                    for(int k:answer[i]){
                        if(j == k){
                           temp1 ^= 1;
                           break;
                        }
                    }
                    if(temp1){
                        answer[i].push_back(j);
                    }
                }
                answer[i].push_back(temp);
                indegree[i]--;
                if(!indegree[i]){
                    queue.push(i);
                }
            }
            queue.pop();
        }
        for(int i = 0; i < answer.size(); i++){
            std::sort(answer[i].begin(), answer[i].end());
        }
        return answer;
    }
};