//
// TYApiMergeModel.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

@interface TYApiMergeModel : NSObject


/// Success.
@property (nonatomic, assign) BOOL      success;


/// Api name.
@property (nonatomic, strong) NSString  *apiName;


/// Error.
@property (nonatomic, strong) NSError   *error;


/// Response result.
@property (nonatomic, strong) id        result;


/// Timestamp.
@property (nonatomic, assign) NSTimeInterval time;

@end
