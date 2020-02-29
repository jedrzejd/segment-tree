#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <stack>
#define pb push_back
#define f first
#define s second
#define fr front
#define bk back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (int)(x).begin(), (int)(x).end()
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long LLU;
typedef pair<int,int> PI;
typedef pair<LL,LL> PL;
typedef vector<int> VI;

inline void fast(){// Wyłaczenie Synchronizacji Strumieni Wyjścia/Wejścia
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
}
const int M = (1<<20);// Postawa drzewa (2^20)
int n;
int a,b,x,co_robimy;
int tab[2*M+5];
int main(){
    fast();
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>co_robimy;
        if(co_robimy==1){//Dodaj wartość x do a_tej komurki
            cin>>a>>x;
            tab[a]+=x;
        }
        else if(co_robimy==2){// Pytamy o przedział <a,b>
            cin>>a>>b;
            int sum=0;
            for(int j=a;j<=b;j++){
                sum+=tab[j];
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
