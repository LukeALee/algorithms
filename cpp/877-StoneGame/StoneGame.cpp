#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int sLen=piles.size();
        vector<int> dp=piles;//dp 记录从i到j先取石子者能够取得的优势
        for(int len=2;len<=sLen;len++){
            for(int i=0;i<sLen-len+1;i++){
                int j=i+len-1;
                dp[i]=max(piles[i]-dp[i+1],piles[j]-dp[i]);
                //此时的dp[i]记录的是len-1时的值，刚好是i to i+len-1;
                //而dp[i+1]也是pile[i+1]到pile[i+1+len-1]=pile[i+len]所能取得的优势
            }
        }
        return dp[0];
    }
};