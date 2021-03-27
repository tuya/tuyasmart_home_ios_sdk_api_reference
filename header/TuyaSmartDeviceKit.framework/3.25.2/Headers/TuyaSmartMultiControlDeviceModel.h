//
// TuyaSmartMultiControlDeviceModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartMultiControlDatapointModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartMultiControlDeviceModel : NSObject

@property (copy, nonatomic) NSString *devId;///< Device ID.
@property (copy, nonatomic) NSString *productId;///< Product ID.
@property (copy, nonatomic) NSString *name;///< Device name.
@property (copy, nonatomic) NSString *iconUrl;///< Device Icon download link.
@property (copy, nonatomic) NSString *roomName;///< Room name.
@property (assign, nonatomic) BOOL inRule;///< A boolean value indicates whether the device in an automated condition.
@property (strong, nonatomic) NSArray<TuyaSmartMultiControlDatapointModel *> *datapoints;
@property (strong, nonatomic) NSArray<NSString *> *multiControlIds;///< Multiple control group ID arrays that the device has been associated with.

@end

NS_ASSUME_NONNULL_END
