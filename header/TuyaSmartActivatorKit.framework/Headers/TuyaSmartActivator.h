//
// TuyaSmartActivator.h
// TuyaSmartActivatorKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmart_TuyaSmartActivator
#define TuyaSmart_TuyaSmartActivator

#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

/// This notification is sent after a broadcast from a wired pairing device is received. The object is a dictionary, such as @{@"productId":productId, @"gwId":gwId}.
extern NSString *const TuyaSmartActivatorNotificationFindGatewayDevice;

/// The following pairing modes are supported: Wi-Fi Easy Connect (EZ), access point (AP), QR code, and wired.
typedef enum : NSUInteger {
    /// The EZ mode.
    TYActivatorModeEZ,
    /// The AP mode.
    TYActivatorModeAP,
    /// The QR code mode.
    TYActivatorModeQRCode,
    /// The wired mode.
    TYActivatorModeWired,
} TYActivatorMode;

/// The pairing procedure: 1. Scan for the device. 2. Register the device in the cloud. 3. Initialize the pairing parameters. 4. Set the pairing timeout value.
typedef enum : NSUInteger {
    /// Scan for the device.
    TYActivatorStepFound = 1,
    /// Register the device in the cloud.
    TYActivatorStepRegisted = 2,
    /// Initialize the device parameters.
    TYActivatorStepIntialized = 3,
    /// Set the pairing timeout value.
    TYActivatorStepTimeOut = 4, 
} TYActivatorStep;

@class TuyaSmartActivator;

@protocol TuyaSmartActivatorDelegate<NSObject>

@required

/// The callback of pairing status updates. A Wi-Fi single product, Zigbee gateways, and Zigbee sub-devices are supported.
/// @param activator The instance.
/// @param deviceModel The device model.
/// @param error An error occurs while processing the request.
- (void)activator:(TuyaSmartActivator *)activator didReceiveDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;

@optional

/// The callback of pairing status updates. A Wi-Fi single product, Zigbee gateways, and Zigbee sub-devices are supported.
/// @param activator The instance.
/// @param deviceModel The device model.
/// @param step One of the activation steps.
/// @param error An error occurs while processing the request.
- (void)activator:(TuyaSmartActivator *)activator didReceiveDevice:(TuyaSmartDeviceModel *)deviceModel step:(TYActivatorStep)step error:(NSError *)error;

/// The callback of pairing status updates for a mesh gateway. This method is deprecated.
/// @param activator The instance.
/// @param deviceId The device ID.
/// @param meshId The mesh ID.
/// @param error An error occurs while processing the request.
/// @deprecated This method is deprecated. Use TuyaSmartActivatorDelegate::activator:didReceiveDevice:error: instead. `deviceId` is set to the value of `deviceModel.devId`. `meshId` is set to the value of `deviceModel.parentId`.
- (void)meshActivator:(TuyaSmartActivator *)activator didReceiveDeviceId:(NSString *)deviceId meshId:(NSString *)meshId error:(NSError *)error __deprecated_msg("Use -[TuyaSmartActivatorDelegate activator:didReceiveDevice:error:] instead. `deviceId` is `deviceModel.devId`, `meshId` is `deviceModel.parentId`.");

@end

/// @brief TuyaSmartActivator is used for device pairing.
///
/// This class provides pairing capabilities for Wi-Fi and Zigbee devices. The following pairing modes are supported: EZ, AP, QR code, and wired.
///
///
@interface TuyaSmartActivator : NSObject

/// Returns a singleton instance of the class.
+ (instancetype)sharedInstance;

#pragma mark - SSID

/// Returns the service set identifier (SSID) of the current Wi-Fi network.
///
/// Starting with iOS 12, in the calls to this function, nil is returned by default. A valid value is returned only when the Access Wi-Fi Information capability is enabled in the Xcode project. This function must be activated with the app IDs on the Developers page before you can use this function.
/// Starting with iOS 13, at least one of the following prerequisites must be met.
///   - An app that has been granted the Location Services permissions.
///   - An enabled VPN application.
///   - The use of NEHotspotConfiguration. Only Wi-Fi networks that are configured in the app are supported.
///
/// @see https://developer.apple.com/videos/play/wwdc2019/713/
///
/// @return The Wi-Fi SSID.
+ (NSString *)currentWifiSSID;

