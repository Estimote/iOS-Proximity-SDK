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

FOUNDATION_EXPORT NSString * const EPXEncryptedFramesRelayErrorDomain;

/**
 Possible errors passed by EPXEncryptedFramesRelayDelegate.
 */
typedef NS_ENUM(NSInteger, EPXEncryptedFramesRelayError) {
    /* Unknown error probably due to a bug. */
    EPXEncryptedFramesRelayErrorUnknown = 0,
    
    EPXEncryptedFramesRelayErrorURLSessionFailed = -1,
    EPXEncryptedFramesRelayErrorInvalidResponse = -2,
    
    EPXEncryptedFramesRelayErrorInvalidRequest = 400,
    EPXEncryptedFramesRelayErrorUnauthorized = 401,
    EPXEncryptedFramesRelayErrorNotFound = 404,
    EPXEncryptedFramesRelayErrorInternalSeverError = 500
};

@class EPXEncryptedFramesRelay;
@class EPXCloudCredentials;

@protocol EPXEncryptedFramesRelayDelegate

- (void)relay:(EPXEncryptedFramesRelay *)relay didFetchTitle:(nullable NSString *)title withError:(nullable NSError *)error;

@end

/**
 Handles beacon monitoring, sending payloads to backend service and fetching venue title to show on screen.
 */
@interface EPXEncryptedFramesRelay : NSObject

- (instancetype)initWithBackendURL:(NSURL *)backendURL
                  cloudCredentials:(EPXCloudCredentials *)cloudCredentials
        desiredMeanTriggerDistance:(double)desiredMeanTriggerDistance
                          delegate:(nullable id<EPXEncryptedFramesRelayDelegate>)delegate;

- (instancetype)initWithBackendURL:(NSURL *)backendURL
                       bearerToken:(NSString *)bearerToken
        desiredMeanTriggerDistance:(double)desiredMeanTriggerDistance
                          delegate:(id<EPXEncryptedFramesRelayDelegate>)delegate;

- (void)start;
- (void)stop;

@end

NS_ASSUME_NONNULL_END

