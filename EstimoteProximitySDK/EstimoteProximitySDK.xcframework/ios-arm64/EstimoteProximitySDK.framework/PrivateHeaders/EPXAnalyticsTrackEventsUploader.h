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

#ifndef EPXAnalyticsTrackEventsUploader_h
#define EPXAnalyticsTrackEventsUploader_h

#import <Foundation/Foundation.h>

@class EPXAnalyticsTrackEvent;
@class EPXCloudAnalyticsTrackEventsSender;
@protocol EPXAnalyticsTrackEventsSender;

NS_ASSUME_NONNULL_BEGIN

@protocol EPXAnalyticsTrackEventsUploader

/**
 Tells if an upload operation is in progress.
 
 Note: at the time of calling `-[delegate didUploadTrackEvents:]`, or `-[delegate didFailUploadingTrackEvents:afterFailedAttemptsCount:]` this property is still YES.
 */
- (BOOL)uploadIsInProgress;

/**
 Sends a request to Cloud with provided track event. If the request fails, asks `decisionSource` if the request should be retried.
 
 Note: this method doesn't check if a batch upload is already happening. This should be done separately, using `-uploadIsInProgress`.
 
 @param trackEvents Array of track events to send in request as a batch.
 */
- (void)scheduleUploadingTrackEvents:(NSArray<EPXAnalyticsTrackEvent *> *)trackEvents;

@end


/**
 Asked by EPXAnalyticsTrackEventsUploader about policy on Cloud request retrial.
 */
@protocol EPXAnalyticsTrackEventsUploaderDecisionSource <NSObject>

- (BOOL)shouldUploaderRetry:(id<EPXAnalyticsTrackEventsUploader>)uploader
   afterFailedAttemptsCount:(NSInteger)failedAttemptsCount
 whenRequestFailedWithError:(NSError *)requestError;

@end

/**
 Notified by EPXAnalyticsTrackEventsUploader when an upload succeeds or fails.
 */
@protocol EPXAnalyticsTrackEventsUploaderDelegate <NSObject>

- (void)uploader:(id<EPXAnalyticsTrackEventsUploader>)uploader didUploadTrackEvents:(NSArray<EPXAnalyticsTrackEvent *> *)trackEventsVOs;

// TODO: consider removing it if unused
- (void)uploader:(id<EPXAnalyticsTrackEventsUploader>)uploader didFailUploadingTrackEvents:(NSArray<EPXAnalyticsTrackEvent *> *)trackEventsVOs afterFailedAttemptsCount:(NSInteger)failedAttemptsCount;

@end

NS_ASSUME_NONNULL_END

#endif /* EPXAnalyticsTrackEventsUploader_h */

