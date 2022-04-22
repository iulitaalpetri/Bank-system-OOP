#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <ctime>
#include <tuple>
#include "exceptii.h"
#include "cont.h"
// doar pt pers fizice
// mai pune aia cu comision la dep, extragere, tranzactie
class contcurent : public Cont{
    std::vector< std::tuple<std::string , std::string, float> > istoric_tranzactii;
    float abonament_telefon;
    float utilitati;
    static constexpr float comision= 0.2;
    static const int suma_min=700;


public:
    [[nodiscard]] std::shared_ptr<Cont> clone() const override {
        return std::make_shared <contcurent>(*this);
    }//nu stiu

    contcurent(float abonament_telefon_, float utilitati_);


    virtual ~contcurent() ;

    void afisare(std::ostream &os) const override ;

    //fctie incarcare cartela- odata pe luna, se apeleaza pe 1.
    void plata_abonament();
    void plata_utilitati();

    void extragere(int sumaextr, const std::string monedaextr) ;
    void depunere(int sumadep, const std::string monedadep) ;




};