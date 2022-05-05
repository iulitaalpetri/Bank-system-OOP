#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "titular.h"
#include "Pers_fizica.h"


//pers_fizica::pers_fizica(const int &id_, const std::string &nume_, const std::string &prenume_,  int varsta_, const std::string  &cnp_)
//        : Titular(id_), nume(nume_), prenume(prenume_), varsta(varsta_), cnp(cnp_) {
//
////    if (varsta_ < 18) throw eroare_varsta();
//
//    std::cout << "constr init pers fizica- derivata" << std::endl;
//}

bool pers_fizica::verificare_varsta() {
    if(varsta< 18) return false;
    return true;
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
std::shared_ptr<Titular> pers_fizica::clone()const {
    std::cout<<"Clonare_titular\n";
    return std::make_shared<pers_fizica>(*this);
}

