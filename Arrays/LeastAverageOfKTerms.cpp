/* Author: Aastha Agrawal
   Finding subarray having least average
*/

#include <bits/stdc++.h>
using namespace std;

void leastAverage(int arr[], int k,int n){
    if(n<k)
        return;
    int i=0, min=0, sum=0, index;
    for(;i<k;i++){
        sum+=arr[i];
    }
    min=sum;
    index=k-1;
    while(i<n){
        sum=sum-arr[i-k]+arr[i];
        if(min>sum){
            min=sum;
            index=i;
        }
        i++;
    }
    cout<<"Subarray between ["<<(index-k+1)<<","<<(index)<<"] has least average.";
}

int main() {
    int arr[]={3, 7, 5, 20, -10, 0, 12};
    int k=2;
    int n=(sizeof(arr)/sizeof(arr[0]));
    leastAverage(arr,k,n);
	return 0;
}
