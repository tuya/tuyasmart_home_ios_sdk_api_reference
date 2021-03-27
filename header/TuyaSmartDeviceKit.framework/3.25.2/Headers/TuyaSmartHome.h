//
// TuyaSmartHome.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartHomeModel.h"
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>
#import "TuyaSmartRoomModel.h"
#import "TuyaSmartHomeMemberModel.h"
#import "TuyaSmartHomeAddMemberRequestModel.h"

@class TuyaSmartHome;

@protocol TuyaSmartHomeDelegate <NSObject>

@optional


/// The delegate of home update information, such as the name, online
///
/// @param home instance
- (void)homeDidUpdateInfo:(TuyaSmartHome *)home;

/// The delegate of shared device list update.
///
/// @param home instance
- (void)homeDidUpdateSharedInfo:(TuyaSmartHome *)home;


/// The delegate when a new room is added.
///
/// @param home instance
/// @param room roomModel
- (void)home:(TuyaSmartHome *)home didAddRoom:(TuyaSmartRoomModel *)room;


/// The delegate when an existing room is removed.
///
/// @param home     instance
/// @param roomId   roomId
- (void)home:(TuyaSmartHome *)home didRemoveRoom:(long long)roomId;


/// The delegate of room update information, such as the name.
///
/// @param home     instance
/// @param room     roomModel
- (void)home:(TuyaSmartHome *)home roomInfoUpdate:(TuyaSmartRoomModel *)room;


/// The delegate of relation update of room, group and device.
///
/// @param home instance
/// @param room roomModel
- (void)home:(TuyaSmartHome *)home roomRelationUpdate:(TuyaSmartRoomModel *)room;


/// The delegate when a new device is added.
///
/// @param home     instance
/// @param device   deviceModel
- (void)home:(TuyaSmartHome *)home didAddDeivice:(TuyaSmartDeviceModel *)device;


/// The delegate when an existing device is removed.
///
/// @param home     instance
/// @param devId    devId
- (void)home:(TuyaSmartHome *)home didRemoveDeivice:(NSString *)devId;


/// The delegate of device update information, such as the name.
///
/// @param home     instance
/// @param device   deviceModel
- (void)home:(TuyaSmartHome *)home deviceInfoUpdate:(TuyaSmartDeviceModel *)device;


/// The delegate of device dps update.
///
/// @param home     instance
/// @param device   deviceModel
/// @param dps      dps
- (void)home:(TuyaSmartHome *)home device:(TuyaSmartDeviceModel *)device dpsUpdate:(NSDictionary *)dps;


/// The delegate of warning information update.
///
/// @param home         instance
/// @param device       deviceModel
/// @param warningInfo  warning Info
- (void)home:(TuyaSmartHome *)home device:(TuyaSmartDeviceModel *)device warningInfoUpdate:(NSDictionary *)warningInfo;


/// The delegate of device firmware upgrade status update.
///
/// @param home                home instance
/// @param device              deviceModel
/// @param upgradeStatusModel  upgradeStatusModel
- (void)home:(TuyaSmartHome *)home device:(TuyaSmartDeviceModel *)device firmwareUpgradeStatusModel:(TuyaSmartFirmwareUpgradeStatusModel *)upgradeStatusModel;


/// the delegate when family/shared devices ota status are updated
/// @param home The home instance
/// @param otaModelList OTA model list
- (void)home:(TuyaSmartHome *)home didUpdateOTAModelList:(NSArray<TuyaSmartDeviceOTAModel *> *)otaModelList;

/// The delegate when a new group is added.
///
/// @param home     instance
///  @param group    groupModel
- (void)home:(TuyaSmartHome *)home didAddGroup:(TuyaSmartGroupModel *)group;


/// The delegate of group dps update.
///
/// @param home     instance
/// @param group    groupModel
/// @param dps      dps
- (void)home:(TuyaSmartHome *)home group:(TuyaSmartGroupModel *)group dpsUpdate:(NSDictionary *)dps;


/// The delegate when an existing group is removed.
///
/// @param home     instance
/// @param groupId  groupId
- (void)home:(TuyaSmartHome *)home didRemoveGroup:(NSString *)groupId;


/// The delegate of group update information, such as the name.
///
/// @param home     instance
/// @param group    groupModel
- (void)home:(TuyaSmartHome *)home groupInfoUpdate:(TuyaSmartGroupModel *)group;

#pragma mark - deprecated

/// The delegate of relation update of home and room.(deprecated)
///
/// @param home instance
/// @deprecated This method is deprecated, Use TuyaSmartHomeDelegate::home:didAddRoom: or  TuyaSmartHomeDelegate::home:didRemoveRoom: instead.
- (void)homeDidUpdateRoomInfo:(TuyaSmartHome *)home __deprecated_msg("Use -[TuyaSmartHomeDelegate home:didAddRoom:] or [TuyaSmartHomeDelegate home:didRemoveRoom:] instead.");

