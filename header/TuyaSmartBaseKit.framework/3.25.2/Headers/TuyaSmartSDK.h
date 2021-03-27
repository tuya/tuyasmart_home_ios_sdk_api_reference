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

/// @brief TuyaSmartSDK is a entry for using the Tuya SDK.
///
/// Before using the SDK, please go to Tuya IoT Platform (https://iot.tuya.com) create a SDK App.
/// We need 4 things from the Platform to initialize the SDK:
///     - Tuya App Key.
///     - Tuya App Secret.
///     - Security Image. Rename to `t_s.bmp` and put it in your project as a resource.
///     - Bundle ID. Must equal to your App's bundle ID.
///
/// If you need to set some params (appGroupId, env, appVersion, lang, etc...) in this class, be sure to set them before initialize the SDK.
///
/// Finally, call this method to initialize the SDK:
///     `[TuyaSmartSDK.sharedInstance startWithAppKey:@"YOUR_APP_KEY" secretKey:@"YOUR_APP_SECRET"];`.
///
@interface TuyaSmartSDK : NSObject

/// Returns the singleton of the class.
+ (instancetype)sharedInstance;

/// Application group identifier.
/// If you want to use the SDK in app extension, set `appGroupId` before SDK initialized both in app & app extension.
@property (nonatomic, strong) NSString *appGroupId;

/// Latitude of the location.
@property (nonatomic, assign) double latitude;

/// Longitude of the location.
@property (nonatomic, assign) double longitude;

/// Server environment, daily/prepare/release. For test only. Not recommended to switch.
@property (nonatomic, assign) TYEnv env;

/// Request need SSL Pinning, default is `YES`.
@property (nonatomic, assign) BOOL useSSLPinning;

/// TuyaSmart AppKey.
@property (nonatomic, strong, readonly) NSString *appKey;

/// TuyaSmart SecretKey.
@property (nonatomic, strong, readonly) NSString *secretKey;

/// Channel.
@property (nonatomic, strong) NSString *channel;

/// UUID of the iOS/watchOS device. Will be created at app first launch.
@property (nonatomic, strong, readonly) NSString *uuid;

/// App version, default value is from Info.plist -> CFBundleShortVersionString.
@property (nonatomic, strong) NSString *appVersion;

/// Device product name. For example: iPhone XS Max.
@property (nonatomic, strong) NSString *deviceProductName;

/// App SDK lang, default value is from mainBundle -> preferredLocalizations -> [0].
@property (nonatomic, strong) NSString *lang;


/// Initialize TuyaSmart SDK.
/// @param appKey TuyaSmart AppKey.
/// @param secretKey TuyaSmart SecretKey.
- (void)startWithAppKey:(NSString *)appKey secretKey:(NSString *)secretKey;


/// Report location if needed.
/// @param latitude Latitude.
/// @param longitude Longitude.
- (void)updateLatitude:(double)latitude longitude:(double)longitude;

@end


@interface TuyaSmartSDK (Upgrade)


/// Check if TuyaSmartKit need to be upgrade to TuyaSmartHomeKit.
/// @return Whether need to upgrade data.
- (BOOL)checkVersionUpgrade;


/// SDK data upgrade.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)upgradeVersion:(nullable TYSuccessHandler)success
               failure:(nullable TYFailureError)failure;

@end


@interface TuyaSmartSDK (PushNotification)

/// Push token.
/// @deprecated Use +[TuyaSmartSDK sharedInstance].deviceToken instead.
@property (nonatomic, strong) NSString *pushToken DEPRECATED_MSG_ATTRIBUTE("Use +[TuyaSmartSDK sharedInstance].deviceToken instead.");

/// Push deviceToken.
@property (nonatomic, strong) NSData *deviceToken;


/// Set push device token and error info.
/// @param token DeviceToken.
/// @param error Error info.
- (void)setDeviceToken:(nullable NSData *)token withError:(nullable NSError *)error;


/// Get the open status of APP messages push.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getPushStatusWithSuccess:(__nullable TYSuccessBOOL)success failure:(__nullable TYFailureError)failure;


/// Enable or disable APP message pushing.
/// @param enable A boolean value indicates whether to enable or disable.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)setPushStatusWithStatus:(BOOL)enable success:(__nullable TYSuccessHandler)success failure:(__nullable TYFailureError)failure;


/// Obtain the on status of device alarm notification.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getDevicePushStatusWithSuccess:(__nullable TYSuccessBOOL)success failure:(__nullable TYFailureError)failure;


/// Enable or disable APP device alert push messages.
/// @param enable  Open or close.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)setDevicePushStatusWithStauts:(BOOL)enable success:(__nullable TYSuccessHandler)success failure:(__nullable TYFailureError)failure;


/// Get the open status of APP family notifications.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getFamilyPushStatusWithSuccess:(__nullable TYSuccessBOOL)success failure:(__nullable TYFailureError)failure;


/// Enable or disable APP family push messages.
/// @param enable Open or close.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)setFamilyPushStatusWithStauts:(BOOL)enable success:(__nullable TYSuccessHandler)success failure:(__nullable TYFailureError)failure;


/// Get the open status of app message notifications.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getNoticePushStatusWithSuccess:(__nullable TYSuccessBOOL)success failure:(__nullable TYFailureError)failure;


/// Enable or disable APP message notification push.
/// @param enable Open or close.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)setNoticePushStatusWithStauts:(BOOL)enable success:(__nullable TYSuccessHandler)success failure:(__nullable TYFailureError)failure;


/// Get the open status of APP marketing messages.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getMarketingPushStatusWithSuccess:(__nullable TYSuccessBOOL)success failure:(__nullable TYFailureError)failure;


/// Turn on or off APP marketing message pushing.
/// @param enable Open or close.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)setMarketingPushStatusWithStauts:(BOOL)enable success:(__nullable TYSuccessHandler)success failure:(__nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif
