class Solution {
public:
    static bool com(std::vector<int> vec1, std::vector<int> vec2){
        if(vec1[0] < vec2[0]){
            return true;
        }
        return false;
    }
    int mostBooked(int n, vector<vector<int>>& meetings) {
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long, int>>> minHeap;
        std::priority_queue<int, std::vector<int>, std::greater<int>> freeRooms;
        std::vector<int> mapa(n, 0);
        
        for(int i = 0; i < n; i++){
            freeRooms.push(i);
        }
        
        std::sort(meetings.begin(), meetings.end());
        
        for(std::vector<int> i:meetings){
            while(!minHeap.empty() && minHeap.top().first <= i[0]){
                freeRooms.push(minHeap.top().second);
                minHeap.pop();
            }
            std::cout<<i[0]<<" "<<i[1]<<'\n';
            if(freeRooms.empty()){
                std::pair<long long, int> temp = minHeap.top();
                minHeap.pop();
                temp.first += i[1] - i[0];
                mapa[temp.second]++;
                minHeap.push(temp);
            }
            else{
                int temp = freeRooms.top();
                freeRooms.pop();
                minHeap.push({i[1], temp});
                mapa[temp]++;
            }
        }
        int answer = 0;
        int max = 0;
        for(int i = 0; i < n; i++){
            if(mapa[i] > max){
                max = mapa[i];
                answer = i;
            }
            else if(mapa[i] == max){
                if(i < answer){
                    answer = i;
                }
            }
        }
        return answer;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();