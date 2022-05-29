#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "cont.h"
#include "cont_account.h"
class Banca{
protected:
    std::string nume;
    std::string sucursala;
    std::vector<std::shared_ptr<Cont>> conturi;



public:
    //constr default
    Banca();
    // const init
    [[maybe_unused]] Banca(const std::string &nume_, const std::string &sucursala_, const std::vector<std::shared_ptr<Cont>> &conturi_);


    //Swap
    friend void swap(Banca & b1, Banca &b2){
        std::swap(b1.conturi, b2.conturi);
    };

    friend std::ostream& operator<<(std::ostream& os, const Banca& ob);//afisare, suprainc op <<
    const std::vector<std::shared_ptr<Cont>> &getConturi() const;

    //adaugare cont in vect
    void addCont(const std::shared_ptr<Cont> c) {
        conturi.push_back(c);
    }
    //constr cop
    [[maybe_unused]] Banca(const Banca& other) ;

    // suprainc op =
    Banca& operator=(const Banca& other) ;
    //destr
    virtual ~Banca();


};
