#pragma once
#include <string>
#include <map>

#include "titular.h"



class Cont {
protected:
    int suma;
    std::string moneda;
    std::string iban;
    std::shared_ptr<Titular> titular;
    std::map<std::pair<std::string, std::string>, double> curs;

    //clonare
    Cont(const Cont&) =default;
    Cont & operator=(const Cont& c)= default ;

public:

    //constr
    Cont(int suma_, std::string moneda_,  std::string iban_, std::shared_ptr<Titular> titular_);

    //destr
    virtual ~Cont() ;
    //setter
    void setSuma(int suma);

    virtual void afisare(std::ostream& os) const;

    friend std::ostream &operator<<(std::ostream &os, const Cont &t);

//getters
    const std::string &getIban() const;

    int getSuma() ;

    [[nodiscard]] const std::string &getMoneda() const;

    // metode - 3
    // fctia 1
    virtual void depunere(int sumadep, std::string monedadep)= 0;

    // fctia 2
    virtual void extragere(int sumaextr,  std::string monedaextr)=0   ;
    // fctia 3
    virtual void tranzactie( Cont& other_cont, int sumatranz) = 0 ;


    [[nodiscard]] virtual std::shared_ptr<Cont> clone() const= 0 ;// ptr
};
