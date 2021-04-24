//
// TuyaSmartShareMemberModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

@interface TuyaSmartShareMemberModel : NSObject

/// The relationship ID.
@property (nonatomic, assign) NSInteger memberId;

/// The nickname.
@property (nonatomic, strong) NSString  *nickName;

/// The username that is the phone number or email address.
@property (nonatomic, strong) NSString  *userName;

/// The URL of the avatar.
@property (nonatomic, strong) NSString *iconUrl;

@end
