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

#ifndef EPXAnalyticsRepository_h
#define EPXAnalyticsRepository_h

@import Foundation;

@class EPXAnalyticsTrackEventsEntity;

NS_ASSUME_NONNULL_BEGIN

@protocol EPXAnalyticsRepository <NSObject>

/**
 Opens or creates a file in "<Caches Dir>/com.estimote.EstimoteProximitySDK/analytics_events.sqlite".
 
 Checks if the file is a proper SQLite file and if the database contains tables with required schema.
 Overwrites the file if it's invalid, drops tables if the schema is invalid.
 Results in an open database object.
 
 @return YES if opening/creating database succeeded, NO otherwise.
 */
- (BOOL)setupDatabase;

/**
 Inserts track event entity to the database. Requires database being set up before.
 
 @param event Event to save.
 */
- (void)saveEvent:(EPXAnalyticsTrackEventsEntity *)event;

/**
 Retrieves a number of oldest events stored in the database.
 
 @param limit Number of events to retrieve.
 @return Retrieved events.
 */
- (NSArray<EPXAnalyticsTrackEventsEntity *> *)findOldestEventsWithLimit:(NSInteger)limit;

/**
 Delete from the database every event with timestamp smaller or equal to the one provided.
 
 @param timestampDate Date (its timeIntervalSince1970) that events' timestamps are compared with.
 */
- (void)deleteAllEventsBeforeOrAtTimestampDate:(NSDate *)timestampDate;

/**
 Returns number of events stored in the database.
 */
- (NSUInteger)eventsCount;

@end

NS_ASSUME_NONNULL_END

#endif /* EPXAnalyticsRepository_h */
