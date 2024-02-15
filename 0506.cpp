class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> copy_vector = score;//deep copy
        vector<string> str;
        map<int,int> rank;

        //sort so that we can get the positions of each players
        sort(copy_vector.begin(),copy_vector.end(),greater<int>());

        //giving them rank
        int ranker=1;
        for(int i=0;i<copy_vector.size();i++){
            rank[copy_vector[i]]=ranker++;
        }

        //updating the vector str to give the ranks
        for(int i=0;i<score.size();i++){
            if(rank[score[i]]==1){
                str.push_back("Gold Medal");
            }
            else if(rank[score[i]]==2){
                str.push_back("Silver Medal");
            }
            else if(rank[score[i]]==3){
                str.push_back("Bronze Medal");
            }
            else{
                str.push_back(to_string(rank[score[i]]));
            }
        }
    return str;
    }
};