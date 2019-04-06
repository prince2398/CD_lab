#include <bits/stdc++.h>

using namespace std;

void ifComments(string program){
    int n = program.length();
    string res;
    
    bool singleLineComment = 0;
    bool multiLineComment = 0;
    
    for (int i = 0; i < n; i++){
        if (program[i] == '/' && program[i + 1] == '/'){
            singleLineComment = 1;
        }else if (program[i] == '/' && program[i + 1] == '*'){
            while(i<n){
                if(program[i] == '*' && program[i+1] == '/'){
                    multiLineComment = 1;
                    break;
                }
                i++;
            }
        }
    }
    
    if (multiLineComment == 1){
        cout << "Multiline comment is present" << endl;
    }
    if (multiLineComment == 0){
        cout << "Multiline comment is not present" << endl;
    }
    if (singleLineComment == 1){
        cout << "Singleline comment present" << endl;
    }
    if (singleLineComment == 0){
        cout << "Singleline comment not present" << endl;
    }
}


int main(){
    string program = " /* Test program */           \
                        int main(){                 \
                            // variable declaration \
                            int sum, y, z;          \
                            /* This is a            \
                                multiline           \
                                comment for         \
                                testing */          \
                            sum = y + z;            \
                            return 0;               \
                        }                           \
                        ";
    ifComments(program);
    return 0;
}