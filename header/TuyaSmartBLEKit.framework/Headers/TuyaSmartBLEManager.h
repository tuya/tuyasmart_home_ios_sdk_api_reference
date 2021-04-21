//
// TuyaSmartBLEManager.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>
#import "TYBLEAdvModel.h"

typedef enum : NSUInteger {
    /// The firmware OTA update type.
    TuyaSmartBLEOTATypeFirmware = 0,
    /// The MCU OTA update type.
    TuyaSmartBLEOTATypeMCU,
} TuyaSmartBLEOTAType;

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartBLEManager;

/// The delegate for scanning and notifications of Bluetooth status changes.
@protocol TuyaSmartBLEManagerDelegate <NSObject>

@optional

/// The notification for Bluetooth status changes.
///
/// @param isPoweredOn      Indicates the Bluetooth status. Valid values: `on` and `off`.
- (void)bluetoothDidUpdateState:(BOOL)isPoweredOn;

/// The result of disconnecting the device.
///
/// @param devId        The device ID.
/// @param error        An error occurs while processing the request.
- (void)onCentralDidDisconnectFromDevice:(NSString *)devId error:(NSError *)error;

/// The result of scanning inactive devices.
///
/// @param uuid         The device UUID.
/// @param productKey   The product ID for the device.
/// @deprecated This method is deprecated. Use TuyaSmartBLEManager::didDiscoveryDeviceWithDeviceInfo: instead.
- (void)didDiscoveryDeviceWithUUID:(NSString *)uuid productKey:(NSString *)productKey __deprecated_msg("This method is deprecated. Use TuyaSmartBLEManager::didDiscoveryDeviceWithDeviceInfo: instead");

/// The result of scanning inactive devices.
///
/// @param deviceInfo   The advertisingData model for the inactive device.
- (void)didDiscoveryDeviceWithDeviceInfo:(TYBLEAdvModel *)deviceInfo;

/// The result of activating Bluetooth LE devices.
///
/// @param manager          The class.
/// @param deviceModel      When the activation is successful, this block is called with DeviceModel.
/// @param error            If an error occurs, this block is called.
- (void)bleManager:(TuyaSmartBLEManager *)manager didFinishActivateDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;

/// Receives the transmission data from the device.
///
/// @param data     Transmission data that is sent by the device.
/// @param devId    The device ID.
- (void)bleReceiveTransparentData:(NSData *)data devId:(NSString *)devId;

@end

/// @brief TuyaSmartBLEManager provides methods to manage Bluetooth LE devices by using multiple functions, such as activation, device control, and OTA updates.
///
/// The types of OTA updates: firmware and MCU.
@interface TuyaSmartBLEManager : NSObject

/// The single instance.
+ (instancetype)sharedInstance;

/// A boolean value that indicates whether the mobile phone's Bluetooth is enabled or disabled.
@property (nonatomic, assign, readonly) BOOL isPoweredOn;

/// The delegate for scanning and notifications of Bluetooth status changes.
@property (nonatomic, weak) id<TuyaSmartBLEManagerDelegate> delegate;

/// Starts listening for broadcast packages for Bluetooth LE devices.
///
/// If an inactive device is scanned, the device information is returned by `TuyaSmartBLEManagerDelegate::didDiscoveryDeviceWithDeviceInfo:`.
///
/// If an active device is scanned, the device is automatically connected.
///
/// @param clearCache Specifies whether to clean up the broadcast packets of scanned devices.
- (void)startListening:(BOOL)clearCache;

/// Stop listening for broadcast packages for BLE devices.
///
/// @param clearCache Specifies whether to clean up the broadcast packets of scanned devices.
- (void)stopListening:(BOOL)clearCache;
 
/// Connects to a device.
///
/// @param uuid         The UUID of the device.
/// @param productKey   The product ID of the device.
/// @param success      After the device is connected, this block is called.
/// @param failure      If an error occurs, this block is called.
- (void)connectBLEWithUUID:(NSString *)uuid
                productKey:(NSString *)productKey
                   success:(TYSuccessHandler)success
                   failure:(TYFailureHandler)failure;

/// Disconnects a device.
///
/// @param uuid         The UUID of the device.
/// @param success      After the device is disconnected, this block is called.
/// @param failure      If an error occurs, this block is called.
- (void)disconnectBLEWithUUID:(NSString *)uuid
                      success:(TYSuccessHandler)success
                      failure:(TYFailureError)failure;


/// Queries the device information before the activation.
///
/// @param uuid         The UUID of the device.
/// @param productKey   The product ID for the device.
/// @param success      When the query is successful, this block is called with the device name string.
/// @param failure      If an error occurs, this block is called.
///
/// @deprecated This method is deprecated. Use TuyaSmartBLEManager::queryDeviceInfoWithUUID:productKey:success:failure: instead.
- (void)queryNameWithUUID:(NSString *)uuid
               productKey:(NSString *)productKey
                  success:(void(^)(NSString *name))success
                  failure:(TYFailureError)failure __deprecated_msg("This method is deprecated. Use TuyaSmartBLEManager::queryDeviceInfoWithUUID:productKey:success:failure instead");

/// Queries the device information before activation
///
/// @param uuid         The UUID of the device.
/// @param productId    The product ID for the device.
/// @param success      When the query is successful, this block is called with a dictionary of device information.
/// @param failure      If an error occurs, this block is called.
- (void)queryDeviceInfoWithUUID:(NSString *)uuid
                      productId:(NSString *)productId
                        success:(TYSuccessDict)success
                        failure:(TYFailureError)failure;

/// Activates the Bluetooth LE device.
/// @param uuid The UUID of the device.
/// @param homeId The ID of the current home.
/// @param productKey The product ID of the device.
/// @param success When the activation is successful, this block is called with DeviceModel.
/// @param failure If an error occurs, this block is called.
/// @deprecated This method is deprecated. Use TuyaSmartBLEManager::activeBLE:homeId:success:failure: instead.
- (void)activeBLEWithUUID:(NSString *)uuid
                   homeId:(long long)homeId
               productKey:(NSString *)productKey
                  success:(void(^)(TuyaSmartDeviceModel *deviceModel))success
                  failure:(TYFailureHandler)failure __deprecated_msg("This method is deprecated. Use TuyaSmartBLEManager::activeBLE:homeId:success:failure instead");

/// Activates the Bluetooth LE device.
///
/// @param deviceInfo       The advertisingData model for the Bluetooth LE device.
/// @param homeId           The ID for the current home.
/// @param success          When the activation is successful, this block is called with DeviceModel.
/// @param failure          If an error occurs, this block is called.
- (void)activeBLE:(TYBLEAdvModel *)deviceInfo
           homeId:(long long)homeId
          success:(void(^)(TuyaSmartDeviceModel *deviceModel))success
          failure:(TYFailureHandler)failure;

/// Publishes the transmitted data.
///
/// @param devId        The device ID.
/// @param data         The data to be transmitted to the device.
/// @param success      The data that is returned by the device.
/// @param failure      If an error occurs, this block is called.
- (void)publishBleTransparentData:(NSString *)devId
                             data:(NSData *)data
                          success:(TYSuccessData)success
                          failure:(TYFailureError)failure;

/// Queries the device DP data through Bluetooth channels.
///
/// @param devId        The device ID.
/// @param dpIds        The array of DP IDs to be queried.
/// @param success      When the query is successful, this block is called.
/// @param failure      If an error occurs, this block is called.
- (void)publishQueryDpCommand:(NSString *)devId
                        dpIds:(NSArray *)dpIds
                      success:(TYSuccessBOOL)success
                      failure:(TYFailureError)failure;

