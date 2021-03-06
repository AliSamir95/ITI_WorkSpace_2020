
#include "STD_TYPES.h"
#include "GPIO.h"
#include "Led.h"
#include "Led_Config.h"


Error_S HLED_Init (void)
{
	Error_S Error_Status = ERROR_OK;

	u8 Leds_Counter = 0;
  
	const LedMap_t* Led_Config = HLED_GetLedConfigurations();

	for ( Leds_Counter =0 ; Leds_Counter < LED_NUMBERS ; Leds_Counter++)
	{
		//GPIO_Init (Led_Config[Leds_Counter]);
		GPIO_Init (Led_Config[Leds_Counter].GPIO_Port, Led_Config[Leds_Counter].GPIO_Pin_Number, GPIO_PIN_DIR_OUTPUT);
	}
	return Error_Status;
}

Error_S HLED_writeLedState (u8 Led_Channel_Number)
{
	Error_S Error_Status = ERROR_OK;

	const LedMap_t* Led_Config = HLED_GetLedConfigurations();
	GPIO_WritePin (Led_Config[Led_Channel_Number].GPIO_Port, Led_Config[Led_Channel_Number].GPIO_Pin_Number, GPIO_PIN_DIR_OUTPUT);

	return Error_Status;
}
