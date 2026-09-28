#ifndef SEMAFORO_HPP
#define SEMAFORO_HPP

#include "main.h"
#include "Display7Segmentos.hpp"

enum class ColorSemaforo {
    ROJO,
    AMARILLO,
    VERDE,
    APAGADO
};

class Semaforo {
    public:
        Semaforo(
             GPIO_TypeDef* puertoRojo, uint16_t pinRojo,
             GPIO_TypeDef* puertoAmarillo, uint16_t pinAmarillo,
             GPIO_TypeDef* puertoVerde, uint16_t pinVerde,
             Display7Segmentos* display = nullptr);

        void setColor(ColorSemaforo color);
        bool tieneDisplay() const;
        void contarRegresivo(uint32_t desde, uint32_t intervaloMs = 1000);

    private:
        GPIO_TypeDef* puertoRojo;
        uint16_t pinRojo;
        GPIO_TypeDef* puertoAmarillo;
        uint16_t pinAmarillo;
        GPIO_TypeDef* puertoVerde;
        uint16_t pinVerde;    
        Display7Segmentos* display_;

};

#endif // SEMAFORO_HPP