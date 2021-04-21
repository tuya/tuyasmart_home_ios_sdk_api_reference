//
//  TYNotification.h
//  TYLibraryExample
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

@interface TYSDKNotification : NSObject

+ (void)tysdk_postNotificationName:(nonnull NSString *)aName;

+ (void)tysdk_postNotificationName:(nonnull NSString *)aName object:(nullable id)anObject;

+ (void)tysdk_postNotificationName:(nonnull NSString *)aName object:(nullable id)anObject userInfo:(nullable NSDictionary *)aUserInfo;


@end
