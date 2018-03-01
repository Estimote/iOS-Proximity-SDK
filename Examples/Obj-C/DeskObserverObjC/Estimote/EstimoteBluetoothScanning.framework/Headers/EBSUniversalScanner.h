//
//    ____  _            _              _   _       ____                        _
//   | __ )| |_   _  ___| |_ ___   ___ | |_| |__   / ___|  ___ __ _ _ __  _ __ (_)_ __   __ _
//   |  _ \| | | | |/ _ \ __/ _ \ / _ \| __| '_ \  \___ \ / __/ _` | '_ \| '_ \| | '_ \ / _` |
//   | |_) | | |_| |  __/ || (_) | (_) | |_| | | |  ___) | (_| (_| | | | | | | | | | | | (_| |
//   |____/|_|\__,_|\___|\__\___/ \___/ \__|_| |_| |____/ \___\__,_|_| |_|_| |_|_|_| |_|\__, |
//                                                                                      |___/
//
//
//  Copyright (c) 2015 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>


@class EBSUniversalScanner;
@class EBSScanRestarter;
@class EBSTimerFactory;
@class EBSScanInfo;
@protocol EBSUniversalScannerProtocol;

NS_ASSUME_NONNULL_BEGIN


/**
 The possible errors returned during scanning Estimote Devices.
 */
typedef NS_ENUM(NSInteger, EBSUniversalScannerError) {
    /** The platform does not support Bluetooth low energy. */
    EBSUniversalScannerErrorBluetoothNotSupported,

    /** The app is not authorized to use Bluetooth low energy. */
    EBSUniversalScannerErrorUnauthorizedToUseBluetooth,

    /** Bluetooth is currently powered off. */
    EBSUniversalScannerErrorBluetoothOff,
};

/**
 Represents the current state of a Central Manager.
 */
typedef NS_ENUM(NSUInteger, EBSCentralManagerState) {
    /* State unknown, update imminent. */
    EBSCentralManagerStateUnknown = 0,
    /* The connection with the system service was momentarily lost, update imminent. */
    EBSCentralManagerStateResetting = 1,
    /* The platform doesn't support the Bluetooth Low Energy Central/Client role. */
    EBSCentralManagerStateUnsupported = 2,
    /* The application is not authorized to use the Bluetooth Low Energy Central/Client role. */
    EBSCentralManagerStateUnauthorized = 3,
    /* Bluetooth is currently powered off. */
    EBSCentralManagerStatePoweredOff = 4,
    /* Bluetooth is currently powered on and available to use. */
    EBSCentralManagerStatePoweredOn = 5,
};

/**
 Restart interval value that causes Universal Scanner to restart scanning
 with each received packet automatically.
 */
#define EBSUniversalScannerRestartIntervalRestartAlways -INFINITY

/**
 Restart interval value that causes Universal Scanner to never restart automatically.
 */
#define EBSUniversalScannerRestartIntervalRestartNever INFINITY

/**
 Defines the methods to receive info about scanned Estimote devices.
 */
@protocol EBSUniversalScannerDelegate <NSObject>

@optional

/**
 Invoked when a new scan info is available.
 
 @param universalScanner The scanner object that generated the event.
 @param scanInfo The info about scanned device.
 */
- (void)universalScanner:(id<EBSUniversalScannerProtocol>)universalScanner didScanEstimoteDevice:(EBSScanInfo *)scanInfo;

/**
 Invoked when an error occurred while scanning.
 
 @param universalScanner The scanner object that generated the event.
 @param error The error object containing information why scanning failed.
 */
- (void)universalScanner:(id<EBSUniversalScannerProtocol>)universalScanner didFailToScanWithError:(NSError *)error;

@end

