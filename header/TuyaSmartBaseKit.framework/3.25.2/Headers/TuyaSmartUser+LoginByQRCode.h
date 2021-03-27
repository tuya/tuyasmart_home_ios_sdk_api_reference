//
// TuyaSmartUser+LoginByQRCode.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartUser (LoginByQRCode)

#pragma mark - Scan code to authorize third-party app login

/// Authorize third-party applications to login by QR code.
/// @param codeInfo QR code information.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByQRcode:(NSDictionary *)codeInfo success:(nullable TYSuccessID)success failure:(nullable TYFailureError)failure;

/// Get third-party applications info.
/// @param codeInfo  QR code information.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)userInfo:(NSDictionary *)codeInfo success:(nullable TYSuccessID)success failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
