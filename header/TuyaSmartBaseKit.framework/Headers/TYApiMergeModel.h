//
// TYApiMergeModel.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

@interface TYApiMergeModel : NSObject


/// Indicates a successful call.
@property (nonatomic, assign) BOOL      success;


/// The name of the API operation.
@property (nonatomic, strong) NSString  *apiName;


/// The error.
@property (nonatomic, strong) NSError   *error;


/// The response result.
@property (nonatomic, strong) id        result;


/// The timestamp.
@property (nonatomic, assign) NSTimeInterval time;

@end
