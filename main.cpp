
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "Banca.h"
#include "cont_curent.h"
#include "cont.h"
#include "titular.h"
#include "pers_juridica.h"
#include "Pers_fizica.h"
#include "exceptii.h"
using namespace std;


int main() {

    try {
        Banca *b;
        Cont *c1 = new contcurent();
        Titular *t = new pers_fizica();
    }

    catch (...) {}


}