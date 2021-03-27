//
// TuyaSmartHomeKitActivator.h
// TuyaSmartActivatorKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartUtil/TuyaSmartUtil.h>
#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>
NS_ASSUME_NONNULL_BEGIN


@class TuyaSmartHomeKitActivator;
@protocol TuyaSmartHomeKitActivatorDelegate <NSObject>

/// Configure callbacks for network status updates.
/// @param activator instance
/// @param deviceModel The device model.
/// @param error error
- (void)homeKitActivator:(TuyaSmartHomeKitActivator *)activator didReceiveHomeKitDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;
@end

/// @brief TuyaSmartHomeKitActivator is used for HomeKit device configuration.
///
/// This class provides HomeKit device configuration capabilities.
///
@interface TuyaSmartHomeKitActivator : NSObject

///Returns the singleton of the class.
+ (instancetype)sharedInstance;

@property (nonatomic, weak) id<TuyaSmartHomeKitActivatorDelegate> delegate;

/// Obtain the HomeKit device configuration token.
/// @param success Called when the task finishes successfully. TYSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(TYSuccessString)success failure:(TYFailureError)failure;


/// Obtain the HomeKit device configuration token with home id.
/// @param homeID The home id
/// @param success Called when the task finishes successfully. token will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithHomeID:(long long)homeID Success:(TYSuccessString)success failure:(TYFailureError)failure;


/// Search for HomeKit devices.
/// @param timeout Timeout time.
/// @param token Configuration token.
/// @param success Called when the task finishes successfully. TuyaSmartDeviceModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverHomeKitDeviceWithTimeout:(NSTimeInterval)timeout token:(NSString *)token success:(void (^)(TuyaSmartDeviceModel *))success failure:(TYFailureError)failure;

/// Search for HomeKit device.
/// @param timeout Timeout time.
/// @param token Configuration token.
/// @param success Called when the task finishes successfully. TuyaSmartDeviceModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverHomeKitDeviceWithTimeout:(NSTimeInterval)timeout token:(NSString *)token success:(void (^)(TuyaSmartDeviceModel *))success failure:(TYFailureError)failure;


/// Search for HomeKit device.
/// @param timeout Timeout time.
/// @param success Called when the task finishes successfully. TYSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverHomeKitDeviceWithTimeout:(NSTimeInterval)timeout success:(TYSuccessString)success failure:(TYFailureError)failure;


/// Binding HomeKit devices to the home.
///
/// Need to call the method when using TuyaSmartHomeKitActivator::getTokenSuccess:failure:, cause configuration token has no home information
///
/// @param homeId The home ID.
/// @param devIds A list of device IDs.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)bindHomeKitDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(TYSuccessHandler)success failure:(TYFailureError)failure;


/// Get device information based on pid.
/// @param productId The product ID.
/// @param success Called when the task finishes successfully. TYSuccessDict will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getHomekitDeviceInfoWithProductId:(NSString *)productId success:(TYSuccessDict)success failure:(TYFailureError)failure;


/// Get device information based on pid.
/// @param productId The product ID.
/// @param uuid The device uuid
/// @param success Called when the task finishes successfully. TYSuccessDict will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getHomekitDeviceInfoWithProductId:(NSString *)productId uuid:(NSString *)uuid success:(TYSuccessDict)success failure:(TYFailureError)failure;


/// Stop discovery devices.
- (void)stopDiscover;

@end

NS_ASSUME_NONNULL_END
