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
// - Dodaj wartość x do a-tej komórki
// - Odczytaj sumę z przedziału <a,b>

// Przedział Bazowy - to zbiór liści, który zawiera się w całości w podrzewie danego wierzchołka
// Jest on długości 2^k ,gdzie k to odległość od liścia w poddrzewie


inline void fast(){// Wyłaczenie Synchronizacji Strumieni Wyjścia/Wejścia
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
}
const int M = (1<<20);// Postawa drzewa (2^20)
int n;
int a,b,x,co_robimy;
int tab[2*M+5];

// Dodajemy wartość do Przedziałów bazowych
inline void Dodaj(int wartosc, int gdzie){

    gdzie+=M;// Ustawiamy Index na odpowiedni liść w drzewie

    tab[gdzie]+=wartosc; // Dodajemy do liścia wartość

    while(gdzie>0){//Dopóki wierzchołek nie wyjdzie poza korzeń(wierzchołek 1 lub 0)

        // Idziemy Ścieżką z liścia do Korzenia poruszająć się po Ojcach wierzchołków
        gdzie/=2;

        tab[gdzie] = tab[2*gdzie] + tab[2*gdzie+1]; // Suma dla danego wiezchołka to suma 2 synów
        // Aktualizujemy w ten sposób sume na Każdym Przedziałach Bazowych
    }

}

// Obliczamy Sume na przedziale <a, b>

inline int Suma_Iteracyjna(int a, int b){

    a+=M; b+=M; // Od teraz a oznacza wskaźnik lewy i b oznacza wskaźnik prawy

    // Oba wskaźniki są na tym samym poziomie!!

    int wynik = 0; // Suma na początku jest równa zero

    wynik=tab[a];// Pobieram wynik z wskaźników
    if(a!=b)wynik+=tab[b];// Jeżeli a i b są rózne to dodaje wartość do wskaźnika b

    // Poruszamy się po drzewie dopóki a i b nie mają wspólnego ojca

    while(a/2 != b/2){

        // Jeśli a jest lewym synem ojca, to istnieje prawy sąsiad, który jest przedziałem bazowym
        // I w całości zawiera się w szukanym Przedziale
        if(a%2==0){
            wynik += tab[a+1];
        }

        // Jeśli b jest prawym synem ojca, to istnieje lewy sąsiad, który jest przedziałem bazowym
        // I w całości zawiera się w szukanym Przedziale
        if(b%2==1){
            wynik += tab[b-1];
        }

        a/=2; b/=2; // Idziemy po do ojców wskaźników, czyli o poziom wyżej
    }

    return wynik; // Zwracamy wynik
}
// <a, b> Przedział z Zapytania
// X to numer wierzchołka w którym jesteśmy aktualnie
// l i p to są liście z krańców przedziału bazowego
inline int Suma_Rekurencyjnie(int a, int b, int x, int l, int p){

    // Jeżeli Przedział Bazowy danego wierzchołka nie pokrywa się z przedziałem z zapytania to zwróć 0
    if( b < l || a > p)
        return 0;

    // Jeżeli Przedział Bazowy danego wierzchołka pokrywa się całkowicie
    if( a<=l && p<=b )
        return tab[x];

    // Jeżeli Przedział Bazowy danego wierzchołka pokrywa się częściowo
    return Suma_Rekurencyjnie(a, b, 2*x, l, (l+p)/2) + Suma_Rekurencyjnie(a, b, 2*x+1, (l+p)/2+1, p);
    //suma z lewgo syna + suma z prawego syna
}

int main(){
    fast();

    // Wczytujemy ilość zapytań
    cin>>n;

    for(int i=0;i<n;i++){

        //Wczytujemy Zapytania

        cin>>co_robimy;

        if(co_robimy==1){//Dodaj wartość x do a_tej komurki
            cin>>a>>x;
            Dodaj(x,a);
        }
        else if(co_robimy==2){// Pytamy o przedział <a,b>
            cin>>a>>b;
            //cout<<Suma_Iteracyjna(a,b)<<'\n';
            cout<<Suma_Rekurencyjnie(a,b,1,0,M-1)<<'\n';
        }
    }
    return 0;
}
