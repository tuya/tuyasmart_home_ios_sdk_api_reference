//
//  TYSDKFile.h
//  Pods-TuyaSmartHomeKit_Tests
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYSDKFile : NSObject

+ (instancetype)sharedInstance;

- (NSString *)tysdk_getAtDocumentPath:(NSString *)fileName;

- (BOOL)tysdk_mkdirAtPath:(NSString *)dir;

- (BOOL)tysdk_fileExistsAtPath:(NSString *)filePath;

- (BOOL)tysdk_delFileAtPath:(NSString *)filepath;

- (BOOL)tysdk_createFileAtPath:(NSString *)filePath;


@end

NS_ASSUME_NONNULL_END
