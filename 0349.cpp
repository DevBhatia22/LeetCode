class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int map[1001] = {0};
        std::vector<int> answers;
        for(int i:nums1){
            map[i] = 1;
        }
        for(int i:nums2){
            if(map[i] == 1){
                answers.push_back(i);
                map[i] = 0;
            }
        }
        return answers;
    }
};