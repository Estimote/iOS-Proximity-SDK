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
 Checks database table schema.
 */
@interface EPXSQLiteTableInspector : NSObject

/**
 Query the database for table schema using "PRAGMA table_info();" SQL query.
 
 From https://sqlite.org/pragma.html#pragma_table_info :
 This pragma returns one row for each column in the named table. Columns in the result set include the column name,
 data type, whether or not the column can be NULL, and the default value for the column. The "pk" column in the result
 set is zero for columns that are not part of the primary key, and is the index of the column in the primary key for
 columns that are part of the primary key.

 @param tableName Table to inspect.
 @param database Database object to execute the query on.
 @return Array of dictionaries. Each table column results in one dictionary.
 */
- (NSArray<NSDictionary<NSString *, id> *> *)tableColumnInfoDictionariesForTableNamed:(NSString *)tableName
                                                                           inDatabase:(FMDatabase_EPX *)database;


/**
 Checks whether the column info dictionaries matches pattern.
 The pattern is defined by a dictionary where a key is column name, and a value is expected column type.
 SQLite column types are "TEXT", "NUMERIC", "INTEGER", "REAL", "BLOB".

 @param columnInfos Column info dictionaries to be checked, one dictionary per column.
 @param columnNameTypes Column name to column type pattern to check against.
 @return YES if each column name from columnNameTypes exists in columnInfos
 and type of that column matches the type in columnNameTypes value.
 */
- (BOOL)schemaWithColumnInfos:(NSArray<NSDictionary<NSString *, id> *> *)columnInfos
       matchesColumnNameTypes:(NSDictionary<NSString *, NSString *> *)columnNameTypes;

@end

NS_ASSUME_NONNULL_END
