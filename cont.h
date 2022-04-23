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



    Cont(const Cont&) ;// pointer
    Cont& operator=(const Cont&) ;
    virtual void afisare(std::ostream& os) const = 0;


public:
    virtual Cont* clone () const=0;
    Cont();

    Cont(int &suma, const std::string &moneda, const std::string &iban, Titular& titular_) : suma(suma),moneda(moneda), iban(iban), titular(titular_) {
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
    virtual void depunere(int sumadep, const std::string monedadep)= 0;

    // fctia 2
    virtual void extragere(int sumaextr, const std::string monedaextr) =0 ;
    // fctia 3
    virtual void tranzactie(  Cont& other_cont, int sumatranz) =0 ;


    virtual ~Cont() ;




};

