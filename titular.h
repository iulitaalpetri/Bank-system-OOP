#pragma once

#include <iosfwd>
#include <memory>


class Titular{
protected:
    bool id{};//  true pers fiz, false pers jurid

public:
    //clonare
    virtual std::shared_ptr<Titular> clone()=0;
    //constr default
    Titular();
    //constr init
    explicit Titular(bool id_) ;

    //destr pur
    virtual ~Titular()= 0 ;



    virtual void afisare(std::ostream& os) const ;

    friend std::ostream &operator<<(std::ostream &os, const Titular &t);

    [[nodiscard]] bool isId() const;



};