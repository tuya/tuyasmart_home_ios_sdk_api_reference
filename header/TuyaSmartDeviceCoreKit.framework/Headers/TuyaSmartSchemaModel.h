//
// TuyaSmartSchemaModel.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartSchemaModel
#define TuyaSmart_TuyaSmartSchemaModel

#import <Foundation/Foundation.h>
#import "TuyaSmartSchemaPropertyModel.h"

/// device schema
@interface TuyaSmartSchemaModel : NSObject

/// Dp ID.
@property (nonatomic, strong) NSString     *dpId;

/// Dp code.
@property (nonatomic, strong) NSString     *code;

/// The name of dp.
@property (nonatomic, strong) NSString     *name;

/// Read and write attributes of the DP point rw - can send down and report | ro - only report | wr - only send down.
@property (nonatomic, strong) NSString     *mode;

/// Type of DP point obj - (numeric, character, bool, enumerated, fault) | raw pass-through type.
@property (nonatomic, strong) NSString     *type;

/// The icon name of dp.
@property (nonatomic, strong) NSString     *iconname;

/// Dp property.
@property (nonatomic, strong) TuyaSmartSchemaPropertyModel *property;

@end

#endif
