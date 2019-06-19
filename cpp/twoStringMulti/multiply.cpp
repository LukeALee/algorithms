#include<iostream>
#include<string>
#include<deque>
#include<iterator>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
       deque<char> result;
       deque<char> iter_result;
       for(int i=num1.size()-1;i>=0;i--){
           iter_result.clear();
           for(int k=0;k<num1.size()-1-i;k++){
              iter_result.push_front(char(0));
           }
           int last_num=num1[i]-'0';
           int carry = 0;
           for(int j=num2.size()-1;j>=0;j--){
               int bitMul=last_num * (num2[j]-'0')+carry;
               carry = bitMul/10;
               iter_result.push_front( (char)(bitMul%10) );
           }
           if(carry>0){
               iter_result.push_front((char)carry);
           }
           int m=result.size()-1,n=iter_result.size()-1;
           carry=0;
           while(m>=0 || n>=0){
               if(m>=0 && n>=0){
                   int bitAdd=(result[m]-char(0))+(iter_result[n]-char(0))+carry;
                   carry=bitAdd/10;
                   result[m]=(char)(bitAdd%10);
                   m--;
                   n--;
               }
               else if(m>=0 && n<0){
                   if(carry>0){
                       int bitAdd=(result[m]-char(0))+carry;
                       carry=bitAdd/10;
                       result[m]=(char)(bitAdd%10);
                       m--;
                   }
               }
              else if(m<0 && n>=0){
                   if(carry>0){
                       int bitAdd=(iter_result[n]-char(0))+carry;
                       carry=bitAdd/10;
                       result.push_front((char)(bitAdd%10));
                       n--;
                   }
                   else{
                       result.push_front(iter_result[n]);
                       n--;
                    }
                       
               }
           }
           if(carry>0){
               result.push_front((char)carry);
           }
       }
       string ans;
       for(deque<char>::iterator iter=result.begin();iter!=result.end();iter++){
           ans += to_string(*iter-char(0));
       } 
       if(ans[0]=='0') return "0";
       return ans; 
    }
};
int main(){
    Solution sol;
    string str1 ="584";
    string str2 =  "18";
    string result;
    result = sol.multiply(str1, str2);
    cout << result << endl;
    return 0;
}