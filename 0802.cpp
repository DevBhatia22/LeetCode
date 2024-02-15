class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        std::vector<std::vector<int>> adjcent(graph.size(), std::vector<int>());
        std::queue<int> queue;
        std::vector<int> answer;
        std::vector<int> temp1(adjcent.size(), 0);
        for(int i = 0; i < graph.size(); i++){
            for(int j:graph[i]){
                adjcent[j].push_back(i);
                temp1[i]++;
            }
            if(graph[i].empty()){
                queue.push(i);
            }

        }
        
        while(!queue.empty()){
            int temp = queue.front();
            queue.pop();
            for(int i:adjcent[temp]){
                temp1[i]--;
                if(!temp1[i]){
                    queue.push(i);
                }
            }
            answer.push_back(temp);
        }
        std::sort(answer.begin(), answer.end());
        return answer;
    }
};