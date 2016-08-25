// Si no apreto boton los leds se van encendiendo en un sentido, si apreto boton los leds se apagan en el otro sentido

#include "bsp/bsp.h"

void APP_1ms(void);

#define INCREASE 1
#define DECREASE 0

uint8_t brightness = 0;		// Brillo
uint16_t counter = 0;
uint8_t color = 1;
uint8_t cambio = 0;

int main(void) {

	BSP_Init();

	led_setBright(LED_ROJO, 0);
	led_setBright(LED_AZUL, 0);
	led_setBright(LED_VERDE, 0);
	led_setBright(LED_NARANJA, 0);

	while (1)
	{
		if(cambio == 1)
		{
			cambio = 2;
			if(Get_SW_State() == 0)	// Lee Boton
			{
				if (brightness < 50)
				{
					brightness ++;
				}
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

		if(cambio == 2)
		{
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
			cambio = 0;
		}
	}
}

void APP_1ms(void)
{
	if((counter == 10)&&(cambio == 0))
	{
		cambio  = 1;
		counter = 0;
	}
	counter++;
}
