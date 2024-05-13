#ifndef HAL_H
#define HAL_H

/* Aquí inclusión de otros encabezados con definiciones necesarias */

/* Aquí tus definiciones de tipo y constantes */

typedef enum HPin{        //Handle 
    Pin_LED, 
    PinPC13=Pin_LED, //Ambos tienen el mismo valor. Es solo para que se puedan usar los dos nombres
    Pin_NUM_HANDLES
}HPin;

/* Aquí tus prototipos de funciones */

static void habilitarRelojPuertoC(void)  //Static significa que tiene vinculacion interna. No es visible fuera del archivo. 
{  
    RCC->APB2ENR = RCC->APB2ENR or RCC_APCB2ENR_IOPCEN; //Operacion de Máscara
}

//Operaciones para pines

void Pin_ponModoSalida(HPin pin);   // Primer argumento: Puntero a estructura Ó un handle 
                                    // Pone un pin en modod salida

void Pin_ponSalida(HPin pin);  //Pone un pin en modo salida (Modo lento. Push-Pull)

void Pin_ponEstadoBajo (HPin pin);  //Pone el estado del pin en estado bajo. Si el pin esta configurado como entrada
                                    // el buffer de entrada esta desconectado

void Pin_InvierteEstado (HPin pin); // Invierte el estado del pin. Lo pone en 1 si estaba en 0 y viceversa. 

#endif