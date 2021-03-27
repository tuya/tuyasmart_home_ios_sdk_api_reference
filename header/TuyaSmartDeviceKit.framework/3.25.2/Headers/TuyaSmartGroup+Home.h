//
// TuyaSmartGroup+Home.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface TuyaSmartGroup (Home)

/// Creating Groups of Wifi Devices.
/// @param name The group name.
/// @param productId Product ID.
/// @param homeId Home ID.
/// @param devIdList DeviceId list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)createGroupWithName:(NSString *)name
                  productId:(NSString *)productId
                     homeId:(long long)homeId
                  devIdList:(NSArray<NSString *> *)devIdList
                    success:(nullable void (^)(TuyaSmartGroup *group))success
                    failure:(nullable TYFailureError)failure;


/// Create groups of zigBee devices.
/// @param name Group name.
/// @param homeId Home ID.
/// @param gwId Gateway ID.
/// @param productId Product ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)createGroupWithName:(NSString *)name
                     homeId:(long long)homeId
                       gwId:(NSString *)gwId
                  productId:(NSString *)productId
                    success:(nullable void (^)(TuyaSmartGroup *))success
                    failure:(nullable TYFailureError)failure;

/// Get a list of ZigBee sub devices for the corresponding support group based on productId and gwId.
/// @param productId Product ID.
/// @param gwId Gateway ID.
/// @param homeId Home ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)getDevListWithProductId:(NSString *)productId
                           gwId:(NSString *)gwId
                         homeId:(long long)homeId
                        success:(nullable void (^)(NSArray<TuyaSmartGroupDevListModel *> *))success
                        failure:(nullable TYFailureError)failure;

/// Get list of WiFi devices that support groups based on productId.
/// @param productId Product ID.
/// @param homeId Home ID.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
+ (void)getDevList:(NSString *)productId
            homeId:(long long)homeId
           success:(nullable void(^)(NSArray <TuyaSmartGroupDevListModel *> *list))success
           failure:(nullable TYFailureError)failure;


#if TARGET_OS_IOS

/// Add ZigBee devices to groups (interacting locally with gateways).
/// @param nodeList Zigbee sub-device nodeId list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addZigbeeDeviceWithNodeList:(NSArray <NSString *>*)nodeList
                            success:(nullable TYSuccessHandler)success
                            failure:(nullable TYFailureError)failure;


/// Remove ZigBee devices from groups (interacting locally with gateways).
/// @param nodeList Zigbee sub-device nodeId list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)removeZigbeeDeviceWithNodeList:(NSArray <NSString *>*)nodeList
                               success:(nullable TYSuccessHandler)success
                               failure:(nullable TYFailureError)failure;

#endif

@end

NS_ASSUME_NONNULL_END
