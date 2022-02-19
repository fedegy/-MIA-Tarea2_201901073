#include "nodo.h"

using namespace std;

Nodo::Nodo()
{

}

void Nodo::mkdisk(){
    cout<<"**************** MkDisk 5 M ******************"<<endl;
    //Disco de 5 megabytes
    //1024 Kb
    //1024*1024 Mb
    int tam = 5*1024*1024;
    int tam_seek = tam - 1;

    //Fecha de creación
    char fecha[25];
    time_t hora;
    hora = time(nullptr);
    ctime(&hora);
    strcpy(fecha, ctime(&hora));

    //Numero random
    int numero_random = rand() % (250 - 1);

    Estructura::mbr disk;
    disk.mbr_tamano = tam;
    strcpy(disk.mbr_fecha_creacion, fecha);
    disk.mbr_dsk_signature = numero_random;

    string ruta = "/home/federico/Documentos/GitHub/-MIA-Tarea2_201901073/Tarea2_201901073/Disco.dk";

    FILE *file = fopen(ruta.c_str(), "wb");
    if(file != nullptr){
        fwrite("\0", 1, 1, file);
        fseek(file, tam_seek, SEEK_SET);
        fwrite("\0", 1, 1, file);
        rewind(file);
        fwrite(&disk, sizeof(Estructura::mbr), 1, file);
    }
    fclose(file);
    cout<<"> Se creo disco de 5 Megas"<<endl<<endl;
}

void Nodo::reporte(){
    Estructura::mbr disk;
    string ruta = "/home/federico/Documentos/GitHub/-MIA-Tarea2_201901073/Tarea2_201901073/Disco.dk";
    FILE *file = fopen(ruta.c_str(), "rb");
    if(file != nullptr){
        rewind(file);
        fread(&disk, sizeof(disk), 1, file);
    }
    fclose(file);
    cout<<"*************** Reporte Mkdisk MBR ************************"<<endl;
    cout<<"mbr_tamano: "<<disk.mbr_tamano<<endl;
    cout<<"mbr_fecha_creacion: "<<disk.mbr_fecha_creacion;
    cout<<"mbr_dsk_signature: "<<disk.mbr_dsk_signature<<endl;
    cout<<"***********************************************************"<<endl;
}
