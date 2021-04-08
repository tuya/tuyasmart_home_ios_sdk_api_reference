//
// TuyaSmartRoom.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartRoomModel.h"
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

@interface TuyaSmartRoom : NSObject

/// room model
@property (nonatomic, strong, readonly) TuyaSmartRoomModel *roomModel;

/// device list
@property (nonatomic, strong, readonly) NSArray <TuyaSmartDeviceModel *> *deviceList;

/// group list
@property (nonatomic, strong, readonly) NSArray <TuyaSmartGroupModel *> *groupList;


/// Get room instance.
///
/// @param roomId Room ID
/// @param homeId Home ID
/// @return instance
+ (instancetype)roomWithRoomId:(long long)roomId homeId:(long long)homeId;


/// Get room instance
///
/// @param roomId Room ID
/// @param homeId Home ID
/// @return instance
- (instancetype)initWithRoomId:(long long)roomId homeId:(long long)homeId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;


/// Rename the room.
///
/// @param roomName    Room name
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)updateRoomName:(NSString *)roomName success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Edit room icon.
///
/// @param icon room icon
/// @param success  Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)updateIcon:(UIImage *)icon success:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

/// Add device to the room.
///
/// @param deviceId    Device ID
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)addDeviceWithDeviceId:(NSString *)deviceId success:(TYSuccessHandler)success failure:(TYFailureError)failure;


/// Remove device from the room.
///
/// @param deviceId    Device ID
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)removeDeviceWithDeviceId:(NSString *)deviceId success:(TYSuccessHandler)success failure:(TYFailureError)failure;


/// Add group to the room.
///
/// @param groupId     Group ID
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)addGroupWithGroupId:(NSString *)groupId success:(TYSuccessHandler)success failure:(TYFailureError)failure;


/// Remove group from the room
///
/// @param groupId     Group ID
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)removeGroupWithGroupId:(NSString *)groupId success:(TYSuccessHandler)success failure:(TYFailureError)failure;


/// Batch modification of the relationship between rooms, groups and devices.
///
/// @param deviceGroupList  List of devices or groups.
/// @param success          Called when the task finishes successfully.
/// @param failure          If error occurred while adding the task, this block will be called.
- (void)saveBatchRoomRelationWithDeviceGroupList:(NSArray <NSString *> *)deviceGroupList
                                         success:(TYSuccessHandler)success
                                         failure:(TYFailureError)failure;


@end
