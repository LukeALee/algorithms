#include <cstdio>
#include <queue>
 
using namespace std;

const int maxn = 1000;
int n,m;	
int matrix[maxn][maxn] ; 
bool inq[maxn][maxn] = {false};		
int X[4] = {0,1,0,-1};		
int Y[4] = {1,0,-1,0};

struct node{	
	int x,y;
}Node;
 
bool judge(int x, int y){		 
	if(x<0||y<0|| x>=n|| y>=m) return false;
	if(matrix[x][y] == 0 || inq[x][y] == true) return false;	
	return true; 
}
void BFS(int x, int y){
	queue<node> Q;	
	Node.x = x, Node.y = y;
	Q.push(Node);		 
	inq[x][y] = true;	
	while(! Q.empty()){		 
		node top = Q.front();	
		Q.pop();
		for(int i=0; i<4; i++){	
			int newX = top.x + X[i];	 
			int newY = top.y + Y[i];
			if( judge(newX,newY) ){	
				Node.x = newX;
				Node.y = newY;
				Q.push(Node);
				inq[newX][newY] = true;
			}
		}
	}
}

int main(){
	scanf("%d%d", &n,&m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d" , &matrix[i][j]);
		}
	}
	int block_n = 0;
	for(int x=0; x<n; x++){
		for(int y=0; y<m; y++){
			if(matrix[x][y] == 1 && inq[x][y] == false){
				block_n++;
				BFS(x,y);
			} 
		}
	} 
	printf("%d",block_n);
	return 0;
}
