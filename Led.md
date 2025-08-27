# IMT-222_AlineVides1
#include <iostream>
#include <thread>   // Para sleep
#include <chrono>   // Para usar segundos

using namespace std;

int main() {
    cout << "Programa: Encender 10 LEDs en secuencia con 2s de intervalo" << endl;
    cout << "Autor: Aline Vides" << endl;
    cout << "-----------------------------------------" << endl;

    for (int i = 1; i <= 10; i++) {
        cout << "LED " << i << " encendido" << endl;
        this_thread::sleep_for(chrono::seconds(2)); // Espera 2 segundos
        cout << "LED " << i << " apagado" << endl;
    }

    cout << "Secuencia terminada." << endl;
    return 0;
}
