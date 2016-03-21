/* Author: Aastha Agrawal
 * Dynamic Programming - Edit Distance
 */

#include <bits/stdc++.h>
using namespace std;

int min(int a,int b,int c){
    return min(a,min(b,c));
}

int editDistance(string str1, string str2, int l1,int l2){
    int dp[l1+1][l2+1];
    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=1+min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]);
            }
        }
    }
    return dp[l1][l2];
}

int main() {
	string str1="satur";
	string str2="sun";
	cout<<editDistance(str1,str2,str1.size(),str2.size());
	return 0;
}
