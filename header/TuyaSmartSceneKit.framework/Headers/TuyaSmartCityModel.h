//
//  TuyaSmartCityModel.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <CoreLocation/CoreLocation.h>

/// @brief TuyaSmartCityModel is used to store basic information about a city.
@interface TuyaSmartCityModel : NSObject

/// The city ID.
@property (nonatomic, assign) long long cityId;

/// The city name.
@property (nonatomic, strong) NSString *city;

/// The city information from a map to be temporarily stored.
@property (nonatomic, copy) NSString *cityNameFromMap;

/// The city latitude that is specified by mapView centerCoordinate.
@property (nonatomic, assign) CLLocationDegrees tempLatitude;

/// The city longitude that is specified by mapView centerCoordinate.
@property (nonatomic, assign) CLLocationDegrees tempLongitude;

/// The area of the city, such as a county.
@property (nonatomic, copy) NSString *area;

/// The name of the city.
@property (nonatomic, copy) NSString *pinyin;

/// The name of the province or state.
@property (nonatomic, copy) NSString *province;

@end
