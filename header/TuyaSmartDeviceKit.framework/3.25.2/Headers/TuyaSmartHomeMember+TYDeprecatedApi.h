//
// TuyaSmartHomeMember+TYDeprecatedApi.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartHomeMember.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartHomeMember (TYDeprecatedApi)


/// Add a home member
///
/// @param homeId      Home Id
/// @param countryCode Country code
/// @param account     User account
/// @param name        Note name
/// @param isAdmin     Whether the administrator
/// @param success     Success block
/// @param failure     Failure block
/// @deprecated This method is deprecated, Use TuyaSmartHome::addHomeMemberWithName:headPic:countryCode:userAccount:isAdmin:success:failure: instead.
- (void)addHomeMemberWithHomeId:(long long)homeId
                    countryCode:(NSString *)countryCode
                        account:(NSString *)account
                           name:(NSString *)name
                        isAdmin:(BOOL)isAdmin
                        success:(TYSuccessHandler)success
                        failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartHome -  addHomeMemberWithName:headPic:countryCode:userAccount:isAdmin:success:failure:] instead");


/// Update home member info
///
/// @param memberId    Member Id
/// @param name        Note name
/// @param isAdmin     Whether the administrator
/// @param success     Success block
/// @param failure     Failure block
/// @deprecated This method is deprecated, Use TuyaSmartHome::updateHomeMemberInfoWithMemberId:name:headPic:isAdmin:success:failure: instead.
- (void)updateHomeMemberNameWithMemberId:(long long)memberId
                                    name:(NSString *)name
                                 isAdmin:(BOOL)isAdmin
                                 success:(TYSuccessHandler)success
                                 failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartHomeMember - (void)updateHomeMemberInfoWithMemberId:name:headPic:isAdmin:success:failure:] instead");


/// Add family members.
/// @param groupId Home Group ID
/// @param name Family member's name
/// @param headPic Family member avatar
/// @param countryCode Country code.
/// @param account User account.
/// @param admin Whether is the administrator.
/// @param success Success block
/// @param failure Failure block
/// @deprecated This method is deprecated, Use TuyaSmartHome::addHomeMemberWithName:headPic:countryCode:userAccount:isAdmin:success:failure: instead.
- (void)addHomeMemberWithHomeId:(long long)groupId
                           name:(NSString *)name
                        headPic:(UIImage *)headPic
                    countryCode:(NSString *)countryCode
                    userAccount:(NSString *)account
                        isAdmin:(BOOL)admin
                        success:(TYSuccessDict)success
                        failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartHome -  addHomeMemberWithName:headPic:countryCode:userAccount:isAdmin:success:failure:] instead");



/// Get home member list
///
/// @param homeId      Home Id
/// @param success     Success block
/// @param failure     Failure block
/// @deprecated This method is deprecated, Use TuyaSmartHome::getHomeMemberListWithSuccess:failure: instead.
- (void)getHomeMemberListWithHomeId:(long long)homeId
                            success:(void(^)(NSArray <TuyaSmartHomeMemberModel *> *memberList))success
                            failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use -[TuyaSmartHome - (void)getHomeMemberListWithSuccess:failure:] instead");



/// Update home member info
///
/// @param memberId    Member Id
/// @param name        Note name
/// @param headPic     Portrait
/// @param isAdmin     Whether the administrator
/// @param success     Success block
/// @param failure     Failure block
/// @deprecated This method is deprecated, Use TuyaSmartHome::updateHomeMemberInfoWithMemberRequestModel:success:failure: instead.
- (void)updateHomeMemberInfoWithMemberId:(long long)memberId
                                    name:(NSString *)name
                                 headPic:(UIImage *)headPic
                                 isAdmin:(BOOL)isAdmin
                                 success:(TYSuccessHandler)success
                                 failure:(TYFailureError)failure  __deprecated_msg("This method will be deprecated and remove, Use [TuyaSmartHomeMember - (void)updateHomeMemberInfoWithMemberRequestModel:success:failure:]");


/// Update home member note name
///
/// @param memberId    Member Id
/// @param name        Note name
/// @param isAdmin     Whether the administrator
/// @param success     Success block
/// @param failure     Failure block
/// @deprecated This method is deprecated, Use TuyaSmartHome::updateHomeMemberInfoWithMemberRequestModel:success:failure: instead.
- (void)updateHomeMemberRemarkNameWithMemberId:(long long)memberId
                                          name:(NSString *)name
                                       isAdmin:(BOOL)isAdmin
                                       success:(TYSuccessHandler)success
                                       failure:(TYFailureError)failure __deprecated_msg("This method will be deprecated and remove, Use [TuyaSmartHomeMember - (void)updateHomeMemberInfoWithMemberRequestModel:success:failure:]");


/// Update home member portrait
///
/// @param memberId    Member Id
/// @param headPic     Portrait
/// @param isAdmin     Whether the administrator
/// @param success     Success block
/// @param failure     Failure block
/// @deprecated This method is deprecated, Use TuyaSmartHome::updateHomeMemberInfoWithMemberRequestModel:success:failure: instead.
- (void)updateHomeMemberHeadPicWithMemberId:(long long)memberId
                                    headPic:(UIImage *)headPic
                                    isAdmin:(BOOL)isAdmin
                                    success:(TYSuccessHandler)success
                                    failure:(TYFailureError)failure __deprecated_msg("This method will be deprecated and remove, Use [TuyaSmartHomeMember - (void)updateHomeMemberInfoWithMemberRequestModel:success:failure:]");


/// Update home member management authority
///
/// @param memberId    Member Id
/// @param isAdmin     Whether the administrator
/// @param success     Success block
/// @param failure     Failure block
/// @deprecated This method is deprecated, Use TuyaSmartHome::updateHomeMemberInfoWithMemberRequestModel:success:failure: instead.
- (void)updateHomeMemberAdminWithMemberId:(long long)memberId
                                  isAdmin:(BOOL)isAdmin
                                  success:(TYSuccessHandler)success
                                  failure:(TYFailureError)failure __deprecated_msg("This method will be deprecated and remove, Use [TuyaSmartHomeMember - (void)updateHomeMemberInfoWithMemberRequestModel:success:failure:]");

@end

NS_ASSUME_NONNULL_END
