////
//// Created by iulit on 5/6/2022.
////
//
//#ifndef OOP_TEMPLATE_H
//#define OOP_TEMPLATE_H
//
//#endif //OOP_TEMPLATE_H
//#pragma once
//#include <iostream>
//#include <string>
//#include <utility>
//#include <vector>
//#include <map>
//#include "cont.h"
//template <typename T, typename T1, typename T2, typename T3>
//class Banca{
//protected:
//    std::string nume;
//    std::string sucursala;
//    std::vector<T> conturi;
//    T1 cod_fiscal;
//    T2 x;
//    T3 y;
//
//
//
//public:
//    //constr default
//    Banca();
//    // const init
//    Banca(const std::string &nume_, const std::string &sucursala_, std::vector<T> conturi_, T1 cod_fiscal_, T2 x_, T3 y_ );
//
//
//    //Swap
//    friend void swap(Banca & b1, Banca &b2){
//        std::swap(b1.conturi, b2.conturi);
//    };
//
//    friend std::ostream& operator<<(std::ostream& os, const Banca& ob);//afisare, suprainc op <<
//
//    //adaugare cont in vect
//    void addCont(Cont& cont) ;
//    //constr cop
//    Banca(const Banca& other) ;
//
//    // suprainc op =
//    Banca& operator=(const Banca& other) ;
//    //destr
//    virtual ~Banca();
//
//
//};
