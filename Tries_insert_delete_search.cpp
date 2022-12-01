// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    TrieNode * children[26];
    bool isEndOfNode;
    
    public:
    
    TrieNode (){
        memset(children,NULL,sizeof(children));
        isEndOfNode = false;
    }
    
    TrieNode * Search(char a)
    {
        cout << a << endl;
        return children[a-'a']; 
    }
    
    TrieNode * Insert(char a)
    {
        if(children[a-'a']) return children[a-'a'];
        children[a-'a'] = new TrieNode();
        
        return children[a-'a'];
    }
    
    void leaf(){
        isEndOfNode = true;
    }
    
    bool check(){
        return isEndOfNode;
    }
    
    bool Delete(string &s,int ind)
    {
        if(ind==s.size()) {
            // cout << "ID "<<isEndOfNode << endl;
            isEndOfNode = false;
            for(int i=0;i<26;i++)
            if(children[i]) return false;
            
            return true;
        }        
        if(!children[s[ind]-'a']) return false;

        bool exists = children[s[ind]-'a'] -> Delete(s,ind+1);
        if(exists) {children[s[ind]-'a']=NULL;}
        
        return exists;
    }
};

void insert(string s,TrieNode * root)
{
    for(int i=0;i<s.size();i++)
    {
        root = root->Insert(s[i]);
        if(i==s.size()-1) root->leaf();
    }
}

bool search(string s, TrieNode * root)
{
    for(int i=0;i<s.size();i++)
    {
        root = root->Search(s[i]);
        if(!root) return false;
        if(i==s.size()-1) return root->check();
    }
}

void deleteKey(string s, TrieNode * root)
{
    root->Delete(s,0);
}

int main() {
    // Write C++ code here
    string keys[5] = {"geek","bad","bat","l","lo"};
    TrieNode * root = new TrieNode();
    
    for(int i=0;i<5;i++)
    {
        insert(keys[i],root);
    }
    cout << search("l",root);
    
    deleteKey("l",root);
    cout << search("l",root);
    return 0;
}
