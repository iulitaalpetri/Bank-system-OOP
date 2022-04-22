#include "exceptii.h"
eroare_varsta::eroare_varsta() noexcept : std::domain_error("Minor, nu isi poate face cont fara un tutore.") {}

eroare_suma_cont::eroare_suma_cont() noexcept : std::domain_error("Suma este prea mica."){}

eroare_fonduri_insuficiente::eroare_fonduri_insuficiente() noexcept : std::domain_error("Fonduri insuficiente"){}

eroare_destinatar::eroare_destinatar() noexcept : std::domain_error("Datele destinatarului nu sunt corecte") {}

eroare_tranzactie::eroare_tranzactie() noexcept: std::domain_error("Suma este prea mica, tranzactoa nu poate fi relaizata."){}
eroare_cont_curent::eroare_cont_curent() noexcept : std::domain_error("O peroana juridica nu poate avea cont curent."){}