#include <iostream>

using namespace std;

class Vehiculo {
    protected:
        string numeroPlaca;
        string color;
        string marca;
        double velocimetro;

    public:
        Vehiculo(string, string, string, double);
        void mostrarDatos();
        void cambiarVelocidad(double);
};

class Automovil : public Vehiculo{
    private:
        int cantidadPuertas;
        int cantidadPasajeros;

    public:
    Automovil(string, string, string, double, int, int);
    void mostrarAutomovil();
    void subirPasajeros(int);
    void bajarPasajeros(int);
};

class Camion : public Vehiculo{
    private:
        double carga;

    public:
        Camion(string, string, string, double, double);
        void mostrarCamion();
        void cambiarCarga(double);
};

int main() {
    Automovil a1("19902", "Blanco", "Susuki", 125.2, 2, 50);
    Camion c1("88145", "Rojo", "Volvo", 80.2, 5000);

    cout << "Datos del Automovil" << endl;
    a1.mostrarAutomovil();
    cout << endl;
    cout << "Datos del Camion" << endl;
    c1.mostrarCamion();

    a1.cambiarVelocidad(50.6);
    a1.bajarPasajeros(12);
    a1.subirPasajeros(3);

    c1.cambiarVelocidad(60.6);
    c1.cambiarCarga(7855);

    cout << endl;
    cout << "Datos actualizados" << endl;
    cout << "Datos del Automovil" << endl;
    a1.mostrarAutomovil();
    cout << endl;
    cout << "Datos del Camion" << endl;
    c1.mostrarCamion();

    return 0;
}

Vehiculo :: Vehiculo(string P, string C, string M, double V) {
    numeroPlaca = P;
    color = C;
    marca = M;
    velocimetro = V;
}

void Vehiculo :: mostrarDatos() {
    cout << "Numero de placa: " << numeroPlaca << endl;
    cout << "Color: " << color << endl;
    cout << "Marca: " << marca << endl;
    cout << "Velocimetro: " << velocimetro << " km/h" << endl;
}

void Vehiculo :: cambiarVelocidad(double V) {
    velocimetro = V;
}

Automovil :: Automovil(string P, string C, string M, double V, int Pu, int Pa) : Vehiculo(P, C, M, V) {
    cantidadPuertas = Pu;
    cantidadPasajeros = Pa;
}

void Automovil :: mostrarAutomovil() {
    mostrarDatos();
    cout << "Puertas: " << cantidadPuertas << endl;
    cout << "Pasajeros:" << cantidadPasajeros << endl;
}

void Automovil :: subirPasajeros(int n) {
    cantidadPasajeros += n;
}

void Automovil :: bajarPasajeros(int n) {
    cantidadPasajeros -= n;
}

Camion :: Camion(string P, string C, string M, double V, double Ca) : Vehiculo(P, C, M, V) {
    carga = Ca;
}

void Camion :: mostrarCamion() {
    mostrarDatos();
    cout << "Carga: " << carga << " kg" << endl;
}

void Camion :: cambiarCarga(double C) {
    carga = C;
}