//
// TuyaSmartFeedbackItemModel.h
// TuyaSmartFeedbackKit
//
// Copyright (c) 2014-2021 Tuya Inc (https://developer.tuya.com)

@interface TuyaSmartFeedbackItemModel : NSObject


/// The ID of the feedback item.
@property (nonatomic, strong) NSString      *hdId;

/// The type of feedback item.
@property (nonatomic, assign) NSUInteger    hdType;

/// The title of the feedback item.
@property (nonatomic, strong) NSString      *title;

@end
