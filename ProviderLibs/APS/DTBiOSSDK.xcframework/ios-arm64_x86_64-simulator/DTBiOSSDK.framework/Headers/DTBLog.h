//
//  DTBLog.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// Log level for the DTBLog util class.
// Lower = finer-grained logs.
typedef enum
{
    DTBLogLevelAll   = 0,
    DTBLogLevelTrace = 10,
    DTBLogLevelDebug = 20,
    DTBLogLevelInfo  = 30,
    DTBLogLevelWarn  = 40,
    DTBLogLevelError = 50,
    DTBLogLevelFatal = 60,
    DTBLogLevelOff   = 70
} DTBLogLevel;

/**
 * Application implements this protocol if further manipulations besides NSLog are required
 *
 */
@protocol DTBLogDelegate
/**
 * delegate is call with a message originated from DTBLog
 */
- (void)onMessageLogged:(NSString *)message;

@end


@protocol DTBLogTagDelegate

- (NSString * _Nonnull) requestedTag;
/**
 * delegate is call with a message originated from DTBLog
 */
- (void)onMessageLogged:(NSString *)message;

@end

// Util class to log the events in DTB Mobile API.
// Logger works only when the constant DTB_DEBUG_MODE is set to 1 in DTBConstants.h file
// If DTB_DOMAIN is set to BETA then default log level is DTBLogLevelAll
// otherwise default Log level is DTBLogLevelError.
@interface DTBLog : NSObject

// Returns the current set log level
+ (DTBLogLevel)logLevel;

// Set's the log level
+ (void)setLogLevel:(DTBLogLevel) level;

+ (void)setDelegate:(id<DTBLogDelegate> _Nullable)delegate;

+ (void)setTagDelegate:(id<DTBLogTagDelegate> _Nullable)delegate;

+ (void)trace:(NSString *)message;
+ (void)debug:(NSString *)message;
+ (void)info:(NSString *)message;
+ (void)warn:(NSString *)message;
+ (void)error:(NSString *)message;
+ (void)fatal:(NSString *)message;

+ (void)traceWithTag:(NSString *)tag message:(NSString *)message;
+ (void)debugWithTag:(NSString *)tag message:(NSString *)message;
+ (void)infoWithTag:(NSString *)tag message:(NSString *)message;
+ (void)warnWithTag:(NSString *)tag message:(NSString *)message;
+ (void)errorWithTag:(NSString *)tag message:(NSString *)message;
+ (void)fatalWithTag:(NSString *)tag message:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
