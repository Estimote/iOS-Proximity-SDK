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

#ifndef EPXAnalyticsSink_h
#define EPXAnalyticsSink_h

@class EPXAnalyticsTrackEvent;

NS_ASSUME_NONNULL_BEGIN


@protocol EPXAnalyticsSink <NSObject>

/*
 Transforms provided trackEventVO to entity consumable by the database, inserts the entity to the database,
 triggers track events batch upload if needed.
 */
- (void)addTrackEvent:(EPXAnalyticsTrackEvent *)trackEvent;

@end

NS_ASSUME_NONNULL_END

#endif /* EPXAnalyticsSink_h */
