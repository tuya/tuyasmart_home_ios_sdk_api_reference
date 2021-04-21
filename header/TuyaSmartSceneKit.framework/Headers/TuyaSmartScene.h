//
//  TuyaSmartScene.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartUtil/TuyaSmartUtil.h>
#import "TuyaSmartSceneModel.h"
#import "TuyaSmartSceneActionModel.h"
#import "TuyaSmartSceneConditionModel.h"

/// @brief TuyaSmartScene is used to add, edit, run, or delete scenes. 
@interface TuyaSmartScene : NSObject

/// Initializes TuyaSmartScene by TuyaSmartSceneModel.
///
/// @param sceneModel The scene model.
/// @return The instance of TuyaSmartScene.
+ (instancetype)sceneWithSceneModel:(TuyaSmartSceneModel *)sceneModel;

/// Initializes TuyaSmartScene by TuyaSmartSceneModel.
///
/// @param sceneModel The scene model.
/// @return The instance of TuyaSmartScene.
- (instancetype)initWithSceneModel:(TuyaSmartSceneModel *)sceneModel;

/// Do not initialize an instance by using the init method.
///
/// @return    This method returns an unavailable instance.
- (instancetype)init NS_UNAVAILABLE;

/// Adds a scene by using required parameters.
///
/// @param name               The scene name.
/// @param homeId            The home ID.
/// @param background        The URL of the background image.
/// @param showFirstPage      Specifies whether to show the scene on the index page.
/// @param preConditionList       The prerequisites, such as the validity period.
/// @param conditionList      A list of conditions.
/// @param actionList         A list of actions.
/// @param matchType          Specifies whether to run the automation when all or any condition is matched.
/// @param success            Called when the task is finished. TuyaSmartSceneModel is returned.
/// @param failure            Called when the task is interrupted by an error.
+ (void)addNewSceneWithName:(NSString *)name
                     homeId:(long long)homeId
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
           preConditionList:(NSArray<TuyaSmartScenePreConditionModel*> *)preConditionList
              conditionList:(NSArray<TuyaSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<TuyaSmartSceneActionModel*> *)actionList
                  matchType:(TuyaSmartConditionMatchType)matchType
                    success:(void (^)(TuyaSmartSceneModel *sceneModel))success
                    failure:(TYFailureError)failure;

/// Adds a new scene. Use a value of sceneModel that provides complete information of a scene.
///
/// @param sceneModel     The value of TuyaSmartSceneModel.
/// @param homeId              The home ID.
/// @param success            Called when the task is finished. TuyaSmartSceneModel is returned.
/// @param failure            Called when the task is interrupted by an error.
+ (void)addNewSceneWithSceneModel:(TuyaSmartSceneModel *)sceneModel
                           homeId:(long long)homeId
                          success:(void (^)(TuyaSmartSceneModel *sceneModel))success
                          failure:(TYFailureError)failure;

/// Edits an existing scene by using required parameters.
///
/// @param name               The scene name.
/// @param background        The URL of the background image.
/// @param showFirstPage      Specifies whether to show the scene on the index page.
/// @param preConditionList       The prerequisites, such as the validity period.
/// @param conditionList      A list of conditions.
/// @param actionList         A list of actions.
/// @param matchType          Specifies whether to run the automation when all or any condition is matched.
/// @param success            Called when the task is finished. TYSuccessHandler is returned.
/// @param failure            Called when the task is interrupted by an error.
- (void)modifySceneWithName:(NSString *)name
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
           preConditionList:(NSArray<TuyaSmartScenePreConditionModel*> *)preConditionList
              conditionList:(NSArray<TuyaSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<TuyaSmartSceneActionModel*> *)actionList
                  matchType:(TuyaSmartConditionMatchType)matchType
                    success:(TYSuccessHandler)success
                    failure:(TYFailureError)failure;

/// Edits an existing scene. Use a value of sceneModel that provides complete information of a scene.
///
/// @param sceneModel     The value of TuyaSmartSceneModel.
/// @param success            Called when the task is finished. TYSuccessHandler is returned.
/// @param failure            Called when the task is interrupted by an error.
- (void)modifySceneWithSceneModel:(TuyaSmartSceneModel *)sceneModel
                          success:(TYSuccessHandler)success
                          failure:(TYFailureError)failure;

