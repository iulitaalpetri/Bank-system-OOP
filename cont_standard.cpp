#include <iostream>
#include <string>
#include <ctime>
#include "exceptii.h"
#include "cont.h"
#include "cont_standard.h"


cont_standard::cont_standard(int suma_, const std::string &moneda_, const std::string &iban_,const  std::shared_ptr<Titular> &titular_,
                              int taxa_, float comision_) :Cont( suma_,   moneda_,   iban_,  titular_),
taxa(taxa_), comision(comision_){
    if (suma < suma_min) throw (eroare_suma_cont{"Suma insuficienta\n"});
    else
    std::cout<<"constr init cont_stand"<<std::endl;

}
cont_standard::~cont_standard() = default ;

void cont_standard::afisare(std::ostream &os) const {
    Cont::afisare(os);
    os << "taxa:"<<taxa<<", comision: "<<comision << "\n";

}



void cont_standard::efectuare_plata() {

    time_t now = time(nullptr);
    tm *local_time = localtime(&now);

    int zi = local_time->tm_mday;
    if(zi>2)
     suma= suma- int(taxa)* int(taxa_intarziere_plata);
    else suma= suma- int(taxa);

}

void cont_standard::depunere(int sumadep, const std::string &monedadep) {

    suma = suma + sumadep * curs[{moneda, monedadep}];

}

void cont_standard::extragere(int sumaextr, const std::string &monedaextr) {

    sumaextr= sumaextr* curs[{moneda, monedaextr}];
    if(suma< sumaextr) throw (eroare_fonduri_insuficiente{"Fonduri insuficiente\n"});
    else suma= suma- comision* sumaextr;

}

void cont_standard::tranzactie(Cont &other_cont, int sumatranz) {

    other_cont.setSuma(other_cont.getSuma()+ sumatranz * curs[{moneda, other_cont.getMoneda()}]) ;
    if(sumatranz< 100) throw(eroare_tranzactie{"Tranzactia nu poate fi realizata, suma prea mica\n"});
    else if(suma< sumatranz) throw( eroare_fonduri_insuficiente{"Fonduri innsuficiente\n"});
    else {
        suma = suma - comision* sumatranz;
        std::cout << "Tranzactie realizata cu succes. Ati trimis" << sumatranz << "lei catre contul cu iban: " <<
                  other_cont.getIban()       <<"."  << std::endl;}}


std::shared_ptr<Cont> cont_standard::clone() const {
    std::cout<<"Clonare_cont\n";
    return std::make_shared<cont_standard>(*this);
}
