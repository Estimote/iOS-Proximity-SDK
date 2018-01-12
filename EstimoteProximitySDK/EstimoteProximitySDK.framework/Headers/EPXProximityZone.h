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
#import "EPXProximityRange.h"
#import "EPXProximityDeviceAttachment.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a logical zone. Is represented by range from a beacon and attachment rule (attachment key + attachment value).
 Can be spanned by one or more beacons. Beacon identification is attachment-based
 (see https://github.com/Estimote/iOS-SDK/blob/sdk_5/README.md for more info).
 */
@interface EPXProximityZone : NSObject

/**
 Range where the action should be reported.
 */
@property (nonatomic, strong, readonly) EPXProximityRange *range;

/**
 Key that should be in a beacon's attachment payload so it's classified for reporting.
 */
@property (nonatomic, strong, readonly) NSString *attachmentKey;

/**
 Value that should be in a beacon's attachment payload so it's classified for reporting.
 */
@property (nonatomic, strong, readonly, nullable) NSString *attachmentValue;

/**
 Register block to be called when user enters proximity of Estimote devices with matching attachment.
 Beacon identification is attachment-based (see https://github.com/Estimote/iOS-SDK/blob/sdk_5/README.md for more info).
 */
@property (nonatomic, copy, readwrite, nullable) void (^onEnterAction)(EPXProximityDeviceAttachment *triggeringDeviceAttachment);

/**
 Block to be called when user exits proximity of Estimote devices with matching attachment.
 Beacon identification is attachment-based (see https://github.com/Estimote/iOS-SDK/blob/sdk_5/README.md for more info).
 */
@property (nonatomic, copy, readwrite, nullable) void (^onExitAction)(EPXProximityDeviceAttachment *triggeringDeviceAttachment);

/**
 Block to be called each time a new beacon is detected in user's range and each time a beacon disappears
 from user's range.
 */
@property (nonatomic, copy, readwrite, nullable) void (^onChangeAction)(NSSet<EPXProximityDeviceAttachment *> *attachmentsCurrentlyInside);

/**
 Init is unavailable.
 */
- (instancetype)init NS_UNAVAILABLE;
/**
 New is unavailable.
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Designated initalizer.

 @param range Range where the action should be reported.
 @param attachmentKey Key that should be in a beacon's attachment payload so it's classified for reporting.
 @param attachmentValue Value that should be in a beacon's attachment payload so it's classified for reporting.
 */
- (instancetype)initWithRange:(EPXProximityRange *)range
                attachmentKey:(NSString *)attachmentKey
              attachmentValue:(nullable NSString *)attachmentValue NS_DESIGNATED_INITIALIZER;

/**
 Convenience initializer. Calls the designated inializer with nil as attachmentValue.

 @param range Range where the action should be reported.
 @param attachmentKey Key that should be in a beacon's attachment payload so it's classified for reporting.
 */
- (instancetype)initWithRange:(EPXProximityRange *)range
                attachmentKey:(NSString *)attachmentKey;

@end

NS_ASSUME_NONNULL_END
