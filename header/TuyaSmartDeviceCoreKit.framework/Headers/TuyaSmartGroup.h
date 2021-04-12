//
// TuyaSmartGroup.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartGroup
#define TuyaSmart_TuyaSmartGroup

#import <Foundation/Foundation.h>
#import "TuyaSmartGroupModel.h"
#import "TuyaSmartGroupDevListModel.h"

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartGroup;

/// The delegate of TuyaSmartGroup class, provides group related status update callback.
@protocol TuyaSmartGroupDelegate<NSObject>

@optional

/// Group dps data update.
/// @param group The instance of TuyaSmartGroup.
/// @param dps dps.
- (void)group:(TuyaSmartGroup *)group dpsUpdate:(NSDictionary *)dps;

/// Group Information Update.
/// @param group The instance of TuyaSmartGroup.
- (void)groupInfoUpdate:(TuyaSmartGroup *)group;

/// Group removal.
/// @param groupId The group ID.
- (void)groupRemove:(NSString *)groupId;

/// Group dpCodes data update.
/// @param group The instance of TuyaSmartGroup.
/// @param dpCodes Dp Codes
- (void)group:(TuyaSmartGroup *)group dpCodesUpdate:(NSDictionary *)dpCodes;

/// Group Response of Zigbee Devices Joining Gateway. 1: Over the Scenario Limit 2: Sub-device Timeout 3: Setting Value Out of Range 4: Write File Error 5: Other Errors.
/// @param group The instance of TuyaSmartGroup.
/// @param responseCode Response code.
- (void)group:(TuyaSmartGroup *)group addResponseCode:(NSArray <NSNumber *>*)responseCode;

/// Group Response of Zigbee Devices removing Gateway 1: Over the Scenario Limit 2: Sub-device Timeout 3: Setting Value Out of Range 4: Write File Error 5: Other Errors.
/// @param group The instance of TuyaSmartGroup.
/// @param responseCode Response code.
- (void)group:(TuyaSmartGroup *)group removeResponseCode:(NSArray <NSNumber *>*)responseCode;

@end

/// @brief Smart device group, including group creation, group command issuance, group basic information update, etc.
///
/// Adding a number of devices with the same function to a group allows you to control them simultaneously.
///
@interface TuyaSmartGroup : NSObject

/// Get the basic group information model
@property (nonatomic, strong, readonly) TuyaSmartGroupModel *groupModel;

@property (nonatomic, weak, nullable) id<TuyaSmartGroupDelegate> delegate;

/// Get TuyaSmartGroup instance.
/// @param groupId The group ID.
+ (nullable instancetype)groupWithGroupId:(NSString *)groupId;

/// Get TuyaSmartGroup instance.
/// @param groupId The group ID.
- (nullable instancetype)initWithGroupId:(NSString *)groupId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

/// Get the device list for the corresponding group based on productId.
/// @param productId Product ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getDevList:(NSString *)productId
           success:(nullable void(^)(NSArray <TuyaSmartGroupDevListModel *> *list))success
           failure:(nullable TYFailureError)failure;

/// Group control command issuance.
/// @param dps dps.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDps:(NSDictionary *)dps success:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

/// Rename the group name.
/// @param name The group name.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateGroupName:(NSString *)name success:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

/// Edit group icon.
/// @param icon Group icon.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateIcon:(UIImage *)icon
           success:(nullable TYSuccessHandler)success
           failure:(nullable TYFailureError)failure;

/// Edit group icon.
/// @param cloudKey The cloud key.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateIconWithCloudKey:(NSString *)cloudKey
                       success:(nullable TYSuccessHandler)success
                       failure:(nullable TYFailureError)failure;

/// Modify the device list of the group.
/// @param devList Device list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateGroupRelations:(NSArray <NSString *>*)devList
                     success:(nullable TYSuccessHandler)success
                     failure:(nullable TYFailureError)failure;

/// Remove Group.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)dismissGroup:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;


#pragma mark - zigbee

#if TARGET_OS_IOS

/// Add sub devices to groups (interacting locally with gateways).
/// @param nodeList Sub-device nodeId list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addSubDeviceWithSubDeviceNodeList:(NSArray <NSString *>*)nodeList
                                  success:(nullable TYSuccessHandler)success
                                  failure:(nullable TYFailureError)failure;

/// Remove sub devices from groups (interacting locally with gateways).
/// @param nodeList  Sub-device nodeId list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)removeSubDeviceWithSubDeviceNodeList:(NSArray <NSString *>*)nodeList
                                     success:(nullable TYSuccessHandler)success
                                     failure:(nullable TYFailureError)failure;

#endif

/// Cancel Request
- (void)cancelRequest;


@end

NS_ASSUME_NONNULL_END

#endif
