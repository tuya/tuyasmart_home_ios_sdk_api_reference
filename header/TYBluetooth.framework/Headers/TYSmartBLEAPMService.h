//
//  TYSmartBLEAPMService.h
//  Bolts
//
//  Created by 温明妍 on 2019/9/2.
//

#import <Foundation/Foundation.h>
#import "TYSmartBLEAPMMessageModel.h"
#import "TYSmartBLEAPMEnum.h"

// Reconnection
#define TY_LOG_EVENT_BLE_RECONNECTION                   @"af66d2469918c8d55dc6346598fd7d4f"  // 重连埋点事件编码

#define TY_RECONNECT_LOG_TYPE_BLE_SUCCESS               @"ble_log_connect_success"  // 第一次直接连接成功
#define TY_RECONNECT_LOG_TYPE_BLE_RETRY_SUCCESS         @"ble_log_reconnect_success"  // 通过重连成功
#define TY_RECONNECT_LOG_TYPE_BLE_FAILURE               @"ble_log_reconnect_failure"  // 连接失败

@interface TYSmartBLEAPMService : NSObject

+ (instancetype)sharedInstance;

- (void)putBLEAPMInDevId:(NSString *)devId type:(TYSmartBLEAPMType)type des:(NSString *)des dps:(NSDictionary *)dps extInfo:(NSDictionary *)extInfo;
 
- (void)putBLEAPMWithMessageModel:(TYSmartBLEAPMMessageModel *)messageModel;

- (void)logReconnectEvent:(NSString *)type reconnectCount:(NSInteger)reconnectCount;

@end
