//
// TuyaSmartDeviceOTAModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Device upgrade status.
typedef enum : NSUInteger {
    /// Not upgrading.
    TuyaSmartDeviceOTAModelUpgradeStatusNone = 0,
    /// During the process of upgrade.
    TuyaSmartDeviceOTAModelUpgradeStatusUpgrading = 2
} TuyaSmartDeviceOTAModelUpgradeStatus;

@interface TuyaSmartDeviceOTAModel : NSObject

/// device Id
@property (nonatomic, strong) NSString     *devId;

/// The status of device upgrading.
@property (nonatomic) TuyaSmartDeviceOTAModelUpgradeStatus otaUpgradeStatus;

//针对BLEBeacon设备添加beaconCategory
@property (nonatomic, strong) NSString     *beaconCategory;

@end

NS_ASSUME_NONNULL_END
