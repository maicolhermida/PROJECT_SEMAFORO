// Core/Inc/Display7Segmentos.hpp
#ifndef DISPLAY_7_SEGMENTOS_HPP
#define DISPLAY_7_SEGMENTOS_HPP

#include "main.h"

class Display7Segmentos {
public:
    // Orden de pines: a, b, c, d, e, f, g
    Display7Segmentos(GPIO_TypeDef* portA, uint16_t pinA,
                       GPIO_TypeDef* portB, uint16_t pinB,
                       GPIO_TypeDef* portC, uint16_t pinC,
                       GPIO_TypeDef* portD, uint16_t pinD,
                       GPIO_TypeDef* portE, uint16_t pinE,
                       GPIO_TypeDef* portF, uint16_t pinF,
                       GPIO_TypeDef* portG, uint16_t pinG,
                       bool activoEnAlto = true); 

    void mostrarNumero(uint8_t numero);
    void apagar();

private:
    struct Segmento {
        GPIO_TypeDef* port;
        uint16_t      pin;
    };

    Segmento segmentos_[7];
    bool  activoEnAlto_;

    void escribirSegmento(int indice, bool encendido);
};

#endif // DISPLAY_7_SEGMENTOS_HPP