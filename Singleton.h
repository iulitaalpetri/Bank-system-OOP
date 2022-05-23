#ifndef OOP_BUILDER_H
#define OOP_BUILDER_H

#endif //OOP_BUILDER_H
//#include "cont.h"
#include "Banca.h"
#include "Pers_fizica.h"
#include "pers_juridica.h"
#include <iostream>
#include <memory>
#include <vector>
#include <exception>
#include "exceptii.h"
//#include "cont_curent.h"
//#include "cont_standard.h"
//#include "cont_premium.h"
//meniu singleton
class Menu {
private:
    static Menu *instance;
    std::shared_ptr<Cont> un_cont;
    std::shared_ptr<Cont> alt_cont;
    std::shared_ptr<Titular> un_titular;
    std::vector<std::shared_ptr<Cont>> lista_conturi;
    Banca b;
    friend class Cont;
    friend class Titular;
    friend class Banca;
    int n;

    Menu() {

    }

public:
    ~Menu(){
        std::cout<<"destructor";

    }
    static Menu *getInstance() {
        if (instance == NULL) {
            instance = new Menu;
        }
        return instance;
    }
    void showOptions(){
        std::cout<<"-------------------------------Meniu-------------------------------------------"<<std::endl;
        std::cout<<"0. creare cont"<<std::endl;
        std::cout<<"1. afisarea informatiilor pentru fiecare cont"<<std::endl;
        std::cout<<"2. depunere numerar"<<std::endl;
        std::cout<<"3. extragere numerar"<<std::endl;
        std::cout<<"4. efectuare tranzactie"<<std::endl;
        std::cout<<"5. plata utilitati(cont curent)"<<std::endl;
        std::cout<<"6. plata abonament telefon"<<std::endl;
        std::cout<<"7. exit"<<std::endl;
        std::cout<<"----------------------------------------------------------------------------------"<<std::endl;
    }
    void cerinta0(){
        std::string un_string;
        //float nr;
        std::cout<<"Introduceti banca:"<<std::endl;
        std::cin>>un_string;
        Banca b{un_string,un_string, lista_conturi};
        std::cout<<"Sunteti persoana fizica sau juridica?"<<std::endl;
        std::cin>>un_string;
        if(un_string=="fizica"){
            std::string nume;
            std::string prenume;
            int varsta;
            std::string cnp;
            std::cout<<"Introduceti:"<<std::endl<<"Nume:"<<std::endl;
            std::cin>>nume;
            std::cout<<"Prenume:"<<std::endl;
            std::cin>>prenume;
            std::cout<<"Varsta:"<<std::endl;
            std::cin>>varsta;

            std::cout<<"Cnp:"<<std::endl;
            std::cin>>cnp;
            try{
           std::shared_ptr<Titular> pers= std::make_shared<pers_fizica>(true, nume, prenume, varsta, cnp);}
            catch(std::runtime_error &err){
                std::cout<<err.what()<<std::endl;
            }
        }
        else{
            std::string nume;
            std::string prenume;
            std::string firma;
            std::cout<<"Introduceti:"<<std::endl<<"Nume:"<<std::endl;
            std::cin>>nume;
            std::cout<<"Prenume:"<<std::endl;
            std::cin>>prenume;
            std::cout<<"Nume firma:"<<std::endl;
            std::cin>>firma;
                       std::shared_ptr<Titular> pers= std::make_shared<pers_juridica>(false, nume, prenume, firma);


        }
        bool a=false;
        std::cout<<"Alegeti un tip de cont:curent, standard sau premium"<<std::endl;
        std::cin>>un_string;
        while(!a){
        if(un_string== "curent"){
        int suma;
        std::string moneda;

        int c;
        float telefon;
        float utilitati;
        std::cout<<"Introduceti:"<<std::endl<<"Suma initiala:"<<std::endl;
        std::cin>>suma;
        std::cout<<"Moneda:"<<std::endl;
        std::cin>>moneda;
        std::cout<<"C: "<<std::endl;// nu stiu
        std::cin>>c;
        std::cout<<"Abonament telefon:"<<std::endl;
        std::cin>>telefon;
        std::cout<<"Utilitati:"<<std::endl;
        std::cin>>utilitati;

//        try{
//            //std::shared_ptr<Cont> cont = std::make_shared<contcurent>(suma, moneda,  pers, c, telefon, utilitati );
//        }
//        catch(std::runtime_error &err){
//            std::cout<<err.what()<<std::endl;
//        }

        }

        }
    }
    void cerinta1(){
        std::cout<<"TODO cerinta 1"<<std::endl;
    }
    void cerinta2(){
        std::cout<<"TODO cerinta 2"<<std::endl;
    }
    void cerinta3(){
        std::cout<<"TODO cerinta 3"<<std::endl;
    }
    void cerinta4(){
        std::cout<<"TODO cerinta 4"<<std::endl;
    }


};

Menu *Menu::instance;
