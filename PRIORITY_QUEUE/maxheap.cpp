#include<iostream>
#include<queue>
using namespace std;
class maxheap{
    public:
    priority_queue<int>pq;
    void insert(vector<int>&temp){
        for(int n:temp){
            pq.push(n);
        }
    }
    void display(){
        while(!pq.empty()){
            cout<<pq.top()<<endl;
            pq.pop();
        }
    }
};
int main(){
    priority_queue<int>pq;
    pq.push(23);
    pq.push(-234);
    pq.push(243);
    pq.push(3);
    pq.push(90);
    pq.push(-1);
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    cout<<"This is second maxheap treee"<<endl;
    vector<int>arr = {23,245,253,-134,-1,0,343,34,5,22,90};
    maxheap var1;
    var1.insert(arr);
    var1.display();
    return 0;
}