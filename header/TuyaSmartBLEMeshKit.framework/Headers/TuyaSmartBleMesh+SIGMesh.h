//
// TuyaSmartBleMesh+SIGMesh.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartBleMesh.h"

NS_ASSUME_NONNULL_BEGIN

/// @brief SIG mesh information category for bluetooth mesh.
@interface TuyaSmartBleMesh (SIGMesh)

+ (void)createSIGMeshWithHomeId:(long long)homeId
                        success:(void(^)(TuyaSmartBleMeshModel *meshModel))success
                        failure:(TYFailureError)failure;

/// Bluetooth device binding after network access, productKey + mac = pid.
/// @param uuid Bluetooth sub device short address identification.
/// @param devKey The device key.
/// @param nodeId The node ID.
/// @param productKey The product key.
/// @param ver Version.
/// @param mac The device mac.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addSIGMeshSubDeviceWithUuid:(NSString *)uuid
                             devKey:(NSString *)devKey
                             nodeId:(NSString *)nodeId
                         productKey:(NSString *)productKey
                                ver:(NSString *)ver
                                mac:(NSString *)mac
                            success:(void (^)(NSString *devId, NSString *name))success
                            failure:(TYFailureError)failure;

/// Bluetooth device binding after network access,  productKey + mac = pid, Compatible with third party equipment of distribution network.
/// @param uuid Bluetooth sub device short address identification.
/// @param devKey The device key.
/// @param nodeId The node ID.
/// @param productKey The product key.
/// @param ver Version.
/// @param mac The device mac.
/// @param companyId Company ID corresponding to sig mesh device.
/// @param venderId The third-party device needs to be transferred in. At present, it supports the light group and switch. If lightless operation exists, it will pass in "01" by default, and "02" will be passed in if there is no lightless operation.
/// @param success  Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addSIGMeshSubDeviceWithUuid:(NSString *)uuid
                             devKey:(NSString *)devKey
                             nodeId:(NSString *)nodeId
                         productKey:(NSString *)productKey
                                ver:(NSString *)ver
                                mac:(NSString *)mac
                          companyId:(nonnull NSString *)companyId
                           venderId:(nonnull NSString *)venderId
                            success:(void (^)(NSString *devId, NSString *name))success
                            failure:(TYFailureError)failure;

/// Bind PID to Bluetooth device before network access.
/// @param uuid Bluetooth sub device short address identification.
/// @param devKey The device key.
/// @param nodeId The node ID.
/// @param productId The product ID.
/// @param ver Version.
/// @param mac The device mac.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addSIGMeshSubDeviceWithUuid:(NSString *)uuid
                             devKey:(NSString *)devKey
                             nodeId:(NSString *)nodeId
                          productId:(NSString *)productId
                                ver:(NSString *)ver
                                mac:(NSString *)mac
                            success:(void (^)(NSString *devId, NSString *name))success
                            failure:(TYFailureError)failure;

/// The Bluetooth device is bound with PID before entering the network, which can be compatible with the third-party equipment of distribution network
/// @param uuid Bluetooth sub device short address identification.
/// @param devKey The device key.
/// @param nodeId The node ID.
/// @param productId The product ID.
/// @param ver Version.
/// @param mac The device mac.
/// @param companyId The company ID.
/// @param venderId The third-party device needs to be transferred in. At present, it supports the light group and switch. If lightless operation exists, it will pass in "01" by default, and "02" will be passed in if there is no lightless operation.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addSIGMeshSubDeviceWithUuid:(NSString *)uuid
                             devKey:(NSString *)devKey
                             nodeId:(NSString *)nodeId
                          productId:(NSString *)productId
                                ver:(NSString *)ver
                                mac:(NSString *)mac
                          companyId:(nonnull NSString *)companyId
                           venderId:(nonnull NSString *)venderId
                            success:(void (^)(NSString *devId, NSString *name))success
                            failure:(TYFailureError)failure;

/// Assign the node ID of SIG mesh to the cloud, + 0000 0111 = 8 each time.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getSIGMeshNodeAddressFromServerWithSuccess:(TYSuccessInt)success failure:(TYFailureError)failure;

/// Get node ID of SIG mesh in batch
/// @param number Allocated quantity
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getMultiNodeAddressFromServerWithNumber:(NSInteger)number success:(TYSuccessList)success failure:(TYFailureError)failure;

/// Remove the sig mesh sub device through the gateway under the gateway connection.
/// @param gatewayId The gateway ID.
/// @param subDeviceId The sub device ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)removeMeshSubDeviceWithGatewayId:(NSString *)gatewayId
                             subDeviceId:(NSString *)subDeviceId
                                 success:(TYSuccessHandler)success
                                 failure:(TYFailureError)failure;

/// Assign sig mesh terminal source ID to cloud.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getSIGMeshSourceAddressFromServerWithSuccess:(TYSuccessInt)success
                                             failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
