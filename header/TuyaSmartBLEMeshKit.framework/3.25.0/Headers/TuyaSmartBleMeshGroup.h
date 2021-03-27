//
// TuyaSmartBleMeshGroup.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartBleMeshGroup;

/// The ble mesh group delegate.  when use gateway to add device into group, will call it.
@protocol TuyaSmartBleMeshGroupDelegate <NSObject>

/// Group response of SIG mesh device joining gateway.
/// @param group TuyaSmartBleMeshGroup.
/// @param responseCode 1: Exceeded the maximum number of scenes 2: sub device timeout 3: set value out of range 4: write file error 5: other errors.
- (void)meshGroup:(TuyaSmartBleMeshGroup *)group addResponseCode:(NSArray <NSNumber *> *)responseCode;

/// SIG mesh device removes response from gateway group.
/// @param group TuyaSmartBleMeshGroup.
/// @param responseCode 1: Exceeded the maximum number of scenes 2: sub device timeout 3: set value out of range 4: write file error 5: other errors.
- (void)meshGroup:(TuyaSmartBleMeshGroup *)group removeResponseCode:(NSArray <NSNumber *> *)responseCode;
  
@end

/// @brief Tuya Bluetooth mesh device groups, including group creation, updating, adding devices to groups, etc.
///
/// Form a group of mesh devices with the same function and control them simultaneously with a single command.
///
@interface TuyaSmartBleMeshGroup : NSObject

@property (nonatomic, weak, nullable) id<TuyaSmartBleMeshGroupDelegate> delegate;

@property (nonatomic, strong, readonly) TuyaSmartGroupModel *meshGroupModel;

/// Get mesh group object.
/// @param groupId The group ID.
+ (instancetype)meshGroupWithGroupId:(NSInteger)groupId;

/// Get mesh group object.
/// @param groupId The group ID.
- (instancetype)initWithGroupId:(NSInteger)groupId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

/// Assign group ID to cloud.
/// @param meshId The mesh ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)getBleMeshGroupAddressFromCluondWithMeshId:(NSString *)meshId
                                           success:(TYSuccessInt)success
                                           failure:(TYFailureError)failure;

/// Create mesh group.
/// @param groupName Mesh group name.
/// @param meshId The mesh ID.
/// @param localId Local short address of the group.
/// @param pcc Group device size class
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)createMeshGroupWithGroupName:(NSString *)groupName
                              meshId:(NSString *)meshId
                             localId:(NSString *)localId
                                 pcc:(NSString *)pcc
                             success:(TYSuccessInt)success
                             failure:(TYFailureError)failure;

+ (NSInteger)getBleMeshGroupAddress;

+ (NSInteger)getBleMeshGroupCount;

- (void)deleteBleMeshGroupAddress:(NSInteger)address;

/// Modify mesh group name.
/// @param meshGroupName The mesh group name.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateMeshGroupName:(NSString *)meshGroupName success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Delete mesh group.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)removeMeshGroupWithSuccess:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Add device.
/// @param deviceId The device ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addDeviceWithDeviceId:(NSString *)deviceId success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Batch modify equipment.
/// @param deviceList The device list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)editDeviceWithDeviceList:(NSArray *)deviceList success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Remove the device.
/// @param deviceId The device ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)removeDeviceWithDeviceId:(NSString *)deviceId success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Get the list information of devices in the group.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getDeviceListInfoWithSuccess:(void (^)(NSArray <TuyaSmartDeviceModel *> *deviceList))success failure:(TYFailureError)failure;

/// Get the list information of devices in the group.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use TuyaSmartBleMeshGroup getDeviceListInfoWithSuccess:failure: instead.
- (void)getDeviveListInfoWithSuccess:(void (^)(NSArray <TuyaSmartDeviceModel *> *deviceList))success failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use [TuyaSmartBleMeshGroup getDeviceListInfoWithSuccess:failure:] instead");

@end

#pragma mark - SIG Mesh

/// @brief The group command for gateway. Add device into group.
@interface TuyaSmartBleMeshGroup (SIGMesh)

/// Add sig mesh sub device group through sig mesh gateway.
/// It is necessary to ensure that the relationship of the sub devices belongs to the sig mesh gateway.
/// @param subList Gateway sub equipment to be operated.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addSubDeviceWithSubList:(NSArray<TuyaSmartDeviceModel *> * _Nonnull )subList success:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

/// Delete sig mesh sub device group through sig mesh gateway.
/// It is necessary to ensure that the relationship of the sub devices belongs to the sig mesh gateway.
/// @param subList Gateway sub equipment to be operated.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)removeSubDeviceWithSubList:(NSArray<TuyaSmartDeviceModel *> * _Nonnull )subList success:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

- (void)publishDps:(NSDictionary *)dps success:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

/// Custom param publish
/// @param params param:dictionary  { "localId":"c050" ,"dps":{"1":true}  “pcc”:"1510"}
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDpsWithParams:(NSDictionary *)params success:(TYSuccessHandler)success failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END

