//
//    ____  _            _              _   _       ____                        _
//   | __ )| |_   _  ___| |_ ___   ___ | |_| |__   / ___|  ___ __ _ _ __  _ __ (_)_ __   __ _
//   |  _ \| | | | |/ _ \ __/ _ \ / _ \| __| '_ \  \___ \ / __/ _` | '_ \| '_ \| | '_ \ / _` |
//   | |_) | | |_| |  __/ || (_) | (_) | |_| | | |  ___) | (_| (_| | | | | | | | | | | | (_| |
//   |____/|_|\__,_|\___|\__\___/ \___/ \__|_| |_| |____/ \___\__,_|_| |_|_| |_|_|_| |_|\__, |
//                                                                                      |___/
//
//
// Copyright (c) 2014 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

/**
 * An object holding information about an Estimote device scan.
 */

@interface EBSScanInfo : NSObject <NSCoding>

/**
 * Services broadcasted by a specific device type.
 *
 * If the device does not broadcast any services `nil` is returned.
 * In the subclasses representing devices with broadcasted services this method should be overwritten.
 * @return A NSArray of `CBUUID`
 */
+ (NSArray *)broadcastedServices;

/** Identifier of scanned peripheral. */
@property (nonatomic, strong, readonly) NSUUID *peripheralIdentifier;

/** RSSI value measured during the scan. */
@property (nonatomic, strong, readonly) NSNumber *rssi;

/** Time when the device was scanned. */
@property (nonatomic, strong, readonly) NSDate *scanDate;

/**
 * Attempts to parse provided info into a new ECOScanInfo object.
 *
 * If the parse is unsuccessful `nil` is returned.
 *
 * @param cbPeripheral Peripheral object associated with the scanned device.
 * @param advertisementData Advertisement data from the scan.
 * @param RSSI RSSI value measured during the scan.
 * @return An ECOScanInfo object parsed from provided data.
 */
+ (EBSScanInfo *)parseScanInfoWithCbPeripheral:(CBPeripheral *)cbPeripheral
                             advertisementData:(NSDictionary *)advertisementData
                                          RSSI:(NSNumber *)RSSI;

/**
 * Returns a new scan info object
 *
 * This method should be called only by subclasses initializer.
 *
 * @param peripheralIdentifier Identifier of the peripheral object associated with the scanned device.
 * @param rssi Rssi value measured during the scan.
 * @param scanDate Exact time of the scan.
 * @return A scan info object initialized with.
 */
- (instancetype)initWithPeripheralIdentifier:(NSUUID *)peripheralIdentifier
                                        rssi:(NSNumber *)rssi
                                    scanDate:(NSDate *)scanDate;


#pragma - Overrides

- (id)initWithCoder:(NSCoder *)coder;
- (void)encodeWithCoder:(NSCoder *)coder;

@end
