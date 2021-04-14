//
//  TuyaSmartSocketWriteModel.h
//  Bolts
//
//  Created by XuChengcheng on 2019/3/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartSocketWriteModel : NSObject <NSCopying>

@property (nonatomic, strong) NSString          *gwId;
@property (nonatomic, assign) BOOL              encrypt;

@property (nonatomic, assign) int               index; // The sequence number.
@property (nonatomic, assign) int               type; // The protocol.
@property (nonatomic, strong) NSString          *lpv; // The version.
@property (nonatomic, strong) NSDictionary      *body; // The body.
@property (nonatomic, strong) NSString          *localKey; // The local key.
@property (nonatomic, strong) NSData            *data; // The data.
@property (nonatomic, strong) NSData            *localKeyData; // The local key.


@property (nonatomic, copy) TYSuccessDict       successBlock;
@property (nonatomic, copy) TYFailureError      failureErrorBlock;
@property (nonatomic, copy) TYFailureHandler    failureBlock;

// Encrypts data.
- (NSData *)buildRequestData;

- (NSDictionary *)attributes;

@end

NS_ASSUME_NONNULL_END