/// The delegate of device firmware upgrade status update.
///
/// @param home           instance
/// @param device         deviceModel
/// @param upgradeStatus  upgrade status
/// @deprecated This method is deprecated, Use TuyaSmartHomeDelegate::home:device:firmwareUpgradeStatusModel: instead.
- (void)home:(TuyaSmartHome *)home device:(TuyaSmartDeviceModel *)device upgradeStatus:(TuyaSmartDeviceUpgradeStatus)upgradeStatus __deprecated_msg("This method is deprecated, Use home:device:firmwareUpgradeStatusModel: instead");

@end

@interface TuyaSmartHome : NSObject

@property (nonatomic, weak) id <TuyaSmartHomeDelegate> delegate;

@property (nonatomic, strong, readonly) TuyaSmartHomeModel *homeModel;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartRoomModel *> *roomList;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartDeviceModel *> *deviceList;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartGroupModel *> *groupList;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartDeviceModel *> *sharedDeviceList;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartGroupModel *>  *sharedGroupList;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartDeviceOTAModel *> *deviceOtaList;

/// Init home.
///
/// @param homeId Home Id
/// @return instance
+ (instancetype)homeWithHomeId:(long long)homeId;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Home

/// After initializing the home object, you need to get the details of the family, homeModel, roomList, deviceList, groupList to have the data。
/// @param success Called when the task finishes successfully. TuyaSmartHomeModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getHomeDetailWithSuccess:(void (^)(TuyaSmartHomeModel *homeModel))success
                         failure:(TYFailureError)failure;

/// After get home details, update device ota status
/// @param homeId Home id
/// @param success Called when the task finishes successfully.
/// @param failure  If error occurred while adding the task, this block will be called.
- (void)getDeviceOTAStatusWithHomeId:(long long)homeId
                             success:(void (^)(NSArray<TuyaSmartDeviceOTAModel *> *))success
                             failure:(TYFailureError)failure;


/// Update home info, API version 2.0.
///
/// @param homeName    Home name
/// @param geoName     City name
/// @param latitude    Lat
/// @param longitude   Lon
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)updateHomeInfoWithName:(NSString *)homeName
                       geoName:(NSString *)geoName
                      latitude:(double)latitude
                     longitude:(double)longitude
                       success:(TYSuccessHandler)success
                       failure:(TYFailureError)failure;



/// Update home info,API version 3.0
///
/// @param homeName    Home name
/// @param geoName     City name
/// @param latitude    Lat
/// @param longitude   Lon
/// @param rooms       Room name array
/// @param overWriteRoom     NSDictionary now only support "overWriteRoom":boolean
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)updateHomeInfoWithName:(NSString *)homeName
                       geoName:(NSString *)geoName
                      latitude:(double)latitude
                     longitude:(double)longitude
                         rooms:(NSArray *)rooms
                 overWriteRoom:(BOOL)overWriteRoom
                       success:(TYSuccessHandler)success
                       failure:(TYFailureError)failure;


/// Remove a home.
///
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)dismissHomeWithSuccess:(TYSuccessHandler)success
                       failure:(TYFailureError)failure;


/// Sorting of devices and groups under the entire family.
/// @param orderList order list [@{@"bizId": @"XXX", @"bizType": @"XXX"},@{@"bizId": @"XXX",@"bizType": @"XXX"}], where bizId is the device's devId or group's groupId, device's bizType = @"6" group's bizType = @"5".
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)sortDeviceOrGroupWithOrderList:(NSArray<NSDictionary *> *)orderList
                               success:(TYSuccessHandler)success
                               failure:(TYFailureError)failure;


#pragma mark - Room


/// Add a new room
///
/// @param name        Room name.
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)addHomeRoomWithName:(NSString *)name
                    success:(TYSuccessHandler)success
                    failure:(TYFailureError)failure;


/// Remove a room
///
/// @param roomId      Home Id
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)removeHomeRoomWithRoomId:(long long)roomId
                         success:(TYSuccessHandler)success
                         failure:(TYFailureError)failure;


/// Homes sort
///
/// @param roomList    Homes list
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)sortRoomList:(NSArray <TuyaSmartRoomModel *> *)roomList
             success:(TYSuccessHandler)success
             failure:(TYFailureError)failure;


#pragma mark - home member

/// Get home member list
///
/// @param success     Called when the task finishes successfully. A list of TuyaSmartHomeMemberModel will be returned.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)getHomeMemberListWithSuccess:(void(^)(NSArray <TuyaSmartHomeMemberModel *> *memberList))success
                             failure:(TYFailureError)failure;


/// Add a home member
///
/// @param requestModel member model
/// @param success      Called when the task finishes successfully.
/// @param failure      If error occurred while adding the task, this block will be called.
- (void)addHomeMemberWithAddMemeberRequestModel:(TuyaSmartHomeAddMemberRequestModel *)requestModel
                                        success:(TYSuccessDict)success
                                        failure:(TYFailureError)failure;

/// Accept or reject to shared home
///
/// @param accept       A boolean value indicates whether to accept the invitation.
/// @param success      Called when the task finishes successfully.
/// @param failure      If error occurred while adding the task, this block will be called.
- (void)joinFamilyWithAccept:(BOOL)accept
                     success:(TYSuccessBOOL)success
                     failure:(TYFailureError)failure;


/// Sync home device list
///
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)syncHomeDeviceListWithSuccess:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;

@end
