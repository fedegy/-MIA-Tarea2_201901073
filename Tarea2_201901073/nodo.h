#ifndef NODO_H
#define NODO_H
#include "estructura.h"
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

class Nodo
{
public:
    Nodo();
    void mkdisk();
    void crearRaid(Estructura::mbr *disco, string pathD);
    void reporte();
};

#endif // NODO_H
