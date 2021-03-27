//
// TuyaSmartMultiControlDpRelationModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartMultiControlParentRuleModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartMcGroupDetailModel : NSObject

@property (copy, nonatomic) NSString *detailId;
@property (copy, nonatomic) NSString *dpId;///< dp id
@property (copy, nonatomic) NSString *dpName;///< dp name
@property (copy, nonatomic) NSString *devId;///< device id
@property (copy, nonatomic) NSString *devName;///< Device name.
@property (assign, nonatomic) BOOL enabled;///< Availability.
@property (copy, nonatomic) NSString *multiControlId;///< Multi-control group id.

@end


@interface TuyaSmartMcGroupModel : NSObject

@property (copy, nonatomic) NSString *multiControlId;///< Multi-control group id.
@property (copy, nonatomic) NSString *groupName;///< Multi-control group name.
@property (strong, nonatomic) NSArray<TuyaSmartMcGroupDetailModel *> *groupDetail;///< Multi-control group association details.

@property (assign, nonatomic) BOOL enabled;
@property (assign, nonatomic) NSInteger groupType;///< Multi-control group type.
@property (copy, nonatomic) NSString *multiRuleId;
@property (copy, nonatomic) NSString *ownerId;///< Family ID.
@property (copy, nonatomic) NSString *uid;///< User ID.

@end


@interface TuyaSmartMultiControlDpRelationModel : NSObject

@property (strong, nonatomic) NSArray<TuyaSmartMultiControlDatapointModel *> *datapoints;
@property (strong, nonatomic) NSArray<TuyaSmartMcGroupModel *> *mcGroups;
@property (strong, nonatomic) NSArray<TuyaSmartMultiControlParentRuleModel *> *parentRules;

@end

NS_ASSUME_NONNULL_END
