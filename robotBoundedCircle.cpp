#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/robot-bounded-in-circle/
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int currdic = 'N';
        int x = 0, y = 0;
        for(int i =0;i<instructions.size();i++){
            if(instructions[i] == 'G'){
                x += currdic == 'E' ? 1 : 0;
                x += currdic == 'W' ? -1 : 0;
                y += currdic == 'N' ? 1 : 0;
                y += currdic == 'S' ? -1 : 0;
            }
            else{
                char incoming = instructions[i];
                if(currdic == 'N'){
                    currdic = incoming == 'L' ? 'W' : 'E';
                }
                else if(currdic == 'W'){
                    currdic = incoming == 'L' ? 'S' : 'N';
                }
                else if(currdic == 'S'){
                    currdic = incoming == 'L' ? 'E' : 'W';
                }
                else{
                    currdic = incoming == 'L' ? 'N' : 'S';
                }
            }
        }
        if(x ==0 && y == 0) return true;
        else if(currdic != 'N') return true;
        return false;
    }
};