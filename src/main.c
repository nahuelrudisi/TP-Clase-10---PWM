#include "bsp/bsp.h"

void APP_1ms(void);

#define INCREASE 1
#define DECREASE 0


uint8_t brightness = 0;		// Brillo
uint8_t intensity = 1;		// Intensidad para saber si esta incrementando o decrementando
uint16_t counter = 10;		// Contador de 10 ms

int main(void) {

	BSP_Init();

//	led_setBright(LED_ROJO, 0);
//	led_setBright(LED_AZUL, 0);
//	led_setBright(LED_VERDE, 0);
//	led_setBright(LED_NARANJA, 0);

	while (1) {

		while(!Get_SW_State());	// Lee Boton
		{
			if (!counter){

				if(intensity == INCREASE){
					brightness ++;
						if (brightness >= 100)
							intensity = DECREASE;
				}else{
					brightness --;
					if(!brightness)
						intensity = INCREASE;
				}
				counter = 10;
			}
		}

		led_setBright(LED_ROJO, brightness);
		led_setBright(LED_AZUL, brightness);
		led_setBright(LED_VERDE, brightness);
		led_setBright(LED_NARANJA, brightness);
	}
}

void APP_1ms(void) {

	if(counter){
		counter--;
	}

}
