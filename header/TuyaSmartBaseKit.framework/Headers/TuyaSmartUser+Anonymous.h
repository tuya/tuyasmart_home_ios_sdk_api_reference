//
// TuyaSmartUser+Anonymous.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartUser (Anonymous)

/// Anonymous register.
/// @param countryCode Country code.
/// @param userName User Name, e.g. : [UIDevice currentDevice].name.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)registerAnonymousWithCountryCode:(NSString *)countryCode
                                userName:(NSString *)userName
                                 success:(nullable TYSuccessHandler)success
                                 failure:(nullable TYFailureError)failure;

/// Delete anonymous account.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)deleteAnonymousAccountWithSuccess:(TYSuccessHandler)success
                                  failure:(TYFailureError)failure;

/// Bind username.
/// @param countryCode Country code.
/// @param userName Mobile phone number or Email address.
/// @param code Verification code.
/// @param password Password.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)usernameBindingWithCountryCode:(NSString *)countryCode
                              userName:(NSString *)userName
                                  code:(NSString *)code
                              password:(NSString *)password
                               success:(nullable TYSuccessHandler)success
                               failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
