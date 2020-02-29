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
inline void fast(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
}
const int M = (1<<20);
int n;
int a,b,x,co_robimy;
int tab[2*M+5],val[2*M+5];
void przepchnij(int x, int roz){
    tab[2*x]+=tab[x];
    tab[2*x+1]+=tab[x];
    val[x]+=tab[x]*roz; 
    tab[x]=0;
}   
inline int Dodaj_Rekurencyjnie(int a, int b, int x, int l, int p,int co){
    //cout<<a<<" "<<b<<" "<<x<<" "<<l<<" "<<p<<" "<<co<<endl;
    if( b < l || a > p){
        return tab[x]*(p-l+1)+val[x];
    }
    if( a<=l && p<=b ){
       tab[x]+=co;
       return tab[x]*(p-l+1)+val[x];
    }
    if(x<M)przepchnij(x,p-l+1);
    return val[x]=Dodaj_Rekurencyjnie(a, b, 2*x, l, (l+p)/2, co) + 
                  Dodaj_Rekurencyjnie(a, b, 2*x+1, (l+p)/2+1, p, co);
}

inline int Suma_Rekurencyjnie(int a, int b, int x, int l, int p){
    //cout<<a<<" "<<b<<" "<<x<<" "<<l<<" "<<p<<endl;
    if( a>p || b<l){
        return 0;
    }
    if( a<=l && p<=b){
     //   cout<<tab[x]*(p-l+1)+val[x]<<endl;
        return tab[x]*(p-l+1)+val[x];
    }
    if(x<M)przepchnij(x,p-l+1);
    return Suma_Rekurencyjnie(a, b, 2*x, l, (l+p)/2) + Suma_Rekurencyjnie(a, b, 2*x+1, (l+p)/2+1, p);
}

int main(){
    fast();
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>co_robimy;
        if(co_robimy==1){// Suma na przedziale <a, b> 
            cin>>a>>b;
            //cout<<Suma_Rekurencyjnie(a,b,1,0,M-1)<<endl;
            cout<<Suma_Rekurencyjnie(a,b,1,0,M-1)<<endl;
        }
        else if(co_robimy==2){// Dodaj na przedziale <a, b>
            cin>>a>>b>>x;
            //cout<<Dodaj_Rekurencyjnie(a,b,1,0,M-1,x)<<endl;
            Dodaj_Rekurencyjnie(a,b,1,0,M-1,x);
        }
    }
    return 0;
}