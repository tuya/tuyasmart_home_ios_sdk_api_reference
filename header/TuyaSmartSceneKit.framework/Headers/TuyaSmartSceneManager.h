//
//  TuyaSmartSceneManager.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>
#import "TuyaSmartCityModel.h"
#import "TuyaSmartSceneDPModel.h"
#import "TuyaSmartSceneModel.h"
#import "TuyaSmartSceneLogModel.h"
#import "TuyaSmartSceneLogDetailModel.h"

@class TuyaSmartSceneManager;

/// The protocol provides the delegate methods to receive changes in the enabled or disabled state of a scene.
@protocol TuyaSmartSceneManagerDelegate<NSObject>

@optional

/// Called when the state of the scene is changed.
///
/// @param manager The scene manager.
/// @param state   The scene state. Valid values: "disabled" and "enabled".
/// @param sceneId The scene ID.
- (void)sceneManager:(TuyaSmartSceneManager *)manager state:(NSString *)state sceneId:(NSString *)sceneId;

@end

/// @brief The TuyaSmartSceneManager class provides multiple methods to get a list of scenes, conditions, tasks, cities, and scene logs.
@interface TuyaSmartSceneManager : NSObject

/// Returns the singleton instance of the TuyaSmartSceneManager class.
///
/// @return The TuyaSmartSceneManager instance.
+ (instancetype)sharedInstance;

/// The delegate is notified when the data of the scene is changed. @see TuyaSmartSceneManagerDelegate.
@property (nonatomic, weak) id<TuyaSmartSceneManagerDelegate> delegate;

/// Returns a list of scenes, including tap-to-run and automation types of scenes. The tap-to-run and automation scenes are differentiated by the value of `entityType` in TuyaSmartSceneModel. A tap-to-run scene is specified when `entityType` is set to `AutoTypeManual`. Otherwise, an automation scene is specified.
///
/// @see For more information, see the TuyaSmartSceneConditionModel class.
///
/// @param homeId  The current home ID.
/// @param success Called when the task is finished. A list of TuyaSmartSceneModel is returned.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getSceneListWithHomeId:(long long)homeId
                       success:(void(^)(NSArray<TuyaSmartSceneModel *> *list))success
                       failure:(TYFailureError)failure;

/// Returns a simple list of scenes, including tap-to-run and automation types of scenes. The tap-to-run and automation scenes are differentiated by the value of `entityType` in TuyaSmartSceneModel. A tap-to-run scene is specified when `entityType` is set to `AutoTypeManual`. Otherwise, an automation scene is specified.
///
/// @note A simple list of scenes provides less JSON data from the server than a precise list of scenes.
///
/// @param homeId  The current home ID.
/// @param success Called when the task is finished. A list of TuyaSmartSceneModel is returned.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getSimpleSceneListWithHomeId:(long long)homeId
                       success:(void(^)(NSArray<TuyaSmartSceneModel *> *list))success
                       failure:(TYFailureError)failure;

/// Returns the scene details based on the specified home ID and scene ID.
///
/// @param homeId  The home ID.
/// @param sceneId The scene ID.
/// @param success Called when the task is finished. A list of TuyaSmartSceneModel is returned.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getSceneDetailWithHomeId:(long long)homeId
                         sceneId:(NSString *)sceneId
                         success:(void(^)(TuyaSmartSceneModel *scene))success
                         failure:(TYFailureError)failure;

/// Returns a recommended list of scenes based on the specified home ID.
///
/// @param homeId  The home ID.
/// @param success Called when the task is finished. A list of TuyaSmartSceneModel is returned.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getRecommendedSceneListWithHomeId:(long long)homeId
                       success:(void(^)(NSArray<TuyaSmartSceneModel *> *list))success
                       failure:(TYFailureError)failure;

/// Returns a collection of scenes based on the specified home ID.
///
/// @param homeId  The home ID.
/// @param success Called when the task is finished. A list of TuyaSmartSceneModel is returned.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getCollectionSceneListWithHomeId:(long long)homeId
                                 success:(TYSuccessList)success
                                 failure:(TYFailureError)failure;