/**
 Objects conforming to`EBSUniversalScannerProtocol` are used to scan for Estimote logical devices.
 In order to scan for a specific logical device or a set of such, there should
 exist for each a subclass of `ECOScanInfo` implementing parsing logic.
 
 To start scan simply implement EBSUniversalScannerDelegate and invoke:
 NSArray *devicesToScan = @[ [`EBSScanInfoLogicalDevice1` class],
 [`EBSScanInfoLogicalDevice2` class],
 [`EBSScanInfoLogicalDevice3` class]];
 EBSUniversalScanner *universalScanner = [EBSUniversalScanner new];
 universalScanner.delegate = myEBSUniversalScannerDelegate;
 [universalScanner startScanForDevicesRepresentedByClasses:devicesToScan];
 
 @see EBSUniversalScanner.
 */
@protocol EBSUniversalScannerProtocol <NSObject>

/**
 The delegate object to receive scan info events.
 */
@property (nonatomic, weak, readwrite, nullable) id<EBSUniversalScannerDelegate> delegate;

/**
 Informs if scan is in progress.
 */
@property (nonatomic, assign, readonly) BOOL isScanning;

/**
 An array of `ECOScanInfo` subclasses representing device types
 for which `EBSUniversalScanner` is scanning.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<Class> *deviceTypesToScan;

/**
 Core Bluetooth Central Manager state.
 */
@property (nonatomic, assign, readonly) EBSCentralManagerState state;

/**
 Start a scan for Estimote devices of specified types.
 Will override previous scan settings if scanner is scanning when the method is called.
 If at least one device type has no service defined `EBSUniversalScanner` won't scan in background.
 
 @param classesRepresentingDevices An array of `EBSScanInfo` subclasses representing device types to scan.
 */
- (void)startScanForDevicesRepresentedByClasses:(NSArray<Class> *)classesRepresentingDevices;

/**
 Stops the delivery of scan info.
 */
- (void)stopScan;

@end


/**
 Implementation of EBSUniversalScannerProtocol, uses Core Bluetooth manager under the hood
 to scan & deserialize Bluetooth packets broadcast by Estimote devices.
 */
@interface EBSUniversalScanner : NSObject <EBSUniversalScannerProtocol>


@property (nonatomic, weak, readwrite, nullable) id<EBSUniversalScannerDelegate> delegate;

/**
 Shared dispatch queue passed to CBCentralManagers upon creation.
 */
@property (nonatomic, strong, readonly, class) dispatch_queue_t defaultCBCentralManagerQueue;

/**
 Designated initializer.
 Useful for testing. In production, use -initWithScanRestartTimerTimeInterval.

 @param cbCentralManager Central manager to be used to scan for peripherals.
 @param scanRestarter Restarter used to determine whether a scan restart should happen.
 */
- (instancetype)initWithCBCentralManager:(CBCentralManager *)cbCentralManager
                           scanRestarter:(EBSScanRestarter *)scanRestarter NS_DESIGNATED_INITIALIZER;

/**
 Convenience initializer.
 Creates a CBCentralManager object operating at +defaultCBCentralManagerQueue queue, a new EBSScanRestarter object
 with provided restartInterval and packet-based restart mode, a new EBSTimerFactory and calls designated initializer.
 Note: This will initialize UniversalScanner with an old version of performing scanning restarts.

 @param restartInterval The interval after which a restart would be triggered with a new packet.
                        Pass in EBSUniversalScannerRestartIntervalRestartAlways to set restarting with every packet,
                        EBSUniversalScannerRestartIntervalRestartNever to disable automatic restarting at all.
 */
- (instancetype)initWithMinRestartInterval:(NSTimeInterval)restartInterval
__deprecated_msg("Use -initWithScanRestartTimerTimeInterval: instead");

/**
 Convenience initializer.
 Creates a CBCentralManager object operating at +defaultCBCentralManagerQueue queue, a new EBSScanRestarter object
 with provided restartInterval and timer-based restart mode and calls designated initializer.
 Note: This will initialize UniversalScanner enabling performing new way of scanning restarts based on timer.
 
 @param restartTimerTimeInterval The time interval for scanning restarts run on a timer.
 */
- (instancetype)initWithScanRestartTimerTimeInterval:(NSTimeInterval)restartTimerTimeInterval;

/**
 Convenience initializer.
 Calls -initWithScanRestartTimerTimeInterval: with default value.
 */
- (instancetype)init;

@end

NS_ASSUME_NONNULL_END
