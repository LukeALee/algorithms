#include<string>
#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int head=0;
        long long strSize=str.size();
        while(head<strSize){
            if(str[head]==' '){
                head++;
                continue;
            }
            else break;
        }
        if(head==strSize){return 0;}
        bool flag=false;
        if(str[head]=='+'){
            head++;
        } else if(str[head]=='-'){
            flag=true;
            head++;
        }
        long long result=0;
        while('0' <= str[head] && str[head]<='9' && head<strSize){
            long long tmpInt=str[head]-'0';
            result = result*10 + tmpInt;
            head++;
            
            if(result>INT_MAX){
                if(flag){
                    result = 0-result;
                    return INT_MIN;
                }return INT_MAX;
            }
            
        }
        if(flag){
            result = 0-result;
        }
        return result;
    }
};