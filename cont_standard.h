#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <ctime>
#include "exceptii.h"

#include "cont.h"

class cont_standard: public Cont{

    int taxa;
    static const int suma_min= 500;
    static constexpr float taxa_intarziere_plata = 0.2 ;

    float comision;


public:


    explicit cont_standard(float suma_, const std::string &moneda_, const std::string &iban_, Titular *titular_,int c,  int taxa_,  float comision_ );
    virtual ~cont_standard();
    void afisare(std::ostream &os) const override ;


    void efectuare_plata();

    void depunere(int sumadep, const std::string &monedadep) override;
    void extragere(int sumaextr, const std::string &monedaextr)  override;
    void tranzactie(Cont & other_cont, int sumatranz ) override;
    Cont* clone() const override { return new cont_standard(*this); }




};