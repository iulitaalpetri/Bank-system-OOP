////
//// Created by iulit on 5/6/2022.
////
//
//#include "template.h"
//
//Banca::Banca() {}
//
//Banca::Banca(const std::string &nume_, const std::string &sucursala_, std::vector<std::shared_ptr<Cont>> conturi_):
//        nume(nume_), sucursala(sucursala_), conturi(conturi_){ std::cout<<"Constr init Banca"; }
//
//std::ostream& operator<<(std::ostream& os, const Banca& ob){
//    os<<"Banca: Nume: "<<ob.nume<<"Sucursala:"<<ob.sucursala<<"\n";
//    // adauga afis cont- doar iban ul , nume- getter
//    return os;
//}
//
//void Banca::addCont(Cont& cont) {
//    conturi.emplace_back(cont.clone());
//}
//
//Banca::Banca(const Banca &other) {
//    nume = other.nume;
//    sucursala= other.sucursala;
//    for(const auto& cont : other.conturi)
//        conturi.push_back(static_cast<const std::shared_ptr<Cont>>(cont->clone()));
//}
//
//Banca &Banca::operator=(const Banca &other) {
//    auto copie{other};
//    swap(copie, *this);
//    return *this;
//}
//
//Banca::~Banca() {
//    std::cout<<"dstructor banca";
//}
//
//
//
//
