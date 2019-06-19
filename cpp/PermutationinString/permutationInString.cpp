/*
 * @LukeA.Lee app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串1的某种排列是否为字符串2的子串
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int sLen1=s1.size();
        int sLen2=s2.size();
        if(sLen1>sLen2 || sLen2<1)return false;
        string s1copy=s1;
        for(int i=0;i<sLen1;i++){
            if(s2.find(s1[i])==string::npos)return false;
            for(int k=0;k<sLen2;k++){
                int start = i;
                if(s1[start]==s2[k]){//找到s1中该字母在s2出现的位置
                    s1copy=s1copy.substr(0,start)+s1copy.substr(start+1,s1copy.size()-start-1);
                    while(s1copy.size()>0){
                        size_t found =s1copy.find(s2[++k]);
                        if(found == string::npos){
                            s1copy=s1;
                            break;
                        }else{
                            s1copy=s1copy.substr(0,found)+s1copy.substr(found+1,s1copy.size()-found-1);
                        }
                    }
                    if(s1copy.size()==0)return true;
                }
            }
        }
        return false;
    }
};

int main(){
    string s1 = "ab";
    string s2 = "sbac";
    Solution sol;
    bool ans = sol.checkInclusion(s1, s2);
    cout << ans << endl;
}