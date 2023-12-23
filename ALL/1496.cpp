class Solution {
public:
    bool isPathCrossing(string path) {
        std::map<std::pair<int, int>, int> map1;
        map1[std::pair<int, int>(0, 0)] = 1;
        int x = 0;
        int y = 0;
        for(char i:path){
            if(i == 'E'){
                x++;
            }
            else if(i == 'W'){
                x--;
            }
            else if(i == 'N'){
                y++;
            }
            else{
                y--;
            }

            map1[std::pair<int, int>(x, y)]++;
            if(map1[std::pair<int, int>(x, y)] > 1){
                return 1;
            }
        }
        return 0;
    }
};