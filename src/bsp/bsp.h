/*
 * bsp.h
 *
 *  Created on: 11 de ago. de 2016
 *      Author: LCSR-AF
 */

#ifndef BSP_BSP_H_
#define BSP_BSP_H_

#include "stdint.h"

#define LEDS_PORT GPIOD

enum{
	LED_VERDE = 0,
	LED_ROJO,
	LED_NARANJA,
	LED_AZUL
}leds;

void BSP_Init(void);

//void led_setBright(uint8_t led, uint8_t value);

uint32_t Get_SW_State(void);
uint32_t Get_SW_State(void);

void led_setBright(uint8_t led, uint8_t value);

#endif /* BSP_BSP_H_ */
