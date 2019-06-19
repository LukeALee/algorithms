#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen=s.size(),tLen=t.size();
        if(sLen>tLen)return false;
        if(sLen==0 && tLen==0)return true;
        vector<vector<bool>> dp(sLen+1,vector<bool>(tLen+1,false));
        for(int i=0;i<=tLen;i++)dp[0][i]=true;
        for(int i=1;i<=sLen;i++){
            for(int j=1;j<=tLen;j++){
                if(t[j-1]=s[i-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=dp[i][j-1];
            }
        }
        return dp[sLen][tLen];
    }
};
int main(){
    string s = "abc";
    string t="ahbgdc";
    Solution sol;
    bool result = sol.isSubsequence(s, t);
    cout << result << endl;
    return 0;
}