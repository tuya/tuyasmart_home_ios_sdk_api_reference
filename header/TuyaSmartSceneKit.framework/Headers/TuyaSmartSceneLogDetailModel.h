//
//  TuyaSmartSceneLogDetailModel.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartSceneLogDetailData;

/// @brief TuyaSmartSceneLogDetailModel provides extra attributes to generate the object of the log detail model.
@interface TuyaSmartSceneLogDetailModel : NSObject

/// The ID of the action entity.
@property (nonatomic, strong) NSString *actionEntityId;

/// The name of the action entity.
@property (nonatomic, strong) NSString *actionEntityName;

/// The URL of the action entity.
@property (nonatomic, strong) NSString *actionEntityUrl;

/// The type of action executor. Example: `dpIssue` and `groupDpIssue`.
@property (nonatomic, strong) NSString *actionExecutor;

/// The ID of the action.
@property (nonatomic, strong) NSString *actionId;

/// The error code.
@property (nonatomic, strong) NSString *errorCode;

/// The error message that is returned while running a scene.
@property (nonatomic, strong) NSString *errorMsg;

/// The running status of the action in the scene.
@property (nonatomic, assign) NSInteger execStatus;

/// The running time of the action in the scene.
@property (nonatomic, strong) NSString *executeTime;

/// A list of the scene log details.
@property (nonatomic, strong) NSArray<TuyaSmartSceneLogDetailData *> *detail;

@end

/// @brief TuyaSmartSceneLogDetailData provides extra attributes to generate the object of log details.
@interface TuyaSmartSceneLogDetailData: NSObject

/// The code that is used to run an action in a scene.
@property (nonatomic, strong) NSString *code;

/// The error message that is returned while running the action.
@property (nonatomic, strong) NSString *msg;

/// The running status of the action in the scene.
@property (nonatomic, assign) NSInteger status;

/// The username.
@property (nonatomic, strong) NSString *detailName;

/// The user ID.
@property (nonatomic, strong) NSString *detailId;

/// The URL of the icon.
@property (nonatomic, strong) NSString * icon;

@end

NS_ASSUME_NONNULL_END
