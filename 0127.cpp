class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::set<std::string> set;
        for(std::string i:wordList){
            set.insert(i);
        }
        std::queue<std::string> queue;
        queue.push(beginWord);
        int time = 2;
        while(!queue.empty()){
            int size = queue.size();
            while(size--){
                std::string temp = queue.front();
                queue.pop();
                for(int i = 0; i < temp.length(); i++){
                    std::string temp1 = temp;
                    for(char j = 'a'; j <= 'z'; j++){
                        if(j == temp[i]){
                            continue;
                        }
                        temp1[i] = j;
                        auto pointer = set.find(temp1);
                        if(pointer != set.end()){
                            if(temp1 == endWord){
                                return time;
                            }
                            queue.push(temp1);
                            set.erase(pointer);
                        }
                    }
                }
            }
            time++;
        }
        return 0;
    }
};