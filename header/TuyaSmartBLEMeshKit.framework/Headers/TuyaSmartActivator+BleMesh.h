//
// TuyaSmartActivator+BleMesh.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartActivatorKit/TuyaSmartActivatorKit.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief Mesh activator category for activator.=====The mesh activator category.
@interface TuyaSmartActivator (BleMesh)

/// WiFi connector adds mesh. Get distribution network token (valid for 10 minutes).=====Adds a Wi-Fi connector to a mesh network and returns a pairing token that is valid for 10 minutes.
/// @param meshId The mesh ID.
/// @param nodeId The node ID.
/// @param productId The product ID.
/// @param uuid The device UUID.
/// @param authKey The authorization key.
/// @param version The version.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithMeshId:(NSString *)meshId
                    nodeId:(NSString *)nodeId
                 productId:(NSString *)productId
                      uuid:(NSString *)uuid
                   authKey:(NSString *)authKey
                   version:(NSString *)version
                   success:(TYSuccessString)success
                   failure:(TYFailureError)failure;

/// Mesh distribution network.======Connects to a mesh device.
/// @param ssid The router hotspot name.
/// @param password The router hotspot password.
/// @param token The pairing token.
/// @param timeout The timeout time is 100 seconds by default.
- (void)startBleMeshConfigWiFiWithSsid:(NSString *)ssid
                              password:(NSString *)password
                                 token:(NSString *)token
                               timeout:(NSTimeInterval)timeout;


@end

NS_ASSUME_NONNULL_END
