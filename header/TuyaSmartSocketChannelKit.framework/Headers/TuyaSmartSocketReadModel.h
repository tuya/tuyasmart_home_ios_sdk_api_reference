//
//  TuyaSmartSocketReadModel.h
//  Bolts
//
//  Created by XuChengcheng on 2019/3/13.
//

#import <Foundation/Foundation.h>

//NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartSocketReadModel : NSObject <NSCopying>

@property (nonatomic, assign) int               index; // The sequence number.
@property (nonatomic, assign) int               type; // The protocol.
@property (nonatomic, assign) int               code; // The success code.
@property (nonatomic, strong) NSDictionary      *body; // The message.
@property (nonatomic, strong) NSString          *error; // The error reason.
@property (nonatomic, strong) NSData            *data;

// Decrypts TCP data.
+ (NSArray <TuyaSmartSocketReadModel *> *)tcpResponseWithData:(NSData *)data gwId:(NSString *)gwId lpv:(NSString *)lpv localKey:(NSString *)localKey localKeyData:(NSData *)localKeyData;

// Decrypts UDP data.
+ (NSArray <TuyaSmartSocketReadModel *> *)udpResponseWithData:(NSData *)data;

- (NSDictionary *)attribute;

@end

//NS_ASSUME_NONNULL_END
