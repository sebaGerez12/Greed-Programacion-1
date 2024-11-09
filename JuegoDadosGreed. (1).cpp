#include "Funciones h Greed.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "rlutil.h"
using namespace std;

int main() {
    srand(time(0)); // Semilla para números aleatorios
    rlutil::locate(50,5);
    mostrarMenu();
    return 0;
}

