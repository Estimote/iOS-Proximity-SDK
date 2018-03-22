//
//    ____                _           _ _           ____  ____  _  __
//   |  _ \ _ __ _____  _(_)_ __ ___ (_) |_ _   _  / ___||  _ \| |/ /
//   | |_) | '__/ _ \ \/ / | '_ ` _ \| | __| | | | \___ \| | | | ' /
//   |  __/| | | (_) >  <| | | | | | | | |_| |_| |  ___) | |_| | . \
//   |_|   |_|  \___/_/\_\_|_| |_| |_|_|\__|\__, | |____/|____/|_|\_\
//                                          |___/
//
//  Copyright © 2017 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 Represents a row in 'analytics_track_events' table in database created by EPXPersistentAnalyticsRepository.
 */
@interface EPXAnalyticsTrackEventsEntity : NSObject

/**
 Packet type powering algorithm that analytics tracks (i.e. Estimote Location for Estimote Monitoring).
 */
@property (nonatomic, strong, readonly) NSString *packetIdentifier;

/**
 Beacon-based event name that triggered analytics ping (i.e. enter).
 */
@property (nonatomic, strong, readonly) NSString *eventType;

/**
 Packet name powering algorithm that analytics tracks (i.e. estimote_location for Estimote Monitoring).
 */
@property (nonatomic, strong, readonly) NSString *packetType;

/**
 Distance where the notification was set to appear.
 */
@property (nonatomic, strong, readonly) NSNumber *expectedDistance;

/**
 UNIX time in seconds.
 */
@property (nonatomic, strong, readonly) NSNumber *timestamp;

/**
 Flag meaning application state.
 */
@property (nonatomic, strong, readonly) NSNumber *foreground;

/**
 SDK-generated identifier used to identify end users (AKA "beacon consumers").
 */
@property (nonatomic, strong, readonly) NSString *distinctID;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;


/**
 Designated initalizer.

 @param packetIdentifier Packet type powering algorithm that analytics tracks (i.e. Estimote Location for Estimote Monitoring).
 @param eventType Beacon-based event name that triggered analytics ping (i.e. enter).
 @param packetType Packet name powering algorithm that analytics tracks (i.e. estimote_location for Estimote Monitoring).
 @param expectedDistance Distance where the notification was set to appear.
 @param timestamp UNIX time in seconds.
 @param foreground Flag meaning application state.
 @param distinctID SDK-generated identifier used to identify end users (AKA "beacon consumers").
 */
- (instancetype)initWithPacketIdentifier:(NSString *)packetIdentifier eventType:(NSString *)eventType packetType:(NSString *)packetType expectedDistance:(NSNumber *)expectedDistance timestamp:(NSNumber *)timestamp foreground:(NSNumber *)foreground distinctID:(NSString *)distinctID NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
