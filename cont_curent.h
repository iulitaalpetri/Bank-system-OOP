#include <iostream>

#include <string>
#include <utility>
#include <vector>
#include <map>
#include <bits/stdc++.h>
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
    contcurent(int suma_, const std::string &moneda_, const std::string &iban_, const std::shared_ptr<Titular>& titular_, float abonament_telefon_, float utilitati_);

    //destr
    virtual ~contcurent() ;

    //afisare
    void afisare(std::ostream &os) const override ;

    //fctie incarcare cartela- odata pe luna, se apeleaza pe 1.
    void plata_abonament();
    void plata_utilitati();

    void extragere(int sumaextr, std::string monedaextr) override ;
    void depunere(int sumadep, std::string monedadep)  override;
    //clonare
    //[[nodiscard]] std::shared_ptr<Cont> clone() const override;




};