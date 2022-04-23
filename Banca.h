#include "cont.h"
class Banca{
    std::string nume;
    [[maybe_unused]] std::string sucursala;
    static Banca* bank;
    [[maybe_unused]] std::vector<std::shared_ptr<Cont>> conturi;

public:

    Banca(std::string  nume_, std::string  sucursala_, std::vector <std::shared_ptr <Cont>> conturi_ ): nume(std::move(nume_)), sucursala(std::move(sucursala_)), conturi(std::move (conturi_)){

        std::cout<<"constructor init banca"<<" ";
    }
    Banca(){};

    static Banca* getBank(){
        if(bank == nullptr){
            bank = new Banca();
        }
        return bank;
    }// daca n am o banca nu pot face nimic


    friend std::ostream& operator<<(std::ostream& os, const Banca& ob);//afisare
    //friend istream& operator>>(istream& os, const Banca& ob);//citire
    void addCont(Cont& cont) {
        conturi.emplace_back(cont.clone());
    }

    Banca(const Banca& other) {
        for(const auto& cont : other.conturi)
            conturi.push_back(static_cast<const std::shared_ptr<Cont>>(cont->clone()));
    }
    friend void swap(Banca& b1, Banca& b2) {
        using std::swap;
        swap(b1.conturi, b2.conturi);

    }

    Banca& operator=(const Banca& other) {
        auto copie{other};
        swap(copie, *this);
        return *this;
    }



};

std::ostream& operator<<(std::ostream& os, const Banca& ob){
    os<<"Nume: "<<ob.nume<<"\n";
    return os;
}