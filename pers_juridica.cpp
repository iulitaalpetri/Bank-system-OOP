#include <iostream>
#include <string>
#include <utility>
#include "titular.h"

#include "pers_juridica.h"

pers_juridica::pers_juridica(int id_, std::string nume_reprezentant_, std::string prenume_reprezentant_,
                             std::string nume_firma_):

        Titular( id_) , nume_reprezentant(std::move(nume_reprezentant_)), prenume_reprezentant(std::move(prenume_reprezentant_)), nume_firma(std::move(nume_firma_)){
    std::cout<<"constr init pers_jur- derivata"<< std::endl;
}
pers_juridica::~pers_juridica()  {
    std::cout<<"destructor pers_jurid- derivata"<<std::endl;
}

void pers_juridica::afisare(std::ostream &os) const {
    Titular::afisare(os);
    os <<"nume reprezentant:"<< nume_reprezentant<<", prenume reprezentant:"<<prenume_reprezentant<<", nume firma:"<<nume_firma<< "\n";
}
