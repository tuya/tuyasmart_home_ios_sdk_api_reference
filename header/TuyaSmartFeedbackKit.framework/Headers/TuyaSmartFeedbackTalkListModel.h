//
// TuyaSmartFeedbackTalkListModel.h
// TuyaSmartFeedbackKit
//
// Copyright (c) 2014-2021 Tuya Inc (https://developer.tuya.com)

@interface TuyaSmartFeedbackTalkListModel : NSObject

/// The time of the feedback content.
@property (nonatomic, strong) NSString          *dateTime;

/// The ID of the feedback content.
@property (nonatomic, strong) NSString          *hdId;

/// The type of feedback content.
@property (nonatomic, assign) NSUInteger        hdType;

/// A string title for the feedback content.
@property (nonatomic, strong) NSString          *title;

/// The string content of the feedback content.
@property (nonatomic, strong) NSString          *content;

@end
