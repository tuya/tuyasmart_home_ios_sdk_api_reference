//
// TuyaSmartRouterActivator.h
// TuyaSmartActivatorKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartRouterActivator;

@protocol TuyaSmartRouterActivatorDelegate <NSObject>

/// The callback of pairing status updates.
/// @param activator The activator instance.
/// @param deviceModel The value of TuyaSmartDeviceModel.
/// @param error An error occurs while processing the request.
- (void)routerActivator:(TuyaSmartRouterActivator *)activator didReceiveAutoConfigDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

/// @brief TuyaSmartRouterActivator is used to pair devices by using a router.
///
/// This class provides capabilities for router-based pairing.
///
@interface TuyaSmartRouterActivator : NSObject

/// Returns the delegate of TuyaSmartRouterActivator.
@property (nonatomic, weak) id<TuyaSmartRouterActivatorDelegate> delegate;


/// Returns all gateway router devices that support router-based pairing for the current home.
/// @param homeId The home ID.
/// @return All home gateway router devices.
- (NSArray <TuyaSmartDeviceModel *> *)autoActiveRouterDeviceListWithHomeId:(long long)homeId;


/// Returns the pairing token. This token is valid for 10 minutes.
/// @param success Called when the task is finished. TYSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(TYSuccessString)success
                failure:(TYFailureError)failure;


/// Starts to scan for devices.
///
/// The value of 'devIds' is generated in the call of TuyaSmartRouterActivator::autoActiveRouterDeviceListWithHomeId:.
///
/// @param devIds A list of device IDs.
/// @param type Specifies whether to start scanning. Set the value to `0` to start scanning.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverRouterWithDevIds:(NSArray<NSString *> *)devIds
                                 type:(NSInteger)type
                              timeout:(NSTimeInterval)timeout
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;


/// Starts to scan for devices.
///
/// The 'devIds' should be obtained form TuyaSmartRouterActivator::autoActiveRouterDeviceListWithHomeId:
///
/// @param devIds A list of device IDs.
/// @param token The pairing token.
/// @param type Specifies whether to start scanning. Set the value to `0` to start scanning.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverRouterWithDevIds:(NSArray<NSString *> *)devIds
                                token:(NSString *)token
                                 type:(NSInteger)type
                              timeout:(NSTimeInterval)timeout
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;


/// Stops scanning for devices.
- (void)stopDiscover;


/// Adds devices to a specified home.
/// @param homeId The home ID.
/// @param devIds A list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)bindDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(TYSuccessHandler)success failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
