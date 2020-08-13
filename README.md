## Wykład z drzew przedziałowych z testami

* [O projekcie](#O-projekcie)
* [Technologie](#technologie)
* [Instrukcja](#instrukcja)

## O projekcie
Wykład przygotowałem na 19 ILOCamp.
Materiały zawierają pliki zródłowe w C++ z gotowymi implementacjami oraz z testami.

Mój wykład zawiera następujące problemy:
- drzewo punkt przedział (dodawanie wartosci w punkcie i zapytanie  o sumę na przedziale) Drzewo_Punkt_Przedział.cpp

- drzewo przedzial punkt (dodawanie wartosci na przedziale i zapytanie  o sumę w punkcie) Drzewo_Przedział_Punkt.cpp

- drzewo przedzial przedzial (dodawanie wartosci na przedziale i zapytanie o sumę na przedziale) Drzewo_Przedział_Przedział.cpp

- drzewo przedzial przedzial (ustawianie wartosci na przedziale i zapytanie  o sumę na przedziale) Drzewo_PrzPrz_set_sum.cpp

- drzewo przedzial przedzial (dodawanie wartosci na przedziale i zapytanie o maksimum na przedziale) Drzewo_Prz_Prz_add_max.cpp

- drzewo przedzial przedzial (ustawianie wartosci na przedziale i zapytanie o maksimum na przedziale) Drzewo_PrzPrz_max.cpp

## Struktura
Każdy folder zawiera programy do testowania konkretnego Przypadku drzewa przedziałowego:
- brut.cpp -> program dające porawne wyniki, ale działa w gorszej złożoności obliczeniowej O(n^2)
- wzor.cpp -> program, który przypuszczamy że jest poprawny,
  złożoność obliczeniowa O(n log n) lub O(n log^2 n)
- Testerka.cpp -> Program uruchamiający programy z folderu i sprawdzający poprawnosc wzor.cpp
- generatorka.py -> Program w Pythonie generujący testy pod konkretny rodzaj drzewa
- test1.in -> plik pomocniczy do przechowywania testu


## Technologie
Wykład powstał w oparciu:
* C++: 11
* Python: 3


## Instrukcja
Uruchomienie Testerki dla jednego z drzew przedziałowych:

```
$ cd testowanie_PrzPrz_max
$ g++ -o Testerka Testerka.cpp
$ ./Testerka
```
Jeżeli podczas testów zostanie wykryty błąd to można:
* wyświetlić test na którym jest błąd
```
$ nano test1.in
```
* Wyświetlić poprawną odpowiedź na test przez program brut.cpp
```
$ nano bout
```
* Wyświetlić odpowiedź na test daną przez wzor.cpp
```
$ nano wout
```
