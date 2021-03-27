//
// TuyaSmartSIGMeshManager+Group.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartBLEMeshKit/TuyaSmartBLEMeshKit.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief SIG mesh activator Category for (SIG) bluetooth mesh manager.
///
/// Mainly contains gong for group management, adding devices to groups and removing devices from groups.
@interface TuyaSmartSIGMeshManager (Group)

/// Add device to group.
/// @param devId The device ID.
/// @param groupAddress Group address.
- (void)addDeviceToGroupWithDevId:(NSString *)devId
                     groupAddress:(uint32_t)groupAddress;

/// Remove device from group.
/// @param devId The device ID.
/// @param groupAddress The group address.
- (void)deleteDeviceToGroupWithDevId:(NSString *)devId
                        groupAddress:(uint32_t)groupAddress;

/// Query the devices in the group through the group address.
/// @param groupAddress The group address.
- (void)queryGroupMemberWithGroupAddress:(uint32_t)groupAddress;


/// Query group list.
/// @param devId The device ID.
- (void)queryGroupListWithDevid:(NSString *)devId;

@end

NS_ASSUME_NONNULL_END
