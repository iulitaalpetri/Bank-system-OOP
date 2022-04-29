#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "titular.h"
#include "titular.cpp"
//de adaugat pointeri
class pers_fizica:public Titular{
    std::string nume;
    std::string prenume;
    int varsta;
    std::string cnp;
public:

    [[nodiscard]] std::shared_ptr<Titular> clone() const override {
        return std::make_shared <pers_fizica>(*this);
    }
    pers_fizica();
    explicit pers_fizica(std::string nume_, std::string prenume_, int varsta_, std::string cnp_);
    void afisare(std::ostream &os) const override;
    ~pers_fizica() override;
//    virtual void verificare() override;// fac fctia verificare direct in cls der

    const std::string &getNume() const;

    const std::string &getPrenume() const;

    int getVarsta() const;

    const std::string &getCnp() const;


};