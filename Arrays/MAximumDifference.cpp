/* Author: Aastha Agrawal
 * Given an unsorted array, find the maximum difference such    
 * that larger element appears after the smaller of the two
 */

#include <bits/stdc++.h>

using namespace std;

void printMax(int arr[], int n){
    int minNum=arr[0];
    int maxDiff=arr[1]-arr[0];
    for(int i=1;i<n;i++){
        if((arr[i]-minNum)>maxDiff)
            maxDiff=arr[i]-minNum;
        if(minNum>arr[i])
            minNum=arr[i];
    }
    cout<<maxDiff<<endl;
}

int main() {
    int arr[] = {1, 2, 6, 80, 100};
    int n = (sizeof(arr))/(sizeof(arr[0]));
    printMax(arr,n);
	return 0;
}
