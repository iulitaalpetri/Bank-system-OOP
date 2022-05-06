#include <iostream>
#include <string>
#include "titular.h"
#include "Pers_fizica.h"




bool pers_fizica::verificare_varsta() const {
    if(varsta< 18) return false;
    return true;
}


void pers_fizica::afisare(std::ostream &os) const {
    Titular::afisare(os);
    os<<"Persoana fizica- nume:"<<nume<<", prenume:"<<prenume<<", varsta:"<<varsta<<", cnp"<<cnp<<std::endl;

}
pers_fizica::pers_fizica() = default;

pers_fizica::~pers_fizica() {
    std::cout<<"destructor pers_fizica- derivata"<<std::endl;
}


[[maybe_unused]] const std::string &pers_fizica::getNume() const {
    return nume;
}


[[maybe_unused]] const std::string &pers_fizica::getPrenume() const {
    return prenume;
}

[[maybe_unused]] int pers_fizica::getVarsta() const {
    return varsta;
}


std::shared_ptr<Titular> pers_fizica::clone()const {
    std::cout<<"Clonare_titular\n";
    return std::make_shared<pers_fizica>(*this);
}

