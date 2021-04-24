//
//  TuyaSmartSceneExprModel.h
//  TuyaSmartSceneKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

/// @brief The expression model of the scene. Any type of expression model is supported.
@interface TuyaSmartSceneExprModel : NSObject

/// Stores the expression data. Any type of expression is supported.
@property (nonatomic, strong) NSArray *expr;

@end

