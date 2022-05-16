#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <ctime>
#include "exceptii.h"
#include "cont.h"
#include "cont_curent.h"
// suprascriu tranz, depunere, si alea fara nimic, asa cum sunt
//intreaba la afisare la conturi daca fac downcast
// mai ai asta de facut, dupa treci la exception
class cont_premium:public Cont{
    int taxa_init;
    static const int suma_min= 1000;

public:

    cont_premium(int suma_,  const std::string &moneda_,const  std::string &iban_,const std::shared_ptr< Titular> &titular_, int c,int taxa_init_);
    virtual ~cont_premium()= default;
    void afisare(std::ostream &os) const override ;
    void depunere(int sumadep, const std::string &monedadep) override;
    void extragere(int sumaextr, const std::string &monedaextr)  override;
    void tranzactie(Cont& other_cont, int sumatranz ) override;
    [[nodiscard]] std::shared_ptr<Cont> clone() const override;


};




