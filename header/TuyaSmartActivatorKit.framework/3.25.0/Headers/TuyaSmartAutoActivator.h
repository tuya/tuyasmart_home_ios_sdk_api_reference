//
// TuyaSmartAutoActivator.h
// TuyaSmartActivatorKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartAutoActivator;

@protocol TuyaSmartAutoActivatorDelegate <NSObject>

/// Configure callbacks for status updates of the network.
/// @param activator instance
/// @param deviceModel Device model.
/// @param error error
- (void)autoActivator:(TuyaSmartAutoActivator *)activator didReceiveAutoConfigDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

/// @brief TuyaSmartAutoActivator is used for password-free configuration.
///
/// This class provides password-free configuration capabilities.
///
@interface TuyaSmartAutoActivator : NSObject

/// Return the delegate of TuyaSmartAutoActivator.
@property (nonatomic, weak) id<TuyaSmartAutoActivatorDelegate> delegate;

/// Returns the single of the class.
+ (instancetype)sharedInstance;

/// Get a list of all the devices under the current household that support password-free configuration.
/// @param homeId HomeId
/// @return Current list of all devices in the home that support password-free configuration.
- (NSArray <TuyaSmartDeviceModel *> *)autoActiveSupportedDeviceListWithHomeId:(long long)homeId;

/// Get the list of all gateway router devices under the current family.
/// @param homeId Current home ID.
/// @return Current list of all home gateway router devices.
/// @deprecated This method is deprecated, Use TuyaSmartRouterActivator::autoActiveRouterDeviceListWithHomeId: instead.
- (NSArray <TuyaSmartDeviceModel *> *)autoActiveRouterDeviceListWithHomeId:(long long)homeId __deprecated_msg("Use -[TuyaSmartRouterActivator autoActiveRouterDeviceListWithHomeId:] instead.");

/// Start discovering devices.
///
/// The 'devIds' should be obtained form TuyaSmartAutoActivator::autoActiveSupportedDeviceListWithHomeId:
///
/// @param devIds Device Id list
/// @param timeout Timeout, default 100 seconds.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverWithDevIds:(NSArray<NSString *> *)devIds
                        timeout:(NSTimeInterval)timeout
                        success:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;

/// Obtain configuration token (valid for 10 minutes).
/// @param success Called when the task finishes successfully. TYSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(TYSuccessString)success
                failure:(TYFailureError)failure;

/// Start discovering devices.
///
/// The 'devIds' should be obtained form TuyaSmartAutoActivator::autoActiveSupportedDeviceListWithHomeId:
///
/// @param devIds Device ID list.
/// @param token Configuration token.
/// @param timeout Timeout, default 100 seconds.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverWithDevIds:(NSArray<NSString *> *)devIds
                          token:(NSString *)token
                        timeout:(NSTimeInterval)timeout
                        success:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;

/// Start discovering gateway routers.
/// @param devIds Device ID list.
/// @param type Type,  0 to start discover device.
/// @param timeout Timeout, default 100 seconds
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use TuyaSmartRouterActivator::startDiscoverRouterWithDevIds:type:timeout:success:failure: instead.
- (void)startDiscoverRouterWithDevIds:(NSArray<NSString *> *)devIds
                                 type:(NSInteger)type
                              timeout:(NSTimeInterval)timeout
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure __deprecated_msg("Use -[TuyaSmartRouterActivator startDiscoverRouterWithDevIds:type:timeout:success:failure:] instead.");

/// Stop discovery devices.
- (void)stopDiscover;

/// Binding devices to a specified home.
/// @param homeId HomeId
/// @param devIds Device ID list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)bindDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(TYSuccessHandler)success failure:(TYFailureError)failure;


@end

NS_ASSUME_NONNULL_END
