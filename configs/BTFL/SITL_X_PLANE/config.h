/*
 * This file is part of Betaflight.
 *
 * Betaflight is free software. You can redistribute this software
 * and/or modify this software under the terms of the GNU General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later
 * version.
 *
 * Betaflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define FC_TARGET_MCU       SITL

#define BOARD_NAME          SITL_X_PLANE
#define MANUFACTURER_ID     BTFL

// Legacy SITL bridge interface used by the X-Plane bridge
// (https://github.com/demvlad/BF-SITL-X-Plane-Bridge):
//   - quaternion sent body-to-world directly
//   - gyro Z negated
//   - GPS position used directly (no origin mirror)
//   - barometric pressure read from fdm_packet
#define ENABLE_GAZEBO_BRIDGE    0

// X-Plane bridge does not push UDP RC packets; default to MSP RX over the
// TCP-emulated UART so Configurator / test harnesses can drive RC channels.
#define DEFAULT_RX_FEATURE      FEATURE_RX_MSP