/// Deletes an existing scene.
///
/// @param success            Called when the task is finished. TYSuccessHandler is returned.
/// @param failure            Called when the task is interrupted by an error.
- (void)deleteSceneWithSuccess:(TYSuccessHandler)success
                       failure:(TYFailureError)failure;

/// Runs a scene.
///
/// @param success            Called when the task is finished. TYSuccessHandler is returned.
/// @param failure            Called when the task is interrupted by an error.
- (void)executeSceneWithSuccess:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;

/// Disables an automation scene. Then, the scene will not be automatically run.
///
/// @param success            Called when the task is finished. TYSuccessHandler is returned.
/// @param failure            Called when the task is interrupted by an error.
- (void)disableSceneWithSuccess:(TYSuccessHandler)success
                        failure:(TYFailureError)failure;

/// Enables an automation scene. Then, the scene is automatically run when specified conditions are matched.
///
/// @param success            Called when the task is finished. TYSuccessHandler is returned.
/// @param failure            Called when the task is interrupted by an error.
- (void)enableSceneWithSuccess:(TYSuccessHandler)success
                       failure:(TYFailureError)failure;

/// Cancels the current request.
- (void)cancelRequest;

#pragma mark - Recommend scene

/// Runs a recommended scene.
///
/// @param homeId              The home ID.
/// @param success            Called when the task is finished. TYSuccessHandler is returned.
/// @param failure            Called when the task is interrupted by an error.
- (void)triggerRecommendSceneWithHomeId:(long long)homeId success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Deletes a recommended scene.
///
/// @param homeId              The home ID.
/// @param success            Called when the task is finished. TYSuccessHandler is returned.
/// @param failure            Called when the task is interrupted by an error.
- (void)removeRecommendSceneWithHomeId:(long long)homeId success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// Saves a recommended scene. This scene can be modified by users. This modified scene becomes a normal scene after it is saved. The recommended scene will not show anymore.
///
/// @param homeId              The home ID.
/// @param success            Called when the task is finished. TYSuccessHandler is returned.
/// @param failure            Called when the task is interrupted by an error.
- (void)saveRecommendSceneWithHomeId:(long long)homeId success:(void (^)(TuyaSmartSceneModel *sceneModel))success failure:(TYFailureError)failure;

#pragma mark - Deprecated

/// Adds a scene by required parameters. (Deprecated)
///
/// @param name               The scene name.
/// @param homeId            The home ID.
/// @param background        The URL of the background image.
/// @param showFirstPage      Specifies whether to show the scene on the index page.
/// @param conditionList      A list of conditions.
/// @param actionList         A list of actions.
/// @param matchType          Specifies whether to run the automation when all or any condition is matched.
/// @param success            Called when the task is finished. TuyaSmartSceneModel is returned.
/// @param failure            Called when the task is interrupted by an error.
///
/// @deprecated This method is deprecated. Use -[TuyaSmartScene addNewSceneWithName:homeId:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead.
+ (void)addNewSceneWithName:(NSString *)name
                     homeId:(long long)homeId
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
              conditionList:(NSArray<TuyaSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<TuyaSmartSceneActionModel*> *)actionList
                  matchType:(TuyaSmartConditionMatchType)matchType
                    success:(void (^)(TuyaSmartSceneModel *sceneModel))success
                    failure:(TYFailureError)failure __deprecated_msg("This method is deprecated. Use -[TuyaSmartScene addNewSceneWithName:homeId:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead");

/// Edits an existing scene with required parameters. (Deprecated)
///
/// @param name               The scene name.
/// @param background        The URL of the background image.
/// @param showFirstPage      Specifies whether to show the scene on the index page.
/// @param conditionList      A list of conditions.
/// @param actionList         A list of actions.
/// @param matchType          Specifies whether to run the automation when all or any condition is matched.
/// @param success            Called when the task is finished. TYSuccessHandler is returned.
/// @param failure            Called when the task is interrupted by an error.
///
/// @deprecated This method is deprecated. Use -[TuyaSmartScene modifySceneWithName:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead.
- (void)modifySceneWithName:(NSString *)name
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
              conditionList:(NSArray<TuyaSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<TuyaSmartSceneActionModel*> *)actionList
                  matchType:(TuyaSmartConditionMatchType)matchType
                    success:(TYSuccessHandler)success
                    failure:(TYFailureError)failure __deprecated_msg("This method is deprecated. Use -[TuyaSmartScene modifySceneWithName:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead");
@end
