class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        std::map<int,int> map1;
        int count = 0;
        for(int i:nums){
            if(map1[i] > 0){
                count += map1[i];
            }
            map1[i]++;
        }
        
        return count;
    }
};