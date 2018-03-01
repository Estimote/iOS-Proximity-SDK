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

typedef NS_ENUM(NSInteger , EBSScanInfoEstimoteLocationAdvertisingChannel) {
    EBSScanInfoEstimoteLocationAdvertisingChannelUnknown = 0,
    EBSScanInfoEstimoteLocationAdvertisingChannel37,
    EBSScanInfoEstimoteLocationAdvertisingChannel38,
    EBSScanInfoEstimoteLocationAdvertisingChannel39
};

@interface EBSScanInfoEstimoteLocation : EBSScanInfo

#pragma mark Properties
///-----------------------------------------
/// @name Properties
///-----------------------------------------

/**
 * Type of Estimote Broadcasting Scheme frame.
 */
@property (nonatomic, assign, readonly) NSInteger frameType;

/**
 * Version of Estimote Broadcasting Scheme protocol.
 */
@property (nonatomic, assign, readonly) NSInteger protocolVersion;

/**
 * Public identifier of the Estimote Device.
 */
@property (nonatomic, strong, readonly) NSString *publicId;

/**
 * Measured power of the beacon (with what RSSI [dBm] device can be heard at exactly 1 m).
 */
@property (nonatomic, assign, readonly) NSInteger measuredPower;

/**
 * Information about channel on which the information was broadcasted.
 */
@property (nonatomic, assign, readonly) EBSScanInfoEstimoteLocationAdvertisingChannel advertisingChannel;


/**
 * Designated initalizer
 *
 * @param peripheralIdentifier Identifier of scanned peripheral.
 * @param rssi RSSI value measured during the scan.
 * @param scanDate Time when the device was scanned.
 * @param frameType Type of Estimote Broadcasting Scheme frame.
 * @param protocolVersion Version of Estimote Broadcasting Scheme protocol.
 * @param publicId Public identifier of the Estimote Device.
 * @param measuredPower Measured power of the beacon (with what RSSI [dBm] device can be heard at exactly 1 m).
 * @param advertisingChannel Channel on which the information was broadcasted.
 * @return Initialized object.
 */
- (instancetype)initWithPeripheralIdentifier:(NSUUID *)peripheralIdentifier
                                        rssi:(NSNumber *)rssi
                                    scanDate:(NSDate *)scanDate
                                   frameType:(NSInteger)frameType
                             protocolVersion:(NSInteger)protocolVersion
                                    publicId:(NSString *)publicId
                               measuredPower:(NSInteger)measuredPower
                          advertisingChannel:(EBSScanInfoEstimoteLocationAdvertisingChannel)advertisingChannel;


#pragma mark - Overrides

- (id)initWithCoder:(NSCoder *)coder;
- (void)encodeWithCoder:(NSCoder *)coder;

@end
