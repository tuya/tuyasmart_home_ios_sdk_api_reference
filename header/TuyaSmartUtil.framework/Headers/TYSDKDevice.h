//
//  TYDevice.h
//  TuyaSmartBaseKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

@interface TYSDKDevice : NSObject

+ (NSString *)tysdk_UUID __deprecated_msg("Use +[TuyaSmartSDK sharedInstance].uuid instead.");

+ (NSString *)tysdk_generateUUID;

+ (NSString *)tysdk_deviceNameString;

+ (NSString *)tysdk_model;

+ (NSString *)tysdk_systemName;

+ (NSString *)tysdk_systemVersion;

@end
