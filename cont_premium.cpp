#include "cont_premium.h"


cont_premium::cont_premium(int &suma_,  std::string &moneda_,  std::string &iban_, Titular& titular_int, int &taxa_init_):Cont(int suma_,  std::string moneda_,  std::string iban_, Titular& titular_), taxa_init(taxa_init_) {
    if(suma< suma_min) throw eroare_suma_cont();
    else suma= suma- taxa_init_;

}
cont_premium::cont_premium() {}


void cont_premium::depunere(int sumadep, const std::string monedadep) {

    suma = suma + sumadep * curs[{moneda, monedadep}];
}



void cont_premium::extragere(int sumaextr, const std::string monedaextr) {

    sumaextr= sumaextr* curs[{moneda, monedaextr}];
    if(suma< sumaextr) throw eroare_fonduri_insuficiente();
    else suma= suma- sumaextr;

}
void cont_premium::tranzactie(Cont &other_cont, int sumatranz) {
    {

        other_cont.getsuma()= other_cont.getsuma()+ sumatranz * curs[{moneda, other_cont.getmoneda()}] ;
        if(sumatranz< 100) throw eroare_tranzactie();
        else if(suma< sumatranz) throw eroare_fonduri_insuficiente();
        else {
            suma = suma - sumatranz;
            std::cout << "Tranzactie realizata cu succes. Ati trimis" << sumatranz << "lei catre contul cu iban:" <<
                      other_cont.getIban()<<"."  << std::endl;}}}




std::shared_ptr<Cont> cont_premium::clone() const {
    std::cout<<"Clonare_cont\n";
    return std::make_shared<cont_premium>(*this);
}