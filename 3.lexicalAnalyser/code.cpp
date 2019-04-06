#include <bits/stdc++.h>

using namespace std;

const int keywordCount = 32;
char keywords[keywordCount][10] = {
    "auto", "break", "case", "char", "const", "continue", 
    "default", "do", "double", "else", "enum", "extern", 
    "float", "for", "goto", "if", "int", "long", "register", 
    "return", "short", "signed", "sizeof", "static", 
    "struct", "switch", "typedef", "union", "unsigned", 
    "void", "volatile", "while"
};

const int operatorCount = 6;
char operators[operatorCount] = {
    '+', '-', '*', '/', '%', '='
};


int isKeyword(char token[]){
    for (int i = 0; i < keywordCount ; ++i){
        if (strcmp(keywords[i], token) == 0){
            return 1;
        }
    }
    return 0;
}

int main(int argc,char *argv[]){
    char *filename;
    char ch, token[15];
    int i, j = 0;

    if(argc>1){
        filename = argv[1];
    }else{
        cout<<"Please Enter name of the code file: ";
        cin>>filename;
    }

    ifstream fin(filename);
    if (!fin.is_open()){
        cout << "Error opening the file\n";
        exit(0);
    }

    while (!fin.eof()){

        ch = fin.get();
        for (i = 0; i < operatorCount; ++i){
            if (ch == operators[i])
                cout << ch << " is operator\n";
        }

        if (isalnum(ch)){
            token[j++] = ch;
        }else if ((ch == ' ' || ch == '\n') && (j != 0)){
            token[j] = '\0';
            j = 0;
            if (isKeyword(token) == 1){
                cout << token << " is keyword\n";
            }else{
                cout << token << " is indentifier\n";
            }
        }
    }

    fin.close();
    return 0;
}