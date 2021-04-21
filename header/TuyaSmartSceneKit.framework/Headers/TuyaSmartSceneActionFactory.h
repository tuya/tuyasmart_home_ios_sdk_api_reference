//
//  TuyaSmartSceneActionFactory.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartSceneKit/TuyaSmartSceneKit.h>

/// The type of automation state. Valid values: enabled and disabled.
typedef enum : NSInteger {
    /// The enabled type.
    kAutoSwitchTypeEnable,
    /// The disabled type.
    kAutoSwitchTypeDisable
}AutoSwitchType;

NS_ASSUME_NONNULL_BEGIN

/// @brief The default design mode to create TuyaSmartSceneActionModel.
///
/// @note To support multiple languages, this class does not process the actionDisplay and actionDisplayNew fields of TuyaSmartSceneActionModel. These two properties are spliced by developers when they are created. After the properties are saved, the server generates the values according to the executiveProperty field value and the language environment of the interface. The property that is saved by developers is not used.
@interface TuyaSmartSceneActionFactory : NSObject

/// Creates a device action with required parameters.
///
/// @param devId The device ID.
/// @param devName The device name.
/// @param executerProperty The action to be run. Format: {dpId: <dpId's value>}. Example: {"1":true}.
/// @param extraProperty The optional parameters that specify extra properties of an action.
///
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createDeviceDpActionWithDevId:(NSString *)devId devName:(NSString *)devName executerProperty:(NSDictionary *)executerProperty extraProperty:(NSDictionary *)extraProperty;

/// Creates a group action by setting the parameters of the group.
///
/// @param groupId The group ID.
/// @param groupName The group name.
/// @param executerProperty The action to be run. Format: {dpId: <dpId's value>}. Example: {"1":true}.
/// @param extraProperty The optional parameters that specify extra properties of an action.
///
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createGroupDpActionWithGroupId:(NSString *)groupId groupName:(NSString *)groupName executerProperty:(NSDictionary *)executerProperty extraProperty:(NSDictionary *)extraProperty;

/// Creates an action to trigger a scene.
///
/// @param sceneId The scene ID.
/// @param sceneName The scene name.
///
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createTriggerSceneActionWithSceneId:(NSString *)sceneId sceneName:(NSString *)sceneName;

/// Creates an action to enable or disable an automation scene.
///
/// @param sceneId The scene ID.
/// @param sceneName The scene name.
/// @param type The value of AutoSwitchType.
///
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createSwitchAutoActionWithSceneId:(NSString *)sceneId sceneName:(NSString *)sceneName type:(AutoSwitchType)type;

/// Creates a delay action.
///
/// @param hours The number of hours in a delay. Valid values: 0 to 5.
/// @param minutes The number of minutes in a delay. Valid values: 0 to 59.
/// @param seconds The number of seconds in a delay. Valid values: 0 to 59.
/// 
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createDelayActionWithHours:(NSString *)hours minutes:(NSString *)minutes seconds:(NSString *)seconds;

/// Creates a push notification action.
///
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createSendNotificationAction;

/// Creates a call notification action (for internal use only).
///
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createCallAction;

/// Creates an SMS sending action (for internal use only).
///
/// @return The TuyaSmartSceneActionModel class.
+ (TuyaSmartSceneActionModel *)createSmsAction;

@end

NS_ASSUME_NONNULL_END

