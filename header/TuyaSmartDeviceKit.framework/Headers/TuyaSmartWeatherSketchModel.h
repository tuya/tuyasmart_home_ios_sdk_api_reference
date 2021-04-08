//
// TuyaSmartWeatherSketchModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartWeatherSketchModel : NSObject

/// Weather conditions, such as sunny, cloudy, rainy, etc.
@property (nonatomic, strong) NSString *condition;

/// Weather icon, which is used by default.
@property (nonatomic, strong) NSString *iconUrl;

/// Weather icon, highlight.
@property (nonatomic, strong) NSString *inIconUrl;

/// Compatible with old version parameters. Business layer not used.
@property (nonatomic, strong) NSString *city;

/// Weather conditions, such as sunny, cloudy, rainy and other property values, such as "Sunny" for sunny, "Cloudy" for cloudy. The business layer is not used yet.
@property (nonatomic, strong) NSString *mark;

/// Temperature.
@property (nonatomic, strong) NSString *temp;

@end

NS_ASSUME_NONNULL_END
