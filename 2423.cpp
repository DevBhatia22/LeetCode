class Solution {
public:
    bool equalFrequency(string word) {
        std::unordered_map<char, int> hash;
        for(char i:word){
            hash[i]++;
        }
        if(hash.size() == 1){
            return true;
        }
        if(hash.size() == 1){
            return true;
        }
        std::map<int, int> hashOfHash;
        for(auto i:hash){
            hashOfHash[i.second]++;
            if(hashOfHash.size() > 2){
                return false;
            }
        }
        if(hashOfHash.find(1) != hashOfHash.end() && hashOfHash[1] == 1){
            return true;
        }
        if(hashOfHash.size() == 1 && hashOfHash[1]){
            return true;
        }
        if(hashOfHash[hashOfHash.begin()->first + 1] == 1){
            return true;
        }
        return 0;
    }
};