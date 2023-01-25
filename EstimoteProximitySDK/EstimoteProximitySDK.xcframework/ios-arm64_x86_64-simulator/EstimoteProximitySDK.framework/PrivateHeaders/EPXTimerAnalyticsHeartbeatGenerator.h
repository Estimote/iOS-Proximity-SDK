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

@class EPXAnalyticsTimerFactory;

NS_ASSUME_NONNULL_BEGIN


@protocol EPXAnalyticsHeartbeatGenerator

/**
 All identifiers registered using `-startGeneratingHeartbeatForIdentifier:`.
 Calling `-stopGeneratingHeartbeatForIdentifier:` removes the identifier from this collection.
 */
@property (nonatomic, strong, readonly) NSSet<NSString *> *heartbeatIdentifiers;

/**
 Create & schedule a timer for generating heartbeat events for a given identifier.
 Generated events are reported by calling delegate.

 Calling this method consecutively with the same argument has the same effect as calling it once.

 @param identifier String used to identify timers, i.e. device identifier of the beacon that heartbeat events should be
                   generated for.
 */
- (void)startGeneratingHeartbeatForIdentifier:(NSString *)identifier;

/**
 Invalidate and remove the timer for generating heartbeat events for given device.
 Stops calling delegate with events generated for this identifier.

 @param identifier String used to identify timers, i.e. device identifier of the beacon that heartbeat events generation
                   should be stopped.
 */
- (void)stopGeneratingHeartbeatForIdentifier:(NSString *)identifier;

@end


@protocol EPXAnalyticsHeartbeatGeneratorDelegate

/**
 Tells the delegate that heartbeat generator's timer generated a tick.
 @param heartbeatGenerator Object that triggered the heartbeat event.
 @param heartbeatDate Date of the heartbeat event.
 @param identifier Identifier that was used to start generating heartbeat events.
 */
- (void)heartbeatGenerator:(id<EPXAnalyticsHeartbeatGenerator>)heartbeatGenerator
             didBeatAtDate:(NSDate *)heartbeatDate
             forIdentifier:(NSString *)identifier;

@end


@interface EPXTimerAnalyticsHeartbeatGenerator : NSObject <EPXAnalyticsHeartbeatGenerator>

/**
 All identifiers registered using `-startGeneratingHeartbeatForIdentifier:`.
 Calling `-stopGeneratingHeartbeatForIdentifier:` removes the identifier from this collection.
 */
@property (nonatomic, strong, readonly) NSSet<NSString *> *heartbeatIdentifiers;
@property (nonatomic, weak, readwrite) id<EPXAnalyticsHeartbeatGeneratorDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 Designated initializer.
 @param timerFactory Timer factory used to create NSTimer objects.
 @param heartbeatInterval Interval at which timers are set to fire.
 @param currentDateProviderBlock Block used to determine current date when calling the delegate.
 @param delegate Delegate object to call on timer ticks.
 */
- (instancetype)initWithTimerFactory:(EPXAnalyticsTimerFactory *)timerFactory heartbeatInterval:(NSTimeInterval)heartbeatInterval currentDateProviderBlock:(NSDate *(^)(void))currentDateProviderBlock delegate:(nullable id <EPXAnalyticsHeartbeatGeneratorDelegate>)delegate;

/**
 Convenience initializer. Calls designated initializer with newly created timer factory & nil delegate.
 @param heartbeatInterval Interval at which timers are set to fire.
 @param currentDateProviderBlock Block used to determine current date when calling the delegate.
 */
- (instancetype)initWithHeartbeatInterval:(NSTimeInterval)heartbeatInterval         currentDateProviderBlock:(NSDate *(^)(void))currentDateProviderBlock;

/**
 Create & schedule a timer for generating heartbeat events for a given identifier.
 Generated events are reported by calling delegate.
 
 Calling this method consecutively with the same argument has the same effect as calling it once.

 @param identifier String used to identify timers, i.e. device identifier of the beacon that heartbeat events should be
                   generated for.
 */
- (void)startGeneratingHeartbeatForIdentifier:(NSString *)identifier;

/**
 Invalidate and remove the timer for generating heartbeat events for given device.
 Stops calling delegate with events generated for this identifier.

 @param identifier String used to identify timers, i.e. device identifier of the beacon that heartbeat events generation
                   should be stopped.
 */
- (void)stopGeneratingHeartbeatForIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
