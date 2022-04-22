#include "cont_premium.h"


cont_premium::cont_premium(int taxa_init_):taxa_init(taxa_init_) {
    if(suma< suma_min) throw eroare_suma_cont();
    else suma= suma- taxa_init_;

}



void cont_premium::depunere(int sumadep, const std::string monedadep) {
    std::map<std::pair<std::string, std::string>, double> curs;
    curs[{"lei", "euro"}] = 5;
    curs[{"euro", "lei"}]= 0.2;
    curs[{"lei", "lei"}]= 1;
    curs[{"euro", "euro"}] = 1;
    suma = suma + sumadep * curs[{moneda, monedadep}];
}

void cont_premium::extragere(int sumaextr, const std::string monedaextr) {
    std::map<std::pair<std::string, std::string>, double> curs;
    curs[{"lei", "euro"}] = 5;
    curs[{"euro", "lei"}]= 0.2;
    curs[{"lei", "lei"}]= 1;
    curs[{"euro", "euro"}] = 1;
    sumaextr= sumaextr* curs[{moneda, monedaextr}];
    if(suma< sumaextr) throw eroare_fonduri_insuficiente();
    else suma= suma- sumaextr;

}
void cont_premium::tranzactie(Cont &other_cont, int sumatranz) {
    {
        std::map<std::pair<std::string, std::string>, double> curs;
        curs[{"lei", "euro"}] = 5;
        curs[{"euro", "lei"}]= 0.2;
        curs[{"lei", "lei"}]= 1;
        curs[{"euro", "euro"}] = 1;
        other_cont.getsuma()= other_cont.getsuma()+ sumatranz * curs[{moneda, other_cont.getmoneda()}] ;
        if(sumatranz< 100) throw eroare_tranzactie();
        else if(suma< sumatranz) throw eroare_fonduri_insuficiente();
        else {
            suma = suma - sumatranz;
            std::cout << "Tranzactie realizata cu succes. Ati trimis" << sumatranz << "lei catre contul cu iban:" <<
                      other_cont.getIban()<<"."  << std::endl;}}}
