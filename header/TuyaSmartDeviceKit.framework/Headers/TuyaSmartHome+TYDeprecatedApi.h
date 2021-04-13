//
// TuyaSmartHome+TYDeprecatedApi.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartHome.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartHome (TYDeprecatedApi)


/// Adds a home member.
///
/// @param name         The member's name.
/// @param headPic      The member's avatar.
/// @param countryCode  The country code.
/// @param account      The user account.
/// @param isAdmin      Specifies whether the member is an administrator.
/// @param success      The success block.
/// @param failure      The failure block.
/// @deprecated This method is deprecated. Use TuyaSmartHome::addHomeMemberWithName:headPic:countryCode:userAccount:role:success:failure: instead.
- (void)addHomeMemberWithName:(NSString *)name
                      headPic:(UIImage *)headPic
                  countryCode:(NSString *)countryCode
                  userAccount:(NSString *)account
                      isAdmin:(BOOL)isAdmin
                      success:(TYSuccessDict)success
                      failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartHome   addHomeMemberWithName:headPic:countryCode:userAccount:role:success:failure:]");

/// Adds a home member.
///
/// @param name         The member's name.
/// @param headPic      The member's avatar.
/// @param countryCode  The country code.
/// @param account      The user account.
/// @param role         The type of the home role.
/// @param success      The success block.
/// @param failure      The failure block.
/// @deprecated This method is deprecated. Use TuyaSmartHome::addHomeMemberWithAddMemeberRequestModel:success:failure: instead.
- (void)addHomeMemberWithName:(NSString *)name
                      headPic:(UIImage *)headPic
                  countryCode:(NSString *)countryCode
                  userAccount:(NSString *)account
                         role:(TYHomeRoleType)role
                      success:(TYSuccessDict)success
                      failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartHome addHomeMemberWithAddMemeberRequestModel:success:failure:]");

@end

NS_ASSUME_NONNULL_END
