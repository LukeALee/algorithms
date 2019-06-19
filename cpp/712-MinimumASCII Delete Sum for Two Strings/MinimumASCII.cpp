#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        //采用类似寻找最长公共子序列的思想，从字符串末尾开始向前递归求解
        int sLen1=s1.size(),sLen2=s2.size();
        vector<vector<int>> dp(sLen1+1,vector<int>(sLen2+1,0));
        for(int i=1;i<=sLen1;i++){//初始化第一列
            dp[i][0] = dp[i-1][0]+s1[i-1];
        }
        for(int j=1;j<=sLen2;j++){//初始化第一列
            dp[0][j] = dp[0][j-1]+s2[j-1];
        }
        for(int i=1;i<=sLen1;i++){
            for(int j=1;j<=sLen2;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=min(dp[i-1][j-1] + s1[i-1] + s2[j-1],
                             min(dp[i-1][j] + s1[i-1],dp[i][j-1] + s2[j-1]));
                }
            }
        }
        return dp[sLen1][sLen2];
    }
};

int main(){
    string s1 = "sea", s2 = "eat";
    Solution sol;
    int result;
    result = sol.minimumDeleteSum(s1, s2);
    cout << result << endl;
}