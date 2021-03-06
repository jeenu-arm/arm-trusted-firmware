/*
 * Copyright (c) 2015-2017, ARM Limited and Contributors. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __TEGRA_DEF_H__
#define __TEGRA_DEF_H__

#include <platform_def.h>

/*******************************************************************************
 * Power down state IDs
 ******************************************************************************/
#define PSTATE_ID_CORE_POWERDN		7
#define PSTATE_ID_CLUSTER_IDLE		16
#define PSTATE_ID_CLUSTER_POWERDN	17
#define PSTATE_ID_SOC_POWERDN		27

/*******************************************************************************
 * This value is used by the PSCI implementation during the `SYSTEM_SUSPEND`
 * call as the `state-id` field in the 'power state' parameter.
 ******************************************************************************/
#define PLAT_SYS_SUSPEND_STATE_ID	PSTATE_ID_SOC_POWERDN

/*******************************************************************************
 * Platform power states (used by PSCI framework)
 *
 * - PLAT_MAX_RET_STATE should be less than lowest PSTATE_ID
 * - PLAT_MAX_OFF_STATE should be greater than the highest PSTATE_ID
 ******************************************************************************/
#define PLAT_MAX_RET_STATE		1
#define PLAT_MAX_OFF_STATE		(PSTATE_ID_SOC_POWERDN + 1)

/*******************************************************************************
 * GIC memory map
 ******************************************************************************/
#define TEGRA_GICD_BASE			0x50041000
#define TEGRA_GICC_BASE			0x50042000

/*******************************************************************************
 * Tegra Memory Select Switch Controller constants
 ******************************************************************************/
#define TEGRA_MSELECT_BASE		0x50060000

#define MSELECT_CONFIG			0x0
#define ENABLE_WRAP_INCR_MASTER2_BIT	(1 << 29)
#define ENABLE_WRAP_INCR_MASTER1_BIT	(1 << 28)
#define ENABLE_WRAP_INCR_MASTER0_BIT	(1 << 27)
#define UNSUPPORTED_TX_ERR_MASTER2_BIT	(1 << 25)
#define UNSUPPORTED_TX_ERR_MASTER1_BIT	(1 << 24)
#define ENABLE_UNSUP_TX_ERRORS		(UNSUPPORTED_TX_ERR_MASTER2_BIT | \
					 UNSUPPORTED_TX_ERR_MASTER1_BIT)
#define ENABLE_WRAP_TO_INCR_BURSTS	(ENABLE_WRAP_INCR_MASTER2_BIT | \
					 ENABLE_WRAP_INCR_MASTER1_BIT | \
					 ENABLE_WRAP_INCR_MASTER0_BIT)

/*******************************************************************************
 * Tegra micro-seconds timer constants
 ******************************************************************************/
#define TEGRA_TMRUS_BASE		0x60005010
#define TEGRA_TMRUS_SIZE		0x1000

/*******************************************************************************
 * Tegra Clock and Reset Controller constants
 ******************************************************************************/
#define TEGRA_CAR_RESET_BASE		0x60006000

/*******************************************************************************
 * Tegra Flow Controller constants
 ******************************************************************************/
#define TEGRA_FLOWCTRL_BASE		0x60007000

/*******************************************************************************
 * Tegra Secure Boot Controller constants
 ******************************************************************************/
#define TEGRA_SB_BASE			0x6000C200

/*******************************************************************************
 * Tegra Exception Vectors constants
 ******************************************************************************/
#define TEGRA_EVP_BASE			0x6000F000

/*******************************************************************************
 * Tegra Miscellaneous register constants
 ******************************************************************************/
#define TEGRA_MISC_BASE			0x70000000
#define  HARDWARE_REVISION_OFFSET	0x804

/*******************************************************************************
 * Tegra UART controller base addresses
 ******************************************************************************/
#define TEGRA_UARTA_BASE		0x70006000
#define TEGRA_UARTB_BASE		0x70006040
#define TEGRA_UARTC_BASE		0x70006200
#define TEGRA_UARTD_BASE		0x70006300
#define TEGRA_UARTE_BASE		0x70006400

/*******************************************************************************
 * Tegra Power Mgmt Controller constants
 ******************************************************************************/
#define TEGRA_PMC_BASE			0x7000E400

/*******************************************************************************
 * Tegra Memory Controller constants
 ******************************************************************************/
#define TEGRA_MC_BASE			0x70019000

/* TZDRAM carveout configuration registers */
#define MC_SECURITY_CFG0_0		0x70
#define MC_SECURITY_CFG1_0		0x74
#define MC_SECURITY_CFG3_0		0x9BC

/* Video Memory carveout configuration registers */
#define MC_VIDEO_PROTECT_BASE_HI	0x978
#define MC_VIDEO_PROTECT_BASE_LO	0x648
#define MC_VIDEO_PROTECT_SIZE_MB	0x64c

/*******************************************************************************
 * Tegra TZRAM constants
 ******************************************************************************/
#define TEGRA_TZRAM_BASE		0x7C010000
#define TEGRA_TZRAM_SIZE		0x10000

#endif /* __TEGRA_DEF_H__ */
