class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::ios_base::sync_with_stdio(false);
        std::stack<int> s;
        for(std::string i:operations){
            int x,y;
            if(i=="+"){
                x= s.top();
                s.pop();
                y=s.top();
                s.push(x);
                s.push(x+y);
            }
            else if(i=="D"){
                x=s.top();
                s.push(x+x);
            }
            else if(i=="C"){
                s.pop();
            }
            else{
                s.push(stoi(i));
            }
        }
        int x=0;
        while(!s.empty()){
            x+=s.top();
            s.pop();
        }
        return x;
    }
};