#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i =0;i<s.size();i++){
            char curr = s[i];
            if(curr == '('){
                st.push(curr);
                continue;
            }
            if(curr == ')' && !st.empty()){
                if(st.top() == '('){
                    st.pop();
                    continue;
                }
                else st.push(curr);
            }
            if(curr == ')' && st.empty()) st.push(curr);
        }
        return st.size();
    }
};