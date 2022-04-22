#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <ctime>
#include "exceptii.h"
#include "cont.h"
//cont standard- plata lunara, cont prem- plata la 2 luni- fctie virt
// suprascriu depunerea alea alea cu comision
class cont_standard: public Cont{

    int taxa;
    static const int suma_min= 500;
    static constexpr float taxa_intarziere_plata = 0.2 ;
    std::map<int, int> plati;
    float comision;


public:
    [[nodiscard]] std::shared_ptr<Cont> clone() const override {
        return std::make_shared <cont_standard>(*this);
    }// eroare

    explicit cont_standard(int taxa_,  float comision_ );
    virtual ~cont_standard();
    void afisare(std::ostream &os) const override ;

    void data_plata();
    void efectuare_plata(int luna);
    //void depunere() override;
    void depunere(int sumadep, const std::string monedadep) override;
    void extragere(int sumaextr, const std::string monedaextr)  override;
    void tranzactie(Cont& other_cont, int sumatranz ) override;




};