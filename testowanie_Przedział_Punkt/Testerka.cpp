// #include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int iletestow=1000;
int main(){
    char buf[40];
    system("g++ -o wzor wzor.cpp");
    system("g++ -o brut brut.cpp");
    for(int i=0;i<iletestow;i++){
        cout<<i+1<<endl;
        system("python generatorka.py");
        system(buf);
        system("./wzor < test1.in > wout");
        system("./brut < test1.in > bout");
        if(system("diff bout wout")){
            cout<<"znalazlem blad!!!!"<<endl;
            return 0;
        }
    }

}
