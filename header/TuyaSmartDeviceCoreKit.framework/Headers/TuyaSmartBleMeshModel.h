//
// TuyaSmartBleMeshModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartBleMeshModel
#define TuyaSmart_TuyaSmartBleMeshModel

#import <Foundation/Foundation.h>

@interface TuyaSmartBleMeshModel : NSObject

//generic mesh info
@property (nonatomic, strong) NSString     *name;

//mesh id
@property (nonatomic, strong) NSString     *meshId;

//localKey
@property (nonatomic, strong) NSString     *localKey;

//pv
@property (nonatomic, strong) NSString     *pv;

@property (nonatomic, strong) NSString     *code;

@property (nonatomic, strong) NSString     *password;

@property (nonatomic, assign) BOOL         share;

@property (nonatomic, assign) long long    homeId;

// --------- sig mesh info
@property (nonatomic, strong) NSString *netKey;

@property (nonatomic, strong) NSString *appKey;

@end

#endif
