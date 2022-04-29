#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "titular.h"
#include "Pers_fizica.h"


pers_fizica::pers_fizica(std::string nume_, std::string prenume_, int varsta_, std::string cnp_):nume(nume_), prenume(prenume_), varsta(varsta_), cnp(cnp_) {
    if (varsta_< 18) throw eroare_varsta();
    std::cout<<"constr init pers fizica- derivata"<<std::endl;
}

void pers_fizica::afisare(std::ostream &os) const {
    Titular::afisare(os);
    os<<"nume:"<<nume<<", prenume:"<<prenume<<", varsta:"<<varsta<<", cnp"<<cnp<<std::endl;

}
pers_fizica::pers_fizica() {}

pers_fizica::~pers_fizica() {
    std::cout<<"destructor pers_fizica- derivata"<<std::endl;
};




const std::string &pers_fizica::getNume() const {
    return nume;
}


const std::string &pers_fizica::getPrenume() const {
    return prenume;
}

int pers_fizica::getVarsta() const {
    return varsta;
}

const std::string &pers_fizica::getCnp() const {
    return cnp;
}

