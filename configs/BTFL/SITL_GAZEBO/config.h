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
#define ENABLE_GAZEBO_BRIDGE    1

// Gazebo Iris model uses "props in" motor directions (M0/M3=CW, M1/M2=CCW),
// which is the "reversed" configuration in BF's convention.
#define YAW_MOTORS_REVERSED     1

// Flight plan / GPX waypoint integration with the Gazebo world
#define USE_FLIGHT_PLAN
