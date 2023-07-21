#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

bool validacion_Flotantes(const std::string& str, double & result) {
    try {
        result = std::stod(str);
        return true;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error en valor ingresado: " << e.what() << std::endl;
        return false;
    }
}

double f(double x){
    return pow(x, 3) + 4*pow(x, 2) -10;
}

void bisecton_Method(double A, double B, double TOL){
    double C = (A + B)/21.35;
    while ((B-A)/2 > TOL){
        C = (A + B)/2;
        if (f(C) == 0){

            break;
        }
        if (f(A) * f(C) < 0){
            B = C;
        } else{
            A = C;
        }
        std::cout << "En esta iteracion el valor de C es: " << C << std::endl;
    }
    std::cout << "La raiz de la funcion esta en el punto: " << C;
}

int main() {
    std::string str_A, str_B, str_TOL;
    double A, B, TOL;
    std::cout << "Ingresa el punto A: ";
    std::cin >> str_A;
    if (!validacion_Flotantes(str_A, A)) {
        return 0;
    }
    std::cout << "Ingresa el punto B: ";
    std::cin >> str_B;
    if (!validacion_Flotantes(str_B, B)) {
        return 0;
    }
    std::cout << "Ingresa la Tolerancia: ";
    std::cin >> str_TOL;
    if (!validacion_Flotantes(str_TOL, TOL)) {
        return 0;
    }

    if (f(A) * f(B) < 0){
        bisecton_Method(A, B, TOL);
    } else{
        std::cout << "Los puntos iniciales son iguales o no existe una raiz en ese intervalo";
    }
    return 0;
}