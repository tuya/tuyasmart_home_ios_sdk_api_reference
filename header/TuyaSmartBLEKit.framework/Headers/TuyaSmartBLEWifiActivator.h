//
// TuyaSmartBLEWifiActivator.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartBLEWifiActivator;

/// The delegate of the activation result for a dual-mode device.
@protocol TuyaSmartBLEWifiActivatorDelegate <NSObject>

/// The result of activating the dual-mode device.
///
/// @param activator        The class.
/// @param deviceModel      When the activation is successful, this block is called with DeviceModel.
/// @param error            If an error occurs, this block is called.
- (void)bleWifiActivator:(TuyaSmartBLEWifiActivator *)activator didReceiveBLEWifiConfigDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

/// @brief TuyaSmartBLEWifiActivator provides methods to implement the activation of dual-mode devices.
///
/// Each dual-mode device that provides both Bluetooth and Wi-Fi chips can publish the activation data through the Bluetooth channel and complete the activation through the Wi-Fi channel.
@interface TuyaSmartBLEWifiActivator : NSObject

/// The delegate of the activation result for a dual-mode device.
@property (nonatomic, weak) id<TuyaSmartBLEWifiActivatorDelegate> bleWifiDelegate;

/// The UUID for the device.
@property (nonatomic, strong) NSString *deviceUUID;

/// The single instance.
+ (instancetype)sharedInstance;

/// Activates the dual-mode device.
///
/// @param UUID         The UUID of the device.
/// @param homeId       The ID of the current home.
/// @param productId    The product ID of the device.
/// @param ssid         The name of the router.
/// @param password     The password of the device.
/// @param timeout      The timeout value.
/// @param success      After the data is sent, this block is called.
/// @param failure      If an error occurs, this block is called.
- (void)startConfigBLEWifiDeviceWithUUID:(NSString *)UUID
                                  homeId:(long long)homeId
                               productId:(NSString *)productId
                                    ssid:(NSString *)ssid
                                password:(NSString *)password
                                timeout:(NSTimeInterval)timeout
                                 success:(TYSuccessHandler)success
                                 failure:(TYFailureHandler)failure;

/// Stops the device discovery.
- (void)stopDiscover;

@end

NS_ASSUME_NONNULL_END
