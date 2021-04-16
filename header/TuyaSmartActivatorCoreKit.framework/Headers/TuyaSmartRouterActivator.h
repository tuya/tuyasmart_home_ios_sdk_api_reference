//
// TuyaSmartRouterActivator.h
// TuyaSmartActivatorCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartRouterActivator;

@protocol TuyaSmartRouterActivatorDelegate <NSObject>

/// Callback for configuration network status update.
/// @param activator The activator instance.
/// @param deviceModel The TuyaSmartDeviceModel.
/// @param error The error message.
- (void)routerActivator:(TuyaSmartRouterActivator *)activator didReceiveAutoConfigDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

@interface TuyaSmartRouterActivator : NSObject

/// Return the delegate of TuyaSmartRouterActivator.
@property (nonatomic, weak) id<TuyaSmartRouterActivatorDelegate> delegate;


/// Obtain configuration token (valid for 10 minutes).
/// @param success Called when the task finishes successfully. TYSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(TYSuccessString)success
                failure:(TYFailureError)failure;


/// Start discovering devices.
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

@end

NS_ASSUME_NONNULL_END
