#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 1000
using namespace std;

bool isPrime(int n ){
    if(n<2)
        return false;
    else if(n==2)
        return true;
    if(n%2==0)
        return false;
    for (int i = 2; i*i <= n;i+=2){
        if(n%i==0)
            return false;
    }
    return true;
}
int main(){
    int n;
    while(1){
        scanf("%d", &n);
        cout << isPrime(n) << endl;
    }
    return 0;
} 