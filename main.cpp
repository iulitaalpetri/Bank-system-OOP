
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "Banca.h"
#include "cont_curent.h"
#include "cont.h"
#include "titular.h"
#include "pers_juridica.h"
#include "Pers_fizica.h"
#include "exceptii.h"
#include "cont_premium.h"
#include "cont_standard.h"
#include "cont_curent.h"
using namespace std;


int main()
{
    std::vector<std::shared_ptr<Cont>> vect_cont;
    std::vector<std::shared_ptr<Cont>> vect1_cont;
//    Banca b1{"Nume_Banca1", "Bucuresti", vect_cont};
//    Banca b2{"Nume_Banca2", "Constanta", vect1_cont};
//    swap(b1, b2);- la final de tot

    try {


        shared_ptr<Titular> p1(new pers_fizica(0, "Alpetri", "Iulita", 20, "7652835689"));
        pers_fizica* p_f_1= dynamic_cast<pers_fizica*>(*p1);
        if(p_f_1->verificare_varsta()== false) throw eroare_varsta();
        else{
            shared_ptr<Cont> c1(new contcurent(300, "lei", "64328", p1, 30, 20));
            contcurent* c_1= dynamic_cast<contcurent*>(*c1);
            if(c_1-> ver_suma()== false) throw eroare_cont_curent();
            else vect_cont.push_back(c1);

            c_1->plata_utilitati();
            c_1->plata_abonament();
            std::cout<<c_1;
            c_1->depunere(78, "lei");
            c_1->extragere(90, "euro");

//            cout<<"Istoric tranz:"<<std::endl;
//            for (vector<std::string, std::string, float> :: it v=  )
//                for (unordered_map<int, int> :: iterator v=tuplu.begin(); v!= tuplu.end(); v++){
//                    g<<( v -> first) <<" "<< (v -> second)<<" ";}- afisat istoric tranzactii

        }}catch(std::domain_error &e){
        std::cout << e.what() << "\n";
    };






    shared_ptr<Titular> p_f_2(new pers_fizica(0, "Ureche", "Mara", 16, "5739"));
        // se puin amandoua in try si daca am eroare, atunci nu fac cont
        std::shared_ptr<Titular> p_j_1 = std::make_shared<pers_juridica>(1, "Popescu", "Ion", "Nume_firma");
        std::shared_ptr<Titular> p_j_2 = std::make_shared<pers_juridica>(1, "Georgescu", "Alin", "Nume_firma_1");
        // constr copiere pt titular titular(shared_ptr)






        std::shared_ptr<Cont> c_pr(new cont_premium(400, "euro", "756834", t_j, 50));


        std::shared_ptr<Cont> c_st(new cont_standard(400, "euro", "756834", t1, 10, 2));
        std::shared_ptr<Cont> c_s(new cont_standard(400, "euro", "756834", t, 10, 2));


        std::vector<std::shared_ptr<Cont>> vect_cont;
        vect_cont.push_back(c_curent);
        vect_cont.push_back(c_pr);
        vect_cont.push_back(c_st);
        std::vector<std::shared_ptr<Cont>> vect1_cont;
        vect1_cont.push_back(c_st1);










    return 0;
}
































