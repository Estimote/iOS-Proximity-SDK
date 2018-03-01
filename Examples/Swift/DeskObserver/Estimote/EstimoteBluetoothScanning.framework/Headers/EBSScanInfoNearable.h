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

typedef NS_ENUM(NSInteger , EBSScanInfoNearableFirmwareState) {
    EBSScanInfoNearableFirmwareStateBoot = 0,
    EBSScanInfoNearableFirmwareStateApp
};

typedef NS_ENUM(NSInteger , EBSScanInfoNearableMotionState) {
    EBSScanInfoNearableMotionStateNotMoving = 0,
    EBSScanInfoNearableMotionStateMoving
};

// TODO: rename to EBS!
typedef NS_ENUM(NSInteger , EBSScanInfoNearableAdvertisingChannel) {
    ECOScanInfoAdvertisingNearableChannelUnknown = 0,
    ECOScanInfoAdvertisingNearableChannel37,
    ECOScanInfoAdvertisingNearableChannel38,
    ECOScanInfoAdvertisingNearableChannel39
};

@interface EBSScanInfoNearable : EBSScanInfo

#pragma mark Properties
///-----------------------------------------
/// @name Properties
///-----------------------------------------

/**
 * State of the firmware on the device.
 */
@property (nonatomic, assign, readonly) EBSScanInfoNearableFirmwareState firmwareState;

/**
 * Version of Nearable protocol.
 */
@property (nonatomic, assign, readonly) NSInteger protocolVersion;

/**
 * Unique identifier of the Nearable device.
 */
@property (nonatomic, strong, readonly) NSString *nearableIdentifier;

/**
 * Code of the device hardware revision.
 *
 * This information is broadcasted alternatively with appSoftwareVersionNumber so may not always be available.
 */
@property (nonatomic, assign, readonly) NSInteger hardwareRevisionNumber;

/**
 * Boot software version run by the device.
 *
 * This information is broadcasted alternatively with appSoftwareVersionNumber so may not always be available.
 */
@property (nonatomic, strong, readonly) NSNumber *bootSoftwareVersionNumber;

/**
 * App software version run by the device.
 *
 * This information is broadcasted alternatively with bootSoftwareVersionNumber so may not always be available.
 * If the device is in boot state this value should not be trusted.
 */
@property (nonatomic, strong, readonly) NSNumber *appSoftwareVersionNumber;

/**
 * Ambient temperature measured by the device.
 *
 * If the device is in boot state this value should not be trusted.
 */
@property (nonatomic, assign, readonly) double temperature;

/**
 * Real batter voltage measured when the device was idle.
 *
 * This information is broadcasted alternatively with stressBatteryVoltage so may not always be available.
 * If the device is in boot state this value should not be trusted.
 */
@property (nonatomic, strong, readonly) NSNumber *idleBatteryVoltage;

/**
 * Real batter voltage measured when the device was under stress.
 *
 * This information is broadcasted alternatively with stressBatteryVoltage so may not always be available.
 * If the device is in boot state this value should not be trusted.
 */
@property (nonatomic, strong, readonly) NSNumber *stressBatteryVoltage;

/**
 * Information about whether the device is in motion or not.
 *
 * If the device is in boot state this value should not be trusted.
 */
@property (nonatomic, assign, readonly) EBSScanInfoNearableMotionState motionState;

/**
 * Length of the current motion state expressed in seconds.
 *
 * If the device is in boot state this value should not be trusted.
 */
@property (nonatomic, assign, readonly) NSUInteger currentMotionStateDuration;

/**
 * Length of the previous motion state expressed in seconds.
 *
 * If the device is in boot state this value should not be trusted.
 */
@property (nonatomic, assign, readonly) NSUInteger previousMotionStateDuration;

/**
 * Acceleration along the x axis of the device expressed in [g].
 *
 * If the device is in boot state this value should not be trusted.
 */
@property (nonatomic, assign, readonly) double xAcceleration;

/**
 * Acceleration along the y axis of the device expressed in [g].
 *
 * If the device is in boot state this value should not be trusted.
 */
@property (nonatomic, assign, readonly) double yAcceleration;

/**
 * Acceleration along the z axis of the device expressed in [g].
 *
 * If the device is in boot state this value should not be trusted.
 */
@property (nonatomic, assign, readonly) double zAcceleration;

/**
 * Power level (txPower) broadcasted by the device (i.e. RSSI measured at 0m in [dBm]).
 *
 * If the device is in boot state this value should not be trusted.
 */
@property (nonatomic, assign, readonly) NSInteger powerLevel;

/**
 * Information about channel on which the information was broadcasted.
 *
 * Information can be unavailable if the device does not support different broadcasting packets for different channels.
 * If the device is in boot state this value should not be trusted.
 */
@property (nonatomic, assign, readonly) EBSScanInfoNearableAdvertisingChannel advertisingChannel;

#pragma mark - Overrides

- (id)initWithCoder:(NSCoder *)coder;
- (void)encodeWithCoder:(NSCoder *)coder;

@end
