
<<<<<<< HEAD
// Si no apreto boton los leds se van encendiendo en un sentido, si apreto boton los leds se apagan en el otro sentido
=======
// Si no apreto el boton los leds se van encendiendo de a uno hacia un lado cuando se encendieron todos se apagan todos y se repite,
// si apreto el boton los leds se van apagando para el otro lado cuando se apagaron todos se encienden todos y se repite
>>>>>>> 7b7cc2e5ef284f86b8cdcda586f2d108a69fcd20

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
