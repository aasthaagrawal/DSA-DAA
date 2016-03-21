/* Author: Aastha Agrawal
 * Segregating even and odd numbers in an array
 */

#include <bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void segregateEvenOdd(int arr[], int n){
    int l=0;
    int r=n-1;
    int lMode,rMode;
    while(l<r){
        lMode=arr[l]%2;
        rMode=arr[r]%2;
        if(lMode==0)
            l++;
        if(rMode==1)
            r--;
        if(lMode==1 && rMode==0){
            swap(arr[l],arr[r]);
            l++;
            r--;
        }
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
	int arr[]={12,34,45,9,8,90,3};
	int n=(sizeof(arr))/(sizeof(int));
	printArray(arr,n);
	segregateEvenOdd(arr,n);
	printArray(arr,n);
	return 0;
}
