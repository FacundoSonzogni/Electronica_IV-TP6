#include "hal.h"

int main(void)
{
    Temporizador_inicializa();
    Pin_configuraSalidaLenta(Pin_LED);
    Pin_enAlto(Pin_LED);
    for(;;)
    {
        Temporizador_esperaMilis(500);
        Pin_cambiaEstado(Pin_LED);
    }

    return 0;
}