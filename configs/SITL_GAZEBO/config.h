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

#define BOARD_NAME          SITL_GAZEBO
#define MANUFACTURER_ID     BTFL

// Gazebo Harmonic (BetaflightPlugin) bridge:
//   - quaternion pre-multiplied by Rz(π/2)
//   - gyro Z kept positive (FRD frame from sensor)
//   - GPS position mirrored around spawn origin
//   - barometric pressure derived from altitude (plugin doesn't supply pressure)
//   - YAW_MOTORS_REVERSED for Iris "props in" model
//   - flight plan / GPX integration enabled
#define SITL_BRIDGE_GAZEBO  1
