//
// TuyaSmartSIGMeshManager+OTA.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartBLEMeshKit/TuyaSmartBLEMeshKit.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief SIG mesh activator Category for (SIG) bluetooth mesh manager.=====The Bluetooth mesh activator category for the Bluetooth mesh manager.
///
/// Mainly contains the OTA upgrade function for device nodes=====This API provides multiple group management functions. For example, devices can be added to groups or removed from groups.
///
@interface TuyaSmartSIGMeshManager (OTA)

/// Ready to upgrade target device.====Prepares for OTA updates for a specific device.
/// @param targetNodeId The node ID of the device to be updated.
- (void)prepareForOTAWithTargetNodeId:(NSString *)targetNodeId;

/// Starts to send the update package.
/// @param data The data.
/// @param targetVersion The version to which the device is updated to.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startSendOTAPack:(NSData *)data
           targetVersion:(NSString *)targetVersion
                 success:(TYSuccessHandler)success
                 failure:(TYFailureHandler)failure;


@end

NS_ASSUME_NONNULL_END
