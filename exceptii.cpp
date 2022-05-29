#include "exceptii.h"
erori::erori(const std::string &arg) : runtime_error(arg) {
    std::cout << "constr err\n";
}

eroare_varsta::eroare_varsta(const std::string &arg) : erori(arg) {}
eroare_suma_cont:: eroare_suma_cont(const std::string &arg) : erori(arg) {}
eroare_cont_curent::eroare_cont_curent(const std::string &arg) : erori(arg) {}
eroare_fonduri_insuficiente:: eroare_fonduri_insuficiente(const std::string &arg) : erori(arg) {}
eroare_tranzactie:: eroare_tranzactie(const std::string &arg) : erori(arg) {}
eroare_account::eroare_account(const std::string &arg): erori(arg) {}


