#pragma once
#include <iostream>

#include <string>
#include <utility>
#include <vector>
#include <map>

#include <ctime>
#include <tuple>



class contcurent : public Cont{
    std::vector< std::tuple<std::string , std::string, float> > istoric_tranzactii;
    float abonament_telefon;
    float utilitati;
    static constexpr float comision= 0.2;
    static const int suma_min=700;
    time_t now = time(0);
    tm *local_time = localtime(&now);
    char* date = ctime(&now);


public:
    //constr
    contcurent(float suma_, const std::string &moneda_, std::shared_ptr<Titular> titular_,
               int c, float abonament_telefon_, float utilitati_);

    //destr
    virtual ~contcurent() ;

    //afisare
    void afisare(std::ostream &os) const override ;

    //fctie incarcare cartela- odata pe luna, se apeleaza pe 1.
    void plata_abonament();

    [[maybe_unused]] void plata_utilitati();

    void extragere(int sumaextr, const std::string &monedaextr) override ;
    void depunere(int sumadep, const std::string &monedadep)  override;

    void tranzactie(Cont& other_cont, int sumatranz) override;
    //clonare
    std::shared_ptr<Cont> clone() override{
        return std::make_shared<contcurent>(*this);
    }
    void afisare_istoric();



};