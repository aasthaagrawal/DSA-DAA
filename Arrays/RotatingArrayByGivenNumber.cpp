/* Author: Aastha Agrawal
 * Rotating a given array by a fixed number
 */

#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int start, int end){
    int temp;
    while(start<end){
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

void leftRotate(int arr[],int d,int n){
   reverse(arr,0,d-1);
   reverse(arr,d,n-1);
   reverse(arr,0,n-1);
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
	int arr[] = {1,2,3,4,5,6,7};
	int d=2;
	int n=(sizeof(arr))/(sizeof(arr[0]));
	printArray(arr,n);
	leftRotate(arr,d,n);
	printArray(arr,n);
	return 0;
}
