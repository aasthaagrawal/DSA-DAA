/* Author: Aastha Agrawal
 * Given dictionaries of pronouns, verbs etc,
 * form all the possible sentences.
 */

#include <bits/stdc++.h>
#define R 3
#define C 3

using namespace std;

void printAllSentencesUtil(string s[R][C],string output[],int r,int c){
    output[r]=s[r][c];
    if(r==R-1){
        for(int i=0;i<R;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    for(int i=0;i<C;i++){
        if(s[r+1][i]!=""){
            printAllSentencesUtil(s,output,r+1,i);
        }
    }
}

void printAllSentences(string s[R][C]){
    string output[R];
    for(int i=0;i<C;i++){
        if(s[0][i]!=""){
            printAllSentencesUtil(s,output,0,i);
        }
    }
}

int main() {
	string s[R][C]= {{"you", "we"},
                  {"have", "are"},
                  {"sleep", "eat", "drink"}};
                  
    printAllSentences(s);
	return 0;
}
