/*
* <:copyright-BRCM:2013:DUAL/GPL:standard
* 
*    Copyright (c) 2013 Broadcom 
*    All Rights Reserved
* 
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License, version 2, as published by
* the Free Software Foundation (the "GPL").
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* 
* A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
* writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
* Boston, MA 02111-1307, USA.
* 
* :> 
*/

#ifndef _RDPA_EPON_H
#define _RDPA_EPON_H

#include <bdmf_data_types.h>

/** \defgroup eponmanagement EPON Management
 * Objects in this group control EPON-related configuration
 */

/**
 * \defgroup epon EPON MAC Management
 * \ingroup eponmanagement
 * Epon object represent the EPON MAC. By setting its attributes EPON MAC
 * functionality can be controlled. 
 * @{
 */

/** Max number of PHY LLIDs */
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96856) || defined(CONFIG_BCM96855)
#define RDPA_EPON_MAX_PHY_LLID      32
#else
#define RDPA_EPON_MAX_PHY_LLID      24
#endif

#define RDPA_EPON_CONTROL_QUEUE_ID             101

/**
 * - In associate mode, each unicast link has to be associated with a mcast link. 
 * same mcast link can be associated with more than one unicast link. "ulink_map"
 * is a bitmap which records the unicast links associated with the mcast link.
 * - In standalone mode, there is no associatation between unicast link and 
 * mcast link.  so, "ulink_map" is unused.
 * The EPON MAC gets configured only when "enable" will set to "yes". 
 */
typedef struct
{
    uint32_t llid;
    uint32_t ulink_map;
    bdmf_boolean enable;
} rdpa_epon_mcast_link_t;

/**
 * Enable EPON MAC FEC in ds and/or us
 */
typedef struct
{
    bdmf_boolean ds;
    bdmf_boolean us;
} rdpa_epon_fec_enable_t;

/**
  * Tx Laser mode
  */
typedef enum
{
    rdpa_epon_laser_tx_off,
    rdpa_epon_laser_tx_burst,
    rdpa_epon_laser_tx_continuous
} rdpa_epon_laser_tx_mode;

/** Epon link MPCP regitration state */
typedef enum
{
    rdpa_epon_link_unregistered,
    rdpa_epon_link_registering,
    rdpa_epon_link_awaiting_register,
    rdpa_epon_link_in_service,
    rdpa_epon_link_awaiting_gate
} rdpa_epon_link_mpcp_state;

/** Epon holdover flags */
typedef enum
{
    rdpa_epon_holdover_noflags = 0,
    rdpa_epon_holdover_rerange = 1
} rdpa_epon_holdover_flags;

/**
 * EPON Holdover
 */
typedef struct 
{
    uint16_t time;
    rdpa_epon_holdover_flags flags;
}__attribute__((__packed__)) rdpa_epon_holdover_t;

/** EPON Rate */
typedef enum
{
    rdpa_epon_rate_1g1g,            /**< epon rate 1_1 */ 
    rdpa_epon_rate_2g1g,            /**< epon rate 2_1 */ 
    rdpa_epon_rate_10g1g,            /**< epon rate 10_1 */ 
    rdpa_epon_rate_10g10g            /**< epon rate 10_10 */ 
} rdpa_epon_rate;

/** Epon assign mcast operation */
typedef enum {
    rdpa_epon_mcast_associate_get = 0,
    rdpa_epon_mcast_standalone_get,
    rdpa_epon_mcast_associate_set,
    rdpa_epon_mcast_standalone_set,
} rdpa_epon_assign_mcast_op;

typedef struct
{
    uint16_t pon;
    uint16_t gate;
} rdpa_epon_los_t;

/**
 * a burst cap for each transmission priority
 */
typedef struct
{
    uint16_t priority_0;
    uint16_t priority_1;
    uint16_t priority_2;
    uint16_t priority_3;
    uint16_t priority_4;
    uint16_t priority_5;
    uint16_t priority_6;
    uint16_t priority_7;
} rdpa_epon_burst_cap_per_priority_t;


/** @} end of epon Doxygen group */

/** @} end of eponmanagement Doxygen group */


#endif //_RDPA_EPON_H

