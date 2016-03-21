/* Author: Aastha Agrawal
 * Can given sentence be formed by given dictionary
 */

#include <bits/stdc++.h>

using namespace std;

bool isValidString(string s){
    string dictionary[]={"i","vamp","hate","love","books","music"};
    int size=(sizeof(dictionary))/(sizeof(dictionary[0]));
    for(int i=0;i<size;i++){
        if(dictionary[i].compare(s)==0)
            return true;
    }
    return false;
}

bool wordBreak(string str){
    int len =str.size();
    if(len==0)
        return true;
    bool dp[len+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=1;i<=len;i++){
        if(dp[i]==false && isValidString(str.substr(0,i)))
            dp[i]=true;
        if(dp[i]==true){
            if(i==len)
                return true;
            for(int j=i+1;j<=len;j++){
                if(dp[j]==false && isValidString(str.substr(i,j-i)))
                    dp[i]=true;
                if(j==len && dp[j]==true)
                    return true;
            }
        }
    }
    return false;
}


int main() {
    string check="ilovebook";
    cout<<wordBreak(check);
	return 0;
}
