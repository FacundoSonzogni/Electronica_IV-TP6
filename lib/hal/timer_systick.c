#include <stm32f1xx.h>
#include "hal.h"

static volatile uint32_t tiempo;

void Temporizador_inicializa(void){
    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock/1000);
}

uint32_t Temporizador_obtMilisegundos(void){
    return tiempo;
}

void Temporizador_esperaMilis(uint32_t tiempo){
    const uint32_t inicial = tiempo;
    while(tiempo-inicial < tiempo);
}

void Temporizador_Handler(void){
    ++tiempo;
}

