//
// TuyaSmartFeedbackModel.h
// TuyaSmartFeedbackKit
//
// Copyright (c) 2014-2021 Tuya Inc (https://developer.tuya.com)

/// The type of feedback. Valid values: question and answer.
typedef enum : NSUInteger {
    /// The question type of feedback.
    TuyaSmartFeedbackQuestion,
    /// The answer type of feedback.
    TuyaSmartFeedbackAnswer,
} TuyaSmartFeedbackType;

@interface TuyaSmartFeedbackModel : NSObject

/// The type of feedback.
@property (nonatomic, assign) TuyaSmartFeedbackType     type;

/// The time when the feedback is created.
@property (nonatomic, assign) NSTimeInterval            ctime;

/// The ID of the feedback ID.
@property (nonatomic, assign) NSUInteger                uniqueId;

/// The content of the feedback.
@property (nonatomic, strong) NSString                  *content;

@end
