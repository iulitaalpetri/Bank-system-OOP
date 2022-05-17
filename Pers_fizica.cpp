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





