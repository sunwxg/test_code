#ifndef D_LedDriver_H
#define D_LedDriver_H

#include <stdint.h>

void LedDriver_Create(uint16_t * address);
void LedDriver_Destroy(void);

void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn(void);
int LedDriver_IsOn(int ledNumber);
int LedDriver_IsOff(int ledNumber);
void LedDriver_TurnAllOff(void);

#endif /* D_LedDriver_H */
