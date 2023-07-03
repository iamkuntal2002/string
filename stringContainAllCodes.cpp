#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
bool check(string s,int k){
    unordered_set<string> st;
    if(s.size()<k) return false;
    for(int i =0;i<=s.size()-k;i++){
        string temp = s.substr(i,k);
        st.insert(temp);
    }
    int total_codes = pow(2,k);
    if(st.size() == total_codes) return true;
    return false;
}