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
#import "EBSScanInfoEstimoteUtilities.h"
#import "EBSScanInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  ECOScanInfoEstimoteTelemetry represents generic telemetry scan info.
 */
@interface EBSScanInfoEstimoteTelemetry : EBSScanInfo <NSCopying>

/**
 *  Version of scan info Protocol.
 */
@property (nonatomic, assign, readonly) EBSScanInfoProtocolVersion protocolVersion;

/**
 *  Half (8 bytes) of the full device identifier (16 bytes)
 *  represented in hex string.
 */
@property (nonatomic, strong, readonly) NSString *shortIdentifier;

/**
 *  Initialize telemetry object.
 *
 *  @param peripheralIdentifier identifier of CBPeripheral
 *  @param rssi                 RSSI of discovered device
 *  @param scanDate             date when packet was discovered
 *  @param shortIdentifier      short identifier from packet
 *  @param protocolVersion      protocol version from packet
 *
 *  @return initialized object
 */
- (instancetype)initWithPeripheralIdentifier:(NSUUID *)peripheralIdentifier
                                        rssi:(NSNumber *)rssi
                                    scanDate:(NSDate *)scanDate
                             shortIdentifier:(NSString *)shortIdentifier
                             protocolVersion:(EBSScanInfoProtocolVersion)protocolVersion;

@end

NS_ASSUME_NONNULL_END
