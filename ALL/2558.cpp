class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long answer = 0;
        std::priority_queue<int> priorityQueue;
        for(int i = 0; i < gifts.size(); i++){
            priorityQueue.push(gifts[i]);
        }
        while(k--){
            int K;
            K = priorityQueue.top();
            priorityQueue.pop();
            priorityQueue.push(sqrt(K));
        }
        while(!priorityQueue.empty()){
            answer += priorityQueue.top();
            priorityQueue.pop();
        }
        return answer;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();