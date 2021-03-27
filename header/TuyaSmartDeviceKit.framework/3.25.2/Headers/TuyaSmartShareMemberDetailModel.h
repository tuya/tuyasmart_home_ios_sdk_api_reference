//
// TuyaSmartShareMemberDetailModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

@class TuyaSmartShareDeviceModel;

@interface TuyaSmartShareMemberDetailModel : NSObject

/// deviceModel list
@property (nonatomic, strong) NSArray <TuyaSmartShareDeviceModel *> *devices;

/// mobile
@property (nonatomic, strong) NSString *mobile;

/// name
@property (nonatomic, strong) NSString *name;

/// remark name
@property (nonatomic, strong) NSString *remarkName;

/// auto sharing
@property (nonatomic, assign) BOOL autoSharing;


@end
