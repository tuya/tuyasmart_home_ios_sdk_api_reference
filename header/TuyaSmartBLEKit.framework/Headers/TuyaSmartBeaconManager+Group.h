//
// TuyaSmartBLEManager.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)


#import "TuyaSmartBeaconManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartBeaconManager (Group)

/// Create a group in the cloud
/// @param groupName grou name
/// @param productId device productId
/// @param beaconCategory device category
/// @param success Called groupId when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)createBeaconGroupWithGroupName:(NSString *)groupName
                             productId:(NSString *)productId
                                   pcc:(NSString *)beaconCategory
                               success:(TYSuccessString)success
                               failure:(TYFailureError)failure;

/// Add device to group.
/// @param devId The device ID.
/// @param groupId The group ID.
/// @param success Called device groups data when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addDeviceToGroupWithDevId:(NSString *)devId
                          groupId:(NSString *)groupId
                          success:(TYSuccessData)success
                          failure:(TYFailureError)failure ;

/// Delete device from group.
/// @param devId The device ID.
/// @param groupId The group ID.
/// @param success Called device groups data when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)deleteDeviceFromGroupWithDevId:(NSString *)devId
                               groupId:(NSString *)groupId
                               success:(TYSuccessData)success
                               failure:(TYFailureError)failure;

/// Query device groups
/// @param devId The device ID.
/// @param success Called device groups data when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)queryGroupsWithDevId:(NSString *)devId
                     success:(TYSuccessData)success
                     failure:(TYFailureError)failure;

/// Group dp command publish.
/// @param dps Dp command
/// @param devId The device ID.
/// @param groupId The group ID.
/// @param success Called  when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)publishGroupDps:(NSDictionary *)dps
             firstDevId:(NSString *)devId
                groupId:(NSString *)groupId
                success:(nullable TYSuccessHandler)success
                failure:(nullable TYFailureError)failure;


/// Remove group of specific address
/// @param groupId The group ID.
/// @param success Called  when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)removeDeviceGroupWithGroupId:(NSString *)groupId
                            success:(nullable TYSuccessHandler)success
                            failure:(nullable TYFailureError)failure ;

/// Add device to cloud
/// @param groupId The group ID.
/// @param deviceId The device ID.
/// @param success Called  when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addDeviceWithGroupId:(NSString *)groupId
                    deviceId:(NSString *)deviceId
                    success:(TYSuccessHandler)success
                     failure:(TYFailureError)failure;

/// The specified device is deleted from the group
/// @param groupId The group ID.
/// @param deviceId The device ID.
/// @param success Called  when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)removeDeviceWithGroupId:(NSString *)groupId
                       deviceId:(NSString *)deviceId
                        success:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;

/// remove device from cloud
/// @param groupId The group ID.
/// @param success Called  when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)removeBeaconGroupGroupId:(NSString *)groupId
                         success:(nullable TYSuccessHandler)success
                         failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
