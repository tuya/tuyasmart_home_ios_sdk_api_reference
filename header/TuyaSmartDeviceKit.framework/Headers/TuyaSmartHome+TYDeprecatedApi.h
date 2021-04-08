//
// TuyaSmartHome+TYDeprecatedApi.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartHome.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartHome (TYDeprecatedApi)


/// Add a home member
///
/// @param name         Member name
/// @param headPic      Member portrait
/// @param countryCode  Country code
/// @param account      User account
/// @param isAdmin      Whether the administrator
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use TuyaSmartHome::addHomeMemberWithName:headPic:countryCode:userAccount:role:success:failure: instead.
- (void)addHomeMemberWithName:(NSString *)name
                      headPic:(UIImage *)headPic
                  countryCode:(NSString *)countryCode
                  userAccount:(NSString *)account
                      isAdmin:(BOOL)isAdmin
                      success:(TYSuccessDict)success
                      failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartHome   addHomeMemberWithName:headPic:countryCode:userAccount:role:success:failure:]");

/// Add a home member
///
/// @param name         Member name
/// @param headPic      Member portrait
/// @param countryCode  Country code
/// @param account      User account
/// @param role         home role type
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use TuyaSmartHome::addHomeMemberWithAddMemeberRequestModel:success:failure: instead.
- (void)addHomeMemberWithName:(NSString *)name
                      headPic:(UIImage *)headPic
                  countryCode:(NSString *)countryCode
                  userAccount:(NSString *)account
                         role:(TYHomeRoleType)role
                      success:(TYSuccessDict)success
                      failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartHome addHomeMemberWithAddMemeberRequestModel:success:failure:]");

@end

NS_ASSUME_NONNULL_END
