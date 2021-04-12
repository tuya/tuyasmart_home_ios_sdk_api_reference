//
// TuyaSmartDeviceCoreKitErrors.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartDeviceCoreKitErrors_h
#define TuyaSmartDeviceCoreKitErrors_h

/*
 *  TYDeviceCoreKitError
 *
 *  Discussion:
 *    Error returned as code to NSError from TuyaSmartDeviceKit.
 */
extern NSString *const kTYDeviceCoreKitErrorDomain;

/// The device core kit errors define.
typedef NS_ENUM(NSInteger, TYDeviceCoreKitError) {
    /// The device does not support a certain capability (capability reported on the device dimension).
    kTYDeviceCoreKitErrorDeviceNotSupport                      = 3000,
    /// LAN downstream data failure.
    kTYDeviceCoreKitErrorSocketSendDataFailed                  = 3001,
    /// DPS command is empty.
    kTYDeviceCoreKitErrorEmptyDpsData                          = 3002,
    /// Group device is empty.
    kTYDeviceCoreKitErrorGroupDeviceListEmpty                  = 3003,
    /// Group ID length error.
    kTYDeviceCoreKitErrorGroupIdLengthError                    = 3004,
    /// Illegal dps, see product dp definition.
    kTYDeviceCoreKitErrorIllegalDpData                         = 3005,
    /// Device ID length error.
    kTYDeviceCoreKitErrorDeviceIdLengthError                   = 3006,
    /// Missing local key.
    kTYDeviceCoreKitErrorDeviceLocalKeyNotFound                = 3007,
    /// Product ID length error.
    kTYDeviceCoreKitErrorDeviceProductIDLengthError            = 3008,
    
};

#endif /* TuyaSmartDeviceCoreKitErrors_h */
