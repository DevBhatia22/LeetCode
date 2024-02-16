class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        std::unordered_map<int, int> map;
        for(int i:arr){
            map[i]++;
        }
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for(std::pair<int, int> i:map){
            pq.push(i.second);
        }
        while(k > 0){
            int num = pq.top();
            pq.pop();
            k -= num;
        }
        std::cout<<k;
        if(k){
            return pq.size() + 1;
        }
        return pq.size();
    }
};