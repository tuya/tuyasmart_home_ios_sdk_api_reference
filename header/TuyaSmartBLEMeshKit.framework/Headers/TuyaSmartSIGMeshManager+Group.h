//
// TuyaSmartSIGMeshManager+Group.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartBLEMeshKit/TuyaSmartBLEMeshKit.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief The Bluetooth mesh activator category for the Bluetooth mesh manager.
///
/// This API provides multiple group management functions. For example, devices can be added to groups or removed from groups.
@interface TuyaSmartSIGMeshManager (Group)

/// Adds a device to a group.
/// @param devId The device ID.
/// @param groupAddress The group address.
- (void)addDeviceToGroupWithDevId:(NSString *)devId
                     groupAddress:(uint32_t)groupAddress;

/// Removes a device from a group.
/// @param devId The device ID.
/// @param groupAddress The group address.
- (void)deleteDeviceToGroupWithDevId:(NSString *)devId
                        groupAddress:(uint32_t)groupAddress;

/// Queries the devices in the group based on the group address.
/// @param groupAddress The group address.
- (void)queryGroupMemberWithGroupAddress:(uint32_t)groupAddress;


/// Queries the group list.
/// @param devId The device ID.
- (void)queryGroupListWithDevid:(NSString *)devId;

@end

NS_ASSUME_NONNULL_END
