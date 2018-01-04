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

NS_ASSUME_NONNULL_BEGIN

/**
 *  ECOScanInfoMirrorConnectivity represents Mirror scan info.
 */
@interface EBSScanInfoMirrorConnectivity : EBSScanInfo

#pragma mark Properties
///-----------------------------------------
/// @name Properties
///-----------------------------------------

/**
 *  Cloud identifier of discovered device.
 */
@property (nonatomic, strong, readonly) NSString *publicID;

/**
 *  Flag indicating if Display Access Control is enabled for this device.
 */
@property (nonatomic, assign, readonly) BOOL displayAccessControlEnabled;

/**
 *  Measured power of discovered device.
 */
@property (nonatomic, assign, readonly) NSInteger measuredPower;

/**
 *  Initializes an object with scan information.
 *
 *  @param peripheralIdentifier        CBPeripheral identifier of a discovered device.
 *  @param rssi                        RSSI of a discovered device.
 *  @param measuredPower               Measured power of discovered device.
 *  @param scanDate                    Date when packet was discovered.
 *  @param publicID                    Cloud identifier of discovered device.
 *  @param displayAccessControlEnabled Flag indicating if Display Access Control is enabled for this device.
 *  @return Initialized object.
 */
- (nullable instancetype)initWithPeripheralIdentifier:(NSUUID *)peripheralIdentifier
                                                 rssi:(NSNumber *)rssi
                                        measuredPower:(NSInteger)measuredPower
                                             scanDate:(NSDate *)scanDate
                                             publicID:(NSString *)publicID
                          displayAccessControlEnabled:(BOOL)displayAccessControlEnabled;

@end

NS_ASSUME_NONNULL_END
