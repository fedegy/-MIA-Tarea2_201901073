#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "scanner.h"
#include "parser.h"
#include "nodo.h"
#include <sys/stat.h>
#include <fstream>
#include <string.h>

using namespace std;

extern int yyparser();
extern Nodo *com;
void leerEntrada(char*);

void exec();

int main()
{
    exec();
}

void exec(){
    string exec;
    string path;
    cout<<"Ingrese comando exec"<<endl;
    cout<<"> ";
    getline(cin, exec);
    istringstream is(exec);
    while(true){
        if(is.eof()){
            break;
        }
        getline(is, path, '=');
    }

    cout<<path<<endl;

    ifstream fs(path);
    string input;
    string linea;
    while(getline(fs, linea)){
        input += linea + '\n';
    }
    //exec -path=/home/federico/Escritorio/Tarea2_201901073/prueba.sh
    cout<<input;
    YY_BUFFER_STATE buffer = yy_scan_string(input.c_str());
    if(yyparse() == 0){

    }else{
        cout<<"Error"<<endl;
    }
}
