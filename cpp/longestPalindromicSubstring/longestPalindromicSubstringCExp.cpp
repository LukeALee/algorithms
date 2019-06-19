#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        int start = 0, end = 0,len=0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = expandAroundCenter(s, i, i);//一个元素为中心
            int len2 = expandAroundCenter(s, i, i + 1);//两个元素为中心
            len = max(max(len1, len2),len);
            if (len > end - start+1) {
                start = i - (len - 1) / 2;//从中心向前扩展
                end = i + len / 2;//从中心向后扩展
            }
        }
        return s.substr(start, len);//从start开始取len长的子串
        }
    int expandAroundCenter(string s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
};

int main(){
    const int i = 3;
    bool dp[i] = {true};
    cout << *dp << endl;
    return 0;
}