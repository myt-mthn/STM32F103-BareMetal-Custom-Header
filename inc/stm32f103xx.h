/*
 * stm32f103xx.h
 * Custom bare-metal header for STM32F103 series
 *
 * Author : MATHAN MG
 * Date   : Nov 2025
 *
 * NOTE:
 * - This header does NOT follow CMSIS.
 * - All register definitions are written manually for learning purposes.
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_

#include <stdint.h>

/* ---------------------------------------------------------
 *  GPIO BASE ADDRESSES (APB2 Bus)
 * ---------------------------------------------------------*/
#define GPIOA_BASEADDR     0x40010800U
#define GPIOB_BASEADDR     0x40010C00U
#define GPIOC_BASEADDR     0x40011000U
#define GPIOD_BASEADDR     0x40011400U
#define GPIOE_BASEADDR     0x40011800U

/* ---------------------------------------------------------
 *  GPIO REGISTER STRUCTURE
 * ---------------------------------------------------------*/
typedef struct
{
    volatile uint32_t CRL;     // Port configuration low register   (0x00)
    volatile uint32_t CRH;     // Port configuration high register  (0x04)
    volatile uint32_t IDR;     // Input data register               (0x08)
    volatile uint32_t ODR;     // Output data register              (0x0C)
    volatile uint32_t BSRR;    // Bit set/reset register            (0x10)
    volatile uint32_t BRR;     // Bit reset register                (0x14)
    volatile uint32_t LCKR;    // Port configuration lock register  (0x18)
} GPIO_RegDef_t;

/* ---------------------------------------------------------
 *  GPIO POINTERS
 * ---------------------------------------------------------*/
#define GPIOA   ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB   ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC   ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD   ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE   ((GPIO_RegDef_t*)GPIOE_BASEADDR)

/* ---------------------------------------------------------
 *  RCC BASE ADDRESS
 * ---------------------------------------------------------*/
#define RCC_BASEADDR        0x40021000U

/* ---------------------------------------------------------
 *  RCC REGISTER STRUCTURE
 * ---------------------------------------------------------*/
typedef struct
{
    volatile uint32_t CR;        // Clock control register
    volatile uint32_t CFGR;      // Clock configuration register
    volatile uint32_t CIR;       // Clock interrupt register
    volatile uint32_t APB2RSTR;  // APB2 peripheral reset register
    volatile uint32_t APB1RSTR;  // APB1 peripheral reset register
    volatile uint32_t AHBENR;    // AHB peripheral clock enable register
    volatile uint32_t APB2ENR;   // APB2 peripheral clock enable register
    volatile uint32_t APB1ENR;   // APB1 peripheral clock enable register
    volatile uint32_t BDCR;      // Backup domain control register
    volatile uint32_t CSR;       // Control/status register
} RCC_RegDef_t;

/* ---------------------------------------------------------
 *  RCC POINTER
 * ---------------------------------------------------------*/
#define RCC     ((RCC_RegDef_t*)RCC_BASEADDR)

/* ---------------------------------------------------------
 *  CLOCK ENABLE MACROS
 * ---------------------------------------------------------*/
#define GPIOA_CLK_EN()     ( RCC->APB2ENR |= (1 << 2) )
#define GPIOB_CLK_EN()     ( RCC->APB2ENR |= (1 << 3) )
#define GPIOC_CLK_EN()     ( RCC->APB2ENR |= (1 << 4) )
#define GPIOD_CLK_EN()     ( RCC->APB2ENR |= (1 << 5) )
#define GPIOE_CLK_EN()     ( RCC->APB2ENR |= (1 << 6) )

#endif /* INC_STM32F103XX_H_ */
