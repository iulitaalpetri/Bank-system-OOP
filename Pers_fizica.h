#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "titular.h"
#include "exceptii.h"

//de adaugat pointeri
class pers_fizica:public Titular{
    std::string nume;
    std::string prenume;
    int varsta{};
    std::string cnp;
public:

    //clonare
    std::shared_ptr<Titular> clone() override{
        return std::make_shared<pers_fizica>(*this);
    }

    pers_fizica();
    pers_fizica(const int &id_, std::string nume_, std::string prenume_,  int varsta_, std::string cnp_)
            : Titular(id_), nume(std::move(nume_)), prenume(std::move(prenume_)), varsta(varsta_), cnp(std::move(cnp_)) {

if(varsta<18) throw(eroare_varsta("Minor, are nevoie de tutore"));
        std::cout << "constr init pers fizica- derivata" << std::endl;
    }
    void afisare(std::ostream &os) const override;
    ~pers_fizica() override;
    bool verificare_varsta() const;






};