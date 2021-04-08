//
// TuyaSmartUser+DeprecatedApi.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartUser (DeprecatedApi)


/// Send verification code. Used for mobile phone verification code login, register, password reset.
/// @param countryCode Country code.
/// @param phoneNumber Mobile phone number.
/// @param type  0: mobile phone verification code login, 1: mobile phone verification code register, 2: mobile phone password reset.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendVerifyCode:(NSString *)countryCode
           phoneNumber:(NSString *)phoneNumber
                  type:(NSInteger)type
               success:(nullable TYSuccessHandler)success
               failure:(nullable TYFailureError)failure
DEPRECATED_MSG_ATTRIBUTE("use sendVerifyCodeWithUserName:region:countryCode:type:success:failure: instead");

#pragma mark email

/// Email register 1.0.
/// @param countryCode Country code.
/// @param email Email.
/// @param password Password.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, use TuyaSmartUser::registerByEmail:email:password:code:success:failure: instead
- (void)registerByEmail:(NSString *)countryCode
                  email:(NSString *)email
               password:(NSString *)password
                success:(nullable TYSuccessHandler)success
                failure:(nullable TYFailureError)failure
DEPRECATED_MSG_ATTRIBUTE("use registerByEmail:email:password:code:success:failure: instead");


#pragma mark phone

/// Mobile phone verification code login and register.
/// @param countryCode Country code.
/// @param phoneNumber Mobile phone number.
/// @param code Verification code.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, use TuyaSmartUser::loginWithMobile:countryCode:code:success:failure: instead
- (void)login:(NSString *)countryCode
  phoneNumber:(NSString *)phoneNumber
         code:(NSString *)code
      success:(nullable TYSuccessHandler)success
      failure:(nullable TYFailureError)failure
DEPRECATED_MSG_ATTRIBUTE("use loginWithMobile:countryCode:code:success:failure: instead");

#pragma mark Uid

/// User ID login/register. The account will be registered at first login.
/// @param countryCode Country code.
/// @param uid User ID.
/// @param password Password.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, use TuyaSmartUser::loginOrRegisterWithCountryCode:uid:password:success:failure: instead
- (void)loginOrRegisterByPhone:(NSString *)countryCode
                           uid:(NSString *)uid
                      password:(NSString *)password
                       success:(nullable TYSuccessHandler)success
                       failure:(nullable TYFailureError)failure
DEPRECATED_MSG_ATTRIBUTE("use loginOrRegisterWithCountryCode:uid:password:success:failure: instead");

/// User ID login/register. The account will be registered at first login.
/// @param countryCode Country code.
/// @param uid User ID.
/// @param password Password.
/// @param createHome Create default home.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, use TuyaSmartUser::loginOrRegisterWithCountryCode:uid:password:createHome:success:failure: instead
- (void)loginOrRegisterByPhone:(NSString *)countryCode
                           uid:(NSString *)uid
                      password:(NSString *)password
                    createHome:(BOOL)createHome
                       success:(nullable TYSuccessID)success
                       failure:(nullable TYFailureError)failure
DEPRECATED_MSG_ATTRIBUTE("use loginOrRegisterWithCountryCode:uid:password:createHome:success:failure: instead");

/// User ID register.
/// @param uid User ID.
/// @param password Password.
/// @param countryCode Country code.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, use TuyaSmartUser::loginOrRegisterWithCountryCode:uid:password:createHome:success:failure: instead
- (void)registerByUid:(NSString *)uid
             password:(NSString *)password
          countryCode:(NSString *)countryCode
              success:(nullable TYSuccessHandler)success
              failure:(nullable TYFailureError)failure
DEPRECATED_MSG_ATTRIBUTE("use loginOrRegisterWithCountryCode:uid:password:createHome:success:failure: instead");

/// User ID login.
/// @param uid User ID.
/// @param password Password.
/// @param countryCode Country code.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, use TuyaSmartUser::loginOrRegisterWithCountryCode:uid:password:createHome:success:failure: instead
- (void)loginByUid:(NSString *)uid
          password:(NSString *)password
       countryCode:(NSString *)countryCode
           success:(nullable TYSuccessHandler)success
           failure:(nullable TYFailureError)failure
DEPRECATED_MSG_ATTRIBUTE("use loginOrRegisterWithCountryCode:uid:password:createHome:success:failure: instead");

/// User ID login/register. The account will be registered at first login.
/// @param countryCode Country code.
/// @param uid User ID.
/// @param password Password.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, use TuyaSmartUser::loginOrRegisterWithCountryCode:uid:password:createHome:success:failure: instead
- (void)loginOrRegisterWithCountryCode:(NSString *)countryCode
                                   uid:(NSString *)uid
                              password:(NSString *)password
                               success:(nullable TYSuccessHandler)success
                               failure:(nullable TYFailureError)failure
DEPRECATED_MSG_ATTRIBUTE("use loginOrRegisterWithCountryCode:uid:password:createHome:success:failure: instead");


/// Send verification code, used for email password reset.
/// @param countryCode Country code.
/// @param email Email.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendVerifyCodeByEmail:(NSString *)countryCode
                        email:(NSString *)email
                      success:(nullable TYSuccessHandler)success
                      failure:(nullable TYFailureError)failure
DEPRECATED_MSG_ATTRIBUTE("use sendVerifyCodeWithUserName:region:countryCode:type:success:failure: instead");

/// Send verification code, used for email password register.
/// @param countryCode Country code.
/// @param email Email.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendVerifyCodeByRegisterEmail:(NSString *)countryCode
                                email:(NSString *)email
                              success:(nullable TYSuccessHandler)success
                              failure:(nullable TYFailureError)failure
DEPRECATED_MSG_ATTRIBUTE("use sendVerifyCodeWithUserName:region:countryCode:type:success:failure: instead");

@end

NS_ASSUME_NONNULL_END
