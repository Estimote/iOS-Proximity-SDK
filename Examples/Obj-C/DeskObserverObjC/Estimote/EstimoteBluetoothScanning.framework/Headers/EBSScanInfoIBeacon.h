//
//    ____  _            _              _   _       ____                        _
//   | __ )| |_   _  ___| |_ ___   ___ | |_| |__   / ___|  ___ __ _ _ __  _ __ (_)_ __   __ _
//   |  _ \| | | | |/ _ \ __/ _ \ / _ \| __| '_ \  \___ \ / __/ _` | '_ \| '_ \| | '_ \ / _` |
//   | |_) | | |_| |  __/ || (_) | (_) | |_| | | |  ___) | (_| (_| | | | | | | | | | | | (_| |
//   |____/|_|\__,_|\___|\__\___/ \___/ \__|_| |_| |____/ \___\__,_|_| |_|_| |_|_|_| |_|\__, |
//                                                                                      |___/
//
//
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "EBSScanInfo.h"

typedef NS_ENUM(NSInteger , EBSScanInfoIBeaconFirmwareState) {
    EBSScanInfoIBeaconFirmwareStateBoot = 0,
    EBSScanInfoIBeaconFirmwareStateApp
};

/**
 * An object holding information about an Estimote device acting as an iBeacon.
 */

@interface EBSScanInfoIBeacon : EBSScanInfo

#pragma mark Properties
///-----------------------------------------
/// @name Properties
///-----------------------------------------

/**
 *  MAC address of the device
*/
@property (nonatomic, strong, readonly) NSString *macAddress;

/**
 * Major value of the beacon.
 *
 * In case of devices running very old firmware or in boot state the value is nil.
 */
@property (nonatomic, strong, readonly) NSNumber *major;

/**
 * Minor value of the beacon.
 *
 * In case of devices running very old firmware or in boot state the value is nil.
 */
@property (nonatomic, strong, readonly) NSNumber *minor;

/**
 * Measured power of the beacon (with what RSSI [dBm] device can be heard at exactly 1 m).
 *
 * In case of devices running very old firmware or in boot state the value is nil.
 */
@property (nonatomic, strong, readonly) NSNumber *measuredPower;

/**
 * State of the firmware on the device.
 */
@property (nonatomic, assign, readonly) EBSScanInfoIBeaconFirmwareState firmwareState;

@end
