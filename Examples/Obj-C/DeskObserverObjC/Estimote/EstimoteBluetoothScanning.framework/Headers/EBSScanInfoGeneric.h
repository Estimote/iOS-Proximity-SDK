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

#import <Foundation/Foundation.h>
#import "EBSScanInfo.h"

/**
 * Represents generic BLE packet.
 * Use this class to scan for any packet with Estimote Service UUID that wasn't deserialized by other ScanInfo classes.
 */


@interface EBSScanInfoGeneric : EBSScanInfo

#pragma mark Properties
///-----------------------------------------
/// @name Properties
///-----------------------------------------

/**
 * Packet's advertisement data dictionary.
 */
@property (nonatomic, strong, readonly) NSDictionary<NSString*, id> *advertisementDataDictionary;

/**
 * Designated initalizer
 *
 * @param peripheralIdentifier Identifier of scanned peripheral.
 * @param rssi RSSI value measured during the scan.
 * @param scanDate Time when the device was scanned.
 * @param advertisementDataDictionary Packet's advertisement data dictionary received from Core Bluetooth.
 * @return Initialized object.
 */
- (instancetype)initWithPeripheralIdentifier:(NSUUID *)peripheralIdentifier
                                        rssi:(NSNumber *)rssi
                                    scanDate:(NSDate *)scanDate
                 advertisementDataDictionary:(NSDictionary *)advertisementDataDictionary;

- (id)initWithCoder:(NSCoder *)coder;

- (void)encodeWithCoder:(NSCoder *)coder;

@end

