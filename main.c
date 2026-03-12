#include"LIB/BIT_MATH.h"
#include"LIB/STD_TYPES.h"
#include"MCAL/GPIO/GPIO_int.h"
#include"MCAL/GPIO/GPIO_cfg.h"
#include"MCAL/SYSTICK/SYSTICK_int.h"
#include"MCAL/RCC/RCC_int.h"
#include"HAL/7_SEGMENT/7_SEGMENT.h"



int main(int argc, char* argv[])
{

	MRCC_vInit();
	MRCC_vEnableClk(RCC_AHB1, RCC_GPIOA);
	MGPIO_vSetMode(GPIO_PORTA, GPIO_PIN7, GPIO_MODE_INPUT);
	MGPIO_vSetPULLType(GPIO_PORTA, GPIO_PIN7, GPIO_PULL_DOWN);

	Segment_int();
	MSYSTICK_Config_t timo={
			INT_ENABLE,
			CLK_SRC_AHB_8
	};
	 MSYSTICK_vInit(&timo);

	//void MSYSTICK_vStartTimer(u32 A_u32LoadValue);
	//void MSYSTICK_vStopTimer(void);
	 while(1)
	 {
			for(int i=0;i<10;i++)
			{

				segment_show(i);

				MSYSTICK_vSetDelay_ms(2000);
			}
			Segment_Disable();
	 }


	//u32 MSYSTICK_u32GetElapsedTime_SingleShot(void);
	//u32 MSYSTICK_u32GetRemainingTime_SingleShot(void);

	//void MSYSTICK_vSetInterval_Single(u32 A_u32Delay_ms, void(*A_xFptr)(void));
//	void MSYSTICK_vSetInterval_Multi(u32 A_u32Delay_ms, void(*A_xFptr)(void));










	return 0;
}


