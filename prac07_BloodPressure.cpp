#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Date{
    int dd;
    int mm;
    int yyyy;
    public:
        Date(int d, int m, int y): dd{d}, mm{m}, yyyy{y}{}
        void printDate(){
            cout<<dd<<"/"<<mm<<"/"<<yyyy<<endl;
        }
};
class Blood{
    float sys;
    float dia;
    friend class Patient;
    Date dt;
    public:
        Blood(float s, float d, Date da): sys{s}, dia{d}, dt{da}{}
        void printBlood(){
            cout<<"sys: "<<sys<<" "<<"dia: "<<dia<<" "<<"measured on ";
            dt.printDate();
        }
};
class Patient{
    const string name;
    vector<Blood> bb;
    public:
        Patient(string k):name(k){}
        void addRecord(Blood h){
            bb.push_back(h);
        }
        void printReport(){
            cout<<"Patient: "<<name<<endl;
            cout<<"Medical Records: "<<endl;
            cout<<"Highest Abnormal BP: "<<endl;
            float max = bb[0].sys;
            int ind_high = 0;
            for(int i=1; i<bb.size();i++){
                if(bb[i].sys>max){
                    max = bb[i].sys;
                    ind_high = i;
                }
                else{
                    continue;
                }
            }
            if(max>140){
            cout<<"\t";
            bb[ind_high].printBlood();
            }
            else{
                cout<<"\t"<<"No Blood Pressure was too high";
            }
            Blood average_bp(0,0,Date(0,0,0));
            for(int i=0; i<bb.size();i++){
                average_bp.sys+=bb[i].sys;
                average_bp.dia+=bb[i].dia;
            }
            average_bp.sys = average_bp.sys/bb.size();
            average_bp.dia = average_bp.dia/bb.size();
            cout<<"Average Blood Pressure: "<<endl;
            cout<<"\t"<<"sys: "<<average_bp.sys<<" dia: "<<average_bp.dia<<endl;
            vector<Blood> max_bp;
            for(int i=0; i<bb.size();i++){
                if(bb[i].sys>140){
                    max_bp.push_back(bb[i]);
                }
                else{
                    continue;
                }
            }
            cout<<"Max blood pressures are: "<<endl;
            for(int i=0; i<max_bp.size(); i++){
                cout<<"\t";
                max_bp[i].printBlood();
            }
            cout<<endl<<endl;
        }
};
int main() {
Patient mary("Mary");
Patient john("John");
mary.addRecord(Blood(94,61, Date(2,5,2013)));
mary.addRecord(Blood(97,65, Date(3,5,2013)));
mary.addRecord(Blood(144,99, Date(4,5,2013)));
mary.addRecord(Blood(123,88, Date(5,5,2013)));
mary.addRecord(Blood(177,110, Date(6,5,2013)));
mary.addRecord(Blood(145,89, Date(7,5,2013)));
mary.printReport();
john.addRecord(Blood(124,66, Date(2,5,2013)));
john.addRecord(Blood(84,54, Date(3,5,2013)));
john.addRecord(Blood(144,99, Date(4,5,2013)));
john.addRecord(Blood(163,48, Date(5,5,2013)));
john.addRecord(Blood(117,10, Date(6,5,2013)));
john.addRecord(Blood(140,109, Date(7,5,2013)));
john.printReport();
return 0;
}