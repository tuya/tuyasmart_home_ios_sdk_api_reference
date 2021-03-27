//
// TuyaSmartUser+Region.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartUser.h"
#import "TYRegionModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartUser (Region)

/// Get region list.
/// @param countryCode Country code.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)regionListWithCountryCode:(NSString *)countryCode
                          success:(void(^)(NSArray<TYRegionModel *> *regionList))success
                          failure:(TYFailureError)failure;

/// Get default region of the country code.`AY` for China, `AZ` for America, `EU` for Europe.
/// @param countryCode Country code.
/// @return Return a default region of the country code.
- (NSString *)getDefaultRegionWithCountryCode:(NSString *)countryCode;

/// Get default domain.
/// @return Return a default region of the country code.
- (NSDictionary *)getDefaultDomain;

/// Check verification code, used for register/login/reset password.
/// @param userName Mobile phone number or Email address.
/// @param region For register is required, use [TuyaSmartUser regionListWithCountryCode:success:failure:] or [TuyaSmartUser getDefaultRegionWithCountryCode:] to get region.
/// @param countryCode Country code.
/// @param code Verification code.
/// @param type 1: Mobile phone verification code register,2: Mobile phone verification code login,3: Mobile phone password reset.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)checkCodeWithUserName:(NSString *)userName
                       region:(NSString *_Nullable)region
                  countryCode:(NSString *)countryCode
                         code:(NSString *)code
                         type:(NSInteger)type
                      success:(TYSuccessBOOL)success
                      failure:(TYFailureError)failure;

/// Mobile phone & Email register.
/// @param userName Mobile phone number or Email address.
/// @param region The region to register account, use [TuyaSmartUser regionListWithCountryCode:success:failure:] or [TuyaSmartUser getDefaultRegionWithCountryCode:] to get region.
/// @param countryCode Country code.
/// @param code Verification code.
/// @param password Password.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)registerWithUserName:(NSString *)userName
                      region:(NSString *)region
                 countryCode:(NSString *)countryCode
                        code:(NSString *)code
                    password:(NSString *)password
                     success:(TYSuccessHandler)success
                     failure:(TYFailureError)failure;

/// Switch the region of logged in user.
/// @warning 1. Switch user region is same as register a new account to the region of user. because of GDPR, switch region will not take user's device and scene to the new account. Only take user information to the new account.
/// @warning 2. When account switch to the new region, old account only reserved for 30 days.After 30 days, old account will be deleted.
/// @warning 3. If switch region success, new account will be logged.
/// @param region The region to register account, use [TuyaSmartUser regionListWithCountryCode:success:failure:] or [TuyaSmartUser getDefaultRegionWithCountryCode:] to get region.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)switchUserRegion:(NSString *)region
                 success:(TYSuccessHandler)success
                 failure:(TYFailureError)failure;


/**
 *  User get white list region list which can send mobile code.
 *  用户获取白名单列表，可以发送手机号来注册账号
 *
 *
 *  @param success     Success block
 *  @param failure     Failure block
 */
- (void)getWhiteListWhoCanSendMobileCodeSuccess:(TYSuccessString)success
                                        failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
