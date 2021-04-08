//
//  TYLogUtils.h
//  TuyaSmartKit
//
//  Created by 冯晓 on 2017/2/14.
//  Copyright © 2017年 Tuya. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface TYSDKLogUtils : NSObject

// Prints bytes.
+ (void)tysdk_logByte:(uint8_t *)bytes len:(int)len str:(NSString *)str;

+ (void)tysdk_eventWithType:(NSString *)type attribute:(NSDictionary *)attribute;

+ (void)tysdk_eventWithType:(NSString *)type attribute:(NSDictionary *)attribute identifier:(NSString *)identifier;

/* Starts an event that indicates a period.
 
 @params type The name of the event.
 @params attributes Common parameters of the event.
 @params infos The information about the event.
 @params identifier The ID of the event. The value is generated in the call of [xxx ty_apm_identifier].
 @params trackType The status of the tracked point. (trackType = @”begin“ Begin / @"track" Send/ @"end" End)
 
 */
+ (void)tysdk_eventWithType:(NSString *)type attribute:(NSDictionary *)attribute infos:(NSDictionary *)infos trackType:(NSString *)trackType identifier:(NSString *)identifier;

+ (NSString *)tysdk_eventIdentifiter;


/// The data compression point.
///
/// @param type The unique name of the event.
/// @param attribute The parameters of the event.
/// @param identify The identifier of the event. The value is used to differentiate event tracking data.
/// @param maxCount The maximum number of entries that are compressed and collected. When the value is x, the handler is executed.
/// @param handler When the value is x, the handler is executed. The collected data is returned.
+ (void)tysdk_eventWithType:(NSString *)type attribute:(NSDictionary *)attribute identify:(NSString *)identify maxCount:(int)maxCount handler:(NSDictionary *(^)(NSInteger index, NSArray * datas))handler;

@end
