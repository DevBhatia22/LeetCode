class Solution {
public:
    int rec(std::vector<std::string>& arr, std::vector<int> vec, int index){
        if(index == arr.size()){
            int i = 0;
            for(int j:vec){
                if(j == 1){
                    i++;
                }
            }
            return i;
        }
        int without = rec(arr, vec, index + 1);
        for(char i:arr[index]){
            if(vec[i - 'a'] == 1){
                return without;
            }
            else{
                vec[i - 'a']++;
            }
        }
        return std::max(without, rec(arr, vec, index));
    }
    int maxLength(vector<string>& arr) {
        std::vector<int> vec(26, 0);
        return rec(arr, vec, 0);
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();