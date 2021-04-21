//
// TuyaSmartAutoActivator.h
// TuyaSmartActivatorKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartAutoActivator;

@protocol TuyaSmartAutoActivatorDelegate <NSObject>

/// Configures the callbacks of network status updates.
/// @param activator The instance.
/// @param deviceModel The device model.
/// @param error An error occurs while processing the request.
- (void)autoActivator:(TuyaSmartAutoActivator *)activator didReceiveAutoConfigDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

/// @brief TuyaSmartAutoActivator is used to configure the password-free pairing function.
///
/// This class provides capabilities for the password-free pairing function.
///
@interface TuyaSmartAutoActivator : NSObject

/// Returns the delegate of TuyaSmartAutoActivator.
@property (nonatomic, weak) id<TuyaSmartAutoActivatorDelegate> delegate;

/// Returns the singleton instance of the class.
+ (instancetype)sharedInstance;

/// Returns all devices for the current home that supports the password-free pairing function.
/// @param homeId The home ID.
/// @return All devices in the home that supports the password-free pairing function.
- (NSArray <TuyaSmartDeviceModel *> *)autoActiveSupportedDeviceListWithHomeId:(long long)homeId;

/// Returns all gateway router devices for the current home.
/// @param homeId The home ID.
/// @return All home gateway router devices.
/// @deprecated This method is deprecated. Use TuyaSmartRouterActivator::autoActiveRouterDeviceListWithHomeId: instead.
- (NSArray <TuyaSmartDeviceModel *> *)autoActiveRouterDeviceListWithHomeId:(long long)homeId __deprecated_msg("Use -[TuyaSmartRouterActivator autoActiveRouterDeviceListWithHomeId:] instead.");

/// Starts to scan for devices.
///
/// The value of 'devIds' is generated in the call of TuyaSmartAutoActivator::autoActiveSupportedDeviceListWithHomeId:.
///
/// @param devIds A list of device IDs.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverWithDevIds:(NSArray<NSString *> *)devIds
                        timeout:(NSTimeInterval)timeout
                        success:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;

/// Returns the pairing token. This token is valid for 10 minutes.
/// @param success Called when the task is finished. TYSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(TYSuccessString)success
                failure:(TYFailureError)failure;

/// Starts to scan for devices.
///
/// The value of 'devIds' is generated in the call of TuyaSmartAutoActivator::autoActiveSupportedDeviceListWithHomeId:
///
/// @param devIds A list of device IDs.
/// @param token The pairing token.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverWithDevIds:(NSArray<NSString *> *)devIds
                          token:(NSString *)token
                        timeout:(NSTimeInterval)timeout
                        success:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;

/// Starts to scan for gateway routers.
/// @param devIds A list of device IDs.
/// @param type Specifies whether to start scanning. Set the value to `0` to start scanning.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use TuyaSmartRouterActivator::startDiscoverRouterWithDevIds:type:timeout:success:failure: instead.
- (void)startDiscoverRouterWithDevIds:(NSArray<NSString *> *)devIds
                                 type:(NSInteger)type
                              timeout:(NSTimeInterval)timeout
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure __deprecated_msg("Use -[TuyaSmartRouterActivator startDiscoverRouterWithDevIds:type:timeout:success:failure:] instead.");

/// Stops scanning devices.
- (void)stopDiscover;

/// Adds devices to a specified home.
/// @param homeId The home ID.
/// @param devIds A list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)bindDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(TYSuccessHandler)success failure:(TYFailureError)failure;


@end

NS_ASSUME_NONNULL_END
