

#include "cont.h"

#include <utility>
#include <iostream>
int Cont::contor=1;

Cont::Cont(float suma_, std::string moneda_,   std::shared_ptr<Titular> titular_, int c) : suma(suma_),moneda(std::move(moneda_)), iban(contor++), titular(std::move(titular_)) {
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

const int &Cont::getIban() const {
    return iban;
}

void Cont::setSuma(float x) {
    Cont::suma = x;
}
