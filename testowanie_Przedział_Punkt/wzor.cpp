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
// - Dodaj wartość x na przedziale <a, b>
// - Odczytaj sumę z komórki a

// Przedział Bazowy - to zbiór liści, który zawiera się w całości w podrzewie danego wierzchołka
// Jest on długości 2^k ,gdzie k to odległość od liścia w poddrzewie


inline void fast(){// Wyłaczenie Synchronizacji Strumieni Wyjścia/Wejścia
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
}
const int M = (1<<20);// Postawa drzewa (2^20)
int n;
int a,b,c,co_robimy;
int tab[2*M+5];

// Obliczamy wartość komórki
inline int Suma(int gdzie){

    gdzie+=M;// Ustawiamy Index na odpowiedni liść w drzewie

    int wynik=0;//Ustawiamy sume na 0

    while(gdzie>0){//Dopuki wierzchołek nie wyjdzie poza korzeń(wierzchołek 1 lub 0)
        wynik +=tab[gdzie];// Dodajemy napotkaną wartość do sumy

        // Idziemy Ścieżką z liścia do Korzenia poruszająć się po Ojcach wierzchołków
        gdzie/=2;
    }

    return wynik;// Zwracamy wynik
}

// Dodajemy wartośc (co) na przedziale <a, b>
inline void Dodaj_Iteracyjnie(int a, int b,int co){

    a+=M; b+=M;// Od teraz a oznacza wskaźnik lewy i b oznacza wskaźnik prawy
    // Oba wskaźniki są na tym samym poziomie!!

    tab[a]+=co;// Dodajemy wartość do wskaznikow krańcowych

    if(a!=b)tab[b]+=co;// Jeżeli a i b są rózne to dodaje wartość do wskaźnika b

    // Poruszamy się po drzewie dopóki a i b nie mają wspólnego ojca
    while(a/2 != b/2){

        // Jeśli a jest lewym synem ojca, to istnieje prawy sąsiad, który jest przedziałem bazowym
        // I w całości zawiera się w szukanym Przedziale
        if(a%2==0){
            tab[a+1]+=co;
        }

        // Jeśli b jest prawym synem ojca, to istnieje lewy sąsiad, który jest przedziałem bazowym
        // I w całości zawiera się w szukanym Przedziale
        if(b%2==1){
            tab[b-1]+=co;
        }

        a/=2; b/=2;// Idziemy po do ojców wskaźników, czyli o poziom wyżej
    }
}

// <a, b> Przedział do którego dodajemy wartość
// X to numer wierzchołka w którym jesteśmy aktualnie
// l i p to są liście z krańców przedziału bazowego
// (co) wartość którą dodajemy
inline void Dodaj_Rekurencyjnie(int a, int b, int x, int l, int p,int co){
    // Jeżeli Przedział Bazowy danego wierzchołka nie pokrywa się z przedziałem z zapytania
    if( b < l || a > p)
        return ;

    // Jeżeli Przedział Bazowy danego wierzchołka pokrywa się całkowicie
    if( a<=l && p<=b ){
       tab[x]+=co;
       return ;
    }
    // Jeżeli Przedział Bazowy danego wierzchołka pokrywa się częściowo
    Dodaj_Rekurencyjnie(a, b, 2*x, l, (l+p)/2, co);
    Dodaj_Rekurencyjnie(a, b, 2*x+1, (l+p)/2+1, p, co);
}

int main(){
    fast();

    // Wczytujemy ilość zapytań
    cin>>n;

    for(int i=0;i<n;i++){

        //Wczytujemy Zapytania
        cin>>co_robimy;

        if(co_robimy==1){// Pytamy o wartość a_tej komórki
            cin>>a;
            cout<<Suma(a)<<endl;
        }

        else if(co_robimy==2){//Dodaj wartość c na przedziale <a,b>

            cin>>a>>b>>c;

            Dodaj_Iteracyjnie(a,b,c);
            //Dodaj_Rekurencyjnie(a,b,1,0,M-1,c);

        }
    }
    return 0;
}
