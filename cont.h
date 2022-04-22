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

    Cont(const Cont&) = default;// pointer
    Cont& operator=(const Cont&) = default;//op egal
    virtual void afisare(std::ostream& os) const = 0;


public:
    const std::string &getIban() const;

    Cont();

    int getSuma() const;

    const std::string &getMoneda() const;



    // supraincarcarea operator << si >>

    //virtual void afisare(std::ostream &os) const = 0;
    friend std::ostream &operator<<(std::ostream &os, const Cont &t);
    virtual std::shared_ptr<Cont> clone() const = 0;






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

