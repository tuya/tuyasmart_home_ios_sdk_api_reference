//
// TuyaSmartUser.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartUser
#define TuyaSmart_TuyaSmartUser

#import <UIKit/UIKit.h>
#import <TuyaSmartUtil/TuyaSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

/// Notification will be sent when user session is invalid.
extern NSString *const TuyaSmartUserNotificationUserSessionInvalid;

/// User register type.
typedef NS_ENUM(NSInteger, TYRegType) {
    /// Register from email.
    TYRegEmailType,
    /// Register from mobile phone.
    TYRegPhoneType,
    /// Register from other.
    TYRegOtherType,
    /// Register from QQ.
    TYRegQQType,
    /// Register from Weibo.
    TYRegWeiboType,
    /// Register from Facebook.
    TYRegFacebookType,
    /// Register from Twitter.
    TYRegTwitterType,
    /// Register from WeChat.
    TYRegWechatType,
    /// Register from Apple.
    TYRegAppleIdType,
    /// Register from google.
    TYRegGoogleType,
    /// Register from Line.
    TYRegLineType,
};

/// Password strength type
/// 密码强度类型
typedef NS_ENUM(NSInteger, TYPasswordRegularType) {
    TYPasswordRegularLow = 1,       // 8-20 character,include letters and numbers
    TYPasswordRegularMiddle = 2,       // 8-20 character,include capital and lower-case letter and numbers
    TYPasswordRegularHigh = 3,     // 8-20 character,include capital and lower-case letter and numbers and special character
};

/// User-related functions.
@interface TuyaSmartUser : NSObject

/// Returns the singleton of the class.
+ (instancetype)sharedInstance;

/// Session ID.
@property (nonatomic, strong, readonly) NSString *sid;

/// User ID.
@property (nonatomic, strong, readonly) NSString *uid;

/// Head icon.
@property (nonatomic, strong, readonly) NSString *headIconUrl;

/// Nick name.
@property (nonatomic, strong, readonly) NSString *nickname;

/// Username. If account is mobile phone, this is mobile phone. If account is email, this is email.
@property (nonatomic, strong, readonly) NSString *userName;

/// Mobile phone.
@property (nonatomic, strong, readonly) NSString *phoneNumber;

/// Email.
@property (nonatomic, strong, readonly) NSString *email;

/// Country code. `86` for China, `1` for America.
@property (nonatomic, strong, readonly) NSString *countryCode;

/// Login status.
@property (nonatomic, assign, readonly) BOOL isLogin;

/// The region code of current account. `AY` for China, `AZ` for America, `EU` for Europe.
@property (nonatomic, strong, readonly) NSString *regionCode;

/// The api domains of current account region.
@property (nonatomic, strong, readonly) NSDictionary *domain;

/// Timezone ID. e.g. `Asia/Shanghai`.
@property (nonatomic, strong, readonly) NSString *timezoneId;

@property (nonatomic, strong, readonly) NSString *partnerIdentity;

/// MQTT host.
@property (nonatomic, strong, readonly) NSString *mbHost;

@property (nonatomic, strong, readonly) NSString *gwHost;

/// MQTT port.
@property (nonatomic, assign, readonly) NSInteger port;

/// Whether to enable SSL.
@property (nonatomic, assign, readonly) BOOL useSSL;

/// QUIC host.
@property (nonatomic, strong, readonly) NSString *quicHost;

/// QUIC port.
@property (nonatomic, assign, readonly) NSInteger quicPort;

/// Whether to enable QUIC.
@property (nonatomic, assign, readonly) BOOL useQUIC;

/// Temperature unit. 1 for `°C`, 2 for `°F`.
@property (nonatomic, assign) NSInteger tempUnit;

/// User register type.
@property (nonatomic, assign, readonly) TYRegType regFrom;

/// Nickname of SNS account.
@property (nonatomic, strong, readonly) NSString *snsNickname;

@property (nonatomic, strong, readonly) NSString *ecode;

/// User type.
@property (nonatomic, assign, readonly) NSInteger userType;

/// Extra parameters.
@property (nonatomic, strong, readonly) NSDictionary *extras;


#pragma mark - Mobile phone verification code login

/// Send verification code, used for register/login/reset password.
/// @param userName Mobile phone number or Email address.
/// @param region For register is required, use [TuyaSmartUser regionListWithCountryCode:success:failure:] or [TuyaSmartUser getDefaultRegionWithCountryCode:] to get region.
/// @param countryCode Country code.
/// @param type 1: Mobile phone verification code register,2: Mobile phone verification code login,3: Mobile phone password reset. 5: Improve account information (in experience mode); 7: Account change; 8: Cancel account
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendVerifyCodeWithUserName:(NSString *)userName
                            region:(NSString *_Nullable)region
                       countryCode:(NSString *)countryCode
                              type:(NSInteger)type
                           success:(TYSuccessHandler)success
                           failure:(TYFailureError)failure;


