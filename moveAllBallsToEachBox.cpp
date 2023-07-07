#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.size());
        int behind = 0;
        int ahead = 0;
        for(int i =0; i<boxes.size(); i++){
            if(boxes[i] == '1'){
                ahead++;
                res[0] += i;
            }
        }
        if(boxes[0] == '1'){
            ahead--;
            behind++;
        }
        for(int i =1; i<boxes.size();i++){
            res[i] = res[i-1] - ahead + behind;
            if(boxes[i] == '1'){
                ahead--;
                behind++;
            }
        }
        return res;
    }
};