/// Returns the basic service set identifiers (BSSID) of the current Wi-Fi network.
/// @see TuyaSmartActivator::currentWifiSSID.
/// @return The Wi-Fi BSSID.
+ (NSString *)currentWifiBSSID;

/// Asynchronously returns the SSID of the current Wi-Fi network.
/// @see TuyaSmartActivator::currentWifiSSID
/// @param success Called when the task is finished. TYSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)getSSID:(TYSuccessString)success
        failure:(TYFailureError)failure;

/// Asynchronously returns the BSSID of the current Wi-Fi network.
/// @param success Called when the task is finished. TYSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)getBSSID:(TYSuccessString)success
         failure:(TYFailureError)failure;

#pragma mark - Delegate

@property (nonatomic, weak) id<TuyaSmartActivatorDelegate> delegate;

#pragma mark - active gateway

/// Returns the pairing token by home ID. This token is valid for 10 minutes.
/// @param homeId The home ID.
/// @param success Called when the task is finished. TYSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithHomeId:(long long)homeId
                   success:(TYSuccessString)success
                   failure:(TYFailureError)failure;

/// Returns the pairing token by product ID. This token is valid for 10 minutes.
/// @param productKey The product ID.
/// @param homeId The home ID.
/// @param success Called when the task is finished. TYSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithProductKey:(NSString *)productKey
                        homeId:(long long)homeId
                       success:(TYSuccessString)success
                       failure:(TYFailureError)failure;

/// Returns the pairing token by UUID. This token is valid for 10 minutes.
/// @param uuid The device UUID.
/// @param homeId The home ID.
/// @param success Called when the task is finished. TYSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithUUID:(NSString *)uuid
                  homeId:(long long)homeId
                 success:(TYSuccessString)success
                 failure:(TYFailureError)failure;

/// Starts wireless pairing.
/// @param mode The pairing mode. Valid values: EZ and AP.
/// @param ssid The name of the router.
/// @param password The password of the router.
/// @param token The pairing token.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
- (void)startConfigWiFi:(TYActivatorMode)mode
                   ssid:(NSString *)ssid
               password:(NSString *)password
                  token:(NSString *)token
                timeout:(NSTimeInterval)timeout;

/// Starts wired pairing.
/// @param token The pairing token.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
- (void)startConfigWiFiWithToken:(NSString *)token timeout:(NSTimeInterval)timeout;

/// Starts wired pairing to activate only one category of devices.
/// @param token The pairing token.
/// @param productId The product ID of the device.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
- (void)startConfigWiFiWithToken:(NSString *)token
                       productId:(NSString *)productId
                         timeout:(NSTimeInterval)timeout;

/// Starts to pair multiple devices in EZ mode.
/// @param ssid The name of the router.
/// @param password The password of the router.
/// @param token The pairing token.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
- (void)startEZMultiConfigWiFiWithSsid:(NSString *)ssid
                              password:(NSString *)password
                                 token:(NSString *)token
                               timeout:(NSTimeInterval)timeout;

/// Stops the pairing process.
- (void)stopConfigWiFi;

#pragma mark - active sub device

/// Activates sub-devices, such as Zigbee or Wi-Fi sub-devices.
/// @param gwId     The gateway ID.
/// @param timeout  The timeout value. Unit: seconds. Default value: 100.
- (void)activeSubDeviceWithGwId:(NSString *)gwId timeout:(NSTimeInterval)timeout;

/// Stops activating sub-devices by gateway ID.
/// @param gwId The gateway ID.
- (void)stopActiveSubDeviceWithGwId:(NSString *)gwId;

@end

#endif
