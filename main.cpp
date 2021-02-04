#include <vector>
#include <iostream>
#include <fstream>
#include <string> 

#include "main.h"

using namespace std;

/*
  C++ alapok
*/

int main(int argc, char *argv[]){
  cout << "HelloWorld!" << endl;

  // "using namespace std" nélkül
  std::cout << "HelloWorld!" << endl; 

  // header file-ban deklaráltuk, hogy a hw függvény milyen tulajdonságokkal bír
  // de még nem került definiálásra a működése, előzetes deklaráláés nélkül fordítási hibát okoz
  hw();

  // változó, referencia, mutató
  int a = 10;
  int b = a; // b értéke egyenlő a értékével
  int &c = a;  // c változó ugyan arra a területre "dolgozik" mint a
  int *d = &a; // d változó hivatkozik a-ra

  a += 5; 
  c += 5; 
  d += 5;  

  // a: 20 b: 10, c: 20, d: ???
  cout << "a: " << a << " b: " << b << ", c: " << c << ", d: " << *d <<endl;

} 


// itt definiáljuk a hw függvény működését
void hw() {
  std::cout << "HelloWorld!" << endl;
}