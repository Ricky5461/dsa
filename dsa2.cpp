#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;
int main(){
    string s="ADOBECODEBANC";
    string t="ABC";
    unordered_set<char> hash;
    hash.insert('A');
    cout<<hash.size()<<endl;
    return 0;
}