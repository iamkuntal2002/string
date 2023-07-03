#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/string-compression/description/
 int compress(vector<char>& chars) {
        string res = "";
        for(int i =0;i<chars.size();i++){
            int count = 1;
            while(chars[i] == chars[i+1] && i<chars.size()-1) {
                i++;
                count++;
            }
            res += chars[i];
            if(count == 1) continue;
            res += to_string(count);
            cout<<res<<endl;
        }
        return res.size();
    }
    int main(){
        vector<char> v = {'a','a','b','b','c'};
        cout<<compress(v)<<endl;
    }