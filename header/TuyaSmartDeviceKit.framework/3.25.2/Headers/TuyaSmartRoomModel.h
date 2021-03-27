//
// TuyaSmartRoomModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

@interface TuyaSmartRoomModel : NSObject

// room Id
@property (nonatomic, assign) long long roomId;

// room icon
@property (nonatomic, strong) NSString *iconUrl;

// room name
@property (nonatomic, strong) NSString *name;

// order
@property (nonatomic, assign) NSInteger displayOrder;


@end
