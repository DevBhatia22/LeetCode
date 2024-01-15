class Solution {
public:
    int minSetSize(vector<int>& arr) {
        std::unordered_map<int, int> frequency;
        std::priority_queue<int> maxHeap;
        int length = arr.size();
        int newLength = length;
        int answer = 0;
        for(int i = 0; i < length; i++){
            frequency[arr[i]]++;
        }
        for(std::pair<int, int> temp:frequency){
            maxHeap.push(temp.second);
        }
        while(!maxHeap.empty()){
            newLength -= maxHeap.top();
            maxHeap.pop();
            answer++;
            if(newLength <= length / 2){
                break;
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