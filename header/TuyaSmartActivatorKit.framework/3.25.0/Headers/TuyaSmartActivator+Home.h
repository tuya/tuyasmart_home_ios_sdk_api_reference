//
// TuyaSmartActivator+Home.h
// TuyaSmartActivatorKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartActivator (Home)

/// Obtain allocation token using home ID (valid for 10 minutes).
/// @param homeId Home Id
/// @param success Called when the task finishes successfully. TYSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithHomeId:(long long)homeId
                   success:(TYSuccessString)success
                   failure:(TYFailureError)failure;


/// Obtain allocation token using product ID (valid for 10 minutes).
/// @param productKey Product Id
/// @param homeId Home Id
/// @param success Called when the task finishes successfully. TYSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithProductKey:(NSString *)productKey
                        homeId:(long long)homeId
                       success:(TYSuccessString)success
                       failure:(TYFailureError)failure;

/// Obtain allocation token using UUID (valid for 10 minutes).
/// @param uuid Device uuid
/// @param homeId Home Id
/// @param success Called when the task finishes successfully. TYSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithUUID:(NSString *)uuid
                  homeId:(long long)homeId
                 success:(TYSuccessString)success
                 failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
