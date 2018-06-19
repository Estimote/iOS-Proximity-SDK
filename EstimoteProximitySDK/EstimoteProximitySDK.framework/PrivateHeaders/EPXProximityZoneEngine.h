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

@class EPXProximityZone;
@class EPXDeviceAttachment;

NS_ASSUME_NONNULL_BEGIN

/**
 Encapsulates decision making on whether a tag fits a given zone, or whether tag insertion/removal
 should trigger callbacks.
 */
@interface EPXProximityZoneEngine : NSObject

/**
 Decides whether the provided tag matches given zone.

 @param tag Tag to be tested.
 @param zone Zone to be tested against.
 @return YES if tag matches the tag provided with the zone.
 */
- (BOOL)tag:(NSString *)tag matchesZone:(EPXProximityZone *)zone;

/**
 Decides whether inserting new tag should trigger an enter callback.

 @param tagsInside Set of tags inside zone before insertion.
 @return YES if tagsInside contains no entries.
 */
- (BOOL)insertionToTagsSetShouldTriggerEnter:(NSSet<NSString *> *)tagsInside;

/**
 Decides whether removing tag should trigger an exit callback.

 @param tagToRemove Tag to be removed from collection.
 @param tagsInside Set of tags inside zone before removal.
 @return YES if tagsInside contains exactly one object and it's equal to `tagToRemove`.
 */
- (BOOL)shouldTriggerExitWhenRemovingTag:(NSString *)tagToRemove fromTagsSet:(NSSet<NSString *> *)tagsInside;

@end

NS_ASSUME_NONNULL_END

