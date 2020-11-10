/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/

#ifndef STK_CONFIG_H
#define STK_CONFIG_H

/*
    Options:
        STK_ENABLE
        STK_DISABLE
*/
#define SYSTICK_STATE           STK_ENABLE
/*
    Options:
        STK_INT_ENABLE
        STK_INT_DISABLE
*/
#if SYSTICK_STATE == STK_ENABLE    
    #define SYSTICK_INTERRUPT       STK_INT_ENABLE
#endif
/*
    Options:
        STK_AHB
        STK_AHB_8
*/
#if SYSTICK_STATE == STK_ENABLE   
    #define SYSTICK_CLK_SOURCE      STK_AHB
#endif


#endif

