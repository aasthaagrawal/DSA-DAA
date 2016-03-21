/* Author: Aastha Agrawal
 * DP for finding Nth catalan number
 */

#include <bits/stdc++.h>
using namespace std;

int getNthCatNo(int n){
    int CatNo[n+1]={0};
    CatNo[0]=CatNo[1]=1;
    cout<<CatNo[0]<<" "<<CatNo[1]<<" ";
    for(int i=2;i<=n;i++){
        CatNo[i]=0;
        for(int j=0;j<i;j++){
            CatNo[i]+=(CatNo[j]*CatNo[i-j-1]);
        }
        cout<<CatNo[i]<<" ";
    }
    return CatNo[n];
}

int main() {
	getNthCatNo(8);
	return 0;
}
