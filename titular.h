#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <memory>

class Titular{
protected:
    bool id;// 1 pt pers fizica, 0 pers juridica
public:
    Titular(bool id);

protected:
    //Titular(const Titular&) = default;
    Titular& operator=(const Titular&) = default;//op =
    virtual void afisare(std::ostream& os) const ;
public:
    friend std::ostream &operator<<(std::ostream &os, const Titular &t);
    Titular();

    //Titular();
    virtual ~Titular()= default;


    bool isId() const;

//    virtual void verificare( );


    virtual std::shared_ptr<Titular> clone() const;// pointer ca sa facem pt constr copiere direct copia poinerului la casa de baza

};










