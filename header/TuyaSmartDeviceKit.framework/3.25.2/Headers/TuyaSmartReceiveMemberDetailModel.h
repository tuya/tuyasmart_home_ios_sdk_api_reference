//
// TuyaSmartReceiveMemberDetailModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

@class TuyaSmartShareDeviceModel;

@interface TuyaSmartReceiveMemberDetailModel : NSObject

@property (nonatomic, strong) NSArray <TuyaSmartShareDeviceModel *> *devices;

/// Account information, email or cell phone number.
@property (nonatomic, strong) NSString *mobile;

/// User nickname.
@property (nonatomic, strong) NSString *name;

/// Remarks.
@property (nonatomic, strong) NSString *remarkName;

@end
