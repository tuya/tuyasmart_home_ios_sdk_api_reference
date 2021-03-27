//
// TuyaSmartHomeDeviceShare+TYDeprecatedApi.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartHomeDeviceShare.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartHomeDeviceShare (TYDeprecatedApi)

/// Add Sharing
/// @param homeId homeId
/// @param countryCode countryCode
/// @param userAccount userAccount
/// @param devIds devId list
/// @param success Success block
/// @param failure Failure block
/// @deprecated This method is deprecated, Use TuyaSmartHomeDeviceShare::addDeviceShareWithRequestModel:success:failure: instead.
- (void)addShareWithHomeId:(long long)homeId
               countryCode:(NSString *)countryCode
               userAccount:(NSString *)userAccount
                    devIds:(NSArray <NSString *> *)devIds
                   success:(void(^)(TuyaSmartShareMemberModel *model))success
                   failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartHomeDeviceShare   addDeviceShareWithRequestModel:success:failure:]");


/// Single device add share
/// @param homeId homeId
/// @param countryCode countryCode
/// @param userAccount userAccount
/// @param devId devId
/// @param success Success block
/// @param failure Failure block
/// @deprecated This method is deprecated, Use TuyaSmartHomeDeviceShare::addDeviceShareWithRequestModel:success:failure: instead.
- (void)addDeviceShareWithHomeId:(long long)homeId
                     countryCode:(NSString *)countryCode
                     userAccount:(NSString *)userAccount
                           devId:(NSString *)devId
                         success:(void(^)(TuyaSmartShareMemberModel *model))success
                         failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartHomeDeviceShare   addDeviceShareWithRequestModel:success:failure:]");

@end

NS_ASSUME_NONNULL_END
