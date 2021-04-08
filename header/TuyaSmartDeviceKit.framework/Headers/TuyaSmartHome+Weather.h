//
// TuyaSmartHome+Weather.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartHome.h"

@class TuyaSmartWeatherModel;
@class TuyaSmartWeatherSketchModel;
@class TuyaSmartWeatherOptionModel;

@interface TuyaSmartHome (Weather)

/// Home location
- (NSString *)geoName;

/// Get brief weather parameters for the home. This request returns brief weather parameters for the city where the family is located, such as the city name, weather conditions for the day (sunny, cloudy, rainy, etc.), and weather picture information.
/// @param success Called when the task finishes successfully. TuyaSmartWeatherSketchModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getHomeWeatherSketchWithSuccess:(void(^)(TuyaSmartWeatherSketchModel *))success
                                failure:(TYFailureError)failure;


/// Get detailed parameters of home weather, such as temperature, humidity, UV index, air quality, etc.
///
///optionModel can be nil. if it is nil, the returned parameter will be the parameter setting of the last successful request. if only one unit setting is changed for the request, the other two will remain the parameter setting of the last successful request.
///
///Due to the different services used by weather services in different regions, the parameters returned may differ from region to region. In particular, if the current home account location is in China, then wind speed and barometric pressure information will not be returned.
///
/// @param optionModel Weather details parameter unit configuration.
/// @param success Called when the task finishes successfully. A list of TuyaSmartWeatherModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getHomeWeatherDetailWithOption:(TuyaSmartWeatherOptionModel *)optionModel
                         success:(void(^)(NSArray<TuyaSmartWeatherModel *> *))success
                         failure:(TYFailureError)failure;

@end
