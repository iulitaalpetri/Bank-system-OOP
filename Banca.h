#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "cont.h"
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

    //adaugare cont in vect
    //[[maybe_unused]] void addCont(const Cont& cont) ;
    //constr cop
    [[maybe_unused]] Banca(const Banca& other) ;

    // suprainc op =
    Banca& operator=(const Banca& other) ;
    //destr
    virtual ~Banca();


};