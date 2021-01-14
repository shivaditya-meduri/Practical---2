#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
int fibc=0;
float d(float x, float y, float a, float b) {
	return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}
void circle(float x, float y, float r, float a, float b) {
	if (d(x, y, a, b) < r) {
		cout << "The point is inside the circle." << endl;
	}
	else {
		cout << "The point is outside the circle." << endl;
	}
}
float pos(float x0, float v, float a, float t){
  return x0+v*t+(0.5*a*t*t);
}
void swap(int *x, int *y){
  int z = *x;
  *x = *y;
  *y = z;
  return;
}
int fib(int n){
  fibc++;
  if (n==0 || n==1){
    return n;
  }
  else{
    return fib(n-1) + fib(n-2);
  }
  
}
int npc=0;
float np(float a,unsigned int n){
  npc++;
  if(n==0){
    return 1;
  }
  else{
    return a*np(a,n-1);
  }
}
int npc2=0;
float np2(float a, unsigned int n){
  npc2++;
  if(n==0){
    return 1;
  }
  else if(n%2==0){
    return pow(np2(a,n/2),2);
  }
  else{
    return a*pow(np2(a,n/2),2);
  }
}
int main() {
	int input;
	cout << "Enter the Excercise number: " << endl;
	cin >> input;
	if (input == 1) {
		float x, y, r, a, b;
		cout << "Enter x,y,r,a,b:" << endl;
		cin >> x >> y >> r >> a >> b;
		circle(x, y, r, a, b);
	}
  else if(input ==2){
    float a, v, x0, n, dt, nt=0;
    cout<<"enter the initial position, the speed and the acceleration:"<<endl;
    cin>>x0>>v>>a;
    cout<<"how many times you want to display the position of the moving body?"<<endl;
    cin>>n;
    cout<<"how often (in seconds) you want to update the position of the moving object?"<<endl;
    cin>>dt;
    for(int i=0;i<n;i++){
      cout<<"At time "<<nt<<" the position is "<<pos(x0, v, a, nt)<<endl;
      nt = nt + dt;
    }
  }
  else if(input==3){
    int x,y;
    cout<<"Enter numbers to be swapped : "<<endl;
    cin>>x>>y;
    swap(&x,&y);
    cout<<"The numbers after swapping are "<<x<<" "<<y<<endl;
  }
  else if(input ==4){
    int n,k=1;
    cout<<"Enter number of lines: : "<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
      for(int j=0; j<i; j++){
        cout<<k<<" ";
        k++;
      }
      cout<<endl;
    }
  }
  else if(input==5){
    int n;
    cout<<"Enter n: "<<endl;
    cin>>n;
    if (n<=1){
      cout<<"Fibbonaci of "<<n<<"is "<<n;
    }
    else{
      int np = 1;
      int nm = 0,k=0;
      for(int i=2; i<=n;i++){
        k=np + nm;
        nm=np;
        np=k;
      }
      cout<<"Fibbonaci of "<<n<<" is "<<k;
    }
  }
  else if(input == 6){
    int n;
    cout<<"Enter n :"<<endl;
    cin>>n;
    cout<<"Fib of "<<n<<" is "<< fib(n)<<endl;
    cout<<"Function calls number is "<<fibc<<endl;
  }
  else if(input==7){
    int a;
    unsigned int n;
    cout<<"Enter a:"<<endl;
    cin>>a;
    cout<<"Enter n: "<<endl;
    cin>>n;
    cout<<"1st Recursion method : "<<np(a,n)<<"   "<<npc<<endl;
    cout<<"2nd Recursion method : "<<np2(a,n)<<"   "<<npc2<<endl;
    //First Recursion number of func calls is n+1
    //2nd Recursionn number of func calls is floor(log(n)) +2

  }
  return 0;
}

