#pragma once
#include "titular.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>

//nu poate face cont curent
class pers_juridica:public Titular{
    std::string nume_reprezentant;
    std::string prenume_reprezentant;
    std::string nume_firma;
public:
    //clonare
    [[nodiscard]] std::shared_ptr<Titular> clone() const override;

    explicit pers_juridica(int id_, const std::string &nume_reprezentant_, const std::string &prenume_reprezentant_ , const std::string &nume_firma_);
    virtual ~pers_juridica();
    void afisare(std::ostream &os) const override;


    const std::string &getnume_firma() const;
    //std::unique_ptr<Titular> clone() const override;// copiere

};