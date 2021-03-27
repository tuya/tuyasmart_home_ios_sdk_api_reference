//
// TuyaSmartDiscovery.h
// TuyaSmartActivatorKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartDiscovery;

@protocol TuyaSmartDiscoveryDelegate<NSObject>

@required

/// Callback of device discovery.
/// @param discovery Instance of TuyaSmartDiscovery class.
/// @param deviceModel Tuya smart device model.
/// @param error NSError object.
- (void)discovery:(TuyaSmartDiscovery *)discovery didDiscoveryDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

/// @brief TuyaSmartDiscovery is used for EZ configuration.
///
/// This class provides EZ configuration capabilities for WiFi devices.
///
/// @note This EZ configuration is different form the EZ mode in 'TuyaSmartActivator'. Need to call the method 'bindDeviceWithHomeId:devIds:success:' after obtaining the devices, cause configuration token has no home information
///
@interface TuyaSmartDiscovery : NSObject

@property (nonatomic, weak) id<TuyaSmartDiscoveryDelegate> delegate;

/// Obtain configuration token (valid for 10 minutes).
/// @param success Called when the task finishes successfully. TYSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(TYSuccessString)success
                failure:(TYFailureError)failure;

/// Start discovering devices.
/// @param ssid Name of route.
/// @param password Password of route.
/// @param timeout Timeout, default 100 seconds.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoveryWithSsid:(NSString *)ssid
                     password:(NSString *)password
                      timeout:(NSTimeInterval)timeout
                      success:(TYSuccessHandler)success
                      failure:(TYFailureError)failure;

/// Start discovering devices using token.
/// @param ssid Name of route.
/// @param password Password of route.
/// @param token Configuration token.
/// @param timeout Timeout, default 100 seconds.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoveryWithSsid:(NSString *)ssid
                     password:(NSString *)password
                         token:(NSString *)token
                      timeout:(NSTimeInterval)timeout
                      success:(TYSuccessHandler)success
                      failure:(TYFailureError)failure;

/// Binding devices to home.
/// @param homeId Home ID.
/// @param devIds Device ID list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)bindDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Stop discovering.
- (void)stopDiscovery;

@end

NS_ASSUME_NONNULL_END
