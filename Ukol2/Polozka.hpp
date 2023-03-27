#pragma once
#include<string>
using namespace std;

class Polozka{
    private:
        int cena;
        string nazev;
    public:
        Polozka(int cena=0, string nazev="");
        ~Polozka();
        int GetCena();
        void SetCena(int cena);
        string GetNazev();
};