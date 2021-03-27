//
// TuyaSmartShareMemberModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

@interface TuyaSmartShareMemberModel : NSObject

/// Relationship Id
@property (nonatomic, assign) NSInteger memberId;

/// Remark name
@property (nonatomic, strong) NSString  *nickName;

/// User name (cell phone number/email number)
@property (nonatomic, strong) NSString  *userName;

/// Avatar address.
@property (nonatomic, strong) NSString *iconUrl;

@end
