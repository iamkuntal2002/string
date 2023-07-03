#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/zigzag-conversion
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> st(numRows);
        if(numRows <= 1) return s;
        int step = 1;
        int row = 0;
        for(int i =0;i<s.size();i++){
            st[row].push_back(s[i]);
            if(row == 0) step = 1;      //if pushing at index 0 then next element should be push at the 1 index
            else if(numRows -1 == row) step = -1;   //if pushing at the last index then next element should be push at the prev index
            row += step;
        }
        string res = "";
        for(auto str : st) res += str;
        return res;
    }
};