/// Returns a list of automation conditions based on the specified temperature scale type, speed unit, and home ID.
///
/// @param fahrenheit If the value is set to `YES`, the temperature unit Fahrenheit (°F) is used. Otherwise, Celsius (°C) is used.
/// @param speedUnit  The description of the speed unit.
/// @param homeId     The current home ID.
/// @param success    Called when the task is finished. The map objects are returned, including the envConditions and devConditions objects.
/// @param failure    Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getAllConditionListWithFahrenheit:(BOOL)fahrenheit
                            windSpeedUnit:(NSString *)speedUnit
                                   homeId:(long long)homeId
                                  success:(void(^)(NSDictionary *dict))success
                                  failure:(TYFailureError)failure;

/// Returns a list of action devices in the scene based on the specified home ID.
///
/// @param homeId  The current home ID.
/// @param success Called when the task is finished. A list of TuyaSmartDeviceModel is returned.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getActionDeviceListWithHomeId:(long long)homeId
                              success:(void(^)(NSArray<TuyaSmartDeviceModel *> *list))success
                              failure:(TYFailureError)failure;

/// Returns a list of action devices based on the specified room ID.
///
/// @param roomId The room ID.
///
/// @retrun The TuyaSmartDeviceModel list. For more information, see the TuyaSmartDeviceModel class.
- (NSArray<TuyaSmartDeviceModel *> *)getActionDeviceListWithRoomId:(long long)roomId;


/// Returns a list of condition devices in the scene based on the specified home ID.
///
/// @param homeId  The home ID.
/// @param success Called when the task is finished. A list of TuyaSmartDeviceModel is returned.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getConditionDeviceListWithHomeId:(long long)homeId
                                 success:(void(^)(NSArray<TuyaSmartDeviceModel *> *list))success
                                 failure:(TYFailureError)failure;

/// Returns a list of condition devices in the scene based on the specified room ID.
///
/// @param roomId The room ID.
///
/// @return The TuyaSmartDeviceModel list, the more information you can see TuyaSmartDeviceModel class.
- (NSArray<TuyaSmartDeviceModel *> *)getConditionDeviceListWithRoomId:(long long)roomId;

/// Returns a list of devices for the face recognition condition based on the specified home ID.
///
/// @param homeId  The home ID.
/// @param success Called when the task is finished. A list of TuyaSmartDeviceModel is returned.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getFaceDeviceListWithHomeId:(long long)homeId success:(void(^)(NSArray<TuyaSmartDeviceModel *> *list))success failure:(TYFailureError)failure;

/// Returns a list of devices for the member's lock condition based on the specified home ID.
///
/// @param homeId  The home ID.
/// @param success Called when the task is finished. A list of TuyaSmartDeviceModel is returned for the member lock condition.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getLockDeviceListWithHomeId:(long long)homeId
                            success:(void(^)(NSArray<TuyaSmartDeviceModel *> *list))success
                            failure:(TYFailureError)failure;

/// Returns a list of groups for an action in the scene based on the specified room ID.
///
/// @param roomId The room ID.
///
/// @return The TuyaSmartGroupModel list for the action in the scene. For more information, see the TuyaSmartGroupModel class.
- (NSArray<TuyaSmartGroupModel *> *)getActionGroupListWithRoomId:(long long)roomId;

/// Returns all devices and groups for an action in the scene based on the specified home ID.
///
/// @param homeId  The home ID.
/// @param success Called when the task is finished. The map objects are returned, including the deviceList, groupList, and extendsDictionary objects.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getActionGroupListAndDeviceListWithHomeId:(long long)homeId
                                          success:(void(^)(NSDictionary *dict))success
                                          failure:(TYFailureError)failure;

/// Returns a list of device data points (DPs) for an action in the scene based on the specified device ID.
///
/// @param devId   The device ID.
/// @param success Called when the task is finished. A list of TuyaSmartSceneDPModel is returned.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getActionDeviceDPListWithDevId:(NSString *)devId
                               success:(void(^)(NSArray<TuyaSmartSceneDPModel *> *list))success
                               failure:(TYFailureError)failure;

