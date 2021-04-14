//
//  TuyaSmartMQTTChannel.h
//  TuyaSmart
//
//  Created by xucheng on 15/5/30.
//  Copyright (c) 2015年 Tuya. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuyaSmartMQTTConfigModel.h"

@interface TuyaSmartPublishMessageModel : NSObject

@property (nonatomic, strong) NSString          *devId;

@property (nonatomic, assign) NSTimeInterval    time; // The timestamp.
@property (nonatomic, assign) NSInteger         protocol; // The protocol.
@property (nonatomic, assign) double            pv; // The version.
@property (nonatomic, strong) NSDictionary      *body; // The body.
@property (nonatomic, strong) NSString          *localKey; // The local key.
@property (nonatomic, assign) NSInteger         publishS;// The sequence.
@property (nonatomic, assign) NSInteger         publishR;// The publishing ID.

@end

@interface TuyaSmartResponseMessageModel : NSObject

@property (nonatomic, strong) NSString          *devId;
@property (nonatomic, strong) id                message;  // The mesh array.
@property (nonatomic, assign) NSInteger         protocol; // The protocol.
@property (nonatomic, strong) NSString          *type;
@property (nonatomic, assign) NSInteger         responseS;// The sequence.
@property (nonatomic, assign) NSInteger         responseR;// The response ID.
@property (nonatomic, assign) NSTimeInterval    time;

@end

@class TuyaSmartMQTTChannel;

/**
 The MQTT connection state.
 */
typedef NS_ENUM (NSInteger, TuyaSmartMqttConnectState){
    TuyaSmartMqttConnectStateCreated,
    TuyaSmartMqttConnectStateConnecting,
    TuyaSmartMqttConnectStateConnected,
    TuyaSmartMqttConnectStateDisconnecting,
    TuyaSmartMqttConnectStateClose,
    TuyaSmartMqttConnectStateError,
};

@protocol TuyaSmartMQTTChannelDelegate <NSObject>

@optional

/**
 *  The callback of changes in MQTT connection channel states.
 */
- (void)mqttChannel:(TuyaSmartMQTTChannel *)mqttChannel connectState:(TuyaSmartMqttConnectState)connectState error:(NSError *)error;

/**
 *  Receives the MTQQ data.
 */
- (void)mqttChannel:(TuyaSmartMQTTChannel *)mqttChannel didReceiveMessage:(TuyaSmartResponseMessageModel *)message topic:(NSString *)topic;

@end


@interface TuyaSmartMQTTChannel : NSObject

+ (instancetype)sharedInstance;

/**
 *  Connects to the MQTT host.
 *
 *  @param mqttConfig mqttConfig
 */
- (void)startConnectToHostWithMqttConfig:(TuyaSmartMQTTConfigModel *)mqttConfig;

/**
 *  Disconnects from the MQTT host.
 */
- (void)close;

/**
 *  The MQTT connection state.
 */
- (TuyaSmartMqttConnectState)connectState;

/**
 *  Subscribes to a topic.
 *
 *  @param topic   The topic.
 *  @param success The success block.
 *  @param failure The failure block.
 */
- (void)subscribeToTopic:(NSString *)topic
                 devInfo:(NSDictionary *)devInfo
                 success:(TYSuccessHandler)success
                 failure:(TYFailureError)failure;

/**
 *  Unsubscribes from a topic.
 *
 *  @param topic   The topic.
 *  @param success The success block.
 *  @param failure The failure block.
 */
- (void)unsubscribeToTopic:(NSString *)topic
                   success:(TYSuccessHandler)success
                   failure:(TYFailureError)failure;

/**
 *  Publishes the MQTT data.
 *
 *  @param data    The data.
 *  @param topic   The topic.
 *  @param success The success block.
 *  @param failure The failure block.
 *  @return The message identifier of the published message. Zero if qos 0. If qos 1 or 2, zero was publish faliure
 */
- (UInt16)publishMessage:(NSData *)data
                   topic:(NSString *)topic
                 success:(TYSuccessHandler)success
                 failure:(TYFailureError)failure;

/**
 *  Publishes MQTT data.
 *
 *  @param messageModel The message model.
 *  @param topic        The topic.
 *  @param success      The success block.
 *  @param failure      The failure block.
 */
- (void)publishMessageWithMessageModel:(TuyaSmartPublishMessageModel *)messageModel
                                 topic:(NSString *)topic
                               success:(TYSuccessHandler)success
                               failure:(TYFailureError)failure;

/**
 *  Adds mqtt channel delegate
 *  添加mqtt长连接的代理
 *
 *  @param delegate Delegate
 */
- (void)addDelegate:(id<TuyaSmartMQTTChannelDelegate>)delegate;

/**
 *  remove mqtt channel delegate
 *  删除mqtt长连接的代理
 *
 *  @param delegate Delegate
 */
- (void)removeDelegate:(id<TuyaSmartMQTTChannelDelegate>)delegate;

@end
