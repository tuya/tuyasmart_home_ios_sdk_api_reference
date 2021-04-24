//
// TuyaSmartMessageSetting.h
// TuyaSmartMessageKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>
#import "TuyaSmartMessageRequestModel.h"

NS_ASSUME_NONNULL_BEGIN


/// @brief TuyaSmartMessageSetting provides methods to manage the Do Not Disturb (DND) mode for devices.
///
@interface TuyaSmartMessageSetting : NSObject

/// Sets the DND status for devices.
/// @param flags The switching status.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. TYFailureError is returned.
- (void)setDeviceDNDSettingStatus:(BOOL)flags success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Returns the DND status for devices.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. TYFailureError is returned.
- (void)getDeviceDNDSettingstatusSuccess:(TYSuccessBOOL)success failure:(TYFailureError)failure;

/// Returns a list of DND settings.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. TYFailureError is returned.
- (void)getDNDListSuccess:(TYSuccessList)success failure:(TYFailureError)failure;

/// Returns a list of devices.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. TYFailureError is returned.
- (void)getDNDDeviceListSuccess:(TYSuccessList)success failure:(TYFailureError)failure;

/// Adds DND time for devices.
/// @param requestModel The model of a DND request.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. TYFailureError is returned.
- (void)addDNDWithDNDRequestModel:(TuyaSmartMessageSettingDNDRequestModel *)requestModel success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Modifies DND time for devices.
/// @param timerID The ID of the timer.
/// @param requestModel The model of a DND request.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. TYFailureError is returned.
- (void)modifyDNDWithTimerID:(long)timerID DNDRequestModel:(TuyaSmartMessageSettingDNDRequestModel *)requestModel success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Removes DND time.
/// @param timerID The ID of the timer.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. TYFailureError is returned.
- (void)removeDNDWithTimerID:(long)timerID success:(TYSuccessHandler)success failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
