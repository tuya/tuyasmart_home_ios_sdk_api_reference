//
//  NSObject+TPCategory.h
//  TYLibraryExample
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

@interface NSObject (TYSDKCategory)

- (NSInteger)tysdk_toInt;

- (NSUInteger)tysdk_toUInt;

- (NSString *)tysdk_toString;

- (float)tysdk_toFloat;

- (double)tysdk_toDouble;

- (NSArray *)tysdk_toArray;

- (NSDictionary *)tysdk_toDictionary;

- (BOOL)tysdk_toBool;

+ (BOOL)tysdk_swizzleInstanceMethod:(SEL)originalSel with:(SEL)newSel;

+ (BOOL)tysdk_swizzleClassMethod:(SEL)originalSel with:(SEL)newSel;

@end
