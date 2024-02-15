class Solution {
public:
    string removeDuplicates(string s, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::stack<char> stk;
        std::stack<char> temp_stk;
        int count=0;
        for(char i:s){
            stk.push(i);
        }
        char temp=stk.top();
        while(!stk.empty()){
            if(stk.top()==temp){
                temp_stk.push(temp);
                stk.pop();
                count++;
            }
            else{
                count=1;
                temp=stk.top();
                stk.pop();
                temp_stk.push(temp);
            }
            if(count==k){
                for(int i=0;i<k;i++){
                    temp_stk.pop();
                }
                int tem=0;
                while(!temp_stk.empty() && tem<k){
                    stk.push(temp_stk.top());
                    temp_stk.pop();
                    tem++;
                }
            }
        }
        s="";
        while(!temp_stk.empty()){
            s+=temp_stk.top();
            temp_stk.pop();
        }
        std::cout<<std::flush;
        return s;
    }
};