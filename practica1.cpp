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
        string nombre, correo;
        float cedula;

        cout<< "ingrese el nombre:  ";
        getline (cin, nombre);
        cout<< "ingrese cedula:";
        cin>> cedula;
        cin.ignore();
        cout<< "ingrese el correo:  ";
        getline(cin, correo);

        archivo<< nombre<< "  " << cedula << "  " << correo<< " \n";
    }
    archivo.close();
    cout<< " los registros se encuentran en personas.txt "<< endl;

    ifstream archivoLectura("data/personas.txt");
    if (!archivoLectura) {
        cerr << "Error abriendo el archivo para lectura!" << endl;
        return 1;
    }

    string nombre;
    float cedula;
    string correo;

    cout << "\nRegistro de personas:\n";
    while (archivoLectura >> nombre >> cedula) {
        archivoLectura.ignore(); 
        getline(archivoLectura, correo); 
        cout << "Mi nombre es " << nombre << ", número de cédula: " 
             << cedula << ", mi correo es " << correo << endl;
    }

    archivoLectura.close();
    return 0;
    
}