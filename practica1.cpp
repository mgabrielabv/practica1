#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string>

using namespace std;

int main(){
    struct stat info;
    if (stat("data", &info) != 0) { 
        mkdir("data");  
    }
     ofstream archivo("data/personas.txt");
    if (!archivo) {
        cerr << "Error creando el archivo!" << endl;
        return 1;
    }

    int N;
    cout<< "ingrese el numero de registros:  ";
    cin>>  N ;
    cin.ignore();

    for (int i = 0; i < N; i++)
    {
        string nombre, cedula, correo;
        cout<< "ingrese el nombre:  ";
        getline (cin, nombre);
        cout<< "ingrese cedula:";
        getline(cin, cedula);
        cout<< "ingrese el correo:  ";
        getline(cin, correo);

        archivo<< nombre<< "" << cedula << "" << correo<< "\n";
    }
    archivo.close();
    cout<< " los registros se encuentran en personas.txt "<< endl;
    return 0;
    
}