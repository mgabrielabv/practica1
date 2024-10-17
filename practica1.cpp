#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

int main(){
    filesystem::create_directory("data");
    ofstream archivo("data/personas.txt");
    if (!archivo){
        cerr << "Error  creando el archivo"<< endl;
        return 1;
    }
    archivo.close();
    cout<< "archivo personas.txt se creo en la carpeta 'data'."<< endl;
    return 0;
}