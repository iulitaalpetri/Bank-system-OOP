#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <ctime>
#include "exceptii.h"
#include "cont.h"
#include "cont_standard.h"

cont_standard::cont_standard(int taxa_ ,   float comision_):
        taxa(taxa_), comision(comision_)
{
    if (suma < suma_min) throw eroare_suma_cont();
    std::cout<<"constr init cont_stand"<<std::endl;
}
cont_standard::~cont_standard() {} ;

void cont_standard::afisare(std::ostream &os) const {
    Cont::afisare(os);
    os << "taxa:"<<taxa<<", comision: "<<comision << "\n";

}

void cont_standard::data_plata() {
    time_t now = time(0);
    tm *local_time = localtime(&now);
    char* date = ctime(&now);
    int zi = local_time->tm_mday;
    int luna= local_time->tm_mon;
    if(zi> 2)
        plati.insert(std::pair<int, bool>(luna, false));

    else plati.insert(std::pair<int, bool>(luna, true));
}
void cont_standard::efectuare_plata(int luna) {
    cont_standard::data_plata();
    if(plati[luna]==false) suma= suma- taxa*taxa_intarziere_plata;
    else suma= suma- taxa;
    plati.erase(luna);
}

void cont_standard::depunere(int sumadep, const std::string monedadep) {
    std::map<std::pair<std::string, std::string>, double> curs;
    curs[{"lei", "euro"}] = 5;
    curs[{"euro", "lei"}]= 0.2;
    curs[{"lei", "lei"}]= 1;
    curs[{"euro", "euro"}] = 1;
    suma = suma + sumadep * curs[{moneda, monedadep}];

}

void cont_standard::extragere(int sumaextr, const std::string monedaextr) {
    std::map<std::pair<std::string, std::string>, double> curs;
    curs[{"lei", "euro"}] = 5;
    curs[{"euro", "lei"}]= 0.2;
    curs[{"lei", "lei"}]= 1;
    curs[{"euro", "euro"}] = 1;
    sumaextr= sumaextr* curs[{moneda, monedaextr}];
    if(suma< sumaextr) throw eroare_fonduri_insuficiente();
    else suma= suma- comision* sumaextr;

}

void cont_standard::tranzactie(Cont &other_cont, int sumatranz) {
    std::map<std::pair<std::string, std::string>, double> curs;
    curs[{"lei", "euro"}] = 5;
    curs[{"euro", "lei"}]= 0.2;
    curs[{"lei", "lei"}]= 1;
    curs[{"euro", "euro"}] = 1;
    other_cont.getsuma()= other_cont.getsuma()+ sumatranz * curs[{moneda, other_cont.getmoneda()}] ;
    if(sumatranz< 100) throw eroare_tranzactie();
    else if(suma< sumatranz) throw eroare_fonduri_insuficiente();
    else {
        suma = suma - comision* sumatranz;
        std::cout << "Tranzactie realizata cu succes. Ati trimis" << sumatranz << "lei catre contul cu iban: " <<
                  other_cont.getIban()       <<"."  << std::endl;}}




//la tranzactii se cere comision

