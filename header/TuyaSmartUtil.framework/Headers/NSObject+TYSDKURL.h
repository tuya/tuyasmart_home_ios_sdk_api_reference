//
//  NSObject+TYURL.h
//  TuyaSmartBaseKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

@interface NSString (TYSDKURL)

- (NSString *)tysdk_urlEncodeString;

- (NSString *)tysdk_urlDecodeString;

@end

@interface NSURL (TYSDKQuery)

- (NSDictionary *)tysdk_queryDict;

@end
