//
// TuyaSmartHomeMember.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartHomeMemberModel.h"
#import "TuyaSmartHomeMemberRequestModel.h"

@interface TuyaSmartHomeMember : NSObject

#pragma mark - public


/// Remove a home member.
///
/// @param memberId    Member Id
/// @param success     Called when the task finishes successfully.
/// @param failure     If error occurred while adding the task, this block will be called.
- (void)removeHomeMemberWithMemberId:(long long)memberId
                             success:(TYSuccessHandler)success
                             failure:(TYFailureError)failure;



/// Update home member info
///
/// @param memberRequestModel request model, Set the corresponding property
/// @param success            Called when the task finishes successfully.
/// @param failure            If error occurred while adding the task, this block will be called.
- (void)updateHomeMemberInfoWithMemberRequestModel:(TuyaSmartHomeMemberRequestModel *)memberRequestModel
                                           success:(TYSuccessHandler)success
                                           failure:(TYFailureError)failure;


/// Get a list of optional rooms.
/// @param homeID homeID
/// @param memberID member id
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
 - (void)getAuthRoomListWithHomeId:(long long)homeID
                         memberID:(long long)memberID
                          success:(TYSuccessList)success
                          failure:(TYFailureError)failure;

/// Get a list of optional scenes or automations.
/// @param homeID homeID
/// @param memberID member id
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getAuthSceneListWithHomeID:(long long)homeID
                          memberID:(long long)memberID
                           success:(TYSuccessList)success
                           failure:(TYFailureError)failure;


/// Update the list of rooms to which custom roles have access.
/// @param homeID homeID
/// @param memberID member id
/// @param roomIDs List of room IDs with permission.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
 - (void)saveAuthRoomListWithHomeId:(long long)homeID
                          memberID:(long long)memberID
                           roomIDs:(NSArray <NSNumber *> *)roomIDs
                           success:(TYSuccessID)success
                           failure:(TYFailureError)failure;


/// Update the list of scenes to which custom roles have access.
/// @param homeID homeID
/// @param memberID member id
/// @param ruleIDs List of scene IDs with permissions.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)saveAuthSceneListWithHomeId:(long long)homeID
                           memberID:(long long)memberID
                            ruleIDs:(NSArray <NSString *> *)ruleIDs
                            success:(TYSuccessID)success
                            failure:(TYFailureError)failure;

@end
