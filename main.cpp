#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
using namespace std;

class Titular{
    std::string nume;
    std::string prenume;
    int varsta;
    std::string cnp;
    std::string serie;


public:
    [[nodiscard]] const std::string& getNume() const { return nume; }
    [[nodiscard]] const std::string& getPrenume() const { return prenume;}
    [[nodiscard]] int getvarsta() const { return varsta; }


// constructor
    Titular( std::string  nume_, std::string  prenume_,std::string  cnp_,std::string  serie_, int varsta_):
            nume(std::move(nume_)), prenume(std::move(prenume_)), varsta(varsta_), cnp(std::move(cnp_)),serie(std::move(serie_))  {
        cout<<"constr titular";
    }

    // regula celor 3- constructor copiere, destructor, operator egal
    //constr copiere
    Titular(const Titular& oth): nume{oth.nume},prenume{oth.prenume}, varsta{oth.varsta}, cnp{oth.cnp}, serie{oth.serie}{
        cout<<"constr copiere titular"<<endl;
    }

    // destructor
    ~Titular(){
        cout<<"destructor titular "<<"\n";
    }
    // op copiere
    Titular& operator=(const Titular& oth){
        nume= oth.nume;
        prenume= oth.prenume;
        varsta= oth.varsta;
        cnp= oth.cnp;
        serie= oth.serie;
        cout<<"operator copiere titular"<<endl;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, Titular& titular) {
        os << "Nume: " << titular.nume << ", Prenume: " << titular.prenume <<", varsta:"<<titular.varsta<<"cnp:"<<titular.cnp<<", seria "<<titular.serie<< "\n";
        return os;
    }
    friend ostream& operator<<(ostream& os, const Titular& s);//afisare
    //friend istream& operator>>(istream& os, const Titular& ob);//citire
    // fctie verificare varsta

};



ostream& operator<<(ostream& os, const Titular& s){
    os<<"Nume: "<<s.nume<<"\n";
    return os;}

class Cont {
    double suma;
    std::string moneda;
    std::string iban;
    float ratadobanzii;
    float comision;
    const Titular titular;

public:
    //[[maybe_unused]] [[nodiscard]] const Titular &getTitular() const;

    // constr init
    Cont(const Titular& titular_,int suma_, std::string  moneda_, std::string  iban_, float ratadobanzii_, float comision_) :
             suma(suma_),
            moneda(std::move(moneda_)),
            iban(std::move(iban_)),
            ratadobanzii(ratadobanzii_),
            comision(comision_),titular(titular_)

    {
        cout<<"Constr init cont"<<endl;
        if ( titular_.getvarsta()<18) std::cout<<"Nu isi poate face cont, are nevoie de tutore"<<endl;}



    // operator << si >>
    friend ostream& operator<<(ostream& os, const Cont& cont);//afisare
    //friend istream& operator>>(istream& os, const Cont& ob);//citire

    double& getsuma(){return suma;}


    // metode - 3
    // fctia 1
    void depunere(int sumadep, const std::string& monedadep) {
        std::map<std::pair<std::string, std::string>, double> curs;
        curs[{"lei", "euro"}] = 5;
        curs[{"euro", "lei"}]= 0.2;
        curs[{"lei", "lei"}]= 1;
        curs[{"euro", "euro"}] = 1;
         suma = suma + sumadep * curs[{moneda, monedadep}];
    }
    // fctia 2
    void extragere(double sumaextr, const std::string& monedaextr) {
        std::map<std::pair<std::string, std::string>, double> curs;
        curs[{"lei", "euro"}] = 5;
        curs[{"euro", "lei"}]= 0.2;
        curs[{"lei", "lei"}]= 1;
        curs[{"euro", "euro"}] = 1;
        sumaextr= sumaextr* curs[{moneda, monedaextr}];
        if(suma< sumaextr) std::cout<< "fonduri insuficiente"<<endl;
        else suma= suma- sumaextr;

    }
    // fctia 3
    void tranzactie(  Cont& other_cont, int sumatranz) {
        std::map<std::pair<std::string, std::string>, double> curs;
        curs[{"lei", "euro"}] = 5;
        curs[{"euro", "lei"}]= 0.2;
        curs[{"lei", "lei"}]= 1;
        curs[{"euro", "euro"}] = 1;
        other_cont.suma= other_cont.suma+ sumatranz * curs[{moneda, other_cont.moneda}] ;
        if(sumatranz< 100) std::cout<<"tranzactia nu poate fi realizata, suma prea mica";
        else if(suma< sumatranz) std::cout<<"fonduri insuficiente";
        else {
            suma = suma - sumatranz;
            std::cout << "Tranzactie realizata cu succes. Ati trimis" << sumatranz << "lei catre " <<
                     other_cont.titular.getNume()         << " " << other_cont.titular.getPrenume() <<"."  << endl;
        }


    }



};
ostream& operator<<(ostream& os, const Cont& cont){
    os<<"Suma: "<<cont.suma<<", moneda:"<<cont.moneda<<", iban:"<<cont.iban<<", rata dobanzii:"<<cont.ratadobanzii<<", comision"<<cont.comision<<"\n";
    return os;}

//[[maybe_unused]] const Titular &Cont::getTitular() const {
//    return titular;
//}






//friend ostream& operator<<(ostream& os, const A& ob);//afisare
//friend istream& operator>>(istream& os, const A& ob);//citire



class Banca{
    std::string nume;
    std::string sucursala;
    std::vector<Cont> conturi;

public:
    // adauga cont in vector



    //constr init
    Banca(std::string  nume_, std::string  sucursala_, const std::vector<Cont>& conturi_ ): nume(std::move(nume_)), sucursala(std::move(sucursala_)), conturi(conturi_){
        this->conturi= conturi_;
        cout<<"constructor init banca"<<" ";
    }


    friend ostream& operator<<(ostream& os, const Banca& ob);//afisare
    //friend istream& operator>>(istream& os, const Banca& ob);//citire
    static void addcont ( const Cont& cont_, std::vector<Cont> conturile){


        conturile.push_back(cont_);
    }

};
ostream& operator<<(ostream& os, const Banca& ob){
    os<<"Nume: "<<ob.nume<<"\n";
    return os;
}

int main()
{
    Titular t1("Alpetri", "Iulita",  "637621878328", "kz", 19);
    Titular t2("Ureche", "Mara", "53721357216", "kz", 20);
    Titular t3("X", "y", "fugego", "kz", 15);

    Titular t4("X", "y", "dhidvyuh", "kz", 67);
    const Titular& t5= t4;
       Cont c1(t1, 234, "lei", "hgdfuieshfioseh", 4, 5);
    Cont c2(t2, 657, "euro", "hbdfjebh", 6, 4);
    Cont c3(t3, 678, "lei", "evgfyewy", 5, 7);
    Cont c4(t4, 569, "euro", "hbunfbrhv", 4, 8);
    Cont c5( t5, 67, "lei", "jndkjbu", 5, 8);

    c1.depunere(456, "euro");
    cout<<c1.getsuma()<<" ";
    c1.extragere(9000, "euro");
    c1.tranzactie( c2, 101);
    cout<<c1.getsuma()<<endl;
    cout<<c2.getsuma()<<endl;
    std::vector<Cont> conturi;
    Banca b1("Numebanca","sucursala", conturi);
    Banca::addcont(c1, conturi);
    Banca::addcont(c2, conturi);
    std::cout<<b1;
    cout<<endl;
    std::cout<<c1;



    return 0;
}
































