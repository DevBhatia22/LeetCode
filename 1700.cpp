class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::stack<int> stksw;
        std::queue<int> qst;
        for(int i=0;i<students.size();i++){
            qst.push(students[i]);
            stksw.push(sandwiches[sandwiches.size()-1-i]);
        }
        int count=0;
        while(!stksw.empty() 
        && count< qst.size()){
            if(stksw.top()==qst.front()){
                stksw.pop();
                qst.pop();
                count=0;
            }
            else{
                int x=qst.front();
                qst.pop();
                count++;
                qst.push(x);
            }
        }
        return stksw.size();
    }
};