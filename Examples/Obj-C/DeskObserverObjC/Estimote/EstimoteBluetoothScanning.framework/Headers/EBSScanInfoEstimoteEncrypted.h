//
//    ____  _            _              _   _       ____                        _
//   | __ )| |_   _  ___| |_ ___   ___ | |_| |__   / ___|  ___ __ _ _ __  _ __ (_)_ __   __ _
//   |  _ \| | | | |/ _ \ __/ _ \ / _ \| __| '_ \  \___ \ / __/ _` | '_ \| '_ \| | '_ \ / _` |
//   | |_) | | |_| |  __/ || (_) | (_) | |_| | | |  ___) | (_| (_| | | | | | | | | | | | (_| |
//   |____/|_|\__,_|\___|\__\___/ \___/ \__|_| |_| |____/ \___\__,_|_| |_|_| |_|_|_| |_|\__, |
//                                                                                      |___/
//
//
//  Copyright © 2018 Estimote. All rights reserved.

#import "EBSScanInfo.h"

/**
 Represents a scan of packet broadcast by Estimote device with Estimote Secure Monitoring enabled.
 */
@interface EBSScanInfoEstimoteEncrypted : EBSScanInfo

/**
 Service data sent in the packet.
 */
@property (nonatomic, strong, readonly) NSData *serviceData;

/**
 Designated initializer.

 @param peripheralIdentifier Identifier of the discovered peripheral that this scan info represents.
 @param rssi Packet rssi.
 @param scanDate Date at which the scan info was parsed.
 @param serviceData Service data broadcasted in packet.
 */
- (instancetype)initWithPeripheralIdentifier:(NSUUID *)peripheralIdentifier
                                        rssi:(NSNumber *)rssi
                                    scanDate:(NSDate *)scanDate
                                 serviceData:(NSData *)serviceData;

// Override
+ (EBSScanInfo *)parseScanInfoWithCbPeripheral:(CBPeripheral *)cbPeripheral
                             advertisementData:(NSDictionary *)advertisementDataDictionary
                                          RSSI:(NSNumber *)RSSI;

// Override
+ (NSArray *)broadcastedServices;


@end
