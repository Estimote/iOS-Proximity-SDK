//
//    ____  _            _              _   _       ____                        _
//   | __ )| |_   _  ___| |_ ___   ___ | |_| |__   / ___|  ___ __ _ _ __  _ __ (_)_ __   __ _
//   |  _ \| | | | |/ _ \ __/ _ \ / _ \| __| '_ \  \___ \ / __/ _` | '_ \| '_ \| | '_ \ / _` |
//   | |_) | | |_| |  __/ || (_) | (_) | |_| | | |  ___) | (_| (_| | | | | | | | | | | | (_| |
//   |____/|_|\__,_|\___|\__\___/ \___/ \__|_| |_| |____/ \___\__,_|_| |_|_| |_|_|_| |_|\__, |
//                                                                                      |___/
//
//
//  Copyright © 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "EBSScanInfo.h"

/*
 * Scan information class dedicated to Connectivity packet implemented in Firmware 4.0.
 * Service device is used to connect and change settings of particular physical device.
 */

@interface EBSScanInfoLocationConnectivity : EBSScanInfo

#pragma mark Properties
///-----------------------------------------
/// @name Properties
///-----------------------------------------

/*
 *  Cloud identifier of discovered device.
 */
@property (nonatomic, strong, readonly) NSString *publicID;

/**
 *  Version of application running on the device.
 */
@property (nonatomic, strong, readonly) NSString *appVersion;

/**
 *  Version of bootloader running on the device.
 */
@property (nonatomic, strong, readonly) NSString *bootloaderVersion;

/**
 *  Flag indicating if device was shaken.
 */
@property (nonatomic, strong, readonly) NSNumber *isShaken;

/**
 *  Flag indicating if device was scanned from very short distance.
 */
@property (nonatomic, strong, readonly) NSNumber *isNear;


@end
