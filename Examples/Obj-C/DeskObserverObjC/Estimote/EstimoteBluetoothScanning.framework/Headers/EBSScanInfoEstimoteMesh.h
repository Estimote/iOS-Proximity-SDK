//
//    ____  _            _              _   _       ____                        _
//   | __ )| |_   _  ___| |_ ___   ___ | |_| |__   / ___|  ___ __ _ _ __  _ __ (_)_ __   __ _
//   |  _ \| | | | |/ _ \ __/ _ \ / _ \| __| '_ \  \___ \ / __/ _` | '_ \| '_ \| | '_ \ / _` |
//   | |_) | | |_| |  __/ || (_) | (_) | |_| | | |  ___) | (_| (_| | | | | | | | | | | | (_| |
//   |____/|_|\__,_|\___|\__\___/ \___/ \__|_| |_| |____/ \___\__,_|_| |_|_| |_|_|_| |_|\__, |
//                                                                                      |___/
//
//
//  Copyright © 2016 Estimote. All rights reserved.

#import <Foundation/Foundation.h>

#import "EBSScanInfoEstimoteUtilities.h"
#import "EBSScanInfo.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  Represents scan information for mesh packet broadcasted by beacons in a mesh.
 */
@interface EBSScanInfoEstimoteMesh : EBSScanInfo

/**
 * Type of Estimote Broadcasting Scheme frame.
 */
@property (nonatomic, readonly) NSInteger frameType;

/**
 * Version of Estimote Broadcasting Scheme protocol.
 */
@property (nonatomic, readonly) NSInteger protocolVersion;

/**
 *  Half (8 bytes) of the full device identifier (16 bytes)
 *  represented as a hex string for version 1.0 and 1.1 mesh packet.
 *  Version 1.2 introduce super short version of identifier - 4 bytes only.
 */
@property (nonatomic, strong, readonly) NSString *shortIdentifier;

/**
 *  Identifier of a mesh network.
 */
@property (nonatomic, strong, readonly) NSNumber *meshNetworkIdentifier;

/**
 *  Version of current mesh settings.
 */
@property (nonatomic, strong, readonly) NSNumber *meshSettingsIdentifier;

/**
 *  Version of current mesh report.
 *  @note Supported by v1.2 mesh frames only, otherwise nil.
 */
@property (nonatomic, strong, readonly) NSNumber *meshReportIdentifier;

/**
 *  Counter for number of intermediate devices through which data had to pass to reach its destination.
 *  @note Supported by v1.0 mesh frames only, otherwise nil.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *hopCounter;

/**
 *  Version of an application running on a device.
 *  @note Supported by v1.1 and v1.2 mesh frames only, otherwise nil.
 */
@property (nonatomic, strong, readonly, nullable) NSString *appVersion;

/**
 *  Version of a bootloader running on a device.
 *  @note Supported by v1.1 and v1.2 mesh frames only, otherwise nil.
 */
@property (nonatomic, strong, readonly, nullable) NSString *bootloaderVersion;

/**
 *  Initializes an object with scan information.
 *
 *  @param peripheralIdentifier     CBPeripheral identifier of a discovered device.
 *  @param rssi                     RSSI of a discovered device.
 *  @param scanDate                 Date when packet was discovered.
 *  @param frameType                Type of Estimote Broadcasting Scheme frame.
 *  @param protocolVersion          Version of Estimote Broadcasting Scheme protocol.
 *  @param shortIdentifier          Short identifier of a device.
 *  @param meshNetworkIdentifier    Identifier of a mesh network.
 *  @param meshSettingsIdentifier   Identifier of current mesh settings.
 *  @param meshReportIdentifier     Identifier of current mesh report.
 *  @param hopCounter               Hop count for the packet.
 *  @param appVersion               Version of an application running on a device.
 *  @param bootloaderVersion        Version of a bootloader running on a device.
 *  @return Initialized object.
 */
- (instancetype)initWithPeripheralIdentifier:(NSUUID *)peripheralIdentifier
                                        rssi:(NSNumber *)rssi
                                    scanDate:(NSDate *)scanDate
                                   frameType:(NSInteger)frameType
                             protocolVersion:(NSInteger)protocolVersion
                             shortIdentifier:(NSString *)shortIdentifier
                       meshNetworkIdentifier:(NSNumber *)meshNetworkIdentifier
                      meshSettingsIdentifier:(NSNumber *)meshSettingsIdentifier
                        meshReportIdentifier:(NSNumber *)meshReportIdentifier
                                  hopCounter:(NSNumber * _Nullable)hopCounter
                                  appVersion:(NSString * _Nullable)appVersion
                           bootloaderVersion:(NSString * _Nullable)bootloaderVersion;

@end

NS_ASSUME_NONNULL_END
