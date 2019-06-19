#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
/*KMP*/
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s);
        reverse(rev.begin(),rev.end());
        string ns=s+"#"+rev;
        const int sLen=ns.size();
        vector<int> fp(sLen,0);
        int tp=fp[0];
        for(int i=1;i<sLen;i++){
            tp=fp[i-1];
            while(tp>0 && ns[i]!=ns[tp])
                tp=fp[tp-1];
            if(ns[i]==ns[tp])
                ++tp;
            fp[i]=tp;
        }
        return rev.substr(0,s.size()-fp[sLen-1])+s;
    }
};
int main(){
    string str = "aacecaaa";
    Solution sol;
    string result;
    result = sol.shortestPalindrome(str);
    cout << result<<endl;
}