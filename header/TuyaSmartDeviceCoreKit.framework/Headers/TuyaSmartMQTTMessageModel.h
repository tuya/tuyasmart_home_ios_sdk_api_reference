//
// TuyaSmartMQTTMessageModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// mqtt message
@interface TuyaSmartMQTTMessageModel : NSObject

/// protocol
@property (nonatomic, assign) NSInteger    protocol;

/// message type
@property (nonatomic, strong) NSString     *type;

/// message data
@property (nonatomic, strong) id           data;

/// device ID
@property (nonatomic, strong) NSString     *devId;

@end

NS_ASSUME_NONNULL_END
