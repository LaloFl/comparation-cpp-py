#include <stdio.h>
#include <iostream>
#include <chrono>

using namespace std;

int main() {
    long long inicio = 0, fin = 0;
    cout << "Números primos en un rango de dos numeros\n";
    cout << "Inicio: ";
    cin >> inicio;
    inicio = inicio < 0 ? 2 : inicio;
    while (fin < inicio) {    
        cout << "Fin: ";
        cin >> fin;
        if (fin < inicio) {
            cout << "El numero final del rango tiene que ser mayor al de inicio\n";
        }
    }

    //inicio = inicio % 2 == 0 ? inicio + 1 : inicio

    auto start = chrono::high_resolution_clock::now();
    // INICIO
    int primosCounter = 0;
    for(long long i = inicio <= 1 ? 2 : inicio; i <= fin; i++) {
        bool esPrimo = true;
        for (long long n = 2; n < i; n++) {
            if (i % n == 0) {
                esPrimo = false;
                break;
            }
        }
        primosCounter += esPrimo ? 1 : 0;
    }
    // FINAL
    auto finish = chrono::high_resolution_clock::now();

    auto ms = chrono::duration_cast<chrono::microseconds>(finish-start);

    cout << ms.count() / 1000 <<"ms\n";
    cout << "Números primos: " << primosCounter << endl;
    return 0;
}