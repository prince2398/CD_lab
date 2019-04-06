#include <bits/stdc++.h>

using namespace std;

const int totalKeywords = 62;
string keywords[totalKeywords] = {
    "auto","const","double","float","int","short","struct","unsigned",
    "break","continue","else","for","long","signed","switch","void",
    "case","default","enum","goto","register","sizeof","typedef","volatile",
    "char","do","extern","if","return","static","union","while",
    "asm","dynamic_cast","namespace","reinterpret_cast","try",
    "bool","explicit","new","static_cast","typeid",
    "catch","false","operator","template","typename",
    "class","friend","private","this","using",
    "const_cast","inline","public","throw","virtual",
    "delete","mutable","protected","true","wchar_t"
};

int countDelimiters(string str){
    int count =0;
    char ch;
    for(int i=0;i<str.length();i++){
        ch = str[i];
        if(ch == '{' || ch == '}' || ch == ';' || ch == ',' 
        || ch == '[' || ch == ']' || ch == ')'){
            count++;
            // cout<<ch<<" is Delimiter"<<endl;
        }
    }
    return count;
}

bool isOperator(string ch){
    if (ch == "+" || ch == "-" || ch == "*" ||
        ch == "/" || ch == ">" || ch == "<" ||
        ch == "=" || ch == "<<" || ch == ">>"){
        return true;
    }
    return false;
}

int countOperators(string str){
    int count = 0;
    string tmp = "";

    for(int i=0; i<str.length(); i++){
        if(str[i]==' '){
            if(isOperator(tmp)){
                count++;
                // cout<<tmp<<" is Operator"<<endl;
            }
            tmp = "";
        }else{
            tmp += str[i];
        }
    }
    return count;
}

bool isKeyword(string str){
    for(int i=0; i<totalKeywords; i++){
        if(str == keywords[i]){
            return true;
        }
    }
    return false;
}

int countKeywords(string str){
    int count = 0;
    string tmp = "";

    for(int i=0; i<str.length(); i++){
        if(str[i]==' '){
            if(isKeyword(tmp)){
                count++;
                // cout<<tmp<<" is Keyword"<<endl;
            }
            tmp = "";
        }else{
            tmp += str[i];
        }
    }
    return count;
}

bool isLiteral(string str){
    if(str.length() == 0){
        return false;
    }
    if(isdigit(str[0])){
        return true;
    }
    return false;
}

int countLiterals(string str){
    int count = 0;
    string tmp = "";

    for(int i=0; i<str.length(); i++){
        if(str[i]==' '){
            if(isLiteral(tmp)){
                count++;
                // cout<<tmp<<" is Literal"<<endl;
            }
            tmp = "";
        }else{
            tmp += str[i];
        }
    }
    return count;
}

int countIdentifiers(string str){
    int count = 0;
    string tmp = "";

    for(int i=0; i<str.length(); i++){
        if(str[i] == ' '){
            if((countDelimiters(tmp)==0) && !isOperator(tmp) &&! isKeyword(tmp) && 
                !isLiteral(tmp) && (tmp != "")){
                count++;
                // cout<<tmp<<" is Identifier"<<endl;
            }
            tmp = "";
        }else{
            tmp += str[i];
        }
    }
    return count;
}

int main(int argc,char* argv[]){

    string filename;
   if(argc>1){
        filename = argv[1];
    }else{
        cout<<"Please Enter name of the code file: ";
        cin>>filename;
    }

    ifstream fin(filename);
    if (!fin.is_open()){
        cout << "Error opening the file\n";
        exit(1);
    }

    int cDelimiters = 0;
    int cOperators = 0;
    int cKeywords = 0; 
    int cLiterals = 0;
    int cIdentifiers = 0;
    int total = 0;

    string temp;

    while(fin){
        getline(fin,temp);
        cDelimiters += countDelimiters(temp);
        cOperators += countOperators(temp);
        cKeywords += countKeywords(temp);
        cLiterals += countLiterals(temp);
        cIdentifiers += countIdentifiers(temp);
    }

    total = cDelimiters + cOperators + cKeywords + cLiterals + cIdentifiers;

    cout<<"Total Token Count: \t"<<total<<endl;
    cout<<"Delimiters Count: \t"<<cDelimiters<<endl;
    cout<<"Operators Count: \t"<<cOperators<<endl;
    cout<<"Keywords Count: \t"<<cKeywords<<endl;
    cout<<"Literals Count: \t"<<cLiterals<<endl;
    cout<<"Identifiers Count: \t"<<cIdentifiers<<endl;

    return 0;
}