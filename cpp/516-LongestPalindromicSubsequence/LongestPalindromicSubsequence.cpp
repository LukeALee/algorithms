#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class SolutionBest {
public:
    int longestPalindromeSubseq(string s) {
        //与最长公共子序列的思想类似，但有细节上的不同，用dp算法解决
        if(s.empty())return 0;
        int sLen=s.size();
        vector<int> dp(sLen,1);
        for(int i=sLen-1;i>=0;i--){
            int pre=0;
            for(int j=i+1;j<sLen;j++){
                int t = dp[j];
                if(s[i]==s[j])dp[j] = pre+2;
                else dp[j]=max(dp[j-1],dp[j]);
                pre=t;
            }
        }
        return dp[sLen-1];
    }
    
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //转化为求s和reverse s 的最长公共子序列，用dp算法解决
        int sLen=s.size();
        if(sLen<=1)return sLen;
        int maxPalSeq=1;
        string s2=s;
        reverse(s2.begin(),s2.end());
        return longestCommongSubSeq(s,s2);
    }
    int longestCommongSubSeq(string s1,string s2){
        int sLen=s1.size();
        vector<vector<int>> dp(sLen,vector<int>(sLen,0));
        for(int i=1;i<sLen;i++){
            for(int j=1;j<sLen;j++){
                if(s1[i]==s2[j])dp[i][j]=dp[i-1][j-1]+1;
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[sLen-1][sLen-1];
    }
};

int main(){
    string s = "bbbab";
    Solution sol;
    int result;
    result = sol.longestPalindromeSubseq(s);
    cout << result << endl;
}

