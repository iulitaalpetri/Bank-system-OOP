#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "cont.h"
#include "exceptii.h"
#include "titular.h"

//Cont::Cont(Titular titular_, int suma_, std::string  moneda_, std::string  iban_) :
//titular(titular_), suma(suma_),
//moneda(std::move(moneda_)),
//iban(std::move(iban_)) {
//    std::cout << "Constr init cont" << std::endl;
//    if (titular_.isId() == 1) {
//        titular_.verificare();
//
//    }//throw o exceptie aici
//}
// dai throw exceptie in clasa derivata
Cont::Cont() {
    std::cout<<"constr init"<< std::endl;
}
int Cont::getSuma() const {
    return suma;
}
const std::string &Cont::getMoneda() const {
    return moneda;
}
void Cont::afisare(std::ostream &os) const {
    auto& Cont= *this;
    os<<"suma:"<<Cont.suma<<" , moneda:"<<Cont.moneda<<" ,iban"<<Cont.iban<< " ,id titular"<<Cont.titular.isId();
}


const std::string &Cont::getIban() const {
    return iban;
}

std::ostream &operator<<(std::ostream &os, const Cont &cont) {
    cont.afisare(os);
    return os;
}
Cont::~Cont() {
    std::cout<<"destructor Cont= baza"<< std::endl;
}





