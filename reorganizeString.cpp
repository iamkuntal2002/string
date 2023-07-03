#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/reorganize-string/
string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26,0);
        int maxfreq = 0;
        char mxfrqchr = '#';
        for(auto &ch : s) {
            freq[ch-'a']++;
            if(freq[ch-'a']>maxfreq){
                maxfreq = freq[ch-'a'];
                mxfrqchr = ch;
            }
        }
        cout<<maxfreq<< " "<<mxfrqchr<<endl;
        if(maxfreq > (n+1)/2) return "";
        int i = 0;
        while(i<n && maxfreq>0){
            s[i] = mxfrqchr;
            i += 2;
            maxfreq--;
        }
        freq[mxfrqchr-'a'] = 0;
        for(int j=0;j<26;j++){
            while(freq[j]>0){
                i = (i>=n) ? 1 : i;
                s[i] = j+'a';
                freq[j]--;
            }
        }
        return s;
    }
    int main(){
        string s = "aab";
        cout<<reorganizeString(s)<<endl;
    }