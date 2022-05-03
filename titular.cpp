#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "titular.h"
#include "exceptii.h"
#include "titular.h"
#include "Pers_fizica.h"





Titular::Titular() {
    std::cout<<"constr init titular-baza"<<std::endl;
}
Titular::Titular(int id_) : id(id_){}
//void Titular::verificare() {}

void Titular::afisare(std::ostream &os) const {
    auto& Titular = *this;
    os << "x: " << Titular.id;
}

std::ostream &operator<<(std::ostream &os, const Titular &t) {
    t.afisare(os);
    return os;
}

bool Titular::isId() const {
    return id;
}








