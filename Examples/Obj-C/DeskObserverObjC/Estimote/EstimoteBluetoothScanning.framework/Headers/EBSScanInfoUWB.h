//
//    ____  _            _              _   _       ____                        _
//   | __ )| |_   _  ___| |_ ___   ___ | |_| |__   / ___|  ___ __ _ _ __  _ __ (_)_ __   __ _
//   |  _ \| | | | |/ _ \ __/ _ \ / _ \| __| '_ \  \___ \ / __/ _` | '_ \| '_ \| | '_ \ / _` |
//   | |_) | | |_| |  __/ || (_) | (_) | |_| | | |  ___) | (_| (_| | | | | | | | | | | | (_| |
//   |____/|_|\__,_|\___|\__\___/ \___/ \__|_| |_| |____/ \___\__,_|_| |_|_| |_|_|_| |_|\__, |
//                                                                                      |___/
//
//
//  Copyright © 2017 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "EBSScanInfo.h"


typedef NS_ENUM(NSInteger, EBSScanInfoRangingInProgressFlag) {
    /* Broadcasting only */
    EBSScanInfoRangingNotInProgress = 0,
    /* Ranging us in progress */
    EBSScanInfoRangingInProgress = 1,
};


@interface EBSScanInfoUWB : EBSScanInfo

#pragma mark Properties
///-----------------------------------------
/// @name Properties
///-----------------------------------------

/**
 * Type of Estimote Broadcasting Scheme frame.
 */
@property (nonatomic, assign, readonly) NSInteger frameType;

/**
 * Version of Estimote Broadcasting Scheme protocol.
 */
@property (nonatomic, assign, readonly) NSInteger protocolVersion;

/**
 * Public identifier of the Estimote UWB Device.
 */
@property (nonatomic, strong, readonly) NSString *publicId;

/**
 * Pairs of mac-distance estimates.
 */
@property (nonatomic, strong, readonly) NSDictionary<NSString*, NSNumber*> *distanceEstimates;

/**
 * Ranging in progress flag.
 */
@property (nonatomic, assign, readonly) EBSScanInfoRangingInProgressFlag rip;


#pragma mark - Overrides

- (id)initWithCoder:(NSCoder *)coder;
- (void)encodeWithCoder:(NSCoder *)coder;

@end
