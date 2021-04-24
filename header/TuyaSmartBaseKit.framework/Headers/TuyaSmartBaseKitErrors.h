//
// TuyaSmartBaseKitErrors.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartBaseKitErrors_h
#define TuyaSmartBaseKitErrors_h

/*
 *  TYBaseKitError
 *
 *    Error returned as code to NSError from TuyaSmartBaseKit.
 */

extern NSString *const kTYBaseKitErrorDomain;

typedef NS_ENUM(NSInteger, TYBaseKitError) {
    /// The request error.
    kTYBaseKitErrorAPIRequestError                       = 2000,
    /// The response type is illegal.
    kTYBaseKitErrorAPIResponseDataTypeIllegal            = 2001,
    /// The response sign is inconsistent.
    kTYBaseKitErrorAPIResponseDataSignInconsistent       = 2002,
    /// The response decoding error.
    kTYBaseKitErrorAPIResponseDataDecodeError            = 2003,
    /// The network error.
    kTYBaseKitErrorNetworkError                          = 2004,
    
};

#endif /* TuyaSmartBaseKitErrors_h */
