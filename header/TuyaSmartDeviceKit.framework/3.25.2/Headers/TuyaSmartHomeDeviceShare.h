//
// TuyaSmartHomeDeviceShare.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <UIKit/UIKit.h>
#import "TuyaSmartShareMemberModel.h"
#import "TuyaSmartShareMemberDetailModel.h"
#import "TuyaSmartReceiveMemberDetailModel.h"
#import "TuyaSmartReceivedShareUserModel.h"
#import "TuyaSmartShareDeviceModel.h"
#import "TuyaSmartDeviceShareModel.h"


/// Sharing device related functions (based on device dimension sharing).
@interface TuyaSmartHomeDeviceShare : NSObject

/// Device add sharing.
/// @param requestModel Adding a shared device model
/// @param success Called when the task finishes successfully. TuyaSmartShareMemberModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)addDeviceShareWithRequestModel:(TuyaSmartDeviceShareRequestModel *)requestModel
                               success:(void(^)(TuyaSmartShareMemberModel *model))success
                               failure:(TYFailureError)failure;


/// Add Share (New, does not overwrite old share)
/// @param memberId memberId
/// @param devIds devId list
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)addShareWithMemberId:(NSInteger)memberId
                      devIds:(NSArray <NSString *> *)devIds
                     success:(TYSuccessHandler)success
                     failure:(TYFailureError)failure;


/// Get a list of all users actively sharing under family.
/// @param homeId homeId
/// @param success Called when the task finishes successfully. A list of TuyaSmartShareMemberModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getShareMemberListWithHomeId:(long long)homeId
                             success:(void(^)(NSArray<TuyaSmartShareMemberModel *> *list))success
                             failure:(TYFailureError)failure;


/// Get a list of all users who have received a share.
/// @param success Called when the task finishes successfully. A list of TuyaSmartShareMemberModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getReceiveMemberListWithSuccess:(void(^)(NSArray<TuyaSmartShareMemberModel *> *list))success
                                failure:(TYFailureError)failure;


/// Get the shared data of a single active share user.
/// @param memberId memberId
/// @param success Called when the task finishes successfully. TuyaSmartShareMemberDetailModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getShareMemberDetailWithMemberId:(NSInteger)memberId
                                 success:(void(^)(TuyaSmartShareMemberDetailModel *model))success
                                 failure:(TYFailureError)failure;


/// Get the shared data of a single user who received a share.
/// @param memberId memberId
/// @param success Called when the task finishes successfully. TuyaSmartShareMemberDetailModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getReceiveMemberDetailWithMemberId:(NSInteger)memberId
                                   success:(void(^)(TuyaSmartReceiveMemberDetailModel *model))success
                                   failure:(TYFailureError)failure;



/// Remove active sharers.
/// @param memberId memberId
/// @param success  Called when the task finishes successfully.
/// @param failure  If error occurred while adding the task, this block will be called.
- (void)removeShareMemberWithMemberId:(NSInteger)memberId
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;


/// Remove received sharer
/// @param memberId Shared member ID.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)removeReceiveShareMemberWithMemberId:(NSInteger)memberId
                                     success:(TYSuccessHandler)success
                                     failure:(TYFailureError)failure;


/// Change the nickname of an active shared user.
/// @param memberId memberId
/// @param name nickname
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)renameShareMemberNameWithMemberId:(NSInteger)memberId
                                     name:(NSString *)name
                                  success:(TYSuccessHandler)success
                                  failure:(TYFailureError)failure;


/// Change the nickname of the person who received the share.
/// @param memberId memberId
/// @param name nickname
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)renameReceiveShareMemberNameWithMemberId:(NSInteger)memberId
                                            name:(NSString *)name
                                         success:(TYSuccessHandler)success
                                         failure:(TYFailureError)failure;


#pragma mark - 

/// Remove Received Shared.
/// @param devId   DevId
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)removeReceiveDeviceShareWithDevId:(NSString *)devId
                                  success:(TYSuccessHandler)success
                                  failure:(TYFailureError)failure;


/// Delete shared devices.
/// @param memberId member ID
/// @param devId Device ID
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)removeDeviceShareWithMemberId:(NSInteger)memberId
                                devId:(NSString *)devId
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;


/// Get a list of device share users.
/// @param devId The device ID.
/// @param success Called when the task finishes successfully. A list of TuyaSmartShareMemberModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getDeviceShareMemberListWithDevId:(NSString *)devId
                                  success:(void(^)(NSArray<TuyaSmartShareMemberModel *> *list))success
                                  failure:(TYFailureError)failure;


/// Get users for device sharing.
/// @param devId The device ID.
/// @param success Called when the task finishes successfully. TuyaSmartReceivedShareUserModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getShareInfoWithDevId:(NSString *)devId
                      success:(void(^)(TuyaSmartReceivedShareUserModel *model))success
                      failure:(TYFailureError)failure;


/// Invitation to share to other users
/// @param countryCode countryCode
/// @param userAccount userAccount
/// @param devId Device ID.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)inviteShareWithCountryCode:(NSString *)countryCode
                       userAccount:(NSString *)userAccount
                             devId:(NSString *)devId
                           success:(TYSuccessInt)success
                           failure:(TYFailureError)failure;


/// Confirm invite share.
/// @param shareId The shareId returned by the invite share interface.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)confirmInviteShareWithShareId:(NSInteger)shareId
                              success:(TYSuccessHandler)success
                              failure:(TYFailureError)failure;

#pragma mark - Group Share

/// Get a list of shared users for a single group (reflected in the panel).
/// @param groupId groupId
/// @param success Called when the task finishes successfully. A list of TuyaSmartShareMemberModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getGroupShareMemberListWithGroupId:(NSString *)groupId
                                   success:(void(^)(NSArray<TuyaSmartShareMemberModel *> *list))success
                                   failure:(TYFailureError)failure;


/// Share groups to other users.
/// @param homeId HomeId
/// @param countryCode Country Code
/// @param userAccount User Account
/// @param groupId GroupId
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)addGroupShareToMemberWithHomeId:(long long)homeId
                             countyCode:(NSString *)countryCode
                            userAccount:(NSString *)userAccount
                                groupId:(NSString *)groupId
                                success:(TYSuccessID)success
                                failure:(TYFailureError)failure;


/// Get sharing information of the group.
/// @param groupId groupId
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getShareGroupFromInfoWithGroupId:(NSString *)groupId
                                 success:(TYSuccessID)success
                                 failure:(TYFailureError)failure;


/// Remove sharing groups.
/// @param groupId groupId
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)removeShareGroupWithGroupId:(NSString *)groupId
                            success:(TYSuccessID)success
                            failure:(TYFailureError)failure;


/// Remove group shares from other members.
/// @param relationId relationId
/// @param groupId groupId
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)removeGroupShareWithRelationId:(NSInteger)relationId
                               groupId:(NSString *)groupId
                               success:(TYSuccessHandler)success
                               failure:(TYFailureError)failure;

@end
