//
// TuyaSmartDeviceShareModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartDeviceShareRequestModel : NSObject

/// Home ID
@property (nonatomic, assign) long long homeID;

/// Country Code
@property (nonatomic, copy) NSString *countryCode;

/// Account
@property (nonatomic, copy) NSString *userAccount;

/// Device list ID
@property (nonatomic, copy) NSArray<NSString *> *devIds;

@end

NS_ASSUME_NONNULL_END
