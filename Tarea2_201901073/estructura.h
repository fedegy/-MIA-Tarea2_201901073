#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

class Estructura
{
public:
    Estructura();
    struct mbr
    {
        int mbr_tamano = {};
        char mbr_fecha_creacion[25] = {};
        int mbr_dsk_signature = {};
    };
};
#endif // ESTRUCTURA_H
