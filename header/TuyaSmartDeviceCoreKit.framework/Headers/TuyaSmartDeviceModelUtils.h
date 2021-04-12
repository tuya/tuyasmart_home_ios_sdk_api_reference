//
// TuyaSmartDeviceModelUtils.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartDeviceModelUtils_h
#define TuyaSmartDeviceModelUtils_h

/// device upgrade status
typedef enum : NSUInteger {
    TuyaSmartDeviceUpgradeStatusDefault = 0,    // Default. No upgrade required by default.
    TuyaSmartDeviceUpgradeStatusReady,          // Ready. Hardware readiness.
    TuyaSmartDeviceUpgradeStatusUpgrading,      // Upgrading. Upgrade in progress.
    TuyaSmartDeviceUpgradeStatusSuccess,        // Success. Upgrade completed.
    TuyaSmartDeviceUpgradeStatusFailure,        // Failure. Upgrade Exception.
    TuyaSmartDeviceUpgradeStatusWaitingExectue, // For nb,waiting execute nb. Equipment tasks have been issued, but not yet executed.
    TuyaSmartDeviceUpgradeStatusDownloaded,     // For nb,downloaded nb. Device firmware has been downloaded.
    TuyaSmartDeviceUpgradeStatusTimeout         // Timeout. Upgrade timeout.
} TuyaSmartDeviceUpgradeStatus;

#endif /* TuyaSmartDeviceModelUtils_h */
