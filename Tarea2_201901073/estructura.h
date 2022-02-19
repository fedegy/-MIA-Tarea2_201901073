#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

class Estructura
{
public:
    Estructura();
    typedef struct
    {
        int mbr_tamano = {};
        char mbr_fecha_creacion[25] = {};
        int mbr_dsk_signature = {};
    }mbr;
};
#endif // ESTRUCTURA_H
