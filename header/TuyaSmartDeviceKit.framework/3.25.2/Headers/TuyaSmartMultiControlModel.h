//
// TuyaSmartMultiControlModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartMultiControlDetailModel : NSObject

@property (copy, nonatomic) NSString *detailId;
@property (copy, nonatomic) NSString *devId;///< Attachment device id.
@property (copy, nonatomic) NSString *dpId;///< The dp id of the associated attached device.
@property (assign, nonatomic) BOOL enable;///< Whether affiliated devices that have been associated can be controlled by the multi-control function.

@end


@interface TuyaSmartMultiControlModel : NSObject

@property (copy, nonatomic) NSString *multiControlId;///< Multi-control group id.
@property (copy, nonatomic) NSString *groupName;///< Multi-control group name.
@property (strong, nonatomic) NSArray<TuyaSmartMultiControlDetailModel *> *groupDetail;

@property (assign, nonatomic, readonly) NSInteger groupType;///< Multi-control group type. Default is 1.
@property (copy, nonatomic, readonly) NSString *ownerId;///< Family id.
@property (copy, nonatomic, readonly) NSString *uid;///< User id.

@end

NS_ASSUME_NONNULL_END
