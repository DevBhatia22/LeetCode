class Solution {
public:
    static bool help(std::vector<int> vec1, std::vector<int> vec2){
        if(vec1[1] < vec2[1]){
            return 1;
        }
        
        return 0;
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::sort(trips.begin(), trips.end(), help);
        int capacityNow = 0;
        for(std::vector<int> i:trips){
            while(minHeap.empty() != true && minHeap.top().first <= i[1]){
                capacityNow -= minHeap.top().second;
                minHeap.pop();
            }
            minHeap.push({i[2], i[0]});
            capacityNow += i[0];
            if(capacity < capacityNow){
                return 0;
            }
        }
        return 1;
    }
};