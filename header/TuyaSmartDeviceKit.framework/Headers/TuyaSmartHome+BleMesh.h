//
// TuyaSmartHome+BleMesh.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

@interface TuyaSmartHome (BleMesh)

@property (nonatomic, strong, readonly) TuyaSmartBleMeshModel *meshModel;

/// Get the mesh list under the family.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getMeshListWithSuccess:(void(^)(NSArray <TuyaSmartBleMeshModel *> *list))success
                       failure:(TYFailureError)failure;


@end
