//
// TuyaSmartHomeMemberRequestModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartHomeModelUtils.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartHomeMemberRequestModel : NSObject

/// Member ID, required field.
@property (nonatomic, assign) long long memberId;

/// Member name, will not update existing name when set to nil。
@property (nonatomic, strong) NSString *name;

/// Member role, please set the correct role type you want to set, if you don't want to update the role type you can keep the current role type or set it to "TYHomeRoleType_Unknown"。
@property (nonatomic, assign) TYHomeRoleType role;

/// Member avatars, will not update existing avatars when set to nil.
@property (nonatomic, strong) UIImage *headPic;

@end

NS_ASSUME_NONNULL_END
