#include<iostream>
using namespace std;

class opertrOverLod
{
    private:
       int data;
    public:
        opertrOverLod(int count);
        ~opertrOverLod();
};

opertrOverLod::opertrOverLod(int c)
{
}

opertrOverLod::~opertrOverLod()
{
    cout<<"Ricky";
}

int main(){
    cout<<"Ricky kumar soni";
    return 0;
}