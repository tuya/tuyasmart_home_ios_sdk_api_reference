//
//  NSNumber+TYRandom.h
//  TuyaSmartBaseKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

@interface NSNumber (TYSDKRandom)

+ (NSInteger)tysdk_randomIntBetweenMin:(NSInteger)minValue andMax:(NSInteger)maxValue;

+ (float)tysdk_randomFloat;

+ (float)tysdk_randomFloatBetweenMin:(float)minValue andMax:(float)maxValue;

@end
