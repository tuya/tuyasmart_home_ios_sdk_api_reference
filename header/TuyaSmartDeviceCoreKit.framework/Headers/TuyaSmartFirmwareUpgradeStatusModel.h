//
// TuyaSmartFirmwareUpgradeStatusModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartDeviceModelUtils.h"

NS_ASSUME_NONNULL_BEGIN

/// device firmware upgrade status
@interface TuyaSmartFirmwareUpgradeStatusModel : NSObject

/// firmware upgrade status
@property (nonatomic, assign) TuyaSmartDeviceUpgradeStatus upgradeStatus;
/// firmware type
@property (nonatomic, assign) NSInteger type;
/// firmware upgrade explain text
@property (nonatomic, copy) NSString *statusText;
/// firmware upgrade explain text title
@property (nonatomic, copy) NSString *statusTitle;

@end

NS_ASSUME_NONNULL_END
