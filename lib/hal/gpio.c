#include <stm32f1xx.h>
#include "hal.h"

/*Se debe diseñar una funcion que habilite el reloj de manera interna que 
no debe ser visible en otras partes del programa. se debe añadir el especificador "static":*/

static void habilitarRelojPuertoC(void)  //Static significa que tiene vinculacion interna. No es visible fuera del archivo. 
{  
    RCC->APB2ENR = RCC->APB2ENR or RCC_APCB2ENR_IOPCEN; //Operacion de Máscara
}

typedef struct Pin{ 
    GPIO_TypeDef* puerto;   // Punteri a los registros del puerto
    int pin;                // Numero de Pin
    void (*habilitaReloj)(void);  //Puntero a funcion
}Pin;

// Tabla de descriptores de pin (en ROM)
static const Pin descriptores [Pin_NUM_HANDLES]={
    [Pin_LED] = {.puerto=GPIOC, .pin=13, habilitaReloj=habilitarRelojPuertoC}
}

//Funciones de operacion

void Pin_ponModoSalida(HPin pin)ç
{
//COMPLETAR 
}

void Pin_ponSalida(HPin pin)
{
    enum{MODO_SALIDA = 0b0010};
    if (pin >= Pin_NUM_HANDLES) return;
    const Pin *desc = descriptores + pin; // &descriptores[pin]

    desc->habilitaReloj();

    const int offset = ((desc->pin % 8) * 4)
    const uint32_t mascaraReset = 0xF << offset;
    const uint32_t mascaraSet = MODO_SALIDA << offset;

// COMPLETAR 
    if(desc->pin <8){
        desc->puerto
    }
}

void Pin_ponEstadoBajo (HPin pin)
{
    if (pin >= Pin_NUM_HANDLES) return;
    const Pin *desc = descriptores + pin; // &descriptores[pin]

    desc->puerto->BRR = 1 << desc->pin;
}  

void Pin_InvierteEstado (HPin pin)
{
// COMPLETAR 
} 