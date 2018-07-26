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
#import "EPXProximityRange.h"
#import "EPXProximityZoneContext.h"

NS_ASSUME_NONNULL_BEGIN

//FIXME: fix this description
/**
 Represents a logical zone. Is represented by range from a beacon and attachment rule (attachment key + attachment value).
 Can be spanned by one or more beacons. Beacon identification is attachment-based
 (see https://github.com/Estimote/iOS-Proximity-SDK/blob/master/README.md for more info).
 
 Note: at the moment, Proximity SDK supports monitoring only 100 devices per zone. If more devices have their attachments
 matching the key, value defined in the zone, the first 100 are monitored.
 */
NS_SWIFT_NAME(ProximityZone)
@interface EPXProximityZone : NSObject

/**
 Range where the action should be reported.
 */
@property (nonatomic, strong, readonly) EPXProximityRange *range;

/**
 Tag assigned in Cloud to that zone.
 */
@property (nonatomic, readonly) NSString *tag;

/**
 Register block to be called when user enters proximity of Estimote devices with matching tag.
 Beacon identification is tag-based (see https://github.com/Estimote/iOS-SDK/blob/sdk_5/README.md for more info).
 */
@property (nonatomic, copy, readwrite, nullable) void (^onEnter)(EPXProximityZoneContext * zoneContext);

/**
 Block to be called when user exits proximity of Estimote devices with matching tag.
 Beacon identification is tag-based (see https://github.com/Estimote/iOS-SDK/blob/sdk_5/README.md for more info).
 */
@property (nonatomic, copy, readwrite, nullable) void (^onExit)(EPXProximityZoneContext * zoneContext);

/**
 Block to be called each time a new beacon is detected in user's range and each time a beacon disappears
 from user's range.
 */
@property (nonatomic, copy, readwrite, nullable) void (^onContextChange)(NSSet<EPXProximityZoneContext *> *zoneContexts);

/**
 Init is unavailable.
 */
- (instancetype)init NS_UNAVAILABLE;
/**
 New is unavailable.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Designated initilizer.

 @param tag Tag name assigned to the zone.
 @param range Range where the action should be reported.
 */
- (instancetype)initWithTag:(NSString *)tag range:(EPXProximityRange *)range NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
