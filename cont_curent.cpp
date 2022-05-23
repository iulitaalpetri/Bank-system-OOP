#include <iostream>
#include <string>
#include <map>

#include "cont.h"
#include "cont_curent.h"
#include "exceptii.h"


contcurent::contcurent(float suma_, const std::string &moneda_, const std::string &iban_,std::shared_ptr<Titular> titular_, int c,float abonament_telefon_, float utilitati_) : Cont( suma_,  moneda_,  iban_, titular_, c) ,abonament_telefon(abonament_telefon_), utilitati(utilitati_){

    if(suma_< suma_min) throw(eroare_suma_cont{"Suma insuficienta\n"});
    else

    std::cout<<"constr init cont_curent"<< std::endl;
}

void contcurent::tranzactie(Cont &other_cont, int sumatranz) {
    other_cont.setSuma(other_cont.getSuma()+ sumatranz * curs[{moneda, other_cont.getMoneda()}]) ;

}


contcurent::~contcurent()  {
    std::cout<<"Destructor derivata"<<std::endl;
}


void contcurent::afisare(std::ostream &os) const {

    Cont::afisare(os);
    os << ", abonament telefon:"<<abonament_telefon<<", cost utilitati:"<<utilitati <<"- Cont curent"<< "\n";

}

void contcurent::plata_abonament() {

    int zi = local_time->tm_mday;
    if(zi == 1){
        std::cout<<"plata abonament\n";
        suma = suma - abonament_telefon ;
        istoric_tranzactii.push_back(std::tuple(date, "Incarcare cartela", abonament_telefon));
    } }

[[maybe_unused]] void contcurent::plata_utilitati() {
    int zi = local_time->tm_mday;
    if(zi == 15){
        std::cout<<"plata utilitati\n";
        suma = suma - utilitati ;
        istoric_tranzactii.push_back(std::tuple(date, "Plata utilitati", utilitati));
    }


}

void contcurent::extragere(int sumaextr, const std::string &monedaextr) {

    sumaextr= sumaextr* curs[{moneda, monedaextr}];
    if(comision* suma< sumaextr) throw(eroare_fonduri_insuficiente{"Fonduri insuficiente.\n"});
    else {suma= suma- comision* sumaextr;
    istoric_tranzactii.push_back(std::make_tuple(date, "Extragere numerar", sumaextr));
    std::cout<<"extragere numerar\n";}

}

void contcurent::afisare_istoric() {
    std::cout<<"Istoric tranzactii:\n";
    for(unsigned long long i=0; i< istoric_tranzactii.size(); i++){

        std::cout<<get<0>(istoric_tranzactii[i]) << " "
                 << get<1>(istoric_tranzactii[i]) << " "
                 << get<2>(istoric_tranzactii[i]) << "\n";
    }}
void contcurent::depunere(int sumadep, const std::string &monedadep) {
    std::cout<<"depunere numerar\n";
    suma = suma + sumadep * curs[{moneda, monedadep}];
    istoric_tranzactii.push_back(std::make_tuple(date, "Depunere numerar", sumadep));}



