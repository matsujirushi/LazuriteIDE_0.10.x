/* hal.h - HALヘッダファイル
 *
 * Copyright (c) 2015  Communication Technology Inc.,
 * All rights reserved.
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 */


#ifndef _INCLUDE_HAL_H
#define _INCLUDE_HAL_H


#include <stdint.h>


/* タイマー割り込みコントロール関数 HAL_TIMER_enableInterrupt() と
 * HAL_TIMER_disableInterrupt() が定義されている場合はコメントアウト
 */
#define ML7396_HWIF_NOTHAVE_TIMER_DI

/* 戻り値定義
 *  0以上=正常終了, 0未満=異常終了
 */
#define HAL_STATUS_OK             0  /* 正常終了 */
#define HAL_STATUS_ERROR_PARAM   -1  /* パラメータ異常 */
#define HAL_STATUS_ERROR_STATE   -2  /* ステート異常 */
#define HAL_STATUS_ERROR_TIMEOUT -3  /* タイムアウト */

/* pin引数定義
 */
/*
#define HAL_GPIO_CSB    19
#define HAL_GPIO_RESETN 35
#define HAL_GPIO_DMON   30
#define HAL_GPIO_SINTN  15
#define BP3596A_SINTN_IRQNUM	3
*/
#define HAL_GPIO_CSB    6
#define HAL_GPIO_RESETN 7
#define HAL_GPIO_DMON   5
#define HAL_GPIO_SINTN  27
#define BP3596A_SINTN_IRQNUM	3

/* 外部公開関数
 */
// 2015.06.08 Eiichi Saito
#define HAL_delayMicroseconds(v) delay_microseconds((unsigned long)v)

extern int HAL_SPI_setup(void);
extern int HAL_SPI_transfer(const uint8_t *wdata, uint8_t *rdata, uint8_t size);
extern int HAL_GPIO_setup(void);
extern int HAL_GPIO_setValue(uint8_t pin, uint8_t value);
extern int HAL_GPIO_getValue(uint8_t pin, uint8_t *value);
extern int HAL_GPIO_setInterrupt(void (*func)(void));
extern int HAL_GPIO_enableInterrupt(void);
extern int HAL_GPIO_disableInterrupt(void);
extern int HAL_TIMER_setup(void);
extern int HAL_TIMER_start(uint16_t msec, void (*func)(void));
extern int HAL_TIMER_stop(void);
#ifndef ML7396_HWIF_NOTHAVE_TIMER_DI
extern int HAL_TIMER_enableInterrupt(void);
extern int HAL_TIMER_disableInterrupt(void);
#endif  /* #ifndef ML7396_HWIF_NOTHAVE_TIMER_DI */
extern int HAL_TIMER_getTick(uint32_t *tick);
extern int HAL_I2C_setup(void);
extern int HAL_I2C_read(uint8_t daddr, uint8_t addr, uint8_t *data, uint8_t size);
// 2015.12.14 Eiichi Saito: for preference of SubGHz
extern void HAL_EX_enableInterrupt(void);
extern void HAL_EX_disableInterrupt(void);


#endif  /* #ifndef _INCLUDE_HAL_H */
