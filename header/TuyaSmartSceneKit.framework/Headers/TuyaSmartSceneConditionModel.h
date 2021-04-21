//
//  TuyaSmartSceneConditionModel.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartSceneDPModel.h"

#import <CoreLocation/CoreLocation.h>

/// The expression type in a scene condition. Valid values: precise and simple.
typedef NS_ENUM(NSInteger, TYSConditionExpressionType) {
    /// The precise expression type, including specific equations. Example: $dp110 == 1, $dp111 > 1000, and $dp113 < 400.
    TYSConditionExpressionTypePrecise = 1,
    /// The simple expression type, excluding equations. Example: $dp112.
    TYSConditionExpressionTypeSimple
};

/// The status of a scene condition. Valid values: loading, success, offline, and timeout.
typedef NS_ENUM(NSInteger, TYSceneConditionStatus) {
    /// The loading scene condition status.
    TYSceneConditionStatusLoading = 0,
    /// The success scene condition status.
    TYSceneConditionStatusSuccess,
    /// The offline scene condition status.
    TYSceneConditionStatusOffline,
    /// The timeout scene condition status.
    TYSceneConditionStatusTimeout,
};

/// The automatic condition type.
typedef NS_ENUM(NSInteger, TYConditionAutoType) {
    /// The automatic device type.
    AutoTypeDevice = 1,
    /// The automatic weather type.
    AutoTypeWhether = 3,
    /// The automatic timer type.
    AutoTypeTimer = 6,
    /// The automatic passive infrared sensor (PIR sensor) type.
    AutoTypePir = 7,
    /// The automatic face recognition type.
    AutoTypeFaceRecognition = 9,
    /// The automatic geofencing type.
    AutoTypeGeofence = 10,
    /// The automatic type for lock members going home.
    AutoTypeLockMemberGoHome = 11,
    /// The automatic condition calculation type. For example, a DP running duration can be set to `x` hours.
    AutoTypeConditionCalculate = 13,
    /// The automatic sunset or sunrise timer type. For example, `x` minutes before sunrise can be specified.
    AutoTypeSunsetriseTimer = 16,
    /// The manual condition type. This type is not saved to the server and the server does not return this type of condition.
    AutoTypeManual = 99,
};

/// @brief The condition data model for a scene.
@interface TuyaSmartSceneConditionModel : NSObject<NSCoding>

/// The condition ID.
@property (nonatomic, copy) NSString *conditionId;

/// The URL of the condition icon.
@property (nonatomic, copy) NSString *iconUrl;

/// The city ID. This parameter is set to the city ID for a meteorological condition, the value of `devId` for a device condition, and the value of @"timer" for a timer condition.
@property (nonatomic, copy) NSString *entityId;

/// The city name. This parameter is set to a city name for a meteorological condition, a device name for a device condition, and the value of @"timer" for a timer condition.
@property (nonatomic, copy) NSString *entityName;

/// The entity type. This parameter is set to `1` for a device condition, `3` for a meteorological condition, `6` for a timer condition, `7` for a motion detection condition, and `10` for a geofencing condition.
@property (nonatomic, assign) TYConditionAutoType entityType;

/// The description of the condition. Example: "Switch : Open" and "Humidity : Comfort".
@property (nonatomic, copy) NSString *exprDisplay;

/// The ID of the scene to which the specified action belongs.
@property (nonatomic, copy) NSString *scenarioId;

/// A sub-device ID or a DP ID of the device for a meteorological condition, or the timer for a timer condition.
@property (nonatomic, copy) NSString *entitySubIds;

/// The expression of a condition. Example: 
/// ("$humidity","==","comfort") or ("$dp1","==",1).
/// timer: {timeZoneId = "Asia/Shanghai",loops = "0000000",time = "08:00",date = "20180308"}
/// loops = "0000000". Each bit represents a day from Sunday to Saturday.
/// Documentation: https://tuyainc.github.io/tuyasmart_home_ios_sdk_doc/en/resource/SmartScene.html#smart-scene.
@property (nonatomic, strong) NSArray *expr;

/// The condition status. For more information, see the enumeration values of TYSceneConditionStatus.
@property (nonatomic, assign) TYSceneConditionStatus status;

/// The unit of temperature, or the details of the geofence. Example: {"tempUnit":"fahrenheit","Hangzhou City":"cityName"} and {"center":{"latitude":30.273173191721956,"longitude":120.09600875035049},"geotitle":"xxx","radius":180.00011311593616}}.
@property (nonatomic, strong) NSDictionary *extraInfo;

/// If this condition is a device condition and this device has been removed from the current account, this flag is set to `YES`.
@property (nonatomic, assign) BOOL devDelMark;

/// If this condition is a device condition and this device has been removed from the current account, the URL of the device icon is specified to display the device icon.
@property (nonatomic, copy) NSString *deleteDevIcon;

/// The name of the city.
@property (nonatomic, copy) NSString *cityName;

/// The latitude of the city.
@property (nonatomic, assign) CLLocationDegrees cityLatitude;

/// The longitude of the city.
@property (nonatomic, assign) CLLocationDegrees cityLongitude;

#pragma mark - Recommend info

/// The ID of the recommended product.
@property (nonatomic, copy) NSString *productId;

/// The icon of the recommended product.
@property (nonatomic, copy) NSString *productPic;

/// The local default icon of the recommended product.
@property (nonatomic, copy) NSString *defaultIconUrl;

#pragma mark - Expression Type

/// The expression type for a condition. For more information, see TYSConditionExpressionType.
///
/// For example, ("$humidity","==","comfort") indicates the precise matching mode, including specific equations such as (==, >, <). All DP types are supported in the condition, such as the enumeration, numeric, and Boolean types. For the enumeration, numeric, or Boolean type of DP, you can use TYSConditionExpressionTypePrecise.
/// For example, ("$dp1") indicates the simple matching mode, excluding an equation. Only the DP descriptions of string or raw type can be used in the condition. When the string or raw type of DP is used, you can use TYSConditionExpressionTypeSimple.
@property (nonatomic, assign) TYSConditionExpressionType conditionExpressionType;

@end
