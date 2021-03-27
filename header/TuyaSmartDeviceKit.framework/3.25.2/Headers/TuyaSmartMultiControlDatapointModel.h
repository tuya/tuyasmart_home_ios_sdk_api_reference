//
// TuyaSmartMultiControlDatapointModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartMultiControlDatapointModel : NSObject

@property (copy, nonatomic) NSString *dpId;///< dp id
@property (copy, nonatomic) NSString *name;///< dp name
@property (copy, nonatomic) NSString *code;///< dp standard name（dpCode）
@property (copy, nonatomic) NSString *schemaId;///< The schema ID to which the key belongs.

@end

NS_ASSUME_NONNULL_END
