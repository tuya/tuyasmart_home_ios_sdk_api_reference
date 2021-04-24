//
//  TuyaSmartSceneDPModel.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <CoreLocation/CoreLocation.h>

/// The type of data point (DP) display style. Valid values:
typedef enum : NSUInteger {
    /// The normal style: displays numeric UI data.
    SceneDisplayNormal = 1,
    /// The first percent style: The content shows numeric UI data and the unit shows a percent. The minimum DP value is `0`.
    SceneDisplayPercent = (1 << 1),
    /// The second percent style: The content shows numeric UI data and the unit shows a percent. The minimum DP value is `1`.
    SceneDisplayNewPercent = (1 << 2),
    /// The first countdown style: The content only shows the number of hours and minutes.
    SceneDisplayCountDown = (1 << 3),
    /// The brightness value style: The content shows a color slider. You can select a brightness value. For example, the brightness value can be set to `500`.
    SceneDisplayBrightness = (1 << 4),
    /// The warm and cool white value style: The content shows a color slider. You can select a warm and cool white value. For example, the warm and cool white value can be set to `500`.
    SceneDisplayTemp = (1 << 5),
    /// The second countdown style: The content shows the number of hours, minutes, and seconds.
    SceneDisplayCountDown1 = (1<< 6)
} SceneDisplayType;

@class TuyaSmartSchemaModel;

/// @brief TuyaSmartSceneDPModel provides extra attributes to implement a DP of a device.
///
/// @note Returns the details of the DP of the device.
@interface TuyaSmartSceneDPModel : NSObject

/// The DP ID. The value might be the condition ID or device ID.
@property (nonatomic, assign) NSInteger dpId;

/// The product ID. This property represents the ID of the product to which the DP belongs. Only the DPs of the device support this value.
@property (nonatomic, strong) NSString *entityId;

/// The entity name. It might be the condition name or DP name of the device.
@property (nonatomic, strong) NSString *entityName;

/// The entity type. This parameter is set to `1` for a device condition, `3` for a meteorological condition, `6` for a timer condition, `7` for a motion detection condition, and `10` for a geofencing condition.
@property (nonatomic, assign) NSInteger entityType;

/// The icon URL of the specified condition.
@property (nonatomic, strong) NSString *iconUrl;

/// The value range of a DP for the specified condition or device. Example: "value:{"unit":"","min":10,"max":1000,"scale":0,"step":1,"type":"value"}".
@property (nonatomic, strong) NSArray *valueRangeJson;

/// Properties of the device. Example: {"id":1,"desc":"","name":"Switch","property":{"type":"bool"},"attr":3,"code":"switch_on","type":"obj","mode":"rw"}.
@property (nonatomic, strong) NSString *actDetail;

/// The description of the DP and the specified value.
@property (nonatomic, strong) TuyaSmartSchemaModel *dpModel;

/// The description of operators, such as "["=="]".
@property (nonatomic, strong) NSString *operators;

/// The name, code, and properties of the specified condition. For more information, see the dpModel property.
@property (nonatomic, strong) NSDictionary *property;

/// The entity sub-identifier of the specified condition or DP of the device. For example, the sub-identifier can be set to @"humidity" for the condition or to "1" for the device DP.
@property (nonatomic, strong) NSString *entitySubId;

/// The multi-control information. A value of nil is returned if the entity does not belong to an multi-control group. Format: [{"id":123,"groupName":"more control group 1"}].
@property (nonatomic, strong) NSArray *mcGroups;

/// Extra information about the DP value, such as the calculation type. The range of `calType` is ["sum","average","max","min","count","duration"].
@property (nonatomic, strong) NSDictionary *condCalExtraInfo;


#pragma mark - Logic properties blow can be ignored.
/*******The following properties are used to store specified values that you can ignore.********/

/// The specified row, `-1` means that no row is specified.
@property (nonatomic, assign) NSInteger selectedRow;

/// The specified operator. `-1` means that no operator is specified.
@property (nonatomic, assign) NSInteger selectedOperationRow;

/// The specified device ID.
@property (nonatomic, strong) NSString *devId;

/// The display type of the DP value.
@property (nonatomic, assign) SceneDisplayType displayType;

#pragma mark - Deprecated

/// The expression. Example: (("$humidity","==","comfort"), ("$dp1","==","1"), ...).
@property (nonatomic, strong) NSArray *expr __deprecated;

/// The specified city ID.
@property (nonatomic, strong) NSString *cityId __deprecated;

/// The specified city name.
@property (nonatomic, strong) NSString *cityName __deprecated;

/// The specified city latitude.
@property (nonatomic, assign) CLLocationDegrees cityLatitude __deprecated;

/// The specified city longitude.
@property (nonatomic, assign) CLLocationDegrees cityLongitude __deprecated;

/// The deprecated property.
@property (nonatomic, assign) NSInteger sceneDPId __deprecated;

/// The percent DP information.
@property (nonatomic, strong) NSDictionary *percentDp __deprecated;

@end
