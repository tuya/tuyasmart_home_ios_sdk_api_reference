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


/// Removes a home member.
///
/// @param memberId    The member ID.
/// @param success     Called when the task is finished.
/// @param failure     If an error occurs while adding the task, this block is called.
- (void)removeHomeMemberWithMemberId:(long long)memberId
                             success:(TYSuccessHandler)success
                             failure:(TYFailureError)failure;



/// Updates the home member information.
///
/// @param memberRequestModel The request model. Set the required properties.
/// @param success            Called when the task is finished.
/// @param failure            If an error occurs while adding the task, this block is called.
- (void)updateHomeMemberInfoWithMemberRequestModel:(TuyaSmartHomeMemberRequestModel *)memberRequestModel
                                           success:(TYSuccessHandler)success
                                           failure:(TYFailureError)failure;


/// Returns a list of optional rooms.
/// @param homeID The home ID.
/// @param memberID The member ID.
/// @param success Called when the task is finished.
/// @param failure If an error occurs while adding the task, this block is called.
 - (void)getAuthRoomListWithHomeId:(long long)homeID
                         memberID:(long long)memberID
                          success:(TYSuccessList)success
                          failure:(TYFailureError)failure;

/// Returns a list of optional scenes or automations.
/// @param homeID The home ID.
/// @param memberID The member ID.
/// @param success Called when the task is finished.
/// @param failure If an error occurs while adding the task, this block is called.
- (void)getAuthSceneListWithHomeID:(long long)homeID
                          memberID:(long long)memberID
                           success:(TYSuccessList)success
                           failure:(TYFailureError)failure;


/// Updates the list of rooms to which custom roles have access.
/// @param homeID The home ID.
/// @param memberID The member ID.
/// @param roomIDs The list of room IDs with permissions.
/// @param success Called when the task is finished.
/// @param failure If an error occurs while adding the task, this block is called.
 - (void)saveAuthRoomListWithHomeId:(long long)homeID
                          memberID:(long long)memberID
                           roomIDs:(NSArray <NSNumber *> *)roomIDs
                           success:(TYSuccessID)success
                           failure:(TYFailureError)failure;


/// Updates the list of scenes to which custom roles have access.
/// @param homeID The home ID.
/// @param memberID The member ID.
/// @param ruleIDs The list of scene IDs with permissions.
/// @param success Called when the task is finished.
/// @param failure If an error occurs while adding the task, this block is called.
- (void)saveAuthSceneListWithHomeId:(long long)homeID
                           memberID:(long long)memberID
                            ruleIDs:(NSArray <NSString *> *)ruleIDs
                            success:(TYSuccessID)success
                            failure:(TYFailureError)failure;

@end
