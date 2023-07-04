#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-good-ways-to-split-a-string/description/
class Solution {
public:
    bool check(unordered_map<char,int> &left,unordered_map<char,int> &right,char c){
        left[c]++;
        right[c]--;
        if(right[c]==0) right.erase(c);
        // cout<<"left size = "<<left.size()<<" right size = "<<right.size()<<endl;
        if(left.size() == right.size()) return true;
        return false;
    }
    int numSplits(string s) {
        int count =0;
        unordered_map<char,int> left,right;
        for(char c : s) right[c]++;
        for(char c : s){
            if(check(left,right,c)) count++;
        }     
        return count;
    }
};