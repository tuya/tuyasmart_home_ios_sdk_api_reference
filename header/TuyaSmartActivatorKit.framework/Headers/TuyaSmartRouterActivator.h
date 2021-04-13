//
// TuyaSmartRouterActivator.h
// TuyaSmartActivatorKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartRouterActivator;

@protocol TuyaSmartRouterActivatorDelegate <NSObject>

/// Callback for configuration network status update.
/// @param activator The activator instance.
/// @param deviceModel The TuyaSmartDeviceModel.
/// @param error The error message.
- (void)routerActivator:(TuyaSmartRouterActivator *)activator didReceiveAutoConfigDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

/// @brief TuyaSmartRouterActivator is used for router configuration.
///
/// This class provides router configuration capabilities.
///
@interface TuyaSmartRouterActivator : NSObject

/// Return the delegate of TuyaSmartRouterActivator.
@property (nonatomic, weak) id<TuyaSmartRouterActivatorDelegate> delegate;


/// Get the list of all gateway router devices which support router configuration under the current home.
/// @param homeId Current home ID.
/// @return Current list of all home gateway router devices.
- (NSArray <TuyaSmartDeviceModel *> *)autoActiveRouterDeviceListWithHomeId:(long long)homeId;


/// Obtain configuration token (valid for 10 minutes).
/// @param success Called when the task finishes successfully. TYSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(TYSuccessString)success
                failure:(TYFailureError)failure;


/// Start discovering devices.
///
/// The 'devIds' should be obtained form TuyaSmartRouterActivator::autoActiveRouterDeviceListWithHomeId:
///
/// @param devIds Device ID list.
/// @param type Type, 0 to start discover device.
/// @param timeout Timeout, default 100 seconds
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverRouterWithDevIds:(NSArray<NSString *> *)devIds
                                 type:(NSInteger)type
                              timeout:(NSTimeInterval)timeout
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;


/// Start discovering devices.
///
/// The 'devIds' should be obtained form TuyaSmartRouterActivator::autoActiveRouterDeviceListWithHomeId:
///
/// @param devIds Device ID list.
/// @param token Configuration token.
/// @param type Type, 0 to start discover device.
/// @param timeout Timeout, default 100 seconds
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverRouterWithDevIds:(NSArray<NSString *> *)devIds
                                token:(NSString *)token
                                 type:(NSInteger)type
                              timeout:(NSTimeInterval)timeout
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;


/// Stop discovering devices.
- (void)stopDiscover;


/// Binding devices to home.
/// @param homeId HomeId.
/// @param devIds Device ID list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)bindDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(TYSuccessHandler)success failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
