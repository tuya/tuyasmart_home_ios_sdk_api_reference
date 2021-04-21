//
//  TuyaSmartScenePreConditionFactory.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>
#import <TuyaSmartSceneKit/TuyaSmartSceneKit.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief TuyaSmartScenePreConditionFactory provides convenient construction methods to generate a precondition object.
@interface TuyaSmartScenePreConditionFactory : NSObject

/// Creates an all-day validity precondition.
///
/// @param sceneId The scene ID. A value of nil is returned when an automation scene is created.
/// @param conditionId The current condition ID. You must pass the original condition ID when you edit an automation scene.
/// @param loops The description of a loop in the format of `1111111`. Each bit specifies a day from Sunday to Saturday. A value of `1` means a valid day and a value of `0` means an invalid day.
/// @param timeZoneId The ID of the time zone. Example: "Asia/Shanghai".
///
/// @return The TuyaSmartScenePreConditionModel instance.
+ (TuyaSmartScenePreConditionModel *)creatAllDayPreConditionWithSceneId:(NSString *__nullable)sceneId
                                                       existConditionId:(NSString * __nullable)conditionId
                                                                  loops:(NSString *)loops
                                                             timeZoneId:(NSString *)timeZoneId;

/// Creates a daytime validity precondition.
/// 
/// @param sceneId The scene ID. Set the value to nil to create an automation scene.
/// @param conditionId The current condition ID. You must pass the original condition ID when an automation scene is edited.
/// @param loops The description of a loop in the format of `1111111`. Each bit specifies a day from Sunday to Saturday. A value of `1` means a valid day and a value of `0` means an invalid day.
/// @param cityId The ID of the current city.
/// @param cityName The name of the current city.
/// @param timeZoneId The ID of the time zone. Example: "Asia/Shanghai".
///
/// @return The TuyaSmartScenePreConditionModel instance.
+ (TuyaSmartScenePreConditionModel *)createDayTimePreConditionWithSceneId:(NSString *__nullable)sceneId
                                                         existConditionId:(NSString * __nullable)conditionId
                                                                    loops:(NSString *)loops
                                                                   cityId:(NSString *)cityId
                                                                 cityName:(NSString *)cityName
                                                               timeZoneId:(NSString *)timeZoneId;

/// Creates a night validity precondition.
///
/// @param sceneId The scene ID. Set the value to nil to create an automation scene.
/// @param conditionId The current condition ID. You must pass the original condition ID when an automation scene is edited.
/// @param loops The description of a loop in the format of `1111111`. Each bit specifies a day from Sunday to Saturday. A value of `1` means a valid day and a value of `0` means an invalid day.
/// @param cityId The ID of the current city.
/// @param cityName The name of the current city.
/// @param timeZoneId The ID of the time zone. Example: "Asia/Shanghai".
///
/// @return The TuyaSmartScenePreConditionModel instance.
+ (TuyaSmartScenePreConditionModel *)createNightTimePreConditionWithSceneId:(NSString *__nullable)sceneId
                                                           existConditionId:(NSString * __nullable)conditionId
                                                                      loops:(NSString *)loops
                                                                     cityId:(NSString *)cityId
                                                                   cityName:(NSString *)cityName
                                                                 timeZoneId:(NSString *)timeZoneId;

/// Creates a validity precondition for a custom period.
///
/// @param sceneId The scene ID. Set the value to nil to create an automation scene.
/// @param conditionId The current condition ID. You must pass the original condition ID when an automation scene is edited.
/// @param loops The description of a loop in the format of `1111111`. Each bit specifies a day from Sunday to Saturday. A value of `1` means a valid day and a value of `0` means an invalid day.
/// @param cityId The ID of the current city.
/// @param cityName The name of the current city.
/// @param timeZoneId The ID of the time zone. Example: "Asia/Shanghai".
/// @param begin The start time. Example: "00:59".
/// @param end The end time. Example: "18:30".
///
/// @return The TuyaSmartScenePreConditionModel instance.
+ (TuyaSmartScenePreConditionModel *)createCustomTimePreConditionWithSceneId:(NSString *__nullable)sceneId
                                                            existConditionId:(NSString * __nullable)conditionId
                                                                       loops:(NSString *)loops
                                                                      cityId:(NSString *)cityId
                                                                    cityName:(NSString *)cityName
                                                                  timeZoneId:(NSString *)timeZoneId
                                                                   beginTime:(NSString *)begin
                                                                     endTime:(NSString *)end;

@end

NS_ASSUME_NONNULL_END

