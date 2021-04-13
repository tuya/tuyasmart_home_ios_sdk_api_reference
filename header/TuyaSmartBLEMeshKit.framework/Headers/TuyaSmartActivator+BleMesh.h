//
// TuyaSmartActivator+BleMesh.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartActivatorKit/TuyaSmartActivatorKit.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief Mesh activator category for activator.
@interface TuyaSmartActivator (BleMesh)

/// WiFi connector adds mesh. Get distribution network token (valid for 10 minutes).
/// @param meshId The mesh ID.
/// @param nodeId The node ID.
/// @param productId The product ID.
/// @param uuid The device uuid.
/// @param authKey The authority key.
/// @param version Version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithMeshId:(NSString *)meshId
                    nodeId:(NSString *)nodeId
                 productId:(NSString *)productId
                      uuid:(NSString *)uuid
                   authKey:(NSString *)authKey
                   version:(NSString *)version
                   success:(TYSuccessString)success
                   failure:(TYFailureError)failure;

/// Mesh distribution network.
/// @param ssid Router hotspot name.
/// @param password Router hotspot password.
/// @param token Distribution network token.
/// @param timeout The timeout time is 100 seconds by default.
- (void)startBleMeshConfigWiFiWithSsid:(NSString *)ssid
                              password:(NSString *)password
                                 token:(NSString *)token
                               timeout:(NSTimeInterval)timeout;


@end

NS_ASSUME_NONNULL_END
