#include <iostream>
#include "titular.h"
#include "cont.h"
#include "pers_juridica.h"
#include "Pers_fizica.h"
#include "cont_curent.h"
#include "cont_premium.h"
#include "exceptii.h"
#include "cont_standard.h"
#include "Singleton.h"

int main()
{
Menu *menu = Menu::getInstance();
    int nr_cerinta;

    while(true){
        menu -> showOptions();
        std::cout<<"Introduceti id-ul cerintei: ";
        std::cin>> nr_cerinta;
        if(nr_cerinta == 0){
            menu -> cerinta0();
        } else if(nr_cerinta == 1){
            menu -> cerinta1();
        } else if(nr_cerinta == 2){
            menu -> cerinta2();
        } else if(nr_cerinta == 3){
            menu -> cerinta3();
        } else if(nr_cerinta == 4){
            menu -> cerinta4();
        }
        else if(nr_cerinta== 5){
            menu -> cerinta5();
        }
        else if(nr_cerinta== 6){
            menu->cerinta6();
        }
        else if(nr_cerinta == 7){
            break;
        }
    }
    delete menu;





//    std::shared_ptr<Titular> pf1 = std::make_shared<pers_fizica>(0, "Alpetri", "Iulita", 20, "7652835689");
//    std::shared_ptr<Titular> pf2 = std::make_shared<pers_fizica>(0, "Ureche", "Mara", 23, "53453435");
//    std::shared_ptr<Titular> pf3 = std::make_shared<pers_fizica>(0, "Ioan", "Georgescu", 16, "568976567");
//    std::shared_ptr<Titular> pj= std::make_shared<pers_juridica>(1, "Alin", "Popescu", "Nume_firma");
//
//
//
//    try{
//        if(dynamic_cast<pers_fizica&>(*pf1).verificare_varsta()== 0) throw (eroare_varsta{"Minor, are nevoie de un tutore! \n"});
//    else {
//        pf1->afisare(std::cout);
//        //modifica, pune throw in constr
//        if  (pf1->isId()) throw(eroare_cont_curent{"Contul curent este valabil doar pentru persoane fizice.\n"});
//
//        else{
//        std::shared_ptr<Cont> c_c = std::make_shared<contcurent>(300, "lei", "643674", pf1, 5, 30, 20 );
//
//        c_c->afisare(std::cout);
//            dynamic_cast<contcurent&>(*c_c).plata_abonament();
//           dynamic_cast<contcurent&>(*c_c).plata_utilitati();
//
//            c_c->extragere(20, "lei");
//            c_c->depunere(100, "euro");
//            c_c->afisare(std::cout);
//            dynamic_cast<contcurent&>(*c_c).afisare_istoric();
//
//
//        }
//
//    }
//    }
//    catch (std::exception& err) {
//        std::cout << err.what() << "\n";
//    }
//
//    try{
//        if(dynamic_cast<pers_fizica&>(*pf2).verificare_varsta()== 0) throw (eroare_varsta{"Minor, are nevoie de un tutore! \n"});
//        else{
//            pf2->afisare(std::cout);
//           // std::cout<<"-------------------------------pers_f 2----------------------"<<std::endl;
//                std::shared_ptr<Cont> c_s = std::make_shared<cont_standard>(10000, "euro", "756834", pf2,5,  10, 0.05);
//                cont_standard x= dynamic_cast<cont_standard&>(*c_s);
//                x.afisare(std::cout);
//
//            x.efectuare_plata();
//            x.afisare(std::cout);
//            x.extragere(10, "euro");
//            x.depunere(30, "lei");
//            x.tranzactie(dynamic_cast<Cont&>(*c_s), 10000);
//            x.afisare(std::cout);
//
//
//
//
//        }
//
//    }
//    catch (std::exception& err) {
//        std::cout << err.what() << "\n";
//    }
//
//    try {
//        if (dynamic_cast<pers_fizica &>(*pf3).verificare_varsta() == 0)
//            throw (eroare_varsta{"Minor, are nevoie de un tutore! \n"});
//    }catch (std::exception& err) {
//        std::cout << err.what() << "\n";
//    }
//    try {
//        std::shared_ptr<Cont> c_p = std::make_shared<cont_premium>( 700, "euro", "756834",pj, 5, 50    );
//        cont_premium x= dynamic_cast<cont_premium &>(*c_p);
//
//        x.afisare(std::cout);
//        x.extragere(900, "euro");
//        x.depunere(20, "lei");
//        x.tranzactie(dynamic_cast<Cont &>(*c_p), 50);
//        x.afisare(std::cout);
//
//    }catch (std::exception& err) {
//        std::cout << err.what() << "\n";
//    }
//    //adauga direct in try
////    std::vector<std::shared_ptr<Cont&>> vect_cont;
////    std::vector<std::shared_ptr<Cont&>> vect_cont1;
////
////
////    vect_cont.push_back(*c_p);
////        vect_cont.push_back(dynamic_cast<Cont &>(*c_c));
////
////        vect1_cont.push_back(dynamic_cast<Cont &>(*c_s));
////        Banca b1{"Nume_Banca1", "Bucuresti", vect_cont};
////    Banca b2{"Nume_Banca2", "Constanta", vect1_cont};
////    //swap(b1, b2);
//
//
//
//
//
//





    return 0;
}
































