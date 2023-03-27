#include <iostream>
#include <string>
#include "Ukol1/Tree.hpp" 

#include "Ukol2/Faktura.hpp"
using namespace std;
 
int main(){
     KVString * tree = new KVString("aa", "bb");
     tree -> CreateTree(3);
 
     tree -> Print();

     Osoba osoba("Jmeno", "Adresa");
     Faktura faktura(999, &osoba);
     
     cout << faktura.CelkovaCena() << endl;

     faktura.PridatPolozku(1500, "Oprava mobilu");

     cout << faktura.CelkovaCena() << endl;

     faktura.PridatPolozku(2000, "Oprava Tabletu");

     cout << faktura.CelkovaCena() << endl;


     faktura.OdebratPlozku("Oprava mobilu");

     cout << faktura.CelkovaCena() << endl;

     faktura.UpravitCenuPolozky("Oprava Tabletu", 9999);

     cout << faktura.CelkovaCena() << endl;

}
 