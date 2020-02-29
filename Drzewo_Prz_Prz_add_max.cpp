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

//  Program wykonuje 2 operacje:
// - Dodaj wartość x na przedziale <a, b>
// - Odczytaj max z przedziale <a, b>

// Przedział Bazowy - to zbiór liści, który zawiera się w całości w podrzewie danego wierzchołka
// Jest on długości 2^k ,gdzie k to odległość od liścia w poddrzewie


inline void fast(){// Wyłaczenie Synchronizacji Strumieni Wyjścia/Wejścia
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
}
const int M = (1<<20);// Postawa drzewa (2^20)
int n;
int a,b,x,co_robimy;
int tab[2*M+5];// Tablica służąca do trzymania wartości 
int val[2*M+5];// Tablica pomocnicza służąca do trzymania MAX na przedziale bazowym
bool extra[2*M+5];

// Funkcja przepychająca
inline void przepchnij(int x){
    extra[2*x]=extra[x];
    extra[2*x+1]=extra[x];
    extra[x]=0;
    tab[2*x]+=tab[x];
    tab[2*x+1]+=tab[x];
    val[x]+=tab[x];
    tab[x]=0;
}

//  Wartosci (co) dodawana na przedziale <a, b>
// <a, b> Przedział z Zapytania
// X to numer wierzchołka w którym jesteśmy aktualnie
// l i p to są liście z krańców przedziału bazowego

inline int Dodaj_Rekurencyjnie(int a, int b, int x, int l, int p,int co){

    if( b < l || a > p){
        // Jeśli wierzcholek jest poza przedziałem ale pobieram sumę
        // MAX na jego przedziale z wartościa dodawaną
        return tab[x]+val[x];
    }
    // Jeżeli Przedział Bazowy danego wierzchołka pokrywa się całkowicie
    if( a<=l && p<=b ){
       // Dodaje wartość i zwaracam MAX
       tab[x]+=co;
       extra[x]=1;// Jeżeli wrzuciłem coś tu to poźniej bedę to przepychać
       return tab[x]+val[x];
    }
    // Jeżeli Przedział Bazowy danego wierzchołka pokrywa się częciowo
    // Przepychamy wartości z danego wierzchołka do 2 synów

    if(x<M && extra[x]==1 )
        przepchnij(x);
        
    return val[x]=max(Dodaj_Rekurencyjnie(a, b, 2*x, l, (l+p)/2, co),
                  Dodaj_Rekurencyjnie(a, b, 2*x+1, (l+p)/2+1, p, co));

    // Pobieram wartości z poddrzew i otrzymuje rekurencyjnie sume na poddrzewie
}

// Podaje max na przedziale <a, b>
// <a, b> Przedział z Zapytania
// X to numer wierzchołka w którym jesteśmy aktualnie
// l i p to są liście z krańców przedziału bazowego

inline int MAX_Rekurencyjnie(int a, int b, int x, int l, int p){

    // Jeżeli Przedział Bazowy danego wierzchołka nie pokrywa się z przedziałem z zapytania to zwróć 0
    if( a>p || b<l){
        return 0;
    }
    // Jeżeli Przedział Bazowy danego wierzchołka pokrywa się całkowicie
    if( a<=l && p<=b){
        // Biorę max z wartości obecnej jeżeli występuje lub z max z podrzewa
        return tab[x]+val[x];
    }

    // Jeżeli Przedział Bazowy danego wierzchołka pokrywa się częciowo

    // Przepychamy wartości z danego wierzchołka do 2 synów
    if(x<M && extra[x]==1 )
        przepchnij(x);
    return max(MAX_Rekurencyjnie(a, b, 2*x, l, (l+p)/2),
               MAX_Rekurencyjnie(a, b, 2*x+1, (l+p)/2+1, p));
    //MAX z lewgo syna + MAX z prawego syna
}

int main(){
    fast();
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>co_robimy;
        if(co_robimy==1){// MAX na przedziale <a, b>
            cin>>a>>b;
            cout<<MAX_Rekurencyjnie(a,b,1,0,M-1)<<endl;
        }
        else if(co_robimy==2){// Ustaw na przedziale <a, b> wartosc x
            cin>>a>>b>>x;
            Dodaj_Rekurencyjnie(a,b,1,0,M-1,x);
        }
    }
    return 0;
}
