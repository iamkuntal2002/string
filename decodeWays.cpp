#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/decode-ways/
int decodeWays(string s) {
    // Write your code here.
    int len = s.size();
    vector<int> dp(len+1,0);
    int mod = 1e9+7;
    // dp[0] = 1;
    dp[0] = s[0] == '0' ? 0 : 1;
    for(int i=1;i<len;i++) {
        int num=10*(s[i-1]-'0')+(s[i]-'0');
        if(s[i]!='0') {
            dp[i]=(dp[i]+dp[i-1])%mod;
        }
        if(num>=1 && num<=26) {
            if(i>1) {
                dp[i]=(dp[i]+dp[i-2])%mod;
            } else {
              dp[i] = (dp[i] + 1) % mod;
            }
        }
    }
    return dp[len-1]%mod;
}