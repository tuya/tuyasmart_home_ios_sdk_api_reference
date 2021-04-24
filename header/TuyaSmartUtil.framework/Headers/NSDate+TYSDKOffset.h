//
//  NSDate+TYOffset.h
//  TuyaSmartBaseKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

@interface NSDate (TYSDKOffset)

// Cloud timestamp. Cloud time is synchronized at each startup.
+ (NSTimeInterval)tysdk_serverTimeIntervalSince1970;

+ (NSString *)tysdk_timeZone;

@end
