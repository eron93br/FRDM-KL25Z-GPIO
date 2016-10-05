/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "MKL25Z4.h"
#include "gpio.h"

int main(void)
{
	uint32_t i = 0;
	uint8_t led = 0;

	gpio_direction(PORT_B,18,OUTPUT,NO_PULL_RESISTOR); // Inicializa IO PTB18 - LED Vermelho
	gpio_direction(PORT_B,19,OUTPUT,NO_PULL_RESISTOR); // Inicializa IO PTB19 - LED Verde
	gpio_direction(PORT_D,1, OUTPUT,NO_PULL_RESISTOR); // Inicializa IO PTB18 - LED Azul

	gpio_set(PORT_B,18,HIGH); // Apaga LED Vermelho
	gpio_set(PORT_B,19,HIGH); // Apaga LED Verde
	gpio_set(PORT_D,1, HIGH); // Apaga LED Azul

	for(;;)
	{
		switch(led)
		{
			case 0:
				//gpio_toggle(PORT_D,1);  // Inverte valor do IO
				gpio_toggle(PORT_B,18);	// Inverte valor do IO
				led = 1;
			break;

			case 1:
				gpio_toggle(PORT_B,18);	// Inverte valor do IO
				led = 2;
			break;

			case 2:
				//gpio_toggle(PORT_B,18);	// Inverte valor do IO
				gpio_toggle(PORT_B,19); // Inverte valor do IO
				led = 3;
			break;

			case 3:
				gpio_toggle(PORT_B,19); // Inverte valor do IO
				led = 4;
			break;

			case 4:
				//gpio_toggle(PORT_B,19); // Inverte valor do IO
				gpio_toggle(PORT_D,1);  // Inverte valor do IO
				led = 5;
			break;

			case 5:
				//gpio_toggle(PORT_B,19); // Inverte valor do IO
				gpio_toggle(PORT_D,1);  // Inverte valor do IO
				led = 0;
			break;
		}
		for(i=0;i<250000;i++);
	}
}
