#include<iostream>
using namespace std;
class Point{
    public: 
           int x,y;
           Point(int xval,int yval):x(xval),y(yval){}
           Point operator+(const Point& other){
            return Point(this->x+other.x,this->y+other.y);
           }
           
};

 int main(){
    Point p1(10,2);
    Point p2(2,8);
    Point p3=p1+p2;
    cout<<"p3.x:"<<p3.x<<",p3.y:"<<p3.y<<endl;

    return 0;
 }