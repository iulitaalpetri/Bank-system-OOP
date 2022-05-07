#include "Banca.h"
Banca::Banca() {}

[[maybe_unused]] Banca::Banca(const std::string &nume_, const std::string &sucursala_, const std::vector<std::shared_ptr<Cont>> &conturi_):
        nume(nume_), sucursala(sucursala_), conturi(conturi_){ std::cout<<"Constr init Banca"; }

std::ostream& operator<<(std::ostream& os, const Banca& ob){
    os<<"Banca: Nume: "<<ob.nume<<"Sucursala:"<<ob.sucursala<<"\n";
    // adauga afis cont- doar iban ul , nume- getter
    return os;
}

//[[maybe_unused]] void Banca::addCont(const Cont& cont) {
//    conturi.emplace_back(cont.clone());
//}

[[maybe_unused]] Banca::Banca(const Banca &other):nume(other.nume), sucursala(other.sucursala), conturi(other.conturi) {
//    conturi.push_back(static_cast<const std::shared_ptr<Cont>>(cont->clone()));
//    for(const auto& cont : other.conturi)
//        conturi.push_back(static_cast<const std::shared_ptr<Cont>>(cont->clone()));
}

Banca &Banca::operator=(const Banca &other) {
    auto copie{other};
    swap(copie, *this);
    return *this;
}

Banca::~Banca() {
    std::cout<<"dstructor banca";
}




