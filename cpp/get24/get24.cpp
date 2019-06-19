#include<string>
#include<iostream>
#include<stdlib.h>
#include<cstdlib>
using namespace std;
bool get2(int a, int b, char& ops){
    if(a+b == 24) {ops = '+';return true;}
    if(a-b == 24) {ops = '-';return true;}
    if(a*b == 24) {ops = '*';return true;}
    if(a != 0 && b%a == 0 && b/a == 24) {ops = '/';return true;}
    return false;
}
bool get3(int a, int b, int c, char& ops1, char& ops2){
    if(get2(a+b, c, ops2)) {ops1 = '+';return true;}
    if(get2(a-b, c, ops2)) {ops1 = '-';return true;}
    if(get2(a*b, c, ops2)) {ops1 = '*';return true;}
    if(b != 0 && a%b == 0 && get2(a/b, c, ops2)) {ops1 = '/';return true;}
    return false;
}
bool get4(int a, int b, int c, int d, char& ops1, char& ops2, char& ops3){
    if(get3(a+b, c, d, ops2, ops3)) {ops1 = '+';return true;}
    if(get3(a-b, c, d, ops2, ops3)) {ops1 = '-';return true;}
    if(get3(a*b, c, d, ops2, ops3)) {ops1 = '*';return true;}
    if(b != 0 && a%b == 0 && get3(a/b, c, d, ops2, ops3)) {ops1 = '/';return true;}
    return false;
}
int main(){
    string in[4];
    cin>>in[0]>>in[1]>>in[2]>>in[3];
    string out[4]={in[0],in[1],in[2],in[3]};
    for(int i=0;i<4;i++){
        
        if(in[i]=="joker" || in[i]=="JOKER"){
            cout<<"ERROR"<<endl;
            return 0;
        }
        else if(in[i]=="A")in[i]="1";
        else if(in[i]=="J")in[i]="11";
        else if(in[i]=="Q")in[i]="12";
        else if(in[i]=="K")in[i]="13";
    }
	char  op1 = '+';
	char  op2 = '+';
	char  op3 = '+';
    bool get24=get4(stoi(in[0]),stoi(in[1]),stoi(in[2]),stoi(in[3]), op1,op2,op3);
    if(get24){
        cout<<out[0]+op1+out[1]+op2+out[2]+op3+out[3]<<endl;
    }
    else{
        cout << "None" << endl;
    }
    return 0;
}