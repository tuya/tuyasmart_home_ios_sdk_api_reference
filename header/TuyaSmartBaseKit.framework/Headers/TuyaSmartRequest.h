//
// TuyaSmartRequest.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartRequest
#define TuyaSmart_TuyaSmartRequest

#import <TuyaSmartUtil/TuyaSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief TuyaSmartRequest is used to call Tuya Cloud API operations.
///
/// The Tuya Cloud API (atop) operations are made from this class.
///
/// A request requires these parameters:
///   - The name of the API operation.
///   - The API version.
///   - The API parameters (aka postData). A serializable dictionary object.
///   - Common parameters (aka getData). A serializable dictionary object. Optional.
///
/// A response is returned with a `success` or `failure` callback.
/// A success callback returns an object based on the specific API operation.
/// An error callback returns an error object. For example, `error.userInfo[NSLocalizedFailureReasonErrorKey]` indicates Tuya error codes and `error.localizedDescription` indicates detailed reasons.
///
/// @warning The `error.localizedDescription` field is not recommended for display. We recommend that you process possible error types and customize the error messages.
///
@interface TuyaSmartRequest : NSObject

/// Calls API operations on the Tuya IoT Platform.
/// @param apiName The name of the API operation.
/// @param postData The API parameters.
/// @param version The API version.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)requestWithApiName:(NSString *)apiName
                  postData:(nullable NSDictionary *)postData
                   version:(NSString *)version
                   success:(nullable TYSuccessID)success
                   failure:(nullable TYFailureError)failure;


/// Calls API operations on the Tuya IoT Platform.
/// @param apiName The name of the API operation.
/// @param postData The API parameters.
/// @param getData Common parameters.
/// @param version The API version.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)requestWithApiName:(NSString *)apiName
                  postData:(nullable NSDictionary *)postData
                   getData:(nullable NSDictionary *)getData
                   version:(NSString *)version
                   success:(nullable TYSuccessID)success
                   failure:(nullable TYFailureError)failure;

/// Cancels the API request.
- (void)cancel;

/// Removes the network cache.
+ (void)removeAllCache;

@end


@interface TuyaSmartRequest (ApiMerge)

/// Calls multiple API operations in one request.
/// @param apiName The name of the API operation.
/// @param postData The API parameters.
/// @param version The API version.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addMergeRequestWithApiName:(NSString *)apiName
                          postData:(nullable NSDictionary *)postData
                           version:(NSString *)version
                           success:(nullable TYSuccessID)success
                           failure:(nullable TYFailureError)failure;


/// Sends a multi-operation request.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendMergeRequestWithSuccess:(nullable TYSuccessList)success
                            failure:(nullable TYFailureError)failure;


/// Sends a multi-operation request.
/// @param getData Common parameters.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendMergeRequestWithGetData:(nullable NSDictionary *)getData
                            success:(nullable TYSuccessList)success
                            failure:(nullable TYFailureError)failure;


/// Removes all multi-operation requests.
- (void)removeAllMergeRequest;

@end

@interface TuyaSmartRequest (Encryption)

/// Calls API operations on the Tuya IoT Platform with encrypted post data.
/// @param apiName The name of the API operation.
/// @param postData The API parameters.
/// @param version The API version.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)requestPostDataEncryptWithApiName:(NSString *)apiName
                                 postData:(nullable NSDictionary *)postData
                                  version:(NSString *)version
                                  success:(nullable TYSuccessID)success
                                  failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif
