class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        int total = 0;
        for(int i = 0; i < heights.size() - 1; i++){
            if(heights[i] < heights[i + 1]){
                if(pq.size() < ladders){
                    pq.push(heights[i + 1] - heights[i]);
                }
                else{
                    if(ladders && heights[i + 1] - heights[i] > pq.top()){
                        total += pq.top();
                        pq.pop();
                        pq.push(heights[i + 1] - heights[i]);
                    }
                    else{
                        total += heights[i + 1] - heights[i];
                    }
                    if(total > bricks){
                        return i;
                    }
                }
            }
        }
        return heights.size() - 1;
    }
};