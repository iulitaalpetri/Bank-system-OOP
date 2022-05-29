//
// Created by iulit on 5/29/2022.
//

#include <string>
#include <vector>
#include <iostream>
#include "exceptii.h"
#include "Banca.h"

#ifndef OOP_CONT_ACCOUNT_H
#define OOP_CONT_ACCOUNT_H

#endif //OOP_CONT_ACCOUNT_H
class Data{
    int luna;
    int an;
public:
    Data(int luna_, int an_): luna(luna_), an(an_){}
};
class cont_account{
    std::string username;
    std::string parola;
    Data data_nastere;
    std::string sex;
    int incercari=0;
    friend class account_builder;
    static std::vector<cont_account> lista_conturi;




public:
    cont_account()= default;
    cont_account(const std::string &username_, const std::string &parola_, int luna_, int an_, const std::string &sex_): username(username_), parola(parola_),
                                                                                                            data_nastere(luna_, an_), sex(sex_){


    }

    void logare(std::string nume, std::string parolaa){
        for(auto i: lista_conturi){
            if (nume== i.username ) {if(i.parola== parolaa){incercari= 0;
            std::cout<<"Te- ai logat cu succes"<<std::endl;}
            else {
                incercari++;
                std::cout<<"Parola incorecta, incearca iar!"<<std::endl;
            }}

        }
        if(incercari== 5){
            std::cout<<"Cont blocat";
            this->~cont_account();
        }

    }
    void add_cont(){
        lista_conturi.push_back(*this);
    }
};
class account_builder{
    cont_account account;
    friend class cont_account;
public:
    account_builder()= default;
    account_builder& username(const std::string& username_ ){
        for(auto i: account.lista_conturi){
            if (i.username== username_) throw(eroare_account("Numele de utilizator este deja folosit."));
        }
        account.add_cont();

        account.username= username_;
        return *this;
    }
    account_builder& parola( const std::string &parola_){
        account.parola= parola_;
        return *this;
    }
    account_builder& data_nastere(int luna, int an){
        Data d= {luna, an};
        account.data_nastere= d;
        return *this;
    }
    account_builder& sex(std::string &sex_){
        account.sex =sex_;
        return *this;
    }
    cont_account build(){
        return account;
    }

};

class account_factory{
    static int id;
public:
    static cont_account automat(){
        id++;
        return cont_account("utilizator"+ std::to_string(id), "parola"+ std::to_string(id),0, 0, "-");
    }
};