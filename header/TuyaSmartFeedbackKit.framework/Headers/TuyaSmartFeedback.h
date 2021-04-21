//
// TuyaSmartFeedback.h
// TuyaSmartFeedbackKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartUtil/TuyaSmartUtil.h>
#import "TuyaSmartFeedbackTalkListModel.h"
#import "TuyaSmartFeedbackModel.h"
#import "TuyaSmartFeedbackTypeListModel.h"

/// @brief TuyaSmartFeedback provides methods to implement feedback functionalities.
///
/// If a problem is found, the feedback on the problem can be submitted. Procedure: 1. Select a type of feedback. 2. Write the content of the feedback. 3. Submit the feedback.
///
/// All functions related to the feedback can be implemented with the TuyaSmartFeedback class. The following functions are supported:
///
/// - TuyaSmartFeedback::getFeedbackTalkList:failure: returns a list of feedback sessions.
/// - TuyaSmartFeedback::getFeedbackList:hdType:success:failure: returns a list of feedback contents in a session.
/// - TuyaSmartFeedback::getFeedbackTypeList:failure: returns a list of feedback types.
/// - Adds feedback.
@interface TuyaSmartFeedback : NSObject

/// Returns a list of sessions on which users have submitted feedback.
///
/// @param success      Called when the task is finished. A list of feedback sessions is returned.
/// @param failure      Called when the task is interrupted by an error. TYFailureError is returned.
- (void)getFeedbackTalkList:(void (^)(NSArray<TuyaSmartFeedbackTalkListModel *> *list))success
                    failure:(TYFailureError)failure;


/// Returns a list of feedback content in a feedback session. The values of `hdId` and `hdType` are returned from TuyaSmartFeedbackTalkListModel.
///
/// @param hdId         The ID of the feedback.
/// @param hdType       The type of feedback.
/// @param success      Called when the task is finished. A list of feedback is returned.
/// @param failure      Called when the task is interrupted by an error. TYFailureError is returned.
- (void)getFeedbackList:(NSString *)hdId
                 hdType:(NSUInteger)hdType
                success:(void (^)(NSArray<TuyaSmartFeedbackModel *> *list))success
                failure:(TYFailureError)failure;


/// Returns a list of feedback types. To add feedback, select a type of feedback first.
///
/// @param success      Called when the task is finished. TuyaSmartFeedbackTypeListModel is returned.
/// @param failure      Called when the task is interrupted by an error. TYFailureError is returned.
- (void)getFeedbackTypeList:(void (^)(NSArray<TuyaSmartFeedbackTypeListModel *> *list))success
                    failure:(TYFailureError)failure;


/// Adds feedback and submits the specified content in the feedback.
///
/// The values of `hdId` and `hdType` are returned from TuyaSmartFeedbackTalkListModel.
///
/// @note We recommend that you make this API request to submit feedback on issues about apps and devices that do not require strong bindings.
///
/// @param content      The content of the feedback.
/// @param hdId         The ID of the feedback.
/// @param hdType       The type of feedback.
/// @param contact      The contact information.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)addFeedback:(NSString *)content
               hdId:(NSString *)hdId
             hdType:(NSUInteger)hdType
            contact:(NSString *)contact
            success:(TYSuccessHandler)success
            failure:(TYFailureError)failure;


/// Adds feedback and submits the content of the feedback.
///
/// The values of `hdId` and `hdType` can be returned from TuyaSmartFeedbackTalkListModel.
///
/// @note We recommend that you make this API request to submit feedback on issues about devices that require strong bindings.
///
/// @param content      The content of the feedback.
/// @param hdId         The ID of the feedback.
/// @param hdType       The type of feedback.
/// @param contact      The contact information.
/// @param uuid         The UUID for the device.
/// @param region       The region of the user.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)addFeedback:(NSString *)content
               hdId:(NSString *)hdId
             hdType:(NSUInteger)hdType
            contact:(NSString *)contact
               uuid:(NSString *)uuid
             region:(NSString *)region
            success:(TYSuccessHandler)success
            failure:(TYFailureError)failure;


/// Cancels an ongoing request.
- (void)cancelRequest;

@end
