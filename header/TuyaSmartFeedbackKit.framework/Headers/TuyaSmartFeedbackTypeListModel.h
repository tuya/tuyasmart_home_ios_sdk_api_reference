//
// TuyaSmartFeedbackTypeListModel.h
// TuyaSmartFeedbackKit
//
// Copyright (c) 2014-2021 Tuya Inc (https://developer.tuya.com)

#import "TuyaSmartFeedbackItemModel.h"

@interface TuyaSmartFeedbackTypeListModel : NSObject

/// The type of feedback type, such as "faulty device" and "more".
@property (nonatomic, strong) NSString *type;

/// A list of items that are supported by the feedback type.
@property (nonatomic, strong) NSArray<TuyaSmartFeedbackItemModel *> *list;

@end
