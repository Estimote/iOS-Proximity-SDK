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

@interface EPXEncryptedFramesRelayInternal : NSObject

- (instancetype)initWithBackendURL:(NSURL *)backendURL
                  cloudCredentials:(EPXCloudCredentials *)cloudCredentials
        desiredMeanTriggerDistance:(double)desiredMeanTriggerDistance
                didFetchTitleBlock:(void (^)(NSString * _Nullable, NSError * _Nullable ))didFetchTitleBlock;

- (instancetype)initWithBackendURL:(NSURL *)backendURL
                       bearerToken:(NSString *)bearerToken
        desiredMeanTriggerDistance:(double)desiredMeanTriggerDistance
                didFetchTitleBlock:(void (^)(NSString * _Nullable, NSError * _Nullable ))didFetchTitleBlock;

- (void)start;
- (void)stop;

@end

NS_ASSUME_NONNULL_END
