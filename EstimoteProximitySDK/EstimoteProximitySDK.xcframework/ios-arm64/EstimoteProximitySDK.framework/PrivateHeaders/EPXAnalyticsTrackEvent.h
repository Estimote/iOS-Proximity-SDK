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

typedef NS_ENUM(NSUInteger, EPXAnalyticsTrackEventEventType) {
    EPXAnalyticsTrackEventEventTypeUnknown = 0,
    EPXAnalyticsTrackEventEventTypeEnter,
    EPXAnalyticsTrackEventEventTypeExit,
    EPXAnalyticsTrackEventEventTypeHeartbeat
};

typedef NS_ENUM(NSUInteger, EPXAnalyticsTrackEventPacketType) {
    EPXAnalyticsTrackEventPacketTypeUnknown = 0,
    EPXAnalyticsTrackEventPacketTypeEstimoteLocation
};

NS_ASSUME_NONNULL_BEGIN

@interface EPXAnalyticsTrackEvent : NSObject

@property (nonatomic, strong, readonly) NSString *deviceIdentifier;
@property (nonatomic, assign, readonly) EPXAnalyticsTrackEventEventType eventType;
@property (nonatomic, assign, readonly) EPXAnalyticsTrackEventPacketType packetType;
@property (nonatomic, assign, readonly) double expectedDistance;
@property (nonatomic, assign, readonly) BOOL inForeground;
@property (nonatomic, strong, readonly) NSUUID *distinctUUID;
@property (nonatomic, strong, readonly) NSDate *date;

- (instancetype)initWithDeviceIdentifier:(NSString *)deviceIdentifier
                               eventType:(EPXAnalyticsTrackEventEventType)eventType
                              packetType:(EPXAnalyticsTrackEventPacketType)packetType
                        expectedDistance:(double)expectedDistance
                            inForeground:(BOOL)inForeground
                            distinctUUID:(NSUUID *)distinctUUID
                                    date:(NSDate *)date;

@end

NS_ASSUME_NONNULL_END
