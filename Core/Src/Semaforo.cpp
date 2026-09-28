#include "Semaforo.hpp"

Semaforo::Semaforo(
    GPIO_TypeDef* puertoRojo, uint16_t pinRojo,
    GPIO_TypeDef* puertoAmarillo, uint16_t pinAmarillo,
    GPIO_TypeDef* puertoVerde, uint16_t pinVerde,
    Display7Segmentos* display)
    : puertoRojo(puertoRojo), pinRojo(pinRojo),
     puertoAmarillo(puertoAmarillo)
      , pinAmarillo(pinAmarillo),
      puertoVerde(puertoVerde), pinVerde(pinVerde),
      display_(display) {}


void Semaforo::setColor(ColorSemaforo color) {
    GPIO_PinState estadoRojo = GPIO_PIN_RESET;
    GPIO_PinState estadoAmarillo = GPIO_PIN_RESET;
    GPIO_PinState estadoVerde = GPIO_PIN_RESET;

    switch (color) {
        case ColorSemaforo::ROJO: estadoRojo = GPIO_PIN_SET; break;
        case ColorSemaforo::AMARILLO: estadoAmarillo = GPIO_PIN_SET; break;
        case ColorSemaforo::VERDE: estadoVerde = GPIO_PIN_SET; break;
        case ColorSemaforo::APAGADO: break;
    }

    HAL_GPIO_WritePin(puertoRojo, pinRojo, estadoRojo);
    HAL_GPIO_WritePin(puertoAmarillo, pinAmarillo, estadoAmarillo);
    HAL_GPIO_WritePin(puertoVerde, pinVerde, estadoVerde);
}

bool Semaforo::tieneDisplay() const {
    return display_ != nullptr;
}

void Semaforo::contarRegresivo(uint32_t desde, uint32_t intervaloMs) {

    if (display_ == nullptr) {
        return; // No hay display asociado
    }
    setColor(ColorSemaforo::ROJO);

    for (int i = desde; i > 0; --i) {
        display_->mostrarNumero(static_cast<uint8_t>(i));
        HAL_Delay(intervaloMs);
    }
    display_->apagar();
}