

#include "cont.h"

#include <utility>
#include <iostream>

Cont::Cont(int suma_, std::string moneda_,  std::string iban_, std::shared_ptr<Titular> titular_, int c) : suma(suma_),moneda(std::move(moneda_)), iban(std::move(iban_)), titular(std::move(titular_)) {
    curs[{"lei", "euro"}] = c;
    curs[{"euro", "lei"}]= 1/c;
    curs[{"lei", "lei"}]= 1;
    curs[{"euro", "euro"}] = 1;
    std::cout<<"constr cont- baza"<<std::endl;
}

Cont::~Cont() {
    std::cout<<"destr - Cont_ baza"<< std::endl;
}


void Cont::afisare(std::ostream &os) const {
    const auto& Cont= *this;
    os<<"Suma:"<<Cont.suma<<" , moneda:"<<Cont.moneda<<" ,iban: "<<Cont.iban;
}

std::ostream &operator<<(std::ostream &os, const Cont &cont) {
    cont.afisare(os);
    return os;
}

int Cont::getSuma() {
    return suma;
}

const std::string &Cont::getMoneda() const {
    return  moneda;
}

const std::string &Cont::getIban() const {
    return iban;
}

void Cont::setSuma(int x) {
    Cont::suma = x;
}
