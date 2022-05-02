#pragma once
#include <iostream>
#include <exception>
#include <string>
#include <utility>
#include <vector>
#include <map>


#include <stdexcept>

class eroare_varsta : public std::domain_error{
public:
    eroare_varsta() noexcept;
};

class eroare_suma_cont : public std::domain_error{
public:
    eroare_suma_cont()noexcept;
};

class eroare_cont_curent : public std::domain_error{
public:
    eroare_cont_curent()noexcept;
};


class eroare_fonduri_insuficiente : public std::domain_error{
public:
    eroare_fonduri_insuficiente() noexcept;
};
class eroare_tranzactie : public std::domain_error{
public:
    eroare_tranzactie() noexcept;
};

class eroare_destinatar : public std::domain_error{
public:
    eroare_destinatar() noexcept;
};



