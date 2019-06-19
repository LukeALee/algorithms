#include<iostream>
#include<algorithm>
#define MAX 1000
using namespace std;

bool isPrime[MAX];

void eraton(int n){
    for (int i = 0; i < n;i++)
        isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n;i++){
        if(isPrime[i]){
            int j = 2 * i;
            while(j<=n){
                isPrime[j] = false;
                j += i;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    eraton(n);
    return 0;
}
