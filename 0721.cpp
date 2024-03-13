class Solution {
public:
    std::vector<int> parent, size;
    void unionDs(int num1, int num2){
        num1 = parentDs(num1);
        num2 = parentDs(num2);
        if(num1 == num2){
            return;
        }
        if(size[num1] > size[num2]){
            parent[num2] = num1;
            size[num1] += size[num2];
        }
        else{
            parent[num1] = num2;
            size[num2] += size[num1];
        }
    }
    int parentDs(int num){
        if(parent[num] == num){
            return num;
        }
        parent[num] = parentDs(parent[num]);
        return parent[num];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        parent.resize(accounts.size());
        for(int i = 0; i < accounts.size(); i++){
            parent[i] = i;
        }
        size.resize(accounts.size(), 1);
        std::unordered_map<std::string, int> map;
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(map.find(accounts[i][j]) != map.end()){
                    unionDs(i, map[accounts[i][j]]);
                }
                else{
                    map[accounts[i][j]] = i;
                }
            }
        }
        std::vector<std::vector<std::string>> answer;
        std::vector<std::vector<std::string>> temp(accounts.size());
        for(std::pair<std::string, int> i:map){
            int index = parentDs(i.second);
            temp[index].push_back(i.first);
        }
        for(std::vector<std::string> i:temp){
            if(i.size() == 0){
                continue;
            }
            sort(i.begin(), i.end());
            i.insert(i.begin(), accounts[map[i[0]]][0]);
            answer.push_back(i);
        }
        return answer;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();