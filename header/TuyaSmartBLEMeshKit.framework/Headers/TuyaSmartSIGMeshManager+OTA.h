//
// TuyaSmartSIGMeshManager+OTA.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartBLEMeshKit/TuyaSmartBLEMeshKit.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief SIG mesh activator Category for (SIG) bluetooth mesh manager.
///
/// Mainly contains the OTA upgrade function for device nodes
///
@interface TuyaSmartSIGMeshManager (OTA)

/// Ready to upgrade target device.
/// @param targetNodeId Target device node ID.
- (void)prepareForOTAWithTargetNodeId:(NSString *)targetNodeId;

/// Start sending upgrade package.
/// @param data Data.
/// @param targetVersion Target version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)startSendOTAPack:(NSData *)data
           targetVersion:(NSString *)targetVersion
                 success:(TYSuccessHandler)success
                 failure:(TYFailureHandler)failure;


@end

NS_ASSUME_NONNULL_END
