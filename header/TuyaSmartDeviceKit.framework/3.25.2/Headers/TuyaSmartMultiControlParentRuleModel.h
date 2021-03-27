//
// TuyaSmartMultiControlParentRuleModel.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TuyaSmartMultiControlDatapointModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartMultiControlParentRuleDpModel : NSObject

@property (copy, nonatomic) NSString *dpId;///< dp id
@property (copy, nonatomic) NSString *dpName;///< dp name

@end

@interface TuyaSmartMultiControlParentRuleModel : NSObject

@property (copy, nonatomic) NSString *ruleId;///< Automation id
@property (copy, nonatomic) NSString *name;///< Automation name

@property (strong, nonatomic) NSArray<TuyaSmartMultiControlParentRuleDpModel *> *dpList;

@end

NS_ASSUME_NONNULL_END
