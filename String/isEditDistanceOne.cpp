/* Author: Aastha Agrawal
 * Check if edit distance is less than 1 or not
 */

#include <bits/stdc++.h>
using namespace std;

bool editDistance(string str1, string str2){
    int l1=str1.size();
    int l2=str2.size();
    if(abs(l1-l2)>1)
        return false;
    
    int i=0, j=0, count=0;
    while(i< l1 && j<l2){
        if(str1[i]==str2[i]){
            i++; 
            j++;
        }
        else{
            if(count==1)
                return false;
            count++;
            
            if(l1>l2)
                i++;
            else if(l2>l1)
                j++;
            else{
                i++;
                j++;
            }
            
        }
    }
    return true;
}

int main() {
	string str1="aastha";
	string str2="aastha94";
	if(editDistance(str1,str2))
	    cout<<"Yes";
	else
	    cout<<"No";
	return 0;
}
