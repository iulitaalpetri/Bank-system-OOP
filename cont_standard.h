
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <ctime>
#include "exceptii.h"

#include "cont.h"

class cont_standard: public Cont{

    int taxa;
    static const int suma_min= 500;
    static constexpr float taxa_intarziere_plata = 0.2 ;
    std::map<int, int> plati;
    float comision;


public:


    explicit cont_standard(int suma_, const std::string &moneda_, const std::string &iban_, const std::shared_ptr<Titular>& titular_, int taxa_,  float comision_ );
    virtual ~cont_standard();
    void afisare(std::ostream &os) const override ;

    void data_plata();
    void efectuare_plata(int luna);

    void depunere(int sumadep, const std::string monedadep) override;
    void extragere(int sumaextr, const std::string monedaextr)  override;
    void tranzactie(Cont& other_cont, int sumatranz ) override;
    [[nodiscard]] std::shared_ptr<Cont> clone() const override;





};