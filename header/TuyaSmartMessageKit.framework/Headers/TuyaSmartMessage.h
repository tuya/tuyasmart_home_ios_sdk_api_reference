//
// TuyaSmartMessage.h
// TuyaSmartMessageKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartUtil/TuyaSmartUtil.h>
#import "TuyaSmartMessageListModel.h"
#import "TuyaSmartMessageRequestModel.h"

NS_ASSUME_NONNULL_BEGIN
/// @brief TuyaSmartMessage provides methods to implement message functionalities.
///
/// TuyaSmartMessage provides a message center and supports push functions. The messages are classified into the following categories: alert messages, home messages, and notifications. Each type of message can be enabled or disabled.
@interface TuyaSmartMessage : NSObject

/// Returns a list of messages.
/// @param listRequestModel Returns a list of TuyaSmartMessageListModel.
/// @param success Called when the task is finished. A list of TuyaSmartMessageListModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchMessageListWithListRequestModel:(TuyaSmartMessageListRequestModel *)listRequestModel
                                     success:(void (^)(NSArray<TuyaSmartMessageListModel *> *messageList))success
                                     failure:(TYFailureError)failure;

/// Returns a list of message details.
/// @param detailListRequestModel Returns a list of TuyaSmartMessageListModel.
/// @param success Called when the task is finished. A list of TuyaSmartMessageListModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchMessageDetailListWithListRequestModel:(TuyaSmartMessageDetailListRequestModel *)detailListRequestModel
                                           success:(void (^)(NSArray<TuyaSmartMessageListModel *> *messageList))success
                                           failure:(TYFailureError)failure;

/// Returns the latest messages of all types.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getLatestMessageWithSuccess:(TYSuccessDict)success failure:(TYFailureError)failure;

/// Sets and reads a list of data of the message center.
/// @param readRequestModel A list of read messages. All types of messages can be read.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)readMessageWithReadRequestModel:(TuyaSmartMessageListReadRequestModel *)readRequestModel success:(TYSuccessBOOL)success failure:(TYFailureError)failure;


/// Deletes a list of data from the message center.
/// @param deleteRequestModel A list of deleted messages. The deletion of all data is not supported.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)deleteMessageWithDeleteRequestModel:(TuyaSmartMessageListDeleteRequestModel *)deleteRequestModel success:(TYSuccessBOOL)success failure:(TYFailureError)failure;

/// Cancels the ongoing request.
- (void)cancelRequest;

@end
NS_ASSUME_NONNULL_END
