//
// TuyaSmartHomeKitActivator+Home.h
// TuyaSmartActivatorKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartHomeKitActivator (Home)

/// Get the token of the homeKit device wiring network.
/// @param homeID The home id
/// @param success Called when the task finishes successfully. token will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithHomeID:(long long)homeID Success:(TYSuccessString)success failure:(TYFailureError)failure;

/// Binding HomeKit devices to the home.
/// @param homeId The home ID.
/// @param devIds A list of device IDs.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)bindHomeKitDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(TYSuccessHandler)success failure:(TYFailureError)failure;


@end

NS_ASSUME_NONNULL_END
