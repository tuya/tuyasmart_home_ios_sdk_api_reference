//
// TuyaSmartHomeModelUtils.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartHomeModelUtils_h
#define TuyaSmartHomeModelUtils_h

typedef NS_ENUM(NSInteger, TYHomeRoleType) {
    TYHomeRoleType_Unknown = -999,  /**< Invalid role */
    TYHomeRoleType_Custom  = -1,  /**< Customized role */
    TYHomeRoleType_Member  = 0,   /**< General family member */
    TYHomeRoleType_Admin,         /**< Family administrator, no add delete other administrator privileges. */
    TYHomeRoleType_Owner,         /**< Family super administrator, owner */
};

typedef NS_ENUM(NSUInteger, TYHomeStatus) {
    TYHomeStatusPending = 1,      /**< To be joined, invitees have not decided whether to join the corresponding family */
    TYHomeStatusAccept,           /**< Invitees have agreed to join the corresponding family */
    TYHomeStatusReject            /**< Invitees have declined to join the corresponding family */
};

#endif /* TuyaSmartHomeModelUtils_h */
