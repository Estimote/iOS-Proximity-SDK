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

@class FMDatabase_EPX;

NS_ASSUME_NONNULL_BEGIN


/**
 Opens, creates or overwrites SQLite file at given path and provides a FMDatabase object.
 */
@interface EPXSQLiteCreator : NSObject

/**
 Unavailable
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Unavailable
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Designated initializer.

 @param fileManager File manager object used to create enclosing directory and remove invalid file at provided URL.
 */
- (instancetype)initWithFileManager:(NSFileManager *)fileManager NS_DESIGNATED_INITIALIZER;

/**
 Attempts to open SQLite file at given URL. Creates enclosing directory if needed. Removes file at given URL if it isn't
 a valid SQLite database file. Calls -open on the database object before returning.

 @param databaseURL URL of database file to open.
 @return Open database object. Nil if couldn't create parent directory, remove invalid file
         or failed to init and open database file properly.
 */
- (nullable FMDatabase_EPX *)openOrOverwriteDatabaseAtURL:(NSURL *)databaseURL;

@end

NS_ASSUME_NONNULL_END
