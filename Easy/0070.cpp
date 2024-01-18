class Solution {
public:
    std::vector<int> vector;
    int declare(int n){
        vector.resize(n, 0);
        return 0;
    }
    int help(int n){
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        if(vector[n - 1] != 0){
            return vector[n - 1];
        }
        else{
            vector[n - 1] = help(n - 1) + help(n - 2);
        }
        return vector[n - 1];
    }
    int climbStairs(int n) {
        declare(n);
        return help(n);
    }
};