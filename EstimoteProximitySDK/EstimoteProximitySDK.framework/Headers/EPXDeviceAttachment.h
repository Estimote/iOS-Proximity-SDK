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

NS_ASSUME_NONNULL_BEGIN


/**
 Represents payload attached to a device in Estimote Cloud.
 The attachments can be configured by visiting https://cloud.estimote.com/# and selecting a device's settings.
 See https://github.com/Estimote/iOS-Proximity-SDK/blob/master/README.md for more info.
 */
@interface EPXDeviceAttachment : NSObject

/**
 Device identifier that has the attachment.
 */
@property (nonatomic, strong, readonly) NSString *deviceIdentifier;

/**
 Payload attached to the device (tag parsed to payload).
 */
@property (nonatomic, strong, readonly) NSDictionary<NSString *, id> *payload;

/**
 Init is disabled for this class.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 New is disabled for this class.
 */
+ (instancetype)new NS_UNAVAILABLE;


/**
 Designated initializer.

 @param deviceIdentifier Device identifier that has the attachment.
 @param payload Payload attached to the device (tag parsed to payload).
 */
- (instancetype)initWithDeviceIdentifier:(NSString *)deviceIdentifier
                                 payload:(NSDictionary<NSString *, id> *)payload NS_DESIGNATED_INITIALIZER;

#pragma mark Equality

/**
 Compare attachment objects. For both obhects, this method invokes `-[NSString isEqualToString:]` on `deviceIdentifier`
 and `-[NSDictionary isEqualToDictionary:]` on `attachmentPayload`.
 */
- (BOOL)isEqualToAttachment:(EPXDeviceAttachment *)other;

/**
 Compare pointer values, classes and invoke `-isEqualToAttachment`.
 */
- (BOOL)isEqual:(nullable id)other;

/**
 `deviceIdentifier` hash XORed with `attachmentPayload` hash.
 */
- (NSUInteger)hash;

@end

NS_ASSUME_NONNULL_END
