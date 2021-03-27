//
// TuyaSmartBLEManager+Channel.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartBLEManager.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^TPBleResultBlock)(NSString *result);

/// @brief TuyaSmartBLEManager+Channel provides methods for developers to make BLE device report large amounts of data through bluetooth channel.
@interface TuyaSmartBLEManager (Channel)
 
/// Determine if the device is connected.
///
/// @param uuid     The UUID for the device.
///
/// @return The local connection status of the BLE device
- (BOOL)isBLEChannelDeviceConnect:(NSString *)uuid;

/// Set the callback when the transfer is completed.
///
/// @param block    When transfer successfully, this block will be called success.
/// @param uuid     The UUID for the device.
- (void)setCompletionBlock:(TPBleResultBlock)block uuid:(NSString *)uuid;

/// App request to start big data transfer.
///
/// @param uuid     The UUID for the device.
- (void)appApplyLaunch:(NSString *)uuid;

/// App forced termination of data transmission.
///
/// @param uuid     The UUID for the device.
- (BOOL)appMandatoryTrans:(NSString *)uuid;

@end

NS_ASSUME_NONNULL_END
