#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <ctime>
#include "exceptii.h"
#include "titular.h"
#include "pers_juridica.h"


class Cont {
protected:
    int suma;


    std::string moneda;
    std::string iban;
    Titular titular;
    std::map<std::pair<std::string, std::string>, double> curs;

    //clonare
    Cont(const Cont&) =default;
    Cont & operator=(const Cont& c)= default ;// ce??



    virtual void afisare(std::ostream& os) const;


public:
    //virtual Cont* clone () ;
    Cont();


    Cont(int suma_, const std::string &moneda_,  const std::string &iban_, const std::shared_ptr<Titular> &titular_) : suma(suma_),moneda(moneda_), iban(iban_), titular(titular_) {
        curs[{"lei", "euro"}] = 5;
        curs[{"euro", "lei"}]= 0.2;
        curs[{"lei", "lei"}]= 1;
        curs[{"euro", "euro"}] = 1;
    }

    const std::string &getIban() const;



    int getSuma() const;

    const std::string &getMoneda() const;



    // supraincarcarea operator << si >>

    //virtual void afisare(std::ostream &os) const = 0;
    friend std::ostream &operator<<(std::ostream &os, const Cont &t);







    //getter suma
    int& getsuma(){return suma;}



    // getter moneda
    std::string& getmoneda(){return moneda;}


    // metode - 3
    // fctia 1
    virtual void depunere(int sumadep, const std::string monedadep);

    // fctia 2
    virtual void extragere(int sumaextr, const std::string monedaextr)  ;
    // fctia 3
    virtual void tranzactie(  Cont& other_cont, int sumatranz)  ;


    virtual ~Cont() ;

    [[nodiscard]] virtual std::shared_ptr<Cont> clone() const ;// clonare



};

