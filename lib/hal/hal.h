#ifndef HAL_H
#define HAL_H
#include <stdbool.h>
#include <stdint.h>

// DEFINICIONES DE TIPOS Y CONSTANTES:

/**
 * @brief Handle del Pin
 * 
 */
typedef enum HPin{        
    Pin_LED, 
    PinPC13=Pin_LED, //Ambos tienen el mismo valor. Es solo para que se puedan usar los dos nombres
    Pin_NUM_HANDLES
}HPin;

// PROTOTIPOS DE FUNCIONES:

/*Funciones para GPIO*/

void Pin_configuraSalidaLenta(HPin pin);   
void Pin_enAlto (HPin pin);  
void Pin_enBajo (HPin pin);  
bool Pin_consultaEstado (HPin pin); 
void Pin_cambiaEstado (HPin pin);  

/*Funciones para el Temporizador Systick*/

void Temporizador_inicializa(void);
uint32_t Temporizador_obtMilisegundos(void);
void Temporizador_esperaMilis(uint32_t espera);


#endif
