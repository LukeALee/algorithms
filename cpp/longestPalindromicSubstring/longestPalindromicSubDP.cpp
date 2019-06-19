#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const int sLen = s.size();
        if (s.size() <= 1) return s;
        bool dp[sLen][sLen] = {false};
        for (int i = 0; i < sLen;i++){
            dp[i][i] = true;
            if(s[i]==s[i+1]){
                dp[i][i + 1] = true;
            }
        }
        int begin = 0, end = 1;
        for (int len = 3; len <= sLen;len++){
            for (int i = 0; i < sLen - len+1;i++){
                int j = len + i -1;
                if(dp[i+1][j-1] && s[i]==s[j]){
                    dp[i][j] = true;
                    if(len>(end-begin+1)){
                        begin = i;
                        end = j;
                    }
                }

            }
        }
        cout << begin << end<<endl;
        return s.substr(begin, (end - begin + 1));
    }
};
int main(){
    string test = "cbbd";
    Solution sol;
    cout << sol.longestPalindrome(test) << endl;
    return 0;
}
