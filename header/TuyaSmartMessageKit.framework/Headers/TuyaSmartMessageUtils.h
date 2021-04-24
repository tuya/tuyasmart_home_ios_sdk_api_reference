//
// TuyaSmartMessageUtils.h
// TuyaSmartMessageKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartMessageUtils_h
#define TuyaSmartMessageUtils_h

/// The type of message. Valid values: alert messages, home messages and notifications.
typedef NS_ENUM(NSInteger, TYMessageType) {
    /// The alert message type.
    TYMessageTypeAlarm = 1,
    /// The home message type.
    TYMessageTypeFamily,
    /// The notification type.
    TYMessageTypeNotice,
};

#endif /* TuyaSmartMessageUtils_h */
