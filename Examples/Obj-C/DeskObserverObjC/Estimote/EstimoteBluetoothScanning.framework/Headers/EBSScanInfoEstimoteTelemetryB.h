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
 *  Scan information representation of Next-Gen beacons telemetry packet of type B.
 */
@interface EBSScanInfoEstimoteTelemetryB : EBSScanInfoEstimoteTelemetry

/**
 *  Strength of magnetic field in X axis in normalized values (-1, 1).
 */
@property (nonatomic, strong, readonly) NSNumber *normalizedMagneticFieldX;

/**
 *  Strength of magnetic field in Y axis in normalized values (-1, 1).
 */
@property (nonatomic, strong, readonly) NSNumber *normalizedMagneticFieldY;

/**
 *  Strength of magnetic field in Z axis in normalized values (-1, 1).
 */
@property (nonatomic, strong, readonly) NSNumber *normalizedMagneticFieldZ;

/**
 *  Level of ambient light in lux.
 */
@property (nonatomic, strong, readonly) NSNumber *ambientLightLevelInLux;

/**
 *  Ambient temperature of device in Celsius degree.
 */
@property (nonatomic, strong, readonly) NSNumber *temperatureInCelsius;

/**
 *  Battery voltage in millivolts.
 */
@property (nonatomic, strong, readonly) NSNumber *batteryVoltageInMillivolts;

/**
 *  Battery level in percents.
 *
 *  Available since protocol version 2.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *batteryLevel;

/**
 *  Uptime since last reboot in seconds.
 */
@property (nonatomic, strong, readonly) NSNumber *uptimeInSeconds;

/**
 *  FIRMWARE Flag indicating application error. Bool value NO - no error, YES at least one error occurred.
 *
 *  Only available in protocol version 0. Since protocol version 1, it got moved to Telemetry A packet.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *applicationError;

/**
 *  FIRMWARE Flag indicating Real Time Clock is not properly configured. Bool value NO - configured, YES - not configured.
 *
 *  Only available in protocol version 0. Since protocol version 1, it got moved to Telemetry A packet.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *realTimeClockError;

/**
 * Init.
 */
- (instancetype)initWithPeripheralIdentifier:(NSUUID *)peripheralIdentifier
                                        rssi:(NSNumber *)rssi
                                    scanDate:(NSDate *)scanDate
                             shortIdentifier:(NSString *)shortIdentifier
                             protocolVersion:(EBSScanInfoProtocolVersion)protocolVersion
                    normalizedMagneticFieldX:(NSNumber *)normalizedMagneticFieldX
                    normalizedMagneticFieldY:(NSNumber *)normalizedMagneticFieldY
                    normalizedMagneticFieldZ:(NSNumber *)normalizedMagneticFieldZ
                      ambientLightLevelInLux:(NSNumber *)ambientLightLevelInLux
                        temperatureInCelsius:(NSNumber *)temperatureInCelsius
                  batteryVoltageInMillivolts:(NSNumber *)batteryVoltageInMillivolts
                                batteryLevel:(NSNumber *)batteryLevel
                             uptimeInSeconds:(NSNumber *)uptimeInSeconds
                            applicationError:(NSNumber *)applicationError
                          realTimeClockError:(NSNumber *)realTimeClockError;

NS_ASSUME_NONNULL_END

@end
