#include<iostream>
using namespace std;
class Shape{
    protected:
        string color;
        bool filled;
    public:
        Shape(){
            color = "Green";
            filled = true;
        }
        Shape(string col, bool f){
            this -> color = col;
            this -> filled = f;
        }
        string getColor(){
            return color;
        }
        bool getFilled(){
            return filled;
        }
        virtual void print(){
            cout<<"The color of the shape is: "<<color<<endl;
        }
        virtual double getArea() = 0;
        virtual double getPerimeter() = 0;
};
class Circle : public Shape{
    private:
        double radius;
    public:
        Circle(){
            radius = 1.0;
        }
        Circle(double r){
            radius = r;
        }
        Circle(double r, string col, bool f){
            radius = r;
            color = col;
            filled = f;
        }
        double getRadius(){
            return radius;
        }
        void setRadius(double r){
            this->radius = r;
        }
        double getArea(){
            return 3.14*radius*radius;
        }
        double getPerimeter(){
            return 2*3.14*radius;
        }
        void print(){
            Shape::print();
            cout<<"Radius: "<<radius<<endl;
            cout<<"Area :"<<getArea()<<endl;
            cout<<"Perimeter :"<<getPerimeter()<<endl;
        }
};
class Rectangle : public Shape{
    protected:
        double width;
        double length;
    public:
        Rectangle(){
            length = 1.0;
            width = 1.0;
        }
        Rectangle(double width, double length){
            this -> width = width;
            this -> length = length;
        }
        Rectangle(double width, double length, string col, bool f){
            this-> width = width;
            this -> length = length;
            color = col;
            filled = f;
        }
        double getLength(){
            return length;
        }
        double getWidth(){
            return width;
        }
        void setLength(double l){
            length = l;
        }
        void setWidth(double w){
            width = w;
        }
        double getArea(){
            return length*width;
        }
        double getPerimeter(){
            return 2*(length + width);
        }
        virtual void print(){
            cout<<length<<" "<<width<<endl;
            cout<<"Area :"<<getArea()<<"Perimeter :"<<getPerimeter()<<endl;
            Shape::print();   
        }
};
class Square : public Rectangle{
    public:
        Square(){
            Rectangle();
        }
        Square(double side){
            length = side;
            width = side;
        }
        Square(double side, string col, bool f){
            length = side;
            width = side;
            color = col;
            filled = f;
        }
        double getSide(){
            return length;
        }
        void setSide(double s){
            length = s;
            width = s;
        }
        void print(){
            Rectangle::print();
        }
};
int main(){
    Shape *arr[4];
    Circle s;
    Circle c;
    Rectangle r;
    Square q;
    arr[0] = &s;
    arr[1] = &c;
    arr[2] = &r;
    arr[4] = &q;
    for(int i=0; i<4 ;i++){
        arr[i]->print();
    }
    return 0;
}