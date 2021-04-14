//
// TuyaSmartBleMesh+SIGMesh.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartBleMesh.h"

NS_ASSUME_NONNULL_BEGIN

/// @brief SIG mesh information category for bluetooth mesh.=====The category of the Bluetooth mesh information.
@interface TuyaSmartBleMesh (SIGMesh)

+ (void)createSIGMeshWithHomeId:(long long)homeId
                        success:(void(^)(TuyaSmartBleMeshModel *meshModel))success
                        failure:(TYFailureError)failure;

/// Bluetooth device binding after network access, productKey + mac = pid.=====Adds a Bluetooth sub-device to the app after the network is connected. The product ID that consists of the product key and MAC address is required in this operation.
/// @param uuid The short address identification of the Bluetooth sub-device.
/// @param devKey The device key.
/// @param nodeId The node ID.
/// @param productKey The product key.
/// @param ver Version.
/// @param mac The device mac.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addSIGMeshSubDeviceWithUuid:(NSString *)uuid
                             devKey:(NSString *)devKey
                             nodeId:(NSString *)nodeId
                         productKey:(NSString *)productKey
                                ver:(NSString *)ver
                                mac:(NSString *)mac
                            success:(void (^)(NSString *devId, NSString *name))success
                            failure:(TYFailureError)failure;

/// Bluetooth device binding after network access,  productKey + mac = pid, Compatible with third party equipment of distribution network.=====Adds a Bluetooth sub-device to the app after the network is connected. The product ID that consists of the product key and MAC address is required in this operation. This applies when a third-party device is paired.
/// @param uuid The short address identification of the Bluetooth sub-device.
/// @param devKey The device key.
/// @param nodeId The node ID.
/// @param productKey The product key.
/// @param ver The version.
/// @param mac The device MAC.
/// @param companyId The company ID of the Bluetooth mesh device.
/// @param venderId The third-party device needs to be transferred in. At present, it supports the light group and switch. If lightless operation exists, it will pass in "01" by default, and "02" will be passed in if there is no lightless operation.======This parameter is required to add a third-party device to the app. Lighting devices and switches are supported. If the lightless operation exists, the value is set to `01`. If no lightless operation exists, the value is set to `02`.
/// @param success  Called when the task is finished.
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

/// Binds a PID to a Bluetooth device before the network is connected.
/// @param uuid The short address identification of the Bluetooth sub-device.
/// @param devKey The device key.
/// @param nodeId The node ID.
/// @param productId The product ID.
/// @param ver The version.
/// @param mac The device MAC.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addSIGMeshSubDeviceWithUuid:(NSString *)uuid
                             devKey:(NSString *)devKey
                             nodeId:(NSString *)nodeId
                          productId:(NSString *)productId
                                ver:(NSString *)ver
                                mac:(NSString *)mac
                            success:(void (^)(NSString *devId, NSString *name))success
                            failure:(TYFailureError)failure;

/// The Bluetooth device is bound with a PID before the network is connected. This applies when a third-party device is paired.
/// @param uuid The short address identification of the Bluetooth sub-device.
/// @param devKey The device key.
/// @param nodeId The node ID.
/// @param productId The product ID.
/// @param ver The version.
/// @param mac The device MAC.
/// @param companyId The company ID.
/// @param venderId The third-party device needs to be transferred in. At present, it supports the light group and switch. If lightless operation exists, it will pass in "01" by default, and "02" will be passed in if there is no lightless operation.======This parameter is required to add a third-party device to the app. Lighting devices and switches are supported. If the lightless operation exists, the value is set to `01`. If no lightless operation exists, the value is set to `02`.
/// @param success Called when the task is finished.
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

/// Assigns the node ID of Bluetooth mesh to the cloud, + 0000 0111 = 8 each time.======Assigns the node ID of Bluetooth mesh to the cloud. In each request, the node ID is incremented by `0000 0111` or `8`.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getSIGMeshNodeAddressFromServerWithSuccess:(TYSuccessInt)success failure:(TYFailureError)failure;

/// Get node ID of SIG mesh in batch====Returns multiple node IDs of Bluetooth mesh in a call.
/// @param number Allocated quantity======The number of assigned node IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getMultiNodeAddressFromServerWithNumber:(NSInteger)number success:(TYSuccessList)success failure:(TYFailureError)failure;

/// Removes a Bluetooth mesh sub-device from the gateway to which the sub-device is connected.
/// @param gatewayId The gateway ID.
/// @param subDeviceId The sub-device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeMeshSubDeviceWithGatewayId:(NSString *)gatewayId
                             subDeviceId:(NSString *)subDeviceId
                                 success:(TYSuccessHandler)success
                                 failure:(TYFailureError)failure;

/// Assign sig mesh terminal source ID to cloud.=======Assigns the terminal source ID of Bluetooth mesh to the cloud.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getSIGMeshSourceAddressFromServerWithSuccess:(TYSuccessInt)success
                                             failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
