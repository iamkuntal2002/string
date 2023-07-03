#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/decode-string/
class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> nums;
        string res = "";
        int num = 0;
        for(char c : s) {
            if(isdigit(c)) {
                num = num*10 + (c-'0');                              
            }
            else if(isalpha(c)) {
                res.push_back(c);                
            }
            else if(c == '[') {
                st.push(res);
                nums.push(num);
                res = "";
                num = 0;
            }
            else if(c == ']') {
                string tmp = res;
                for(int i = 0; i < nums.top()-1; ++i) {
                    res += tmp;
                }
                res = st.top() + res;
                st.pop(); 
                nums.pop();
            }
        }
        return res;
    }
};