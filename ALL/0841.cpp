class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        std::vector<int> visited(rooms.size(), 0);
        std::queue<int> q;
        q.push(0);
        while(q.empty() != true){
            int m = q.front();
            visited[m] = 1;
            for(int i:rooms[m]){
                if(visited[i] == 0){
                    q.push(i);
                }
            }
            q.pop();
        }
        for(int i:visited){
            if(i == 0){
                return false;
            }
        }
        return true;
    }
};