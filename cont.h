#pragma once
#include <string>
#include <map>

#include "titular.h"
//#include "Singleton.h"



class Cont {
protected:
    static int contor;
    float suma;
    std::string moneda;
    int iban;
   std::shared_ptr<Titular> titular;
    std::map<std::pair<std::string, std::string>, double> curs;
    friend class cont_account;



public:
    //clone
    virtual std::shared_ptr<Cont> clone()=0;

    //constr
    Cont(float suma_, std::string moneda_,   std::shared_ptr<Titular> titular_, int c);

    //destr
    virtual ~Cont() ;
    //setter
    void setSuma(float suma);

    virtual void afisare(std::ostream& os) const;

    friend std::ostream &operator<<(std::ostream &os, const Cont &t);

//getters
    const int &getIban() const;

    int getSuma() ;

    [[nodiscard]] const std::string &getMoneda() const;

    // metode - 3
    // fctia 1
    virtual void depunere(int sumadep, const std::string &monedadep)= 0;

    // fctia 2
    virtual void extragere(int sumaextr, const  std::string &monedaextr)=0   ;
    // fctia 3
    virtual void tranzactie( std::shared_ptr<Cont> other_cont, int sumatranz) = 0 ;


};
