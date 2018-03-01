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

#define EBSScanInfoEstimoteUtilitiesErrorDomain @"EBSScanInfoEstimoteUtilitiesErrorDomain"

/**
 *  Estimote packet type. Note that the values under the enum aren't equal to values broadcast in the packets.
 */
typedef NS_ENUM(NSInteger, EBSScanInfoFrameType) {
    /**
     *  Unknown frame type, parsing error.
     */
    EBSScanInfoFrameTypeUnknown = 0,
    /**
     *  Estimote Connectivity frame type.
     */
    EBSScanInfoFrameTypeEstimoteConnectivity,
    /**
     *  Estimote Location frame type.
     */
    EBSScanInfoFrameTypeEstimoteLocation,
    /**
     *  Estimote Telemetry frame type.
     */
    EBSScanInfoFrameTypeEstimoteTelemetry,
    /**
     *  Estimote UWB frame type.
     */
    EBSScanInfoFrameTypeUWB,
    /**
     *  Estimote Mirror frame type.
     */
    EBSScanInfoFrameTypeMirror,
    /**
     *  Estimote Mesh frame type.
     */
    EBSScanInfoFrameTypeMesh
};

/**
 *  Estimote packet's subframe type
 */
typedef NS_ENUM(NSInteger, EBSScanInfoSubframeType) {
    /**
     *  Unknown subframe type, parsing error.
     */
    EBSScanInfoSubframeTypeUnknown,
    /**
     *  Estimote Telemetry A packet subframe type.
     */
    EBSScanInfoSubframeTypeTelemetryA,
    /**
     *  Estimote Telemetry B packet subframe type.
     */
    EBSScanInfoSubframeTypeTelemetryB
};

typedef NS_ENUM(NSInteger, EBSScanInfoTimeUnit) {
    EBSScanInfoTimeUnitSeconds = 0,
    EBSScanInfoTimeUnitMinutes = 1,
    EBSScanInfoTimeUnitHours = 2,
    EBSScanInfoTimeUnitDaysWeeks = 3
};

typedef NS_ENUM(NSInteger, EBSScanInfoEstimoteUtilitiesError) {
    ECOScanInfoEstimoteUtilitiesMeasuredPowerError = 1
};

/**
 *  Enum with available protocol versions
 */
typedef NS_ENUM(NSInteger, EBSScanInfoProtocolVersion) {
    EBSScanInfoProtocolVersionUnsupported = -1,
    // XXX: the raw values of this enum don't match the actual protocol version codes (e.g., v1.0 = "0", not "1")
    // this usually isn't a problem, except may ocassionally cause some confusion, especially when printing EBSScanInfoEstimoteTelemetry objects (the `description` method will print out "1", not "0" for v1.0)
    // changing this is likely NOT backward-compatible, e.g., Indoor already has some serialized Telemetry packets
    EBSScanInfoProtocolVersion_v1 = 1,
    EBSScanInfoProtocolVersion_v11,
    EBSScanInfoProtocolVersion_v12
};

NS_ASSUME_NONNULL_BEGIN

/**
 *  ECOScanInfoEstimoteUtilities class contains set of static utility methods
 *  used to parse scan response advertisement data coming from Next-Gen beacons
 *  scanning.
 */
@interface EBSScanInfoEstimoteUtilities : NSObject

/**
 *  Method is parsing long version (16 bytes) of device identifier
 *  used for decoding bluetooth scan response of Next-Gen beacons.
 *
 *  @param data advertisementData to parse
 *
 *  @return parsed identifier as NSString object
 */
+ (NSString * _Nullable)parse16ByteIdentifier:(NSData *)data;

/**
 *  Method is parsing short version (8 bytes) of device identifier
 *  used for decoding bluetooth scan response of Next-Gen beacons.
 *
 *  @param data advertisementData to parse
 *
 *  @return parsed identifier as NSString object
 */
+ (NSString * _Nullable)parse8ByteIdentifier:(NSData *)data;

/**
 *  Method is parsing super short version (4 bytes) of device identifier
 *  used for decoding bluetooth scan response of Next-Gen beacons.
 *
 *  @param data advertisementData to parse
 *
 *  @return parsed identifier as NSString object
 */
+ (NSString * _Nullable)parse4ByteIdentifier:(NSData *)data;

/**
 *  Method is parsing frame type of Next-Gen
 *  beacons from bluetooth scan response.
 *
 *  @param data advertisementData to parse
 *
 *  @return parsed frame type as EBSScanInfoFrameType.
 */
+ (EBSScanInfoFrameType)parseFrameType:(NSData *)data;

/**
 *  Method is parsing subframe type of Next-Gen
 *  beacons from bluetooth scan response.
 *
 *  @param data advertisementData to parse
 *
 *  @return parsed subframe type as EBSScanInfoSubframeType.
 */
+ (EBSScanInfoSubframeType)parseSubframeType:(NSData *)data;

/**
 *  Method is parsing protocol version of Next-Gen
 *  beacons from bluetooth scan response.
 *
 *  @param data advertisementData to parse
 *
 *  @return parsed subframe type as NSInteger. Value EBSScanInfoProtocolVersionUnsupported (-1) means error in parsing.
 */
+ (EBSScanInfoProtocolVersion)parseProtocolVersion:(NSData *)data;

/**
 *  Method is parsing timer return from the Next-Gen
 *  beacons  from bluetooth scan response.
 *
 *  @param counter counter value (number of units)
 *  @param unit    time unit
 *  @param weeks   enables weeks support when parsing unit 3. When NO, unit is days. If YES, unit is days for counter < 32. When counter is greater then 32 unit is weeks.
 *
 *  @return calculated time
 */
+ (long)parseTimeWithCounter:(uint16_t)counter unit:(EBSScanInfoTimeUnit)unit weeks:(BOOL)weeks;

/**
 * Method is parsing measured power.
 *
 * @param data     advertisementData to parse
 * @param errorRef reference to error
 *
 * @return parsed measured power.
 */
+ (NSInteger)parseMeasuredPower:(NSData *)data withError:(NSError **)errorRef;

NS_ASSUME_NONNULL_END

@end
