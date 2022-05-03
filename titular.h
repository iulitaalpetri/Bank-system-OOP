#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <memory>

class Titular{
protected:
    int id;// 1 pt pers fizica, 0 pers juridica



    //Titular(const Titular&) = default;

    virtual void afisare(std::ostream& os) const ;


public:

    //clonare
    Titular(const Titular&) = default;

    Titular & operator=(const Titular& t) = default;

    Titular(int  id_);
    friend std::ostream &operator<<(std::ostream &os, const Titular &t);
    Titular();

    //constr copiere
    Titular(const std::shared_ptr<Titular> &other) {
        id= other->id;
    }

    //Titular();
    virtual ~Titular()= default;


    bool isId() const;

//    virtual void verificare( );


    [[nodiscard]] virtual std::shared_ptr<Titular> clone() const ;// clonare

};










