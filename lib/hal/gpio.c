#include <stm32f1xx.h>
#include "hal.h"

// DEFINICIÓN DE FUNCIONES LOCALES:

static void habilitaRelojPuertoC(void)  
{  
     RCC->APB2ENR = RCC->APB2ENR | RCC_APB2ENR_IOPCEN; //Operacion de Máscara
}

// DEFINICIONES DE TIPOS Y CONSTANTES

/*Definición del Objeto Pim */

typedef struct Pin{ 
    GPIO_TypeDef* puerto;   
    int pin;                
    void (*habilitaReloj)(void);  
}Pin;

/* Tabla de descriptores de pin (en ROM) */

static const Pin descriptores[Pin_NUM_HANDLES]={
    [Pin_LED] = {.puerto=GPIOC, .pin=13, .habilitaReloj=habilitaRelojPuertoC}
};


//DEFINICIÓN DE FUNCIONES EN "hal.h"

void Pin_configuraSalidaLenta(HPin pin)
{
    enum{MODO_SALIDA = 0b0010};
    if (pin >= Pin_NUM_HANDLES) return;
    const Pin *desc = descriptores+pin; // &descriptores[pin]

    desc->habilitaReloj();

    const int offset = ((desc->pin % 8) * 4);
    const uint32_t mascaraReset = 0xF << offset;
    const uint32_t mascaraSet = MODO_SALIDA << offset;

    if (desc->pin < 8){
        desc->puerto->CRL = (desc->puerto->CRL & ~mascaraReset) | mascaraSet;
    }else{
        desc->puerto->CRH = (desc->puerto->CRH & ~mascaraReset) | mascaraSet;
    }    
}

void Pin_enAlto (HPin pin)
{
    if (pin >= Pin_NUM_HANDLES) return;
    const Pin *desc = descriptores + pin; 
    const uint32_t mascaraPin = 1 << desc->pin;
    desc->puerto->BSRR = mascaraPin;
}

void Pin_enBajo (HPin pin)
{
    if (pin >= Pin_NUM_HANDLES) return;
    const Pin *desc = descriptores + pin; 
    const uint32_t mascaraPin = 1 << desc->pin;
    desc->puerto->BRR = mascaraPin;
}  

bool Pin_consultaEstado (HPin pin)
{
    if (pin >= Pin_NUM_HANDLES) return false;
    const Pin *desc = descriptores + pin; 
    const uint32_t mascaraPin = 1 << desc->pin;
    return desc->puerto->ODR & mascaraPin; 
}

void Pin_cambiaEstado (HPin pin)
{
    if (Pin_consultaEstado(pin) == 1){
        Pin_enBajo(pin);
    }else{
        Pin_enAlto(pin);
    }
}