
// Si apreto boton funciona el pwm en todos los leds, se van apagando y encendiendo los leds
// Si suelto el boton los leds quedan con un brillo determinado

#include "bsp/bsp.h"

void APP_1ms(void);

#define INCREASE 1
#define DECREASE 0

uint8_t brightness = 0;		// Brillo
uint16_t counter = 0;
uint8_t color = 1;

int main(void) {

	BSP_Init();

	led_setBright(LED_ROJO, 0);
	led_setBright(LED_AZUL, 0);
	led_setBright(LED_VERDE, 0);
	led_setBright(LED_NARANJA, 0);

	while (1) {	}
}

void APP_1ms(void)
{
	if(counter == 10)
	{
		counter = 0;
		if(Get_SW_State() == 0)	// Lee Boton
		{
			if (brightness < 50)
				brightness ++;
			else
			{
				color++;
				brightness = 0;
			}
		}
		else
		{
			if (brightness > 0)
				brightness --;
			else
			{
				color--;
				brightness = 50;
			}
		}
	}
	switch(color)
	{
		case 0:
				color = 4;
				led_setBright(LED_ROJO, 50);
				led_setBright(LED_AZUL, 50);
				led_setBright(LED_VERDE, 50);
				led_setBright(LED_NARANJA, 50);
		case 1:
				led_setBright(LED_ROJO, brightness);
				break;
		case 2:
				led_setBright(LED_AZUL, brightness);
				break;
		case 3:
				led_setBright(LED_VERDE, brightness);
				break;
		case 4:
				led_setBright(LED_NARANJA, brightness);
				break;
		case 5:
				color=1;
				led_setBright(LED_ROJO, 0);
				led_setBright(LED_AZUL, 0);
				led_setBright(LED_VERDE, 0);
				led_setBright(LED_NARANJA, 0);
		default:
				break;
	}
	counter++;
}
