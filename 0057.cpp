class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>answer;
        int start=newInterval[0],end=newInterval[1];
        bool inserted=false;
        for(int i=0;i<size(intervals);i++){
            int cstart=intervals[i][0],cend=intervals[i][1];
            
            if(cend<start || inserted){
                answer.push_back({cstart,cend});
                continue;
            }
            start=min(start,cstart);
            if(end<cstart){
                answer.push_back({start,end});
                answer.push_back({cstart,cend});
                inserted=true;
                continue;
            }
            if(end<=cend){
                answer.push_back({start,cend});
                inserted=true;               
            }
        }
        if(!inserted){
            answer.push_back({start,end});
        }
        return answer;
    }
};