//
// TuyaSmartSDK.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartSDK
#define TuyaSmart_TuyaSmartSDK

#import <TuyaSmartUtil/TuyaSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TYEnv) {
    TYEnvDaily,
    TYEnvPrepare,
    TYEnvRelease,
};

/// @brief TuyaSmartSDK is an entry to use the Tuya SDK.
///
/// Before you use the SDK, go to the Tuya IoT Platform (https://iot.tuya.com) to create an SDK app.
/// The following data from the platform is required to initialize the SDK:
///     - Tuya App Key.
///     - Tuya App Secret.
///     - Security image: renamed to `t_s.bmp` and put in your project as a resource.
///     - Bundle ID: your app's bundle ID.
///
/// To set parameters in this class, such as appGroupId, env, appVersion, and lang, set them before you initialize the SDK.
///
/// Then, call this method to initialize the SDK:
///     `[TuyaSmartSDK.sharedInstance startWithAppKey:@"YOUR_APP_KEY" secretKey:@"YOUR_APP_SECRET"];`.
///
@interface TuyaSmartSDK : NSObject

/// Returns the singleton of the class.
+ (instancetype)sharedInstance;

/// The app group identifier.
/// To use the SDK in the app extension, set `appGroupId` both in the app and app extension before the SDK is initialized.
@property (nonatomic, strong) NSString *appGroupId;

/// The latitude of the location.
@property (nonatomic, assign) double latitude;

/// The longitude of the location.
@property (nonatomic, assign) double longitude;

/// The server environment, such as the daily, prerelease, or release environment. Used for test only. Not recommended to switch.
@property (nonatomic, assign) TYEnv env;

/// Specifies whether the request requires SSL pinning. Default value: `YES`.
@property (nonatomic, assign) BOOL useSSLPinning;

/// The appKey in Tuya Smart.
@property (nonatomic, strong, readonly) NSString *appKey;

/// The secretKey in Tuya Smart.
@property (nonatomic, strong, readonly) NSString *secretKey;

/// The channel.
@property (nonatomic, strong) NSString *channel;

/// The UUID of the iOS and watchOS device. The value is created when the app is published for the first time.
@property (nonatomic, strong, readonly) NSString *uuid;

/// The app version. The value of CFBundleShortVersionString in Info.plist is used as the default value.
@property (nonatomic, strong) NSString *appVersion;

/// The device product name, such as the iPhone XS Max.
@property (nonatomic, strong) NSString *deviceProductName;

/// The app SDK language. The value [0] of preferredLocalizations in mainBundle is used as the default value.
@property (nonatomic, strong) NSString *lang;


/// Initializes the TuyaSmart SDK.
/// @param appKey The appKey in Tuya Smart.
/// @param secretKey TuyaSmart The secretKey in Tuya Smart.
- (void)startWithAppKey:(NSString *)appKey secretKey:(NSString *)secretKey;


/// Reports the location on demand.
/// @param latitude The latitude.
/// @param longitude The longitude.
- (void)updateLatitude:(double)latitude longitude:(double)longitude;

@end


@interface TuyaSmartSDK (Upgrade)


/// Checks whether TuyaSmartKit must be updated to TuyaSmartHomeKit.
/// @return Indicates whether to update data.
- (BOOL)checkVersionUpgrade;


/// The update of SDK data.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)upgradeVersion:(nullable TYSuccessHandler)success
               failure:(nullable TYFailureError)failure;

@end


@interface TuyaSmartSDK (PushNotification)

/// Pushes a token.
/// @deprecated Use +[TuyaSmartSDK sharedInstance].deviceToken instead.
@property (nonatomic, strong) NSString *pushToken DEPRECATED_MSG_ATTRIBUTE("Use +[TuyaSmartSDK sharedInstance].deviceToken instead.");

/// Pushes deviceToken.
@property (nonatomic, strong) NSData *deviceToken;


/// Sets the device token pushing and error information.
/// @param token The device token.
/// @param error An error occurs while processing the request.
- (void)setDeviceToken:(nullable NSData *)token withError:(nullable NSError *)error;


/// Indicates whether the app messages pushing function is enabled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getPushStatusWithSuccess:(__nullable TYSuccessBOOL)success failure:(__nullable TYFailureError)failure;


/// Enables or disables app message pushing.
/// @param enable A Boolean value indicates whether to enable or disable the function.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setPushStatusWithStatus:(BOOL)enable success:(__nullable TYSuccessHandler)success failure:(__nullable TYFailureError)failure;


/// Indicates whether device alert notifications are enabled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getDevicePushStatusWithSuccess:(__nullable TYSuccessBOOL)success failure:(__nullable TYFailureError)failure;


/// Enables or disables app device alert pushing messages.
/// @param enable Specifies whether to enable or disable the function.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setDevicePushStatusWithStauts:(BOOL)enable success:(__nullable TYSuccessHandler)success failure:(__nullable TYFailureError)failure;


/// Indicates whether app home notifications are enabled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getFamilyPushStatusWithSuccess:(__nullable TYSuccessBOOL)success failure:(__nullable TYFailureError)failure;


/// Enables or disables app home push messages.
/// @param enable Specifies whether to enable or disable the function.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setFamilyPushStatusWithStauts:(BOOL)enable success:(__nullable TYSuccessHandler)success failure:(__nullable TYFailureError)failure;


/// Indicates whether app message notifications are enabled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getNoticePushStatusWithSuccess:(__nullable TYSuccessBOOL)success failure:(__nullable TYFailureError)failure;


/// Enables or disables app message pushing.
/// @param enable Specifies whether to enable or disable the function.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setNoticePushStatusWithStauts:(BOOL)enable success:(__nullable TYSuccessHandler)success failure:(__nullable TYFailureError)failure;


/// Indicates whether app marketing messages are enabled.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getMarketingPushStatusWithSuccess:(__nullable TYSuccessBOOL)success failure:(__nullable TYFailureError)failure;


/// Enables or disables app marketing message pushing.
/// @param enable Specifies whether to enable or disable the function.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)setMarketingPushStatusWithStauts:(BOOL)enable success:(__nullable TYSuccessHandler)success failure:(__nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif
