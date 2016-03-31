/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// System-wide
typedef struct master_t {
    uint8_t mixerMode;
    uint8_t persistentFlags;

    // Profile configuration
    uint8_t current_profile_index;

    uint16_t looptime;                      // imu loop time in us
    uint8_t gyroSync;                       // Enable interrupt based loop
    uint8_t gyroSyncDenominator;            // Gyro sync Denominator

    flight3DConfig_t flight3DConfig;

    uint16_t dcm_kp_acc;                    // DCM filter proportional gain ( x 10000) for accelerometer
    uint16_t dcm_ki_acc;                    // DCM filter integral gain ( x 10000) for accelerometer
    uint16_t dcm_kp_mag;                    // DCM filter proportional gain ( x 10000) for magnetometer and GPS heading
    uint16_t dcm_ki_mag;                    // DCM filter integral gain ( x 10000) for magnetometer and GPS heading

    rxConfig_t rxConfig;

    uint8_t disarm_kill_switch;             // allow disarm via AUX switch regardless of throttle value
    uint8_t auto_disarm_delay;              // allow automatically disarming multicopters after auto_disarm_delay seconds of zero throttle. Disabled when 0
    uint8_t small_angle;

    // mixer-related configuration
    mixerConfig_t mixerConfig;

    //int8_t yaw_control_direction;           // change control direction of yaw (inverted, normal)

#ifdef GPS
    gpsConfig_t gpsConfig;
#endif

#ifdef NAV
    navConfig_t navConfig;
#endif

    serialConfig_t serialConfig;

    telemetryConfig_t telemetryConfig;

#ifdef LED_STRIP
    ledConfig_t ledConfigs[MAX_LED_STRIP_LENGTH];
    hsvColor_t colors[CONFIGURABLE_COLOR_COUNT];
#endif

    uint32_t beeper_off_flags;
    uint32_t prefered_beeper_off_flags;
} master_t;

PG_DECLARE(master_t, masterConfig);

extern controlRateConfig_t *currentControlRateProfile;
