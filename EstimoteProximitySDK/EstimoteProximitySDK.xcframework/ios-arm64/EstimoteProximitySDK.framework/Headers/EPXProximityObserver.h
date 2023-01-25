//
//    ____                _           _ _           ____  ____  _  __
//   |  _ \ _ __ _____  _(_)_ __ ___ (_) |_ _   _  / ___||  _ \| |/ /
//   | |_) | '__/ _ \ \/ / | '_ ` _ \| | __| | | | \___ \| | | | ' /
//   |  __/| | | (_) >  <| | | | | | | | |_| |_| |  ___) | |_| | . \
//   |_|   |_|  \___/_/\_\_|_| |_| |_|_|\__|\__, | |____/|____/|_|\_\
//                                          |___/
//
//   Copyright © 2017 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>

@class EPXCloudCredentials;
@class EPXProximityZone;
@class EPXProximityObserverConfiguration;

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const EPXProximityObserverErrorDomain;

/**
 Possible errors invoked with Proximity Observer's error block.
 */
typedef NS_ENUM(NSUInteger, EPXProximityObserverError) {
    /* Unknown error probably due to a bug. If you're getting errors with this code please report it on
     * https://forums.estimote.com, using contact@estimote.com or filing an issue on Github. */
    EPXProximityObserverErrorUnknown = 0,

    /* Fetching tags from Cloud failed. */
    EPXProximityObserverErrorFetchingTagsFailed,

    /* Fetching attachments from Cloud failed. */
    EPXProximityObserverErrorFetchingAttachmentsFailed,

    /* Bluetooth is unsupported on this iOS device. */
    EPXProximityObserverErrorBluetoothUnsupported,

    /* Bluetooth is turned off. */
    EPXProximityObserverErrorBluetoothOff,

    /* Couldn't use motion detection. */
    EPXProximityObserverErrorMotionDetectionFailed,
    
    /* Core Location Services interferred with monitoring */
    EPXProximityObserverErrorMonitoringNotPermitted
};

/**
 Observes and reports proximity of Estimote devices.
 Uses Estimote Monitoring under the hood. Encapsulates it under tag-based beacon identification and callback blocks.
 */
NS_SWIFT_NAME(ProximityObserver)
@interface EPXProximityObserver : NSObject

/**
 Init is disabled for this class.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 New is disabled for this class.
 */
+ (instancetype) new NS_UNAVAILABLE;

/**
 Convenience initializer. Calls designated initializer with default configuration.
 @param credentials Cloud Credentials object used to authorize requests sent to Estimote Cloud.
 @param errorBlock Block invoked whenever error occurs. The parameter is an NSError object, with
                   domain equal to EPXProximityObserverErrorDomain and code from EPXProximityObserverError enum.
 */
- (instancetype)initWithCredentials:(EPXCloudCredentials *)credentials onError:(void (^)(NSError *error))errorBlock;

/**
 Designated initializer.
 @param credentials Cloud Credentials object used to authorize requests sent to Estimote Cloud.
 @param configuration Proximity observer configuration that can be used for Proximity Observer's behaviour customization.
 @param errorBlock Block invoked whenever error occurs. The parameter is an NSError object, with
                   domain equal to EPXProximityObserverErrorDomain and code from EPXProximityObserverError enum.
 */
- (instancetype)initWithCredentials:(EPXCloudCredentials *)credentials
                      configuration:(EPXProximityObserverConfiguration *)configuration
                            onError:(void (^)(NSError *error))errorBlock;

/**
 Start observing and calling callbacks on provided proximity zones:
 - request device details for all user's devices from Estimote Cloud,
 - start Estimote Monitoring at registered ranges,
 - call registered enter/exit/change blocks when proximity event occurs.

 Subsequent calls of this method cause overwriting previously observed zones.

 @param zones Zones to be observed.
 */
- (void)startObservingZones:(NSArray<EPXProximityZone *> *)zones;

/**
 Stop observing and calling callbacks for all zones that were provided with -startObservingZones:,
 release memory resources allocated for monitoring the zones.

 Subsequent calls of this method (without re-starting observing zones) have the same effect as calling it just once.
 */
- (void)stopObservingZones;

@end

NS_ASSUME_NONNULL_END
