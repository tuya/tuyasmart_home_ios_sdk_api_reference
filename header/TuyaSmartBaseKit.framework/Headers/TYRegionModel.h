//
// TYLoginRegionModel.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYRegionModel : NSObject


/// The region name.
@property (nonatomic, strong) NSString *name;

/// The region code.
@property (nonatomic, strong) NSString *region;

/// Indicates whether the region is the default region.
@property (nonatomic, assign) BOOL isDefault;

@end

NS_ASSUME_NONNULL_END
