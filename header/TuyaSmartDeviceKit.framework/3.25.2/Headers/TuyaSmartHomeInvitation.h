//
// TuyaSmartHomeInvitation.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartHomeInvitation : NSObject

/// Invite new members by invitation code.
/// @param createRequestModel The request model.
/// @param success Called when the task finishes successfully. TuyaSmartHomeInvitationResultModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)createInvitationWithCreateRequestModel:(TuyaSmartHomeInvitationCreateRequestModel *)createRequestModel
                                       success:(void(^)(TuyaSmartHomeInvitationResultModel *invitationResultModel))success
                                       failure:(TYFailureError)failure;

/// Cancel invitation.
/// @param invitationID invitation ID
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)cancelInvitationWithInvitationID:(NSNumber *)invitationID
                                 success:(TYSuccessBOOL)success
                                 failure:(TYFailureError)failure;

/// Re-invite members.
/// @param reinviteRequestModel The re-invite request model.
/// @param success Called when the task finishes successfully. TuyaSmartHomeInvitationResultModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)reinviteInvitationWithReinviteRquestModel:(TuyaSmartHomeInvitationReinviteRequestModel *)reinviteRequestModel
                                          success:(void(^)(TuyaSmartHomeInvitationResultModel *invitationResultModel))success
                                          failure:(TYFailureError)failure;

/// Get invitation record list information.
/// @param homeID homeID
/// @param success Called when the task finishes successfully. A list of TuyaSmartHomeInvitationRecordModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)fetchInvitationRecordListWithHomeID:(long long)homeID
                                    success:(void(^)(NSArray<TuyaSmartHomeInvitationRecordModel *> *invitationRecordList))success
                                    failure:(TYFailureError)failure;

/// Update invitation information.
/// @param invitationInfoRequestModel The invitation info request model.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)updateInvitationInfoWithInvitationInfoRequestModel:(TuyaSmartHomeInvitationInfoRequestModel *)invitationInfoRequestModel
                                                   success:(TYSuccessBOOL)success
                                                   failure:(TYFailureError)failure;


/// Get family information of the invitee.
/// @param invitationCode The invitation code.
/// @param success Called when the task finishes successfully. TuyaSmartHomeModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)fetchInvitationHomeInfoWithInvitationCode:(NSString *)invitationCode
                                          success:(void(^)(TuyaSmartHomeModel *homeModel))success
                                          failure:(TYFailureError)failure;

/// Join the family.
/// @param invitationCode The invitation code.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)joinHomeWithInvitationCode:(NSString *)invitationCode
                           success:(TYSuccessBOOL)success
                           failure:(TYFailureError)failure;
@end

NS_ASSUME_NONNULL_END
