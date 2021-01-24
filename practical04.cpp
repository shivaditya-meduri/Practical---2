#include <iostream>
#include<cmath>
using namespace std;
void print_polynomial(double p[], int d){
  for(int i=0; i<=d; i++){
    cout<<'('<<p[i]<<')';
    cout<<'*';
    cout<<"x^"<<i;
    if(i!=d){
      cout<<"+";
    }
  }
  cout<<endl;
}
double poly(double p[], int d, double x){
  double v=0;
  for(int i=0; i<=d; i++){
    v=v+pow(x,i)*p[i];
  }
  return v;
}
int max(int d1, int d2){
  if(d1>d2){
    return d1;
  }
  else{
    return d2;
  }
}
int min(int d1, int d2){
  if(d1<d2){
    return d1;
  }
  else{
    return d2;
  }
}
double* sum(double p1[], int d1, double p2[], int d2, int *rd){
  int f = max(d1, d2);
  *rd = f;
  int g = min(d1, d2);
  double *h = new double(f);
  for(int i=0; i<=f; i++){
    if(i<=g){
      h[i] = p1[i] + p2[i];
    }
    else{
      if(d1==f){
        h[i] = p1[i];
      }
      else{
        h[i] = p2[i];
      }
    }
  }
  return h;
}

double* prod(double p1[], int d1, double p2[], int d2, int *r){
  *r = d1+d2;
  int d = *r;
  double* h = new double[d+1];
  for(int i=0; i<=d; i++){
    h[i] = 0;
    for(int j=0; j<=i; j++){
      if((j<=d1) && ((i-j)<=d2)){
        h[i] = h[i] + p1[j] * p2[i-j];
      }
   }
  }
  return h;
}
int main() {
  int d5;
  cout<<"Enter the degree of the polynomial: "<<endl;
  cin>>d5;
  double *p5 = new double(d5+1);
  for(int i=0; i<=d5; i++){
    cout<<"Enter the coefficient of degree "<<i<<": "<<endl;
    cin>>p5[i];
    }
  print_polynomial(p5, d5);
  cout<<"Enter x: "<<endl;
  double x;
  cin>>x;
  double v=poly(p5, d5, x);
  cout<<endl<<"The value of the polynomial at x is : "<<v<<endl;
  int d1,d2;
  cout<<"Enter the degree of the polynomial: "<<endl;
  cin>>d1;
  double *p1 = new double(d1+1);
  for(int i=0; i<=d1; i++){
    cout<<"Enter the coefficient of degree "<<i<<": "<<endl;
    cin>>p1[i];
    }
  cout<<"Enter the degree of the polynomial: "<<endl;
  cin>>d2;
  double *p2 = new double(d2+1);
  for(int i=0; i<=d2; i++){
    cout<<"Enter the coefficient of degree "<<i<<": "<<endl;
    cin>>p2[i];
    }
  int yd;
  double *rt = sum(p1, d1, p2, d2, &yd);
  cout<<endl<<"The result of the sum of p1 and p2: "<<endl;
  print_polynomial(rt, yd);
  int rd;
  double *re = prod(p1, d1, p2, d2, &rd);
  cout<<endl<<"The result of the product of p1 and p2: "<<endl;
  print_polynomial(re, rd);
  return 0;
}