/// Sends an OTA package to update the firmware.
///
/// The value of `otaData` can be obtained from TuyaSmartFirmwareUpgradeModel. You can get TuyaSmartFirmwareUpgradeModel by using TuyaSmartDevice::getFirmwareUpgradeInfo:failure:.
///
/// @note Your device must be connected over Bluetooth before the update.
///
/// @param uuid         The UUID of the device.
/// @param otaData      The OTA package data.
/// @param success      When the OTA update is successful, this block is called.
/// @param failure      If an error occurs, this block is called.
///
/// @deprecated This method is deprecated. Use TuyaSmartBLEManager::sendOTAPack:pid:otaData:otaType:otaVersion:success:failure: instead.
- (void)sendOTAPack:(NSString *)uuid
            otaData:(NSData *)otaData
            success:(TYSuccessHandler)success
            failure:(TYFailureHandler)failure __deprecated_msg("This method is deprecated. Use TuyaSmartBLEManager::sendOTAPack:pid:otaData:otaType:success:failure instead");

/// Sends an OTA package to update the firmware.
///
/// The value of `otaData` can be obtained from TuyaSmartFirmwareUpgradeModel. You can get TuyaSmartFirmwareUpgradeModel by using TuyaSmartDevice::getFirmwareUpgradeInfo:failure:.
///
/// @note Your device must be connected over Bluetooth before the update.
///
/// @param uuid         The UUID of the device.
/// @param pid          The product ID of the device.
/// @param otaData      The OTA package data.
/// @param success      When the OTA update is successful, this block is called.
/// @param failure      If an error occurs, this block is called.
///
/// @deprecated This method is deprecated. Use TuyaSmartBLEManager::sendOTAPack:pid:otaData:otaType:otaVersion:success:failure: instead.
- (void)sendOTAPack:(NSString *)uuid
                pid:(NSString *)pid
            otaData:(NSData *)otaData
            success:(TYSuccessHandler)success
            failure:(TYFailureHandler)failure __deprecated_msg("This method is deprecated. Use TuyaSmartBLEManager::sendOTAPack:pid:otaData:otaType:otaVersion:success:failure instead");

/// Sends an OTA package to update the firmware.
///
/// The values of `otaData`, `otaType`, and `otaVersion` can be obtained from TuyaSmartFirmwareUpgradeModel. You can get TuyaSmartFirmwareUpgradeModel by using TuyaSmartDevice::getFirmwareUpgradeInfo:failure:.
///
/// @note Your device must be connected over Bluetooth before the update.
///
/// @param uuid         The UUID of the device.
/// @param pid          The product ID of the device.
/// @param otaData      The OTA package data.
/// @param otaType      The OTA update type.
/// @param otaVersion   The OTA version.
/// @param success      When the OTA update is successful, this block is called.
/// @param failure      If an error occurs, this block is called.
- (void)sendOTAPack:(NSString *)uuid
                pid:(NSString *)pid
            otaData:(NSData *)otaData
            otaType:(TuyaSmartBLEOTAType)otaType
         otaVersion:(NSString *)otaVersion
            success:(TYSuccessHandler)success
            failure:(TYFailureHandler)failure;

/// Returns the RSSI value of the Bluetooth LE device.
///
/// @param uuid        The UUID of the device.
///
/// @return The RSSI value of the Bluetooth LE device.
- (NSInteger)getPeripheralRSSI:(NSString *)uuid;

/// Returns the local connection status of the Bluetooth LE device by device UUID.
///
/// @param uuid        The UUID of the device.
///
/// @return The local connection status of the Bluetooth LE device.
- (BOOL)deviceStatueWithUUID:(NSString *)uuid;

/// Sends request parameters to the Bluetooth LE device. Then, the device reports data through big data channels.
/// 
/// @param devId        The device ID.
/// @param paramsDict   A dictionary of parameters that are defined by the protocol party.
/// @param success      When the OTA update is successful, this block is called.
/// @param failure      If an error occurs, this block is called.
- (void)postBleBigDataChannel:(NSString *)devId params:(NSDictionary *)paramsDict success:(TYSuccessHandler)success failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
