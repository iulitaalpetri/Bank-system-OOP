
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
using namespace std;


int main()
{
// adauga swap






    std::shared_ptr<Titular> t= std::make_shared<pers_fizica>( 0, "Alpetri", "Iulita", 20, "7342983");


    std::shared_ptr<Titular> t1 ( new pers_fizica(1, "Alpetri", "iulita", 20, "5689"));
    std::shared_ptr<Titular> t_j= std::make_shared<pers_juridica>( 1, "hbf", "ifha", "udhiaw") ;
    std::shared_ptr<Titular> t_j1= std::make_shared<pers_juridica>( 1, "hbf", "768698", "udhiaw") ;

    std::shared_ptr<Cont> c_curent ( new contcurent(500, "lei", "748634",t1,  120, 200 ));
    std::shared_ptr<Cont> c_pr (new cont_premium(400, "euro", "756834",t_j,  50));
    std::shared_ptr<Cont> c_st (new cont_standard (400, "euro", "756834",t, 10, 0.2));
    std::shared_ptr<Cont> c_st1 (new cont_standard (400, "euro", "756834",t, 10, 0.2));

    std::vector<std::shared_ptr<Cont>> vect_cont;
    vect_cont.push_back(c_curent);
    vect_cont.push_back(c_pr);
    vect_cont.push_back(c_st);
    std::vector<std::shared_ptr<Cont>> vect1_cont;
    vect1_cont.push_back(c_st1);
    Banca b1{"Nume_Banca1", "Bucuresti", vect_cont};
    Banca b2{"Nume_Banca2", "Constanta", vect1_cont};
    swap(b1, b2);


    try{

    }








    return 0;
}
































