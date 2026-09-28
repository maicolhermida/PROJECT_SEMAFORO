#ifndef INTERSECCION_HPP
#define INTERSECCION_HPP

#include "Semaforo.hpp"

class Interseccion {
    
    public:
        Interseccion(Semaforo& s1, Semaforo& s2, Semaforo& s3, Semaforo& s4, 
        uint32_t tiempoVerde = 5000, uint32_t tiempoAmarillo = 2000);

    void correrCiclo();
    
    [[noreturn]] void run();

    private:
        Semaforo* semaforos_[4];
        uint32_t tiempoVerde;
        uint32_t tiempoAmarillo;

        void ponerTodoEnRojoMenos(int indiceActivo);
        void faseVerde(int indice);
        void faseAmarilla(int indice);
};

#endif