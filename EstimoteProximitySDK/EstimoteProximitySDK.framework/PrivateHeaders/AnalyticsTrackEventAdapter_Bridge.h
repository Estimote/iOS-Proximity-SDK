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

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@class EPXAnalyticsTrackEvent;
@class EPXAnalyticsTrackEventsEntity;


@interface EPXAnalyticsTrackEventAdapter : NSObject

- (EPXAnalyticsTrackEvent *)trackEventFromEntity:(EPXAnalyticsTrackEventsEntity *)entity;
- (EPXAnalyticsTrackEventsEntity *)entityFromTrackEvent:(EPXAnalyticsTrackEvent *)trackEvent;

@end

NS_ASSUME_NONNULL_END
