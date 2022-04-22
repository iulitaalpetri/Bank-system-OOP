#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "titular.h"
#include "Pers_fizica.h"//fctie virtuala ca nu poate avea cont curent
#include "pers_juridica.h"

pers_juridica::pers_juridica(std::string nume_reprezentant_, std::string prenume_reprezentant_,
                             std::string nume_firma_):

        nume_reprezentant(nume_reprezentant_), prenume_reprezentant(prenume_reprezentant_), nume_firma(nume_firma_){
    std::cout<<"constr init pers_jur- derivata"<< std::endl;
}
pers_juridica::~pers_juridica() noexcept {
    std::cout<<"destructor pers_jurid- derivata"<<std::endl;
}

void pers_juridica::afisare(std::ostream &os) const {
    Titular::afisare(os);
    os <<"nume reprezentant:"<< nume_reprezentant<<", prenume reprezentant:"<<prenume_reprezentant<<", nume firma:"<<nume_firma<< "\n";
}

const std::string &pers_juridica::getnume_firma() const {}


