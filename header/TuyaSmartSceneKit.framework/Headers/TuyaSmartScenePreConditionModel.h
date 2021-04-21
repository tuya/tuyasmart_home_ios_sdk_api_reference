//
//  TuyaSmartScenePreConditionModel.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

/// @brief TuyaSmartScenePreConditionModel provides extra attributes to create pre-conditions for an automation scene.
@interface TuyaSmartScenePreConditionModel : NSObject<NSCoding>

/// The scene ID.
@property (nonatomic, copy) NSString *scenarioId;

/// The condition ID in the scene.
@property (nonatomic, copy) NSString *conditionId;

/// The precondition type for an automation scene.
@property (nonatomic, copy) NSString *condType;

/// The information about a precondition expression. The following fields are supported:
///
/// timeInterval: the interval of enumeration string type. Valid values: custom, daytime, night, and allDay. Example: "timeInterval": "allDay".
/// timeZoneId: the time zone ID of string type. Example: "timeZoneId": "Asia/Shanghai".
/// loops: the loop of string type. Each bit represents a day from Sunday to Saturday. A value of "1" means a valid day. Example: `1111111`.
/// start: the string type. If the `timeCheck` type is specified and `timeInterval` is set to `custom`, this property is useful. Example: "start": "20:30".
/// end: the string type. If the `timeCheck` type is specified and `timeInterval` is set to `custom`, this property is useful. Example: "end": "06:30".
/// cityId: the city ID of string type. Example: "cityId": "793409534348627968".
/// cityName: the city name of string type. Example: "cityName": "hangzhou".
@property (nonatomic, strong) NSDictionary *expr;

@end

