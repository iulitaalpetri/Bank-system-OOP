#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>

class erori : public std::runtime_error {
public:
    explicit erori(const std::string &arg);
};

class eroare_varsta : public erori {
public:
    explicit eroare_varsta(const std::string &arg);
};



class eroare_suma_cont : public erori{
public:
    explicit eroare_suma_cont(const std::string &arg);
};

class eroare_cont_curent : public erori{
public:
    explicit eroare_cont_curent(const std::string &arg);
};


class eroare_fonduri_insuficiente : public erori{
public:
    explicit eroare_fonduri_insuficiente( const std::string &arg) ;
};
class eroare_tranzactie : public erori{
public:
    explicit eroare_tranzactie(const std::string &arg) ;
};




