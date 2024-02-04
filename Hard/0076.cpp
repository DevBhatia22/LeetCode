#include<bits/stdc++.h>
class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> map1;
        std::unordered_map<char, int> map2;
        std::string answer;
        int start = 0, end = 0;
        
        for(char i:t){
            map2[i]++;
        }
        
        std::string temp;
        while(end < s.length()){
            if(map2[s[end]]){
                map1[s[end]]++;
            }
            temp += s[end];
            while(start < end){
                if(map2[s[start]] && map1[s[start]] > map2[s[start]]){
                    map1[s[start]]--;
                    start++;
                }
                else if(map2[s[start]]){
                    break;
                }
                else{
                    start++;
                }
            }
            temp = s.substr(start, end - start + 1);
            bool trash = true;
            for(std::pair<int, int> i:map2){
                if(map1[i.first] < i.second){
                    trash = false;
                    break;
                }
            }
            if(trash){
                if(temp.length() < answer.length() || answer == ""){
                    answer = temp;
                }
            }
            end++;
        }
        return answer;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();