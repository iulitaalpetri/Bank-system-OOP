#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "titular.h"
#include "titular.cpp"
//de adaugat pointeri
class pers_fizica:public Titular{
    std::string nume;
    std::string prenume;
    int varsta;
    std::string cnp;
public:

    //clonare
    [[nodiscard]] std::shared_ptr<Titular> clone() const override;
    pers_fizica();
    pers_fizica(int &id_, std::string &nume_, std::string &prenume_, int &varsta_, std::string &cnp_);
    void afisare(std::ostream &os) const override;
    ~pers_fizica() override;


    const std::string &getNume() const;

    const std::string &getPrenume() const;

    int getVarsta() const;

    const std::string &getCnp() const;


};