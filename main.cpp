#include <iostream>
#include "titular.h"
#include "cont.h"
#include "pers_juridica.h"
#include "Pers_fizica.h"
#include "cont_curent.h"
#include "cont_premium.h"
#include "exceptii.h"
#include "cont_standard.h"

int main()
{



    std::shared_ptr<Titular> pf1 = std::make_shared<pers_fizica>(0, "Alpetri", "Iulita", 20, "7652835689");
    std::shared_ptr<Titular> pf2 = std::make_shared<pers_fizica>(0, "Ureche", "Mara", 23, "53453435");
    std::shared_ptr<Titular> pf3 = std::make_shared<pers_fizica>(0, "Ioan", "Georgescu", 16, "568976567");
    std::shared_ptr<Titular> pj= std::make_shared<pers_juridica>(1, "Alin", "Popescu", "Nume_firma");

    try{
    if(dynamic_cast<pers_fizica&>(*pf1).verificare_varsta()== 0) throw (eroare_varsta{"Minor, are nevoie de un tutore! \n"});
    else {
        dynamic_cast<pers_fizica&>(*pf1).afisare(std::cout);
        if  (pf1->isId()) throw(eroare_cont_curent{"Contul curent este valabil doar pentru persoane fizice.\n"});
        else{
        std::shared_ptr<Cont> c_c = std::make_shared<contcurent>(300, "lei", "643674", pf1, 5, 30, 20 );
        dynamic_cast<contcurent&>(*c_c).afisare(std::cout);
            dynamic_cast<contcurent&>(*c_c).plata_abonament();
            dynamic_cast<contcurent&>(*c_c).plata_utilitati();

            dynamic_cast<contcurent&>(*c_c).extragere(20, "lei");
            dynamic_cast<contcurent&>(*c_c).depunere(100, "euro");
            dynamic_cast<contcurent&>(*c_c).afisare(std::cout);
            dynamic_cast<contcurent&>(*c_c).afisare_istoric();


        }

    }
    }
    catch (std::exception& err) {
        std::cout << err.what() << "\n";
    }

    try{
        if(dynamic_cast<pers_fizica&>(*pf2).verificare_varsta()== 0) throw (eroare_varsta{"Minor, are nevoie de un tutore! \n"});
        else{
            dynamic_cast<pers_fizica&>(*pf2).afisare(std::cout);

                std::shared_ptr<Cont> c_s = std::make_shared<cont_standard>(10000, "euro", "756834", pf2,5,  10, 0.05);
            dynamic_cast<cont_standard&>(*c_s).afisare(std::cout);

            dynamic_cast<cont_standard&>(*c_s).efectuare_plata();
            dynamic_cast<cont_standard&>(*c_s).afisare(std::cout);
            dynamic_cast<cont_standard&>(*c_s).extragere(10, "euro");
            dynamic_cast<cont_standard&>(*c_s).depunere(30, "lei");
            dynamic_cast<cont_standard&>(*c_s).tranzactie(dynamic_cast<Cont&>(*c_s), 50);



        }

    }
    catch (std::exception& err) {
        std::cout << err.what() << "\n";
    }

    try {
        if (dynamic_cast<pers_fizica &>(*pf3).verificare_varsta() == 0)
            throw (eroare_varsta{"Minor, are nevoie de un tutore! \n"});
    }catch (std::exception& err) {
        std::cout << err.what() << "\n";
    }
    try {
        std::shared_ptr<Cont> c_p = std::make_shared<cont_premium>( 700, "euro", "756834",pj, 5, 50    );
        dynamic_cast<cont_premium &>(*c_p).afisare(std::cout);
        dynamic_cast<cont_premium &>(*c_p).extragere(900, "euro");
        dynamic_cast<cont_premium &>(*c_p).depunere(20, "lei");
        dynamic_cast<cont_premium &>(*c_p).tranzactie(dynamic_cast<Cont &>(*c_p), 50);


    }catch (std::exception& err) {
        std::cout << err.what() << "\n";
    }
    //adauga direct in try
//    std::vector<std::shared_ptr<Cont&>> vect_cont;
//    std::vector<std::shared_ptr<Cont&>> vect_cont1;
//
//
//    vect_cont.push_back(*c_p);
//        vect_cont.push_back(dynamic_cast<Cont &>(*c_c));
//
//        vect1_cont.push_back(dynamic_cast<Cont &>(*c_s));
//        Banca b1{"Nume_Banca1", "Bucuresti", vect_cont};
//    Banca b2{"Nume_Banca2", "Constanta", vect1_cont};
//    //swap(b1, b2);











    return 0;
}
































