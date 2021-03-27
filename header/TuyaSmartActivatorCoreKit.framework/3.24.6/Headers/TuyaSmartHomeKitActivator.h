//
// TuyaSmartHomeKitActivator.h
// TuyaSmartActivatorCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartUtil/TuyaSmartUtil.h>
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>
NS_ASSUME_NONNULL_BEGIN


@class TuyaSmartHomeKitActivator;
@protocol TuyaSmartHomeKitActivatorDelegate <NSObject>

/// Configure callbacks for network status updates.
/// @param activator instance
/// @param deviceModel The device model.
/// @param error error
- (void)homeKitActivator:(TuyaSmartHomeKitActivator *)activator didReceiveHomeKitDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;
@end

@interface TuyaSmartHomeKitActivator : NSObject

///Returns the singleton of the class.
+ (instancetype)sharedInstance;

@property (nonatomic, weak) id<TuyaSmartHomeKitActivatorDelegate> delegate;

/// Get the HomeKit device configuration token.
/// @param success Called when the task finishes successfully. TYSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(TYSuccessString)success failure:(TYFailureError)failure;


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
