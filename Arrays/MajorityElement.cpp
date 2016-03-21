
/*	Author: Aastha Agrawal
	Finding the majority element from a n-size array
 	Moore's Voting Algorithm is being used
*/

#include <bits/stdc++.h>
using namespace std;

int findingCandidate(int arr[],int n){
    //Moore's Voting  Algorithm for finding candidate 
    int maj_index=0;
    int count=1;
    for(int i=1;i<n;i++){
        if(arr[maj_index]==arr[i])
            count++;
        else
            count--;
        if(count==0){
            maj_index=i;
            count=1;
        }
    }
    return arr[maj_index];
}

bool isMajority(int arr[],int n,int candidate){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==candidate)
            count++;
    }
    if(count>(n/2))
        return true;
    else
        return false;
}

void printMajorityElement(int arr[],int n){
    
    int candidate=findingCandidate(arr,n);
    
    if(isMajority(arr,n,candidate))
        cout<<"Majority element is "<<candidate<<endl;
    else
        cout<<"No majority element!"<<endl;
}

int main() {
	int array[]={1,3,4,1,5,2,1,1};
	int n=(sizeof(array))/(sizeof(array[0]));
	printMajorityElement(array,n);
	return 0;
}
