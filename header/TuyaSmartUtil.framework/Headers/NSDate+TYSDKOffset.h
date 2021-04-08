//
//  NSDate+TYOffset.h
//  TuyaSmartBaseKit
//
//  Created by 高森 on 2018/6/11.
//

#import <Foundation/Foundation.h>

@interface NSDate (TYSDKOffset)

// Cloud timestamp. Cloud time is synchronized at each startup.
+ (NSTimeInterval)tysdk_serverTimeIntervalSince1970;

+ (NSString *)tysdk_timeZone;

@end
