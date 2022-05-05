#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <bits/stdc++.h>
#include "exceptii.h"
#include "cont.h"
#include "cont_curent.h"


contcurent::contcurent(int suma_, const std::string &moneda_, const std::string &iban_, const std::shared_ptr<Titular> &titular_,float abonament_telefon_, float utilitati_) : Cont( suma_,  moneda_,  iban_, titular_) ,abonament_telefon(abonament_telefon_), utilitati(utilitati_){



    std::cout<<"constr init cont_curent"<< std::endl;
}


contcurent::~contcurent()  {
    std::cout<<"Destructor derivata"<<std::endl;
}


void contcurent::afisare(std::ostream &os) const {

    Cont::afisare(os);
    os << "abonament telefon:"<<abonament_telefon<<", cost utilitati:"<<utilitati << "\n";

}

void contcurent::plata_abonament() {

    int zi = local_time->tm_mday;
    if(zi == 1){
        suma = suma - abonament_telefon ;
    }
    istoric_tranzactii.push_back(std::tuple(date, "Incarcare cartela", abonament_telefon));

}

void contcurent::plata_utilitati() {
    int zi = local_time->tm_mday;
    if(zi == 15){
        suma = suma - utilitati ;
    }
    istoric_tranzactii.push_back(std::tuple(date, "Plata utilitati", utilitati));

}

void contcurent::extragere(int sumaextr, const std::string monedaextr) {
    sumaextr= sumaextr* curs[{moneda, monedaextr}];
    if(comision* suma< sumaextr) throw eroare_fonduri_insuficiente();
    else suma= suma- comision* sumaextr;
    istoric_tranzactii.push_back(std::make_tuple(date, "Extragere numerar", sumaextr));

}

void contcurent::depunere(int sumadep, const std::string monedadep) {
    suma = suma + sumadep * curs[{moneda, monedadep}];
    istoric_tranzactii.push_back(std::make_tuple(date, "Depunere numerar", sumadep));}


//std::shared_ptr<Cont> contcurent::clone() const{
//
//    return std::make_shared<contcurent>(*this);
//
//} //eroare
