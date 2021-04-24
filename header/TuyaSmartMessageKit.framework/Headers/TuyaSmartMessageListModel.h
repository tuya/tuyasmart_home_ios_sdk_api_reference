//
// TuyaSmartMessageListModel.h
// TuyaSmartMessageKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartMessageUtils.h"

NS_ASSUME_NONNULL_BEGIN
/// The model of a message attachment.
@interface TuyaSmartMessageAttachModel : NSObject

/// Specifies whether the attachment is a video file, such as MP4 files.
@property (nonatomic, assign) BOOL isVideo;

/// The URL of the attachment.
@property (nonatomic, strong) NSString *url;

/// The thumbnail of the attachment.
@property (nonatomic, strong) NSString *thumbUrl;

@end

/// The model of a message list.
@interface TuyaSmartMessageListModel : NSObject

/// The identifier of a message.
@property (nonatomic, strong) NSString *msgId;

/// The title of a message.
@property (nonatomic, strong) NSString *msgTypeContent;

/// The content of a message.
@property (nonatomic, strong) NSString *msgContent;

/// The formatted date and time.
@property (nonatomic, strong) NSString *dateTime;

/// The timestamp of a message.
@property (nonatomic, assign) NSInteger time;

/// The icon of a message.
@property (nonatomic, strong) NSString *icon;

/// A list of attachments.
@property (nonatomic, strong) NSArray<TuyaSmartMessageAttachModel *> *attachPicList;

@property (nonatomic, assign) BOOL hasNotRead;

/// The device ID. Only alert messages support this field.
@property (nonatomic, strong) NSString  *msgSrcId;

///  Valid values: `1` means an alert message. `2` means an automation message. Only alert messages support this field to distinguish between alert messages and automation messages. The home messages and notifications are ignored.
@property (nonatomic, assign) NSInteger  alarmType;

/// The type of message. Valid values: `0` means system messages. `1` means that new devices are added. `2` means that new friends are added. `4` means device alerts.
@property (nonatomic, assign) NSInteger msgType;

/// The ID of the current home.
@property (nonatomic, assign) long long homeID;

/// The name of the current home.
@property (nonatomic, copy) NSString *homeName;

@end

NS_ASSUME_NONNULL_END
