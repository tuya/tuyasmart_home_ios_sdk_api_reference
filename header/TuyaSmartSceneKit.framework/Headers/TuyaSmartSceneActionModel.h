//
//  TuyaSmartSceneActionModel.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

/// The push message action.
static NSString * const ACTION_EXECUTOR_APP_PUSH = @"appPushTrigger";
/// The call action.
static NSString * const ACTION_EXECUTOR_APP_CALL = @"mobileVoiceSend";
/// The SMS action.
static NSString * const ACTION_EXECUTOR_SMS_SEND = @"smsSend";
/// The device DP action.
static NSString * const ACTION_EXECUTOR_DP_ISSUE = @"dpIssue";
/// The device group DP action.
static NSString * const ACTION_EXECUTOR_GROUP_DP_ISSUE = @"deviceGroupDpIssue";
/// The infrared device DP action.
static NSString * const ACTION_EXECUTOR_IR_ISSUE = @"irIssue";
/// The infrared device DP action (Version 2).
static NSString * const ACTION_EXECUTOR_IR_ISSUE_VII = @"irIssueVii";
/// Enables an automation scene.
static NSString * const ACTION_EXECUTOR_RULE_ENABLE = @"ruleEnable";
/// Disables an automation scene.
static NSString * const ACTION_EXECUTOR_RULE_DISABLE = @"ruleDisable";
/// Runs a scene.
static NSString * const ACTION_EXECUTOR_RULE_TRIGGER = @"ruleTrigger";
/// Delays an action.
static NSString * const ACTION_EXECUTOR_DELAY = @"delay";
/// Runs a toggle action.
static NSString * const ACTION_EXECUTOR_TOGGLE = @"toggle";
/// Runs a step action.
extern NSString * const ACTION_EXECUTOR_STEP;

/// The type of action status. Valid values: loading, success, offline, timeout, and delay.
typedef NS_ENUM(NSInteger, TYSceneActionStatus)
{
    /// The loading action type.
    TYSceneActionStatusLoading = 0,
    /// The success action type.
    TYSceneActionStatusSuccess,
    /// The offline action type.
    TYSceneActionStatusOffline,
    /// The timeout action type.
    TYSceneActionStatusTimeout,
    /// The delay action type.
    TYSceneActionStatusDelay,
};


/// @brief The data model of the scene-based action.
@interface TuyaSmartSceneActionModel : NSObject<NSCoding>

/// The action ID.
@property (nonatomic, copy) NSString *actionId;

/// The entity ID. For a device action, this parameter is set to the value of `devId`. For a group action, it is set to the value of `groupId`. For a delay action, it is set to the value of @"delay". For a scene action, it is set to the value of `sceneId`.
@property (nonatomic, copy) NSString *entityId;

/// The entity name, such as `lamp` or `lamp group`.
@property (nonatomic, copy) NSString *entityName;

/// The ID of the scene to which the specified action belongs.
@property (nonatomic, copy) NSString *scenarioId;

/// Describes the details of the specified action, such as `Switch : Open`.
@property (nonatomic, copy) NSString *actionDisplay;

/// Describes the details of the specified action. The following sample code shows the original format. You can use this sample code to create the description:
/// {
///    1: [
///        "Switch",
///        "Open"
///        ]
/// }
@property (nonatomic, strong) NSDictionary *actionDisplayNew;


/// The type of action. Valid values:
/// "dpIssue": runs a device action.
/// "deviceGroupDpIssue": runs a group action.
/// "irIssue": runs an infrared device, such as an air conditioner that is controlled by a remote control.
/// "irIssueVii": runs an infrared device, such as an air conditioner that is controlled by a remote control. ExecutorProperty specifies real-time infrared ray remote control.
/// "ruleTrigger": runs a scene.
/// "ruleEnable":  enables an automation scene.
/// "ruleDisable": disables an automation scene.
/// "delay": delays a scene for a specific period.
@property (nonatomic, copy) NSString *actionExecutor;


/// The property that is used to run a scene. For example, {"1":true, ...} can be specified. In this example, "1" is the value of `dpId` that is a data point ID. You can set the value to the preferred data point. For a delay action, `executorProperty` is set in the format such as {"seconds":"5","minutes":"0"}.
@property (nonatomic, strong) NSDictionary *executorProperty;

/// Tne local property of the scene, such as `gId` and `gwId`.
@property (nonatomic, strong) NSDictionary *extraProperty;

/// If this action is a device action and this device has been removed from the current account, this flag is set to `YES`.
@property (nonatomic, assign) BOOL devDelMark;

/// If this action is a device action and this device has been removed from the current account, this icon URL is used to display the device icon.
@property (nonatomic, copy) NSString *deleteDevIcon;

/// The status of the current running action.
@property (nonatomic, assign) TYSceneActionStatus status;

#pragma mark - Panel info

/// The panel ID. When a React Native panel is used to run the specified action, the value is assigned by the cloud server.
@property (nonatomic, copy) NSString *uiid;

#pragma mark - Recommend info

/// The recommended product ID.
@property (nonatomic, copy) NSString *productId;

/// The recommended product icon.
@property (nonatomic, copy) NSString *productPic;

/// The URL of the default icon of the recommended product.
@property (nonatomic, copy) NSString *defaultIconUrl;
@end
