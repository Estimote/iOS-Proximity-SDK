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
 Encapsulates decision making on whether an attachment fits a given zone, or whether attachment insertion/removal
 should trigger callbacks.
 */
@interface EPXProximityZoneEngine : NSObject

/**
 Decide whether the provided attachment matches zone's predicate (payload attachment key, value pair).

 @param attachment Attachment to be tested.
 @param zone Zone to be tested against.
 @return YES if attachment payload contains value defined in zone for key defined in zone.
 */
- (BOOL)attachment:(EPXDeviceAttachment *)attachment matchesZone:(EPXProximityZone *)zone;

/**
 Descide whether inserting attachment should trigger "enter" monitoring callback.

 @param attachmentsInside Set of device attachment inside zone before insertion.
 @return YES if attachmentsInside contains no entries.
 */
- (BOOL)insertionToAttachmentsSetShouldTriggerEnter:(NSSet<EPXDeviceAttachment *> *)attachmentsInside;

/**
 Decide whether removing attachment should trigger "exit" monitoring callback.

 @param attachmentToRemove Attachment to check.
 @param attachmentsInside Set of attachments inside zone before removal.
 @return YES if attachmentsInside contains exactly one object and it's equal to `attachmentToRemove`. NO otherwise.
 */
- (BOOL)shouldTriggerExitWhenRemovingAttachment:(EPXDeviceAttachment *)attachmentToRemove
                             fromAttachmentsSet:(NSSet<EPXDeviceAttachment *> *)attachmentsInside;

/**
 Check which attachments match provided zone and return their identifiers.

 @param attachments Array of attachments.
 @param zone Zone to filter attachments against.
 @return Array of identifiers.
 */
- (NSArray<NSString *> *)identifiersFromAttachments:(NSArray<EPXDeviceAttachment *> *)attachments
                                       matchingZone:(EPXProximityZone *)zone;

@end

NS_ASSUME_NONNULL_END

