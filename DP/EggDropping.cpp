/* Author: Aastha Agrawal
 * Egg dropping puzzle
 * n eggs and f floors
 */

#include <bits/stdc++.h>
using namespace std;

int eggDrop(int n,int f){
    int eggFloor[n+1][f+1],res;
    for(int i=1;i<=n;i++){
        eggFloor[i][0]=0;
        eggFloor[i][1]=1;
    }
    
    for(int j=1;j<=f;j++)
        eggFloor[1][j]=j;
        
    for(int i=2;i<=n;i++){
        for(int j=2;j<=f;j++){
            eggFloor[i][j]=INT_MAX;
            for(int x=1;x<=j;x++){
                res=1+max(eggFloor[i-1][x-1],eggFloor[i][j-x]);
                if(res<eggFloor[i][j])
                    eggFloor[i][j]=res;
            }
        }
    }
    return eggFloor[n][f];
}

int main() {
	int n=2;    
	int k=100;
	cout<<eggDrop(n,k);
	return 0;
}
