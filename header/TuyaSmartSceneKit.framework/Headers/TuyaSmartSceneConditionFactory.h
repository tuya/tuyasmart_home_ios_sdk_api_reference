//
//  TuyaSmartSceneConditionFactory.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartSceneKit/TuyaSmartSceneKit.h>
#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>
#import "TuyaSmartSceneExprModel.h"

/// The type of geofencing. Valid values: reach, exit, and not set.
typedef enum : NSInteger{
    /// Reaches a geofence.
    kGeoFenceTypeReach,
    /// Exits a geofence.
    kGeoFenceTypeExit,
    /// The geofence is not set.
    kGeoFenceTypeNotSet
}GeoFenceType;

/// @brief A default design mode to create TuyaSmartSceneConditionModel.
///
/// @note To support multiple languages, this class does not process the actionDisplay and actionDisplayNew fields of TuyaSmartSceneConditionModel.
@interface TuyaSmartSceneConditionFactory : NSObject

/// Creates a device condition.
///
/// @param device The device model to create a condition.
/// @param dpModel The DP model to create a condition.
/// @param exprModel Creates a condition by using TYSmartSceneConditionExprBuilder.
///
/// @return The TuyaSmartSceneConditionModel object.
+ (TuyaSmartSceneConditionModel *)createDeviceConditionWithDevice:(TuyaSmartDeviceModel *)device dpModel:(TuyaSmartSceneDPModel *)dpModel exprModel:(TuyaSmartSceneExprModel *)exprModel;

/// Creates a timed type of motion detection condition, such as no movement for five minutes. Common motion detection conditions use -createDeviceConditionWithDevice:dpModel:exprModel:.
///
/// @param device The device model to create a condition.
/// @param dpModel The DP model to create a condition.
/// @param exprModel Creates a condition by using TYSmartSceneConditionExprBuilder.
///
/// @return The TuyaSmartSceneConditionModel object.
+ (TuyaSmartSceneConditionModel *)createPirConditionWithDevice:(TuyaSmartDeviceModel *)device dpModel:(TuyaSmartSceneDPModel *)dpModel exprModel:(TuyaSmartSceneExprModel *)exprModel;

/// Creates a weather condition.
///
/// @param city The city that is required in a weather condition.
/// @param dpModel The DP model to create a condition.
/// @param exprModel Creates a condition by using TYSmartSceneConditionExprBuilder.
///
/// @return The TuyaSmartSceneConditionModel object.
+ (TuyaSmartSceneConditionModel *)createWhetherConditionWithCity:(TuyaSmartCityModel *)city dpModel:(TuyaSmartSceneDPModel *)dpModel exprModel:(TuyaSmartSceneExprModel *)exprModel;

/// Creates a timer condition.
///
/// @param exprModel Creates a condition by using TYSmartSceneConditionExprBuilder.
///
/// @return The TuyaSmartSceneConditionModel object.
+ (TuyaSmartSceneConditionModel *)createTimerConditionWithExprModel:(TuyaSmartSceneExprModel *)exprModel;

/// Creates a timer condition related to the sunrise and sunset time.
///
/// @param city The city to be managed.
/// @param exprModel Creates a condition by using TYSmartSceneConditionExprBuilder.
///
/// @return The TuyaSmartSceneConditionModel object.
+ (TuyaSmartSceneConditionModel *)createSunsetriseTimerConditionWithCity:(TuyaSmartCityModel *)city ExprModel:(TuyaSmartSceneExprModel *)exprModel;

/// Creates a geofencing condition. The entity ID of the condition model is assigned after the scene is saved. The entity ID represents the geofence ID and is uploaded to the server in an HTTP API request to trigger the automation scene.
///
/// @param type The geofencing type to specify that a perimeter is reached or crossed.
/// @param latitude  The geofence center latitude.
/// @param longitude The geofence center longitude.
/// @param radius If the latitude and longitude of the geofence are regarded as the center of a circle, this property represents the radius.
/// @param geoTitle The name of the geofence.
///
/// @return The TuyaSmartSceneConditionModel object.
+ (TuyaSmartSceneConditionModel *)createGeoFenceConditionWithGeoType:(GeoFenceType)type geoLati:(CGFloat)latitude geoLonti:(CGFloat)longitude geoRadius:(CGFloat)radius geoTitle:(NSString *)geoTitle;

/// Creates a manual running condition. This condition is not saved to the cloud server. When you make an API request to save a smart condition, delete this manual running condition first.
///
/// @return The TuyaSmartSceneConditionModel object.
+ (TuyaSmartSceneConditionModel *)createManualExecuteCondition;

@end

