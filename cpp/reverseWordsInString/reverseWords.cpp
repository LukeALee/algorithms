#include<iostream>
#include<sstream>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
       string ans = "";
        if (s.empty()) return ans;
        stringstream ss(s);
        string str;
        while (ss >> str) {
            int l = 0, r = str.length()-1;
            while (l < r) {
                swap(str[l++], str[r--]);
            }
            ans += " ";
            ans += str;
        }
        return ans.substr(1);
    }
};
int main(){
    string str = "Let's take LeetCode contest";
    Solution sol;
    str = sol.reverseWords(str);
    cout << str << endl;
}