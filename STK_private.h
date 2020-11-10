/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

#define SYSTICK_BASE_ADDRESS    0xE000E010

#define STK_CTRL        *((uint32_t *)(SYSTICK_BASE_ADDRESS + 0x00))
#define STK_LOAD        *((uint32_t *)(SYSTICK_BASE_ADDRESS + 0x04))
#define STK_VAL         *((uint32_t *)(SYSTICK_BASE_ADDRESS + 0x08))
#define STK_CALIB       *((uint32_t *)(SYSTICK_BASE_ADDRESS + 0x0C))


#define STK_AHB             0
#define STK_AHB_8           1
#define STK_ENABLE          1
#define STK_DISABLE         0
#define STK_INT_ENABLE      1
#define STK_INT_DISABLE     0

#endif