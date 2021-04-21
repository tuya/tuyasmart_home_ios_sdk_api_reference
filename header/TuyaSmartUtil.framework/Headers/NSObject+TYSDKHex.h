//
//  NSObject+TYHex.h
//  TuyaSmartBaseKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

@interface NSString (TYSDKHex)

+ (instancetype)tysdk_stringFromHexString:(NSString *)hexString;

- (NSString *)tysdk_hexString;

@end

@interface NSData (TYSDKHex)

+ (instancetype)tysdk_dataFromHexString:(NSString *)hexString;

- (NSString *)tysdk_hexString;

@end
