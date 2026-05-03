
// optial partition of string
#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

int optimal_partition_of_String(string s){
  unordered_set<char> hash;
    int count=1;
    for(char c:s){
        if(hash.find(c)!=hash.end()){ // element found in hash
            count++;
            hash.clear();
            hash.insert(c);
        }
        else{
            hash.insert(c);
        }
      
    }
    return count;
}
int main() {
    string s="Dataeee";
    cout<<"Total number of OPtimal partition string is: "<< optimal_partition_of_String(s)<<endl;
    return 0;
}