//
// TYApiMergeService.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TYApiMergeModel.h"
#import "TuyaSmartRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface TYApiMergeService : TuyaSmartRequest

@property (nonatomic, strong) TYSDKSafeMutableArray *requestList;


/// Adds an API request.
/// @param apiName The name of the API operation.
/// @param postData The Post data.
/// @param version The version.
- (void)addApiRequest:(NSString *)apiName postData:(NSDictionary *)postData version:(NSString *)version;


/// Sends a request.
/// @param getData Returns data.
/// @param success Called when the task is finished. A list of TYApiMergeModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)sendRequest:(NSDictionary *)getData success:(nullable void (^)(NSArray <TYApiMergeModel *> *list))success failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
