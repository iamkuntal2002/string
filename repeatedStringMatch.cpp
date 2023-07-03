#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/repeated-string-match/description/
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp = "";
        int count=0;
        while(temp.size() < b.size()){
            temp+= a;
            count++;
        }
        if(temp.find(b) != string::npos) return count;
        temp+= a;
        count++;
        if(temp.find(b) != string::npos) return count;
        return -1;
    }
};