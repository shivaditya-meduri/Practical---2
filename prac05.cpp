#include<iostream>
#include<cmath>
#include<string>
#include "geometry.hpp"
using namespace std;
struct A{
    int a;
    int b;
};
class s{
    public:
        int a;
        int b;
};
void str_dig(string a){
    int l=a.length();
    for(int i=0; i<l;i++){
        if(a[i]>='0' && a[i]<='9'){
            continue;
        }
        else{
            cout<<"The string does not contain all digits."<<endl;
            return;
        }
    }
    cout<<"The string contains all digits."<<endl;
}
int pairc(string a,char* d){
    int count=0;
    for(int i=0;i<a.length();i++){
            if(a[i] == d[1]){
                if(a[i-1] == d[0]){
                    count++;
                }
            }
    }
    cout<<"The number of time the pair "<<d<<"is repeated in string "<<a<<" is "<<count<<endl;
    return count;
}
int main()
{
    string a;
    char t[3] = "ab";
    int i;
    /*cout<<"Enter the string:"<<endl;
    cin>>a;
    cout<<"Enter the pair:"<<endl;
    cin>>t;
    str_dig(a);
    int f = pairc(a,t);*/
    //Point p1(1,1), p2(2,2), p3;
    //cout<<p1.dist(p2)<<"\t"<<p2.dist(p1)<<"\t"<<p2.dist(p3)<<endl;
    Point c(0,0);
    float r=10;
    Circle y(r,c);
    y.circum();
    y.area();
    Point h(10,0);
    bool k = y.inside(h);
    return 0;
}