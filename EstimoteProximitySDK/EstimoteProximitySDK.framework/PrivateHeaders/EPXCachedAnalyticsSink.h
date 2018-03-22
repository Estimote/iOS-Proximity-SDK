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
#import "EPXAnalyticsSink.h"
#import "EPXAnalyticsTrackEventsUploader.h"
#import "EPXAnalyticsRepository.h"
#import "EPXAnalyticsTrackEventsUploader.h"

@class EPXAnalyticsTrackEvent;

NS_ASSUME_NONNULL_BEGIN

/**
 Caches analytics events, persists them on disk, schedules uploading events to Cloud, clears uploaded events.
 */
@interface EPXCachedAnalyticsSink : NSObject <EPXAnalyticsSink,
        EPXAnalyticsTrackEventsUploaderDecisionSource,
        EPXAnalyticsTrackEventsUploaderDelegate>

/*
 Repository used to save and retrieve analytics events.
 */
@property (nonatomic, strong, readonly) id<EPXAnalyticsRepository> analyticsRepository;

/*
 Number of events sent in each batch in analytics requests.
 * */
@property (nonatomic, assign, readonly) NSUInteger batchSize;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithAnalyticsRepository:(id<EPXAnalyticsRepository>)analyticsRepository
                        trackEventsUploader:(id<EPXAnalyticsTrackEventsUploader>)trackEventsUploader
                                  batchSize:(NSUInteger)batchSize NS_DESIGNATED_INITIALIZER;

/*
 Transforms provided trackEvent to entity consumable by the database, inserts the entity to the database,
 triggers track events batch upload if needed.
 */
- (void)addTrackEvent:(EPXAnalyticsTrackEvent *)trackEvent;

@end

NS_ASSUME_NONNULL_END
