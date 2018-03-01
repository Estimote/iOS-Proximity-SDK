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

#import "EBSScanInfoEstimoteTelemetry.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Scan information representation of Next-Gen beacons telemetry packet of type A.
 */
@interface EBSScanInfoEstimoteTelemetryA : EBSScanInfoEstimoteTelemetry

/**
 *  Accelerometer data related to X axis
 */
@property (nonatomic, strong, readonly) NSNumber *accelerationX;

/**
 *  Accelerometer data related to Y axis
 */
@property (nonatomic, strong, readonly) NSNumber *accelerationY;

/**
 *  Accelerometer data related to Z axis
 */
@property (nonatomic, strong, readonly) NSNumber *accelerationZ;

/**
 *  Duration of previous motion state in seconds.
 */
@property (nonatomic, strong, readonly) NSNumber *previousMotionStateDurationInSeconds;

/**
 *  Duration of current motion state in seconds.
 */
@property (nonatomic, strong, readonly) NSNumber *currentMotionStateDurationInSeconds;

/**
 *  Motion state of the device. It can be moving (bool value YES) or not moving (bool value NO).
 */
@property (nonatomic, strong, readonly) NSNumber *motionState;

/**
 *  Value of GPIO port 0. Possible values are 0 (LOW) and 1 (HIGH).
 */
@property (nonatomic, strong, readonly) NSNumber *gpioPort0Value;

/**
 *  Value of GPIO port 1. Possible values are 0 (LOW) and 1 (HIGH).
 */
@property (nonatomic, strong, readonly) NSNumber *gpioPort1Value;

/**
 *  Value of GPIO port 2. Possible values are 0 (LOW) and 1 (HIGH).
 */
@property (nonatomic, strong, readonly) NSNumber *gpioPort2Value;

/**
 *  Value of GPIO port 3. Possible values are 0 (LOW) and 1 (HIGH).
 */
@property (nonatomic, strong, readonly) NSNumber *gpioPort3Value;

/**
 *  FIRMWARE Flag indicating application error. Bool value NO - no error, YES at least one error occurred.
 *
 *  Available since protocol version 1. In protocol version 0, it's in the type B Telemetry packet.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *applicationError;

/**
 *  FIRMWARE Flag indicating Real Time Clock is not properly configured. Bool value NO - configured, YES - not configured.
 *
 *  Available since protocol version 1. In protocol version 0, it's in the type B Telemetry packet.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *realTimeClockError;

/**
 *  Atmospheric pressure in pascals (Pa).
 *
 *  Note that unlike what you see on the weather forecast, this value is not normalized to the sea level!
 *
 *  Available since protocol version 2.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *pressureInPascals;

/**
 * Init.
 */
- (instancetype)initWithPeripheralIdentifier:(NSUUID *)peripheralIdentifier
                                        rssi:(NSNumber *)rssi
                                    scanDate:(NSDate *)scanDate
                             shortIdentifier:(NSString *)shortIdentifier
                             protocolVersion:(EBSScanInfoProtocolVersion)protocolVersion
                               accelerationX:(NSNumber *)accelerationX
                               accelerationY:(NSNumber *)accelerationY
                               accelerationZ:(NSNumber *)accelerationZ
        previousMotionStateDurationInSeconds:(NSNumber *)previousMotionStateDurationInSeconds
         currentMotionStateDurationInSeconds:(NSNumber *)currentMotionStateDurationInSeconds
                                 motionState:(NSNumber *)motionState
                              gpioPort0Value:(NSNumber *)gpioPort0Value
                              gpioPort1Value:(NSNumber *)gpioPort1Value
                              gpioPort2Value:(NSNumber *)gpioPort2Value
                              gpioPort3Value:(NSNumber *)gpioPort3Value
                            applicationError:(NSNumber *)applicationError
                          realTimeClockError:(NSNumber *)realTimeClockError
                           pressureInPascals:(NSNumber *)pressureInPascals;

NS_ASSUME_NONNULL_END

@end
