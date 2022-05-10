//
// Created by iulit on 5/6/2022.
//

#ifndef OOP_TEMPLATE_H
#define OOP_TEMPLATE_H

#endif //OOP_TEMPLATE_H
#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <scardssp.h>
#include "cont.h"
template < typename T>
class Banca;
template < typename T>
std::ostream& operator<<(std::ostream& os, const Banca<T>& ob);



template < typename T>
class Banca{
protected:
    std::string nume;
    std::string sucursala;
    std::vector<T> conturi;
//    T1 cod_fiscal;
//    T2 x;
//    T3 y;



public:
    //constr default
    Banca()= default;
    // const init
    Banca(const std::string &nume_, const std::string &sucursala_, std::vector<T> conturi_ ): nume(nume_),
    sucursala(sucursala_), conturi(conturi_){};


    //Swap
    friend void swap(Banca & b1, Banca &b2){
        std::swap(b1.conturi, b2.conturi);
    }
    friend std::ostream& operator<< <>(std::ostream&, const Banca<T>&);




    //adaugare cont in vect
    void addCont(T& cont) {
        conturi.emplace_back(cont.clone());
    }

    //constr cop
    Banca(const Banca& other){
        nume = other.nume;
        sucursala= other.sucursala;
        for(const auto& cont : other.conturi)
            conturi.push_back(static_cast<const std::shared_ptr<Cont>>(cont->clone()));
    }
    ;

    // suprainc op =
//    Banca& operator=(const Banca& other) ;
    //destr
    virtual ~Banca()= default;


};



template <typename T>
std::ostream& operator<<(std::ostream& os, const Banca<T>& ob) {
    os << ob.nume<<" "<<ob.sucursala<<" "<<ob.codfiscal;
    for (auto i: ob.conturi){
        std::cout<<i<<std::endl;
    }
    return os;

}