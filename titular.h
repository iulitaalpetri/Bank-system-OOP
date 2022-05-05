#pragma once

#include <iosfwd>
#include <memory>
#include "pers_juridica.h"
#include "Pers_fizica.h"

class Titular{
protected:
    bool id{};//  true pers fiz, false pers jurid
    //clonare
    Titular(const Titular&) = default;
    Titular & operator=(const Titular& ac) = default;

public:
    //constr default
    Titular();
    //constr init
    explicit Titular(bool id_) ;

    //destr pur
    virtual ~Titular()= 0 ;



    virtual void afisare(std::ostream& os) const ;

    friend std::ostream &operator<<(std::ostream &os, const Titular &t);

    [[nodiscard]] bool isId() const;


    [[nodiscard]] virtual std::shared_ptr<Titular> clone() const = 0; //ptr clasa de baza

};