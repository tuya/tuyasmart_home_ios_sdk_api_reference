//
// TuyaSmartBleMesh.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The ble mesh delegate when mesh do some action.
@protocol TuyaSmartBleMeshDelegate<NSObject>

@optional

/// DP data update.
- (void)subDeviceUpdateWithAddress:(NSString *)address dps:(NSDictionary *)dps;

/// Raw transparent command received.
- (void)bleMeshReceiveRawData:(NSString *)raw;

/// Batch report of received data.
- (void)bleMeshReceiveBatchDeviceDpsInfo;

@end

/// @brief Bluetooth mesh base class, including the basic operations of Bluetooth mesh, such as create, update, delete mesh, etc.
///
/// mesh as an important parameter for Bluetooth mesh connection.
///
@interface TuyaSmartBleMesh : NSObject

@property (nonatomic, strong, readonly) TuyaSmartBleMeshModel *bleMeshModel;

@property (nonatomic, weak) id<TuyaSmartBleMeshDelegate> delegate;

/// Get device object.
/// @param meshId The mesh ID.
/// @param homeId The home ID.
+ (instancetype)bleMeshWithMeshId:(NSString *)meshId homeId:(long long)homeId;

/// Get device object.
/// @param meshId The mesh ID.
/// @param homeId The home ID.
- (instancetype)initWithMeshId:(NSString *)meshId homeId:(long long)homeId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

/// Create mesh.
/// @param meshName The mesh name.
/// @param homeId The home ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)createBleMeshWithMeshName:(NSString *)meshName homeId:(long long)homeId success:(void(^)(TuyaSmartBleMeshModel *meshModel))success failure:(TYFailureError)failure;

/// Get the sub device information of mesh.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getSubDeviceListFromCloudWithSuccess:(void (^)(NSArray <TuyaSmartDeviceModel *> *subDeviceList))success failure:(TYFailureError)failure;

/// Get single sub device information.
/// @param deviceId The device ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getSubDeviceFromCloudWithDeviceId:(NSString *)deviceId success:(void (^)(TuyaSmartDeviceModel *subDeviceModel))success failure:(TYFailureError)failure;

/// Single sub device DPS command issued.
/// @param nodeId The node ID.
/// @param pcc Size class label.
/// @param dps Command dictionary.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)publishNodeId:(NSString *)nodeId
                  pcc:(NSString *)pcc
                  dps:(NSDictionary *)dps
              success:(TYSuccessHandler)success
              failure:(TYFailureError)failure;

/// Group control equipment.
/// @param localId Local ID.
/// @param pcc Size class label.
/// @param dps Command dictionary.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)multiPublishWithLocalId:(NSString *)localId
                            pcc:(NSString *)pcc
                            dps:(NSDictionary *)dps
                        success:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;

/// Broadcast DPS command issued.
/// @param dps Command dictionary.
/// @param pcc Size class label.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)broadcastDps:(NSDictionary *)dps
                 pcc:(NSString *)pcc
             success:(TYSuccessHandler)success
             failure:(TYFailureError)failure;

/// Get the latest DPS information of the sub device.
/// @param nodeId The node ID.
/// @param pcc Size class label.
/// @param dpIdList List of keys in DPS.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getSubDeviceDpsWithNodeId:(NSString *)nodeId
                              pcc:(NSString *)pcc
                         dpIdList:(NSArray <NSNumber *> *)dpIdList
                          success:(TYSuccessHandler)success
                          failure:(TYFailureError)failure;

/// Send transparent instruction to device.
/// @param raw Transmission value.
/// @param pcc Size class label.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)publishRawDataWithRaw:(NSString *)raw
                          pcc:(NSString *)pcc
                      success:(TYSuccessHandler)success
                      failure:(TYFailureError)failure;

/// Modify mesh name.
/// @param meshName The mesh name.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateMeshName:(NSString *)meshName success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Delete mesh. If there are devices under the mesh group, the sub devices are also removed. The WiFi connector is also removed.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)removeMeshWithSuccess:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Bluetooth device access 2.0.
/// @param uuid Bluetooth sub device short address identification.
/// @param homeId The home ID.
/// @param authKey The authority key.
/// @param nodeId The node ID.
/// @param productKey The product key.
/// @param ver Version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addSubDeviceWithUuid:(NSString *)uuid
                      homeId:(long long)homeId
                     authKey:(NSString *)authKey
                      nodeId:(NSString *)nodeId
                  productKey:(NSString *)productKey
                         ver:(NSString *)ver
                     success:(void (^)(NSString *devId, NSString *name))success
                     failure:(TYFailureError)failure;

/// Rename mesh subdevice.
/// @param deviceId The device ID.
/// @param name The device name.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)renameMeshSubDeviceWithDeviceId:(NSString *)deviceId name:(NSString *)name success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Remove mesh sub device.
/// @param deviceId The device ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)removeMeshSubDeviceWithDeviceId:(NSString *)deviceId success:(TYSuccessHandler)success failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
