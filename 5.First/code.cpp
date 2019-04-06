#include <bits/stdc++.h>

using namespace std;

map<string, vector<string> > grammar;

bool isCapital(char ch){
    if(ch>='A' && ch<='Z'){
        return true;
    }
    return false;
}

bool ifEpsilon(set<string> s){
    return (s.count("^") > 0) ? true : false;
}

void setPrint(set<string> s){
    for(auto i:s){
        cout<<i<<", ";
    }
}

void setUnion(set<string> &s1, set<string> &s2){
    for(auto i:s2){
        if(i != "^"){
            s1.insert(i);
        }
    }
    return;
}

void calcFirst(string nonTerminal, set<string> &firstTemp){
    vector<string> prods = grammar[nonTerminal];
    bool epsilon = false;
    
    for(auto p:prods){
        set<string> temp;
        string prod = p;

        if(prod=="^"){
            firstTemp.insert("^");
            continue;
        }
        if(!isCapital(prod[0])){
            firstTemp.insert(string(1, prod[0]));
            continue;
        }
        calcFirst(string(1, prod[0]), temp);
        
        setUnion(firstTemp, temp);
        
        if(ifEpsilon(temp)){
            int j = 1;
            
            while(j<prod.size() && ifEpsilon(temp) && isCapital(prod[j])){
                temp.clear();
                calcFirst(string(1, prod[j]), temp);
                setUnion(firstTemp, temp);
                j++;
            }
            if(j==prod.size() && ifEpsilon(temp)){
                epsilon = true;
            }
            if(j<prod.size() && ifEpsilon(temp)) {
                firstTemp.insert(string(1, prod[j]));
            }
        }
    }
    if(epsilon){
        firstTemp.insert("^");
    }
    return;
}

int main(int argc, char const *argv[]){
    int nProds;
    
    cout<<"Enter the no. of non-terminals: ";
    cin>>nProds;
    
    for (int i=0;i<nProds;i++){
        cout<<"\nEnter the non-terminal: ";
        string str;
        cin>>str;
        
        grammar[str] = vector<string> ();
        cout<<"Enter the number of productions: ";
        int n;
        cin>>n;

        cout<<"Enter the productions from '"<<str<<"' (space separated): ";
        for (int j=0;j<n;j++){
            string temp;
            cin>>temp;
            grammar[str].push_back(temp);
        }
    }
    cout<<"\nEnter start symbol: ";
    string startSymbol;
    cin>>startSymbol;

    cout<<"\nFirst of Non-Terminals in Given Grammer: \n";
    for(auto p:grammar){
        cout<<"\t";
        set<string> firstTemp;
        calcFirst(p.first, firstTemp);
        cout<<p.first<<" => { ";
        setPrint(firstTemp);
        cout<<"}"<<endl;
    }
    return 0;
}
