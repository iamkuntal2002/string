#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string res = "1";
        for(int i =1;i<n;i++){
            string temp = "";
            for(int j = 0;j<res.size();j++){
                int count = 1;
                while(j<res.size()-1 && res[j] == res[j+1]){
                    j++;
                    count++;
                }
                temp += to_string(count);
                temp += res[j];
            }
            res = temp;
        }
        return res;
    }
};