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
#import "EBSScanInfo.h"

typedef NS_ENUM(NSInteger , EBSScanInfoProximityFirmwareState) {
    EBSScanInfoProximityFirmwareStateBoot = 0,
    EBSScanInfoProximityFirmwareStateApp
};

NS_ASSUME_NONNULL_BEGIN


/**
 *  ECOScanInfoProximityConnectivity is a class dedicated to Connectivity packet for Proximity Beacons.
 */
@interface EBSScanInfoProximityConnectivity : EBSScanInfo <NSCoding>

/*
 *  Identifier of discovered device.
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
 * Measured power of the beacon (with what RSSI [dBm] device can be heard at exactly 1 m).
 *
 * In case of devices running very old firmware or in boot state the value is nil.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *measuredPower;

/**
 * State of the firmware on the device.
 */
@property (nonatomic, assign, readonly) EBSScanInfoProximityFirmwareState firmwareState;


/**
 * Initializer.
 *
 * @param peripheralIdentifier Identifier of the peripheral object associated with the scanned device.
 * @param rssi Rssi value measured during the scan.
 * @param scanDate Exact time of the scan.
 * @param macAddress Device MAC Address (hex string).
 * @param firmwareState State of the firmware on the device.
 * @param measuredPower Measured power of the beacon.
 * @return Initialized scan info object.
 */
- (instancetype)initWithPeripheralIdentifier:(NSUUID *)peripheralIdentifier
                                        rssi:(NSNumber *)rssi
                                    scanDate:(NSDate *)scanDate
                                  macAddress:(NSString *)macAddress
                               firmwareState:(EBSScanInfoProximityFirmwareState)firmwareState
                               measuredPower:(NSNumber *)measuredPower;


@end

NS_ASSUME_NONNULL_END
