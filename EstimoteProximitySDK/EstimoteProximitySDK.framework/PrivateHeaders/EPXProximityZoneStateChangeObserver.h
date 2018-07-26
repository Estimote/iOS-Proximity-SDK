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
@class EPXProximityZoneEngine;
@class EPXProximityZoneContext;

NS_ASSUME_NONNULL_BEGIN

@protocol EPXProximityZoneContextStore <NSObject>

/**
 Proximity zone this object wraps and holds state for.
 */
@property (nonatomic, strong, readonly) EPXProximityZone *proximityZone;

- (void)insertZoneContext:(EPXProximityZoneContext *)context;
- (void)removeZoneContext:(EPXProximityZoneContext *)context;

@end

/**
 Wraps a Proximity Zone to hold state of devices that are currently inside the zone (`deviceAttachmentsInside`).
 Additionally, allows to insert a device to the zone or remove it. Calls zone's registered callback if needed.
 */
@interface EPXProximityZoneStateChangeObserver : NSObject <EPXProximityZoneContextStore>

/**
 Proximity zone this object wraps and holds state for.
 */
@property (nonatomic, strong, readonly) EPXProximityZone *proximityZone;

/**
 Proximity Zone Engine used for decisions on when enter/exit/change handlers should be called.
 */
@property (nonatomic, strong, readonly) EPXProximityZoneEngine *engine;

/**
 Set of device attachments that are currently inside the zone.
 */
@property (nonatomic, strong, readonly) NSSet<EPXProximityZoneContext *> *zoneContextsInside;

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

 @param zone Proximity Zone to hold state for.
 @param engine Proximity Zone Engine used for decisions on when enter/exit/change handlers should be called.
 */
- (instancetype)initWithZone:(EPXProximityZone *)zone
                      engine:(EPXProximityZoneEngine *)engine NS_DESIGNATED_INITIALIZER;

/**
 Check whether provided zone's context matches the zone, inserts it into `zoneContextsInside` set and calls `proximityZone`'s callbacks if necessary.
 Asks `engine` to decide whether enter/exit/change callbacks should happen.

 @param context Attachment to be inserted.
 */
- (void)insertZoneContextAndCallHandlerIfNeeded:(EPXProximityZoneContext *)context;

/**
 Check whether provided zone's context matches the zone, removes it from `zoneContextsInside` set and calls `proximityZone`'s callbacks if necessary.
 Asks `engine` to decide whether enter/exit/change callbacks should happen.

 @param context Attachment to be removed.
 */
- (void)removeZoneContextAndCallHandlerIfNeeded:(EPXProximityZoneContext *)context;

@end

NS_ASSUME_NONNULL_END
