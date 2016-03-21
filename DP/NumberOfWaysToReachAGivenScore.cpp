/* Author: Aastha Agrawal
 * Count number of ways to reach a given score in a game
 */

#include <bits/stdc++.h>
using namespace std;

int numWays(int arr[], int score, int n){
    int ways[score+1][n],inc,exc;
    for(int i=0;i<n;i++)
        ways[0][i]=1;
    for(int i=1;i<=score;i++){
        for(int j=0;j<n;j++){
            inc=(i-arr[j]<0)?0:ways[i-arr[j]][j];
            exc=(j>=1)?ways[i][j-1]:0;
            ways[i][j]=inc+exc;
        }
    }
    return ways[score][n-1];
}

int main() {
	int score=13;
	int arr[]={3,5,10};
	int n=(sizeof(arr))/(sizeof(arr[0]));
	cout<<numWays(arr,score,n);
	return 0;
}
