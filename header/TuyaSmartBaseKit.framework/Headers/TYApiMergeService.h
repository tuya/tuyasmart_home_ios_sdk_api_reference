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


/// Add api request.
/// @param apiName Api name.
/// @param postData Post data.
/// @param version Version.
- (void)addApiRequest:(NSString *)apiName postData:(NSDictionary *)postData version:(NSString *)version;


/// Send request.
/// @param getData Get data.
/// @param success Called when the task finishes successfully. A list of TYApiMergeModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)sendRequest:(NSDictionary *)getData success:(nullable void (^)(NSArray <TYApiMergeModel *> *list))success failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
