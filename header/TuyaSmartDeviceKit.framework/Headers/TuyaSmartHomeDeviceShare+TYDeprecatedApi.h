//
// TuyaSmartHomeDeviceShare+TYDeprecatedApi.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartHomeDeviceShare.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartHomeDeviceShare (TYDeprecatedApi)

/// Adds a sharing task.
/// @param homeId The home ID.
/// @param countryCode The country code.
/// @param userAccount The user account.
/// @param devIds A list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use TuyaSmartHomeDeviceShare::addDeviceShareWithRequestModel:success:failure: instead.
- (void)addShareWithHomeId:(long long)homeId
               countryCode:(NSString *)countryCode
               userAccount:(NSString *)userAccount
                    devIds:(NSArray <NSString *> *)devIds
                   success:(void(^)(TuyaSmartShareMemberModel *model))success
                   failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartHomeDeviceShare   addDeviceShareWithRequestModel:success:failure:]");


/// Adds a task to share a single device.
/// @param homeId The home ID.
/// @param countryCode The country code.
/// @param userAccount The user account.
/// @param devId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use TuyaSmartHomeDeviceShare::addDeviceShareWithRequestModel:success:failure: instead.
- (void)addDeviceShareWithHomeId:(long long)homeId
                     countryCode:(NSString *)countryCode
                     userAccount:(NSString *)userAccount
                           devId:(NSString *)devId
                         success:(void(^)(TuyaSmartShareMemberModel *model))success
                         failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartHomeDeviceShare   addDeviceShareWithRequestModel:success:failure:]");

@end

NS_ASSUME_NONNULL_END