/// Returns a list of device DPs for a condition in the scene based on the specified device ID.
///
/// @param devId   The device ID.
/// @param success Called when the task is finished. A list of TuyaSmartSceneDPModel is returned. The TuyaSmartSceneDPModel object describes the DP data of the device.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getCondicationDeviceDPListWithDevId:(NSString *)devId
                                    success:(void(^)(NSArray<TuyaSmartSceneDPModel *> *list))success
                                    failure:(TYFailureError)failure;

/// Returns a list of group DPs for an action in the scene based on the specified group ID.
///
/// @param groupId The group ID.
/// @param success Called when the task is finished. A list of TuyaSmartSceneDPModel is returned.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getActionGroupDPListWithGroupId:(NSString *)groupId
                                success:(void(^)(NSArray<TuyaSmartSceneDPModel *> *list))success
                                failure:(TYFailureError)failure;

/// Returns a list of cities based on the specified country code. If the account is located out of China, we recommend that you specify the latitude and longitude to get the city information.
///
/// @param countryCode The country code.
/// @param success     Called when the task is finished. A list of TuyaSmartCityModel is returned.
/// @param failure     Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getCityListWithCountryCode:(NSString *)countryCode
                           success:(void(^)(NSArray<TuyaSmartCityModel *> *list))success
                           failure:(TYFailureError)failure;

/// Returns the city information based on the specified latitude and longitude.
///
/// @param latitude  The latitude.
/// @param longitude The longitude.
/// @param success   Called when the task is finished. A list of TuyaSmartCityModel is returned.
/// @param failure   Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getCityInfoWithLatitude:(NSString *)latitude
                      longitude:(NSString *)longitude
                        success:(void(^)(TuyaSmartCityModel *model))success
                        failure:(TYFailureError)failure;

/// Returns the city information based on the specified city ID.
///
/// @param cityId  The city ID.
/// @param success Called when the task is finished. A list of TuyaSmartCityModel is returned.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getCityInfoWithCityId:(NSString *)cityId
                      success:(void(^)(TuyaSmartCityModel *model))success
                      failure:(TYFailureError)failure;

/// Sorts a list of scenes by home ID.
///
/// @param homeId      The home ID.
/// @param sceneIdList A list of scenes to be sorted.
/// @param success     Called when the task is finished. A list of TYSuccessHandler is returned.
/// @param failure     Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)sortSceneWithHomeId:(long long)homeId
                sceneIdList:(NSArray<NSString *> *)sceneIdList
                    success:(TYSuccessHandler)success
                    failure:(TYFailureError)failure;

/// Returns a list of URLs for the scene background icons.
///
/// @param success If the task is finished, this block is called and the URL list is returned.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getSmartSceneBackgroundCoverWithsuccess:(TYSuccessList)success failure:(TYFailureError)failure;

/// Returns a list of custom style resources for scenes, including the color, icon, and background. The map objects are returned, including the coverColors, coverIconList, and coverPics objects.
///
/// @param success Called when the task is finished. The map objects are returned, including the coverColors, coverIconList, and coverPics objects.
/// @param failure Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getSmartSceneCustomStyleListWithSuccess:(TYSuccessDict)success failure:(TYFailureError)failure;

/// Returns all scene linkage logs that indicate successful or failed operations, such as scene running results and push notifications.
///
/// @param homeId         The home ID.
/// @param startTime      The start date.
/// @param endTime        The end date.
/// @param size           The number of items to be queried.
/// @param lastId         The ID of the last query item.
/// @param lastRecordTime The record date of the last query item.
/// @param success        Called when the task is finished. A list of TuyaSmartSceneLogModel is returned.
/// @param failure        Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getSmartSceneLogWithHomeId:(long long)homeId
                         startTime:(long long)startTime
                           endTime:(long long)endTime
                              size:(NSInteger)size
                            lastId:(NSString *)lastId
                    lastRecordTime:(long long)lastRecordTime
                           success:(void(^)(TuyaSmartSceneLogModel *logModel))success
                           failure:(TYFailureError)failure;

