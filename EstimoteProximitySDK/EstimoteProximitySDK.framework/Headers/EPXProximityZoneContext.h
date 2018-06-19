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

@class EPXDeviceAttachment;

NS_SWIFT_NAME(ProximityZoneContext)
/**
 Interface providing all contextual data about a Proximity Zone.
 */
@protocol EPXProximityZoneContext <NSObject>

/**
 Identifier of a device that is the zone's source.
 */
@property (nonatomic, readonly) NSString *deviceIdentifier;
/**
 Tag assigned in Cloud to that zone's source.
 */
@property (nonatomic, readonly) NSString *tag;
/**
 Dictionary of attachments assigned in Cloud to that zone's source.
 */
@property (nonatomic, readonly, nullable) NSArray<EPXDeviceAttachment *> *attachments;

@end

NS_ASSUME_NONNULL_END
