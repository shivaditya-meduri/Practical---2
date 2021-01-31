#include<iostream>
#include<cmath>
using namespace std;
class Point{
    public:
        float x,y;
        Point(float a, float b): x{a},y{b}{
        }
        Point(): x{0},y{0}{
        }
        float dist(Point p2){
            float dis;
            dis = sqrt((x-p2.x)*(x-p2.x) + (y-p2.y)*(y-p2.y));
            return dis;
        }
        void display(){
            cout<<"("<<x<<","<<y<<")"<<endl;
        }
};
class Circle{
    public:
        float r;
        Point c;
        Circle(float r, Point c): r{r},c{c}{
            cout<<"The radius of the circle: "<<r<<endl;
            cout<<"The Centre of the circle is :";
            c.display();
        }
        float circum(){
            float p = 3.14159*r*2;
            cout<<"The circumference of a circle: "<<p<<endl;
            return p;
        }
        float area(){
            float p = 3.14159*r*r;
            cout<<"The area of a circle: "<<p<<endl;
            return p;
        }
        bool inside(Point e){
            if(c.dist(e)<r){
                cout<<"The point is inside the circle."<<endl;
                return true;
            }
            else if(c.dist(e)==r){
                cout<<"The point is on the circle."<<endl;
                return true;
            }
            else{
                cout<<"The point is outside the circle."<<endl;
                return false;
            }
        }

};
