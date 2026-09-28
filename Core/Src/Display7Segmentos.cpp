// Core/Src/Display7Segmentos.cpp
#include "Display7Segmentos.hpp"

Display7Segmentos::Display7Segmentos(GPIO_TypeDef* portA, uint16_t pinA,
                                      GPIO_TypeDef* portB, uint16_t pinB,
                                      GPIO_TypeDef* portC, uint16_t pinC,
                                      GPIO_TypeDef* portD, uint16_t pinD,
                                      GPIO_TypeDef* portE, uint16_t pinE,
                                      GPIO_TypeDef* portF, uint16_t pinF,
                                      GPIO_TypeDef* portG, uint16_t pinG,
                                      bool activoEnAlto)
    : segmentos_{ {portA, pinA}, {portB, pinB}, {portC, pinC},
                  {portD, pinD}, {portE, pinE}, {portF, pinF}, {portG, pinG} },
      activoEnAlto_(activoEnAlto)
{
}

void Display7Segmentos::escribirSegmento(int indice, bool encendido)
{
    bool nivelAlto = activoEnAlto_ ? encendido : !encendido;
    HAL_GPIO_WritePin(segmentos_[indice].port, segmentos_[indice].pin,
                       nivelAlto ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void Display7Segmentos::mostrarNumero(uint8_t numero)
{
    static const uint8_t patrones[10] = {
        0x3F, // 0
        0x06, // 1
        0x5B, // 2
        0x4F, // 3
        0x66, // 4. 
        0x6D, // 5
        0x7D, // 6
        0x07, // 7
        0x7F, // 8
        0x6F  // 9
    };

    if (numero > 9) return;

    uint8_t patron = patrones[numero];
    for (int i = 0; i < 7; ++i)
    {
        bool encendido = (patron >> i) & 0x01;
        escribirSegmento(i, encendido);
    }
}

void Display7Segmentos::apagar()
{
    for (int i = 0; i < 7; ++i)
    {
        escribirSegmento(i, false);
    }
}