/// Mobile phone verification code login.
/// @param mobile Mobile phone number.
/// @param countryCode Country code.
/// @param code Verification code.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginWithMobile:(NSString *)mobile
            countryCode:(NSString *)countryCode
                   code:(NSString *)code
                success:(TYSuccessHandler)success
                failure:(TYFailureError)failure;


#pragma mark - Mobile phone binding

/// Send verification code. Used for mobile phone bind, mobile phone change.
/// @param countryCode Country code.
/// @param phoneNumber Mobile phone number.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendBindVerifyCode:(NSString *)countryCode
               phoneNumber:(NSString *)phoneNumber
                   success:(nullable TYSuccessHandler)success
                   failure:(nullable TYFailureError)failure;


/// Send verification code. Used for mobile phone bind for more service.
/// @param countryCode Country code.
/// @param phoneNumber Mobile phone number.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendBindVasVerifyCode:(NSString *)countryCode
                  phoneNumber:(NSString *)phoneNumber
                      success:(nullable TYSuccessHandler)success
                      failure:(nullable TYFailureError)failure;

/// Mobile phone bind.
/// @param countryCode Country code.
/// @param phoneNumber Mobile phone number.
/// @param code Verification code.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)mobileBinding:(NSString *)countryCode
          phoneNumber:(NSString *)phoneNumber
                 code:(NSString *)code
              success:(nullable TYSuccessHandler)success
              failure:(nullable TYFailureError)failure;

#pragma mark - Mobile phone password login

/// Mobile phone register.
/// @param countryCode Country code.
/// @param phoneNumber Mobile phone number.
/// @param password Password.
/// @param code Verification code.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)registerByPhone:(NSString *)countryCode
            phoneNumber:(NSString *)phoneNumber
               password:(NSString *)password
                   code:(NSString *)code
                success:(nullable TYSuccessHandler)success
                failure:(nullable TYFailureError)failure;

/// Mobile phone password login.
/// @param countryCode Country code.
/// @param phoneNumber Mobile phone number.
/// @param password Password.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByPhone:(NSString *)countryCode
         phoneNumber:(NSString *)phoneNumber
            password:(NSString *)password
             success:(nullable TYSuccessHandler)success
             failure:(nullable TYFailureError)failure;

/// Mobile phone password reset.
/// @param countryCode  Country code.
/// @param phoneNumber Mobile phone number.
/// @param newPassword New password.
/// @param code Verification code.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)resetPasswordByPhone:(NSString *)countryCode
                 phoneNumber:(NSString *)phoneNumber
                 newPassword:(NSString *)newPassword
                        code:(NSString *)code
                     success:(nullable TYSuccessHandler)success
                     failure:(nullable TYFailureError)failure;

#pragma mark - Email login

/// Email login.
/// @param countryCode Country code.
/// @param email Email.
/// @param password Password.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByEmail:(NSString *)countryCode
               email:(NSString *)email
            password:(NSString *)password
             success:(nullable TYSuccessHandler)success
             failure:(nullable TYFailureError)failure;


/// Email password reset.
/// @param countryCode Country code.
/// @param email Email.
/// @param newPassword New password.
/// @param code Verification code.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)resetPasswordByEmail:(NSString *)countryCode
                       email:(NSString *)email
                 newPassword:(NSString *)newPassword
                        code:(NSString *)code
                     success:(nullable TYSuccessHandler)success
                     failure:(nullable TYFailureError)failure;


#pragma mark - Email register 2.0

/// Email register 2.0.
/// @param countryCode Country code.
/// @param email Email.
/// @param password Password.
/// @param code Verification code.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)registerByEmail:(NSString *)countryCode
                  email:(NSString *)email
               password:(NSString *)password
                   code:(NSString *)code
                success:(nullable TYSuccessHandler)success
                failure:(nullable TYFailureError)failure;

#pragma mark - Email verification code login

/// Email verification code login.
/// @param email Email.
/// @param countryCode Country code.
/// @param code Verification code.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginWithEmail:(NSString *)email countryCode:(NSString *)countryCode code:(NSString *)code success:(TYSuccessHandler)success failure:(TYFailureError)failure;

#pragma mark - Email bind

/// Get email binding verification code.
/// @param email E-mail.
/// @param countryCode Country Code.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendBindingVerificationCodeWithEmail:(NSString *)email
                                 countryCode:(NSString *)countryCode
                                     success:(nullable TYSuccessHandler)success
                                     failure:(nullable TYFailureError)failure;

