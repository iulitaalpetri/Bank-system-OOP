#include <iostream>
#include "titular.h"
#include "pers_juridica.h" 

Titular::Titular() = default;
Titular::Titular(bool id_): id(id_) {
    std::cout<<"constr init Titular- cls baza"<<std::endl;
}
Titular::~Titular() {
    std::cout<<"destructor Titular - cls de baza"<< std::endl;
}

void Titular::afisare(std::ostream &os) const {
    const auto& Titular = *this;
    os << "x: " << Titular.id<<std::endl;
}

std::ostream &operator<<(std::ostream &os, const Titular &t) {
    t.afisare(os);
    return os;
}

bool Titular::isId() const {
    return id;
}

