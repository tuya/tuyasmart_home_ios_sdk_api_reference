//
//  TYUserDefault.h
//  TuyaSmart
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYSDKUserDefault : NSObject

+ (void)tysdk_setUserDefault:(id)object forKey:(NSString *)aKey;
+ (id)tysdk_getUserDefault:(NSString *)aKey;
+ (void)tysdk_removeUserDefault:(NSString *)aKey;

@end

NS_ASSUME_NONNULL_END
