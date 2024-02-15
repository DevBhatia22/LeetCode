class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int sCurrent = 0;
        int gCurrent = 0;
        while(sCurrent < s.size() && gCurrent < g.size()){
            if(s[sCurrent] >= g[gCurrent]){
                count++;
                sCurrent++;
                gCurrent++;
            }
            else{
                sCurrent++;
            }
        }
        return count;
    }
};