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
 Represents range of a proximity where enter/exit events should occur.
 
 Note:
 Due to BLE signal instability the actual place where notifications occur will differ.
 The `meanTriggerDistance` value defines the desired mean of distance at which events occur.
 
 The distance is rounded up to decimeters. Don't expect decimeter accuracy; this is only for simplification
 of EPXProximityRange objects comparison.
 */
@interface EPXProximityRange : NSObject

/**
 Distance in meters where enter/exit events should occur passed in initializer rounded to decimeters (to 0.1).
 */
@property (nonatomic, assign, readonly) double desiredMeanTriggerDistance;

/**
 Convenience factory for near range. Returns range with meanTriggerDistance set to 1m.
 
 It's a class property instead of class method to enable good-looking Swift code.
 */
@property (nonatomic, copy, readonly, class) EPXProximityRange *nearRange;

/**
 Convenience factory for far range. Returns range with meanTriggerDistance set to 5m.
 
 It's a class property instead of class method to enable good-looking Swift code.
 */
@property (nonatomic, copy, readonly, class) EPXProximityRange *farRange;

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

 @param desiredMeanTriggerDistance Distance in meters where enter/exit events should occur rounded to decimeters (to 0.1).
                                   It has to be a non-negative number.
 
 @return Initialized object. Nil if passed desiredMeanTriggerDistance is negative.
 */
- (nullable instancetype)initWithDesiredMeanTriggerDistance:(double)desiredMeanTriggerDistance NS_DESIGNATED_INITIALIZER;

/**
 Convenience factory method. Calls `-initWithMeanTriggerDistance:`.

 @param desiredMeanTriggerDistance Distance in meters where enter/exit events should occur rounded to decimeters (to 0.1).
                                   It has to be a non-negative number.
 
 @return Initialized object. Nil if passed desiredMeanTriggerDistance is negative.
 */
+ (nullable instancetype)customRangeWithDesiredMeanTriggerDistance:(double)desiredMeanTriggerDistance
NS_SWIFT_NAME(custom(desiredMeanTriggerDistance:));

#pragma mark isEqual overrides
- (BOOL)isEqualToRange:(EPXProximityRange *)otherRange;
- (BOOL)isEqual:(nullable id)otherObject;
- (NSUInteger)hash;

@end

NS_ASSUME_NONNULL_END
