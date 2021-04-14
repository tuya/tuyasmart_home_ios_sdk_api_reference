//
// TuyaSmartRouterActivator+Home.h
// TuyaSmartActivatorKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartRouterActivator (Home)


/// Get the list of all gateway router devices under the current home.
/// @param homeId Current home ID.
/// @return The list of all home gateway router devices.
- (NSArray <TuyaSmartDeviceModel *> *)autoActiveRouterDeviceListWithHomeId:(long long)homeId;


/// Binding devices to home.
/// @param homeId HomeId.
/// @param devIds Device ID list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)bindDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(TYSuccessHandler)success failure:(TYFailureError)failure;


@end

NS_ASSUME_NONNULL_END
