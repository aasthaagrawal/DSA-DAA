/* Author: Aastha Agrawal
 * Finding all the leaders in the array
 * Leaders are elements in an array which are greater than all  
 * other elements to their right
 */

#include <bits/stdc++.h>
using namespace std;

void printLeaders(vector<int> arr,int n){
    int max_till_now=arr[n-1];
    cout<<max_till_now<<" ";
    for(int i=n-2;i>=0;i--){
        if(arr[i]>max_till_now){
            max_till_now=arr[i];
            cout<<max_till_now<<" ";
        }
    }
    cout<<endl;
}

int main() {
    int n=6;
	vector<int> arr(n);
	arr[0]=16;
	arr[1]=17;
	arr[2]=4;
	arr[3]=3;
	arr[4]=5;
	arr[5]=2;
	printLeaders(arr,n);
	return 0;
}