/// Binding email.
/// @param email E-mail.
/// @param countryCode Country Code.
/// @param code Verification Code.
/// @param sId User session ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)bindEmail:(NSString *)email
  withCountryCode:(NSString *)countryCode
             code:(NSString *)code
              sId:(NSString *)sId
          success:(nullable TYSuccessHandler)success
          failure:(nullable TYFailureError)failure;

#pragma mark - uid login

/// User ID. login/register. The account will be registered at first login.
/// @param countryCode Country code.
/// @param uid User ID.
/// @param password Password.
/// @param createHome Create default home.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginOrRegisterWithCountryCode:(NSString *)countryCode
                                   uid:(NSString *)uid
                              password:(NSString *)password
                            createHome:(BOOL)createHome
                               success:(nullable TYSuccessID)success
                               failure:(nullable TYFailureError)failure;

#pragma mark - Social login

/// QQ login.
/// @param countryCode Country code.
/// @param userId UserId from QQ authorization login.
/// @param accessToken AccessToken from QQ authorization login.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByQQ:(NSString *)countryCode
           userId:(NSString *)userId
      accessToken:(NSString *)accessToken
          success:(nullable TYSuccessHandler)success
          failure:(nullable TYFailureError)failure;

/// WeChat login.
/// @param countryCode Country code.
/// @param code Code from WeChat authorization login.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByWechat:(NSString *)countryCode
                 code:(NSString *)code
              success:(nullable TYSuccessHandler)success
              failure:(nullable TYFailureError)failure;

/// Facebook Login.
/// @param countryCode Country code.
/// @param token Token from Facebook authorization login
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByFacebook:(NSString *)countryCode
                  token:(NSString *)token
                success:(nullable TYSuccessHandler)success
                failure:(nullable TYFailureError)failure;

/// Twitter login.
/// @param countryCode Country code.
/// @param key Key from Twitter authorization login.
/// @param secret Secret from Twitter authorization login.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByTwitter:(NSString *)countryCode
                   key:(NSString *)key
                secret:(NSString *)secret
               success:(nullable TYSuccessHandler)success
               failure:(nullable TYFailureError)failure;

/// Third login.
/// @param type Login type(ap for "login with apple").
/// @param countryCode Country code.
/// @param accessToken  Token from third authorization login.
/// @param extraInfo Extra params.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByAuth2WithType:(NSString *)type
                 countryCode:(NSString *)countryCode
                 accessToken:(NSString *)accessToken
                   extraInfo:(NSDictionary *)extraInfo
                     success:(nullable TYSuccessHandler)success
                     failure:(nullable TYFailureError)failure;

#pragma mark -

/// Logout.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)loginOut:(nullable TYSuccessHandler)success
         failure:(nullable TYFailureError)failure;

/// Edit nick name.
/// @param nickName Nick name.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateNickname:(NSString *)nickName
               success:(nullable TYSuccessHandler)success
               failure:(nullable TYFailureError)failure;

/// Edit head icon.
/// @param headIcon Head icon.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateHeadIcon:(UIImage *)headIcon
               success:(nullable TYSuccessHandler)success
               failure:(nullable TYFailureError)failure;

/// Update user information.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateUserInfo:(nullable TYSuccessHandler)success
               failure:(nullable TYFailureError)failure;

/// Edit user timezone information.
/// @param timeZoneId TimeZone ID. e.g. `Asia/Shanghai`.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateTimeZoneWithTimeZoneId:(NSString *)timeZoneId
                             success:(nullable TYSuccessHandler)success
                             failure:(nullable TYFailureError)failure;

/// Edit user temperature unit.
/// @param tempUnit Temperature unit. 1 for `°C`, 2 for `°F`.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)updateTempUnitWithTempUnit:(NSInteger)tempUnit
                           success:(nullable TYSuccessHandler)success
                           failure:(nullable TYFailureError)failure;

/// Destroy account. One week after, all of the account information will be removed from server forever. If you login before removed, the destroy request will be canceled.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)cancelAccount:(nullable TYSuccessHandler)success
              failure:(nullable TYFailureError)failure;


/**
 * Check password format by password regular type
 * 根据密码强度类型检验密码格式是否符合
 * @param password  Inputed password
 * @param regularType Password regular type
 * @return Result of check password format
 */
- (BOOL)checkPasswordFormat:(NSString *)password withPasswordRegularType:(TYPasswordRegularType)regularType;



#pragma mark -

/// Cancel network request.
- (void)cancelRequest;

@end

#endif

NS_ASSUME_NONNULL_END
