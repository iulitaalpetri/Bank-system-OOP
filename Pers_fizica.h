#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "titular.h"

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
    pers_fizica(const int &id_, const std::string &nume_, const std::string &prenume_,  int varsta_, const std::string  &cnp_)
            : Titular(id_), nume(nume_), prenume(prenume_), varsta(varsta_), cnp(cnp_) {

//    if (varsta_ < 18) throw eroare_varsta();

        std::cout << "constr init pers fizica- derivata" << std::endl;
    }
    void afisare(std::ostream &os) const override;
    ~pers_fizica() override;
    bool verificare_varsta();

    const std::string &getNume() const;

    const std::string &getPrenume() const;

    int getVarsta() const;

    const std::string &getCnp() const;


};