//
//  TuyaSmartSceneModel.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

#import "TuyaSmartSceneActionModel.h"
#import "TuyaSmartSceneConditionModel.h"
#import "TuyaSmartScenePreConditionModel.h"


/// The type of condition to be matched. Valid values: any and all types.
typedef enum : NSUInteger {
    /// If any type of condition in a scene is matched, the scene is run.
    TuyaSmartConditionMatchAny = 1,
    /// If all types of conditions in a scene are matched, the scene is run.
    TuyaSmartConditionMatchAll
} TuyaSmartConditionMatchType;

/// The type of recommended scene. Valid values: none, tap-to-run, and automation types.
typedef enum : NSUInteger {
    /// None: Neither the tap-to-run scene nor the automation scene is run.
    TuyaSmartSceneRecommendTypeNone,
    /// The tap-to-run type of recommended scene is run.
    TuyaSmartSceneRecommendTypeScene,
    /// The automation type of recommended scene is run.
    TuyaSmartSceneRecommendTypeAutomation
} TuyaSmartSceneRecommendType;

/// The type of collection scene. Valid values: none, tap-to-run, and automation types.
typedef enum : NSUInteger {
    /// None: Neither the tap-to-run scene nor the automation scene is run.
    TuyaSmartSceneCollectionTypeNone,
    /// The tap-to-run type of collection scene is run.
    TuyaSmartSceneCollectionTypeScene,
    /// The automation type of collection scene is run.
    TuyaSmartSceneCollectionTypeAutomation
} TuyaSmartSceneCollectionType;

/// The type of device list that is supported by the panel when you create a scene.
typedef NS_ENUM(NSInteger, TuyaSmartScenePanelType) {
    /// NonAllDevevice: Only Zigbee devices can be added in the scene action.
    TuyaSmartScenePanelTypeNonAllDevevice = 0,
    /// AllDevices: Zigbee devices and Wi-Fi devices can be added in the scene action.
    TuyaSmartScenePanelTypeAllDevices
};

/// @brief TuyaSmartSceneModel provides extra attributes to implement the service logic of the scene.
@interface TuyaSmartSceneModel : NSObject<NSCoding>

/// The unique scene ID that only applies to custom scenes.
@property (nonatomic, strong) NSString *sceneId;

/// The scene code that only applies to default scenes.
@property (nonatomic, strong) NSString *code;

/// The scene name that describes the purpose of the scene.
@property (nonatomic, strong) NSString *name;

/// Specifies whether the specified scene is enabled. This status can be used to describe an automation scene. By default, a tap-to-run scene is enabled.
@property (nonatomic, assign) BOOL enabled;

/// Specifies whether to show scenes on the homepage. The status can be switched only when the scene is edited. 
@property (nonatomic, assign) BOOL stickyOnTop;

/// A list of preconditions is used to set the validity period of an automation scene. For more information, see the TuyaSmartScenePreConditionModel class.
@property (nonatomic, strong) NSArray<TuyaSmartScenePreConditionModel *> *preConditions;

/// A list of conditions.
@property (nonatomic, strong) NSArray<TuyaSmartSceneConditionModel *> *conditions;

/// A list of actions.
@property (nonatomic, strong) NSArray<TuyaSmartSceneActionModel *> *actions;

/// A list of devices.
@property (nonatomic, strong) NSArray *devList;

/// The URL of the scene background icon.
@property (nonatomic, copy) NSString *coverIcon;

/// The hexadecimal string of the scene background color.
@property (nonatomic, copy) NSString *displayColor;

/// The URL of the scene background. To create a scene, use the URL provided by Tuya.
@property (nonatomic, strong) NSString *background;

/// The type of condition to be matched. For more information, see the enumeration values of TuyaSmartConditionMatchType.
@property (nonatomic, assign) TuyaSmartConditionMatchType matchType;

/// Indicates whether this scene is bound to a panel. This attribute only supports standard Zigbee devices.
@property (nonatomic, assign) BOOL boundForPanel;

/// Specifies whether this scene is bound to a panel with later firmware updates. The new panel specifies that the scene supports Zigbee devices and Wi-Fi devices.
@property (nonatomic, assign) BOOL boundForWiFiPanel;

/// Specifies whether the automation scene supports running over a LAN. A value of `YES` means that the automation scene can be run when a Zigbee gateway goes offline.
@property (nonatomic, assign) BOOL localLinkage;

/// Indicates whether the tap-to-run scene supports running over a LAN. A value of `YES` means that specific commands can be sent in TCP or MQTT messages and used to notify the Zigbee gateway to run the scene.
@property (nonatomic, assign) BOOL newLocalScene;

/// The type of the associated panel. For more information, see the enumeration values of TuyaSmartScenePanelType.
@property (nonatomic, assign) TuyaSmartScenePanelType panelType;

/// The type of recommended scene. For more information, see the enumeration values of TuyaSmartSceneRecommendType.
@property (nonatomic, assign) TuyaSmartSceneRecommendType recommendType;

/// The type of collection scene. For more information, see the enumeration values of TuyaSmartSceneCollectionType.
@property (nonatomic, assign) TuyaSmartSceneCollectionType collectionType;

/// The description of the recommended scene.
@property (nonatomic, copy) NSString *recomDescription;

/// The coefficient value of recommended scene. Valid values: 0-100.
@property (nonatomic, assign) CGFloat recomCoefficient;

/// The timestamp when the automation scene is automatically closed. A value of `zero` means that the timestamp has not been set.
@property (nonatomic, assign) long long  disableTime;

#pragma mark - Business field

/// Indicates whether the details of the scene are returned. 
@property (nonatomic, assign) BOOL cached;

/// The URL of the arrow icon.
@property (nonatomic, copy) NSString *arrowIconUrl;

#pragma mark - Deprecated

/// The subtitle of the scene.
@property (nonatomic, strong) NSString *subTitle __deprecated;

/// The URL of the edit icon for the scene.
@property (nonatomic, strong) NSString *editIcon __deprecated;

/// The URL of the display icon for the scene.
@property (nonatomic, strong) NSString *displayIcon __deprecated;

@end
