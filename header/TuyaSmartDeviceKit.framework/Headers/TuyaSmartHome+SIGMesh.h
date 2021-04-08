//
// TuyaSmartHome+SIGMesh.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartHome (SIGMesh)

@property (nonatomic, strong, readonly) TuyaSmartBleMeshModel *sigMeshModel;

/// Get the sig mesh list under the family
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getSIGMeshListWithSuccess:(void(^)(NSArray <TuyaSmartBleMeshModel *> *list))success
                          failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
