//
// TuyaSmartBLEWifiActivator.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartBLEWifiActivator;

/// Delegate for dual-mode device activator result.
@protocol TuyaSmartBLEWifiActivatorDelegate <NSObject>

/// The result of the activator dual-mode devices.
///
/// @param activator        The class itself.
/// @param deviceModel      When activator successfully, this param will be called with DeviceModel.
/// @param error            This error will be called if some error occurred.
- (void)bleWifiActivator:(TuyaSmartBLEWifiActivator *)activator didReceiveBLEWifiConfigDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

/// @brief TuyaSmartBLEWifiActivator provides methods for developers to implement dual-mode device activator functionalities.
///
/// Dual-mode device, which has both Bluetooth and Wi-Fi chips, can publish activator data through Bluetooth channel and completed through Wi-Fi channel.
@interface TuyaSmartBLEWifiActivator : NSObject

/// Delegate for dual-mode device activator result.
@property (nonatomic, weak) id<TuyaSmartBLEWifiActivatorDelegate> bleWifiDelegate;

/// The UUID for the device.
@property (nonatomic, strong) NSString *deviceUUID;

/// Single instance.
+ (instancetype)sharedInstance;

/// Activator dual-mode device.
///
/// @param UUID         The UUID for the device.
/// @param homeId       The Id for the current home.
/// @param productId    The product Id for the device.
/// @param ssid         The name of the router.
/// @param password     The password Id for the device.
/// @param timeout      Timeout time.
/// @param success      When data send successfully, this block will be called success.
/// @param failure      This block will be called if some error occurred.
- (void)startConfigBLEWifiDeviceWithUUID:(NSString *)UUID
                                  homeId:(long long)homeId
                               productId:(NSString *)productId
                                    ssid:(NSString *)ssid
                                password:(NSString *)password
                                timeout:(NSTimeInterval)timeout
                                 success:(TYSuccessHandler)success
                                 failure:(TYFailureHandler)failure;

/// Stop discover device.
- (void)stopDiscover;

@end

NS_ASSUME_NONNULL_END
