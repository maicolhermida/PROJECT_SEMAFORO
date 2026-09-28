#include "App.hpp"
#include "Interseccion.hpp"
#include "Semaforo.hpp"
#include "Display7Segmentos.hpp"

extern "C" void AppRun(void) {
    static Display7Segmentos display1(
        DISP_A_GPIO_Port, DISP_A_Pin,
        DISP_B_GPIO_Port, DISP_B_Pin,
        DISP_C_GPIO_Port, DISP_C_Pin,
        DISP_D_GPIO_Port, DISP_D_Pin,
        DISP_E_GPIO_Port, DISP_E_Pin,
        DISP_FB11_GPIO_Port, DISP_FB11_Pin,
        DISP_GB10_GPIO_Port, DISP_GB10_Pin,
        true); // catodo comun

    static Semaforo semaforo1(
        S1_R_GPIO_Port, S1_R_Pin,
        S1_A_GPIO_Port, S1_A_Pin,
        S1_V_GPIO_Port, S1_V_Pin,
        &display1
    );
    static Semaforo semaforo2(
        S2_R_GPIO_Port, S2_R_Pin,
        S2_A_GPIO_Port, S2_A_Pin,
        S2_V_GPIO_Port, S2_V_Pin
    );
    static Semaforo semaforo3(
        S3_R_GPIO_Port, S3_R_Pin,
        S3_A_GPIO_Port, S3_A_Pin,
        S3_V_GPIO_Port, S3_V_Pin
    );
    static Semaforo semaforo4(
        S4_R_GPIO_Port, S4_R_Pin,
        S4_A_GPIO_Port, S4_A_Pin,
        S4_V_GPIO_Port, S4_V_Pin
    );

    static Interseccion interseccion(semaforo1, semaforo2, semaforo3, semaforo4);
    interseccion.run();
}