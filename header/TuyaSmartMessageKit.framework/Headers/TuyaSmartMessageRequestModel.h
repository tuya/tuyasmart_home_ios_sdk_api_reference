//
// TuyaSmartMessageRequestModel.h
// TuyaSmartMessageKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartMessageUtils.h"

NS_ASSUME_NONNULL_BEGIN

/// The model of a message list request in the message center.
@interface TuyaSmartMessageListRequestModel : NSObject

/// The type of message.
@property (nonatomic, assign) TYMessageType msgType;

/// The maximum number of messages that can be requested.
@property (nonatomic, assign) NSInteger limit;

/// The total number of requested messages.
@property (nonatomic, assign) NSInteger offset;

@end

/// The model of a message detail list request in the message center.
@interface TuyaSmartMessageDetailListRequestModel : NSObject

/// The type of message. Currently, only TYMessageTypeAlarm is supported.
@property (nonatomic, assign) TYMessageType msgType;

/// The maximum number of messages that can be requested.
@property (nonatomic, assign) NSInteger limit;

/// The total number of requested messages.
@property (nonatomic, assign) NSInteger offset;

/// The ID of the device that sends messages.
@property (nonatomic, copy) NSString *msgSrcId;

@end

@interface TuyaSmartMessageListDeleteRequestModel : NSObject
/// The type of message.
@property (nonatomic, assign) TYMessageType msgType;

/// The ID of the message.
@property (nonatomic, copy) NSArray<NSString *> *msgIds;

/// The ID of the device that sends messages.
@property (nonatomic, copy) NSArray<NSString *> *msgSrcIds;

@end

@interface TuyaSmartMessageListReadRequestModel : NSObject

/// The type of message. Currently, only TYMessageTypeAlarm is supported.
@property (nonatomic, assign) TYMessageType msgType;

/// The ID of the message.
@property (nonatomic, copy) NSArray<NSString *> *msgIds;

@end

#pragma mark - setting
/// The model of the Do Not Disturb (DND) request for devices.
@interface TuyaSmartMessageSettingDNDRequestModel : NSObject

/// The start time.
@property (nonatomic, copy) NSString *startTime;

/// The end time.
@property (nonatomic, copy) NSString *endTime;

/// A list of device IDs.
@property (nonatomic, copy) NSArray<NSString *> *devIDs;

/// The weekly cycle in which the DND mode is enabled or disabled. Each bit of the string value specifies the day on which the DND mode is disabled or disabled.
///
/// Valid values: `0` means that the DND mode is disabled on the day. `1` means that the DND mode is enabled on the day. @"0000111" means that the DND mode is enabled from Friday to Sunday within a week.
///
@property (nonatomic, copy) NSString *loops;

/// Specifies whether all devices support the DND mode.
///
/// 'devIDs' is not required when 'isAllDevIDs' is set to `True`.
@property (nonatomic, assign) BOOL isAllDevIDs;

@end

NS_ASSUME_NONNULL_END
