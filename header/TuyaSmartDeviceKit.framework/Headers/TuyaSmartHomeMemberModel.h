//
// TuyaSmartHomeMemberModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartHomeModelUtils.h"

@interface TuyaSmartHomeMemberModel : NSObject

// member Id
@property (nonatomic, assign) long long memberId;

// Head portraits of members
@property (nonatomic, strong) NSString *headPic;

// name of members
@property (nonatomic, strong) NSString *name;

// role
@property (nonatomic, assign) TYHomeRoleType role;

// home Id
@property (nonatomic, assign) long long homeId;

// mobile
@property (nonatomic, strong) NSString *mobile;

// user name
@property (nonatomic, strong) NSString *userName;

// uid
@property (nonatomic, strong) NSString *uid;

// state of deal
@property (nonatomic, assign) TYHomeStatus dealStatus;

#pragma mark - deprecated
// admin or not
@property (nonatomic, assign) BOOL isAdmin __deprecated_msg("The property will be deprecated and remove in a future version，Please use role");

@end