/// Returns a list of scene linkage logs of a specified device.
///
/// @param devId          The device ID.
/// @param homeId         The home ID.
/// @param startTime      The start date.
/// @param endTime        The end date.
/// @param size           The number of items to be queried.
/// @param lastId         The ID of the last query item.
/// @param lastRecordTime The record date of the last query item.
/// @param success        Called when the task is finished. A list of TuyaSmartSceneLogModel is returned.
/// @param failure        Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getSmartSceneLogOfDeviceWithDevId:(NSString *)devId
                                   homeId:(long long)homeId
                                startTime:(long long)startTime
                                  endTime:(long long)endTime
                                     size:(NSInteger)size
                                   lastId:(NSString *)lastId
                           lastRecordTime:(long long)lastRecordTime
                                  success:(void(^)(TuyaSmartSceneLogModel *logModel))success
                                  failure:(TYFailureError)failure;

/// Returns the scene log details by homeId, eventId, startTime, endTime, and returnType.
///
/// @param homeId     The home ID.
/// @param eventId    The event ID.
/// @param startTime  The start date.
/// @param endTime    The end date.
/// @param returnType The return type.
/// @param success    Called when the task is finished. A list of TuyaSmartSceneLogDetailModel is returned.
/// @param failure    Called when the task is interrupted by an error. An error message from TYFailureError is returned.
- (void)getSmartSceneLogDetailWithHomeId:(long long)homeId
                                 eventId:(NSString *)eventId
                               startTime:(long long)startTime
                                 endTime:(long long)endTime
                              returnType:(long long)returnType
                                 success:(void(^)(NSArray <TuyaSmartSceneLogDetailModel *>*items))success
                                 failure:(TYFailureError)failure;

/// Removes all geofencing data that is registered in the iOS system for automation scenes after user logout.
- (void)removeAllGeoFence;

/// Cancels the current request.
- (void)cancelRequest;

#pragma mark - Deprecated

/// Returns a list of weather conditions for automation scenes based on the specified temperature scale type. If the value of `fahrenheit` is `YES`, °F is used as the temperature unit. Otherwise, °C is used.
///
/// @param fahrenheit If the value is `YES`, °F is used as the temperature unit. Otherwise, °C is used.
/// @param success    Called when the task is finished. A list of TuyaSmartSceneDPModel is returned.
/// @param failure    Called when the task is interrupted by an error. An error message from TYFailureError is returned.
///
/// @deprecated This method is deprecated. Use getAllConditionListWithFahrenheit:windSpeedUnit:homeId:success:failure instead.
- (void)getConditionListWithFahrenheit:(BOOL)fahrenheit
                               success:(void(^)(NSArray<TuyaSmartSceneDPModel *> *list))success
                               failure:(TYFailureError)failure __deprecated_msg("use -getAllConditionListWithFahrenheit:windSpeedUnit:homeId:success:failure instead");

/// Returns all conditions for automation scenes, such as the weather condition and device condition.
///
/// @param fahrenheit If the value is `YES`, °F is used as the temperature unit. Otherwise, °C is used.
/// @param homeId     The current home ID.
/// @param success    Called when the task is finished. The map objects are returned, including the envConditions and devConditions objects.
/// @param failure    Called when the task is interrupted by an error. An error message from TYFailureError is returned.
///
/// @deprecated This method is deprecated. Use getAllConditionListWithFahrenheit:windSpeedUnit:homeId:success:failure instead.
- (void)getAllConditionListWithFahrenheit:(BOOL)fahrenheit
                                   homeId:(long long)homeId
                                  success:(void(^)(NSDictionary *dict))success
                                  failure:(TYFailureError)failure __deprecated_msg("use -getAllConditionListWithFahrenheit:windSpeedUnit:homeId:success:failure instead");

@end
