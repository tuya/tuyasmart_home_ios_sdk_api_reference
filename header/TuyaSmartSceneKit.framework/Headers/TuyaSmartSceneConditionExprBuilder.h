//
//  TuyaSmartSceneConditionExprBuilder.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartSceneExprModel.h"

/// The type of expression data model. Valid values: weather and device.
typedef enum : NSInteger {
    /// The weather expression model type.
    kExprTypeWhether,
    /// The device expression model type.
    kExprTypeDevice
}ExprType;

/// The type of expression data model. Valid values: unknown, sunrise, and sunset.
typedef enum : NSInteger {
    /// An unknown type.
    kSunTypeNotDetermin,
    /// The sunrise type.
    kSunTypeRise,
    /// The sunset type.
    kSunTypeSet
}SunType;

NS_ASSUME_NONNULL_BEGIN

/// @brief Creates TuyaSmartSceneExprModel by using different type values.
@interface TuyaSmartSceneConditionExprBuilder : NSObject

/// Creates the Boolean value and condition type for an expression model.
///
/// @param type The weather type or the DP ID of a device.
/// @param isTrue The Boolean value.
/// @param exprType The entity type.
/// 
/// @return The TuyaSmartSceneExprModel object.
+ (TuyaSmartSceneExprModel *)createBoolExprWithType:(NSString *)type isTrue:(BOOL)isTrue exprType:(ExprType)exprType;

/// Creates an expression model by using enumeration string value and condition type.
///
/// @param type The weather type or the DP ID of a device.
/// @param chooseValue The enumeration string value. Get the value in TuyaSmartSceneDPModel.dpModel.property.range.
/// @param exprType The entity type.
///
/// @return The TuyaSmartSceneExprModel object.
+ (TuyaSmartSceneExprModel *)createEnumExprWithType:(NSString *)type chooseValue:(NSString *)chooseValue exprType:(ExprType)exprType;

/// Creates an expression model, such as `temp <= 40`.
///
/// @param type The weather type or the DP ID of a device.
/// @param operateString The operators. Valid values: @">=", @"<=", and @"==".
/// @param value The specified value.
/// @param exprType The entity type.
///
/// @return The TuyaSmartSceneExprModel object.
+ (TuyaSmartSceneExprModel *)createValueExprWithType:(NSString *)type operater:(NSString *)operateString chooseValue:(NSInteger )value exprType:(ExprType)exprType;

/// Creates an expression model, such as `rawType`.
///
/// @param type The weather type or the DP ID of a device.
/// @param exprType The entity type.
///
/// @return The TuyaSmartSceneExprModel object.
+ (TuyaSmartSceneExprModel *)createRawExprWithType:(NSString *)type exprType:(ExprType)exprType;

/// Creates a timer condition.
///
/// @param timeZoneId The ID of a time zone, such as @"Asia/Shanghai".
/// @param loops The timer loop. For example, each character in @"0111110" specifies a day from Sunday to Monday. @"0000000" specifies only once.
/// @param date The date, such as @"20190501".
/// @param time The time, such as @"20:40".
///
/// @return The TuyaSmartSceneExprModel object.
+ (TuyaSmartSceneExprModel *)createTimerExprWithTimeZoneId:(NSString *)timeZoneId loops:(NSString *)loops date:(NSString *)date time:(NSString *)time;

/// Creates the expression of a timer condition related to sunrise or sunset time, such as `x minutes before sunrise`. `at sunrise` is still used as a normal weather condition.
///
/// @param city The city.
/// @param type The sunrise or sunset.
/// @param minutes The number of minutes. Valid values: -300 to 300.
///
/// @return The TuyaSmartSceneExprModel object.
+ (TuyaSmartSceneExprModel *)createSunsetriseTimerExprWithCity:(TuyaSmartCityModel *)city type:(SunType)type deltaMinutes:(NSInteger)minutes;

@end

NS_ASSUME_NONNULL_END

