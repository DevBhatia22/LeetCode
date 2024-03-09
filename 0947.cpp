class Solution {
private:
    std::vector<int> parent, size;
public:
    int search(int i){
        if(parent[i] == i){
            return i;
        }
        parent[i] = search(parent[i]);
        return parent[i];
    }
    void join(int i, int j){
        i = search(i);
        j = search(j);
        if(i == j){
            return;
        }
        else if(size[i] < size[j]){
            parent[i] = j;
            size[j] += size[i];
        }
        else{
            parent[j] = i;
            size[i] += size[j];
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        parent.resize(stones.size());
        for(int i = 0; i < stones.size(); i++){
            parent[i] = i;
        }
        size.resize(stones.size(), 1);
        std::unordered_map<int, int> x, y;
        int count = 0;
        for(int i = 0; i < stones.size(); i++){
            if(x[stones[i][0]] || y[stones[i][1]]){
                if(x[stones[i][0]]){
                    join(i, x[stones[i][0]] - 1);
                }
                if(y[stones[i][1]]){
                    join(i, y[stones[i][1]] - 1);
                }
            }
            x[stones[i][0]] = i + 1;
            y[stones[i][1]] = i + 1;
        }
        for(int i = 0; i < stones.size(); i++){
            if(parent[i] != i){
                count++;
            }
        }
        return count;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();