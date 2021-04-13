//
// TuyaSmartBLEManager.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>
#import "TYBLEAdvModel.h"

typedef enum : NSUInteger {
    /// The firmware OTA type.
    TuyaSmartBLEOTATypeFirmware = 0,
    /// The MCU OTA type.
    TuyaSmartBLEOTATypeMCU,
} TuyaSmartBLEOTAType;

NS_ASSUME_NONNULL_BEGIN

@class TuyaSmartBLEManager;

/// Delegate for scanning and Bluetooth status change notification.
@protocol TuyaSmartBLEManagerDelegate <NSObject>

@optional

/// The notification for bluetooth status changing.
///
/// @param isPoweredOn      Bluetooth status, on or off
- (void)bluetoothDidUpdateState:(BOOL)isPoweredOn;

/// Disconnecting result from device.
///
/// @param devId        The device Id for the device.
/// @param error        The error for the disconnect.
- (void)onCentralDidDisconnectFromDevice:(NSString *)devId error:(NSError *)error;

/// Results of the scanning inactive devices.
///
/// @param uuid         The UUID for the device.
/// @param productKey   The product Id for the device.
/// @deprecated This method is deprecated, Use TuyaSmartBLEManager::didDiscoveryDeviceWithDeviceInfo: instead.
- (void)didDiscoveryDeviceWithUUID:(NSString *)uuid productKey:(NSString *)productKey __deprecated_msg("This method is deprecated, Use TuyaSmartBLEManager::didDiscoveryDeviceWithDeviceInfo: instead");

/// Results of the scanning inactive devices.
///
/// @param deviceInfo   The advertisingData model for the inactive device.
- (void)didDiscoveryDeviceWithDeviceInfo:(TYBLEAdvModel *)deviceInfo;

/// The result of the activator BLE devices.
///
/// @param manager          The class itself.
/// @param deviceModel      When activator successfully, this param will be called with DeviceModel.
/// @param error            This error will be called if some error occurred.
- (void)bleManager:(TuyaSmartBLEManager *)manager didFinishActivateDevice:(TuyaSmartDeviceModel *)deviceModel error:(NSError *)error;

/// Receive the transmission data from the device.
///
/// @param data     Transmission data receiving from the device.
/// @param devId    The device Id for the device.
- (void)bleReceiveTransparentData:(NSData *)data devId:(NSString *)devId;

@end

/// @brief TuyaSmartBLEManager provides methods for developers to activator, control or OTA BLE device.
///
/// The two types of OTA. Provides firmware and MCU types.
@interface TuyaSmartBLEManager : NSObject

/// Single instance.
+ (instancetype)sharedInstance;

/// A boolean value indicates whether the mobile phone's Bluetooth is on or off.
@property (nonatomic, assign, readonly) BOOL isPoweredOn;

/// Delegate for scanning and Bluetooth status change notification.
@property (nonatomic, weak) id<TuyaSmartBLEManagerDelegate> delegate;

/// Start listening broadcast package for BLE devices.
///
/// If an inactive device is scanned, the device info will be callback by `TuyaSmartBLEManagerDelegate::didDiscoveryDeviceWithDeviceInfo:`
///
/// If an active device is scanned, it will be automatically connected.
///
/// @param clearCache Whether to clean up the broadcast packets of scanned devices.
- (void)startListening:(BOOL)clearCache;

/// Stop listening broadcast package for BLE devices.
///
/// @param clearCache Whether to clean up the broadcast packets of scanned devices.
- (void)stopListening:(BOOL)clearCache;
 
/// Connect device
///
/// @param uuid         The UUID for the device.
/// @param productKey   The product Id for the device.
/// @param success      When connect successfully, this block will be called success.
/// @param failure      This block will be called if some error occurred.
- (void)connectBLEWithUUID:(NSString *)uuid
                productKey:(NSString *)productKey
                   success:(TYSuccessHandler)success
                   failure:(TYFailureHandler)failure;

/// Disconnect device
///
/// @param uuid         The UUID for the device.
/// @param success      When disconnect successfully, this block will be called success.
/// @param failure      This block will be called if some error occurred.
- (void)disconnectBLEWithUUID:(NSString *)uuid
                      success:(TYSuccessHandler)success
                      failure:(TYFailureError)failure;


/// Query device information before activator.
///
/// @param uuid         The UUID for the device.
/// @param productKey   The product Id for the device.
/// @param success      When query successfully, this block will be called with a string for device name.
/// @param failure      This block will be called if some error occurred.
///
/// @deprecated This method is deprecated, Use TuyaSmartBLEManager::queryDeviceInfoWithUUID:productKey:success:failure: instead.
- (void)queryNameWithUUID:(NSString *)uuid
               productKey:(NSString *)productKey
                  success:(void(^)(NSString *name))success
                  failure:(TYFailureError)failure __deprecated_msg("This method is deprecated, Use TuyaSmartBLEManager::queryDeviceInfoWithUUID:productKey:success:failure instead");

/// Query device information before activator
///
/// @param uuid         The UUID for the device.
/// @param productId    The product Id for the device.
/// @param success      When query successfully, this block will be called with a dictionary for device information.
/// @param failure      This block will be called if some error occurred.
- (void)queryDeviceInfoWithUUID:(NSString *)uuid
                      productId:(NSString *)productId
                        success:(TYSuccessDict)success
                        failure:(TYFailureError)failure;

/// Activator BLE device.
/// @param uuid The UUID for the device.
/// @param homeId The Id for the current home.
/// @param productKey The product Id for the device.
/// @param success When activator successfully, this block will be called with DeviceModel.
/// @param failure This block will be called if some error occurred.
/// @deprecated This method is deprecated, Use TuyaSmartBLEManager::activeBLE:homeId:success:failure: instead.
- (void)activeBLEWithUUID:(NSString *)uuid
                   homeId:(long long)homeId
               productKey:(NSString *)productKey
                  success:(void(^)(TuyaSmartDeviceModel *deviceModel))success
                  failure:(TYFailureHandler)failure __deprecated_msg("This method is deprecated, Use TuyaSmartBLEManager::activeBLE:homeId:success:failure instead");

/// Activator BLE device.
///
/// @param deviceInfo       The advertisingData model for the BLE device.
/// @param homeId           The Id for the current home.
/// @param success          When activator successfully, this block will be called with DeviceModel.
/// @param failure          This block will be called if some error occurred.
- (void)activeBLE:(TYBLEAdvModel *)deviceInfo
           homeId:(long long)homeId
          success:(void(^)(TuyaSmartDeviceModel *deviceModel))success
          failure:(TYFailureHandler)failure;

/// Publish the transmitted data.
///
/// @param devId        The device Id for the device.
/// @param data         Data to be transmitted to the device.
/// @param success      Transmission data returned by the device.
/// @param failure      This block will be called if some error occurred.
- (void)publishBleTransparentData:(NSString *)devId
                             data:(NSData *)data
                          success:(TYSuccessData)success
                          failure:(TYFailureError)failure;

/// Query device dp data by Bluetooth channel.
///
/// @param devId        The device Id for the device.
/// @param dpIds        Array of dpId's to be queried.
/// @param success      When query successfully, this block will be called.
/// @param failure      This block will be called if some error occurred.
- (void)publishQueryDpCommand:(NSString *)devId
                        dpIds:(NSArray *)dpIds
                      success:(TYSuccessBOOL)success
                      failure:(TYFailureError)failure;

/// Send OTA package to upgrade firmware.
///
/// The `otaData` can be obtained from TuyaSmartFirmwareUpgradeModel. You can get TuyaSmartFirmwareUpgradeModel by TuyaSmartDevice::getFirmwareUpgradeInfo:failure: .
///
/// @note Please make sure your device is connected via Bluetooth before upgrading.
///
/// @param uuid         The UUID for the device.
/// @param otaData      The OTA package data.
/// @param success      When ota successfully, this block will be called success.
/// @param failure      This block will be called if some error occurred.
///
/// @deprecated This method is deprecated, Use TuyaSmartBLEManager::sendOTAPack:pid:otaData:otaType:otaVersion:success:failure: instead.
- (void)sendOTAPack:(NSString *)uuid
            otaData:(NSData *)otaData
            success:(TYSuccessHandler)success
            failure:(TYFailureHandler)failure __deprecated_msg("This method is deprecated, Use TuyaSmartBLEManager::sendOTAPack:pid:otaData:otaType:success:failure instead");

/// Send OTA package to upgrade firmware.
///
/// The `otaData` can be obtained from TuyaSmartFirmwareUpgradeModel. You can get TuyaSmartFirmwareUpgradeModel by TuyaSmartDevice::getFirmwareUpgradeInfo:failure: .
///
/// @note Please make sure your device is connected via Bluetooth before upgrading.
///
/// @param uuid         The UUID for the device.
/// @param pid          The product Id for the device.
/// @param otaData      The OTA package data.
/// @param success      When ota successfully, this block will be called success.
/// @param failure      This block will be called if some error occurred.
///
/// @deprecated This method is deprecated, Use TuyaSmartBLEManager::sendOTAPack:pid:otaData:otaType:otaVersion:success:failure: instead.
- (void)sendOTAPack:(NSString *)uuid
                pid:(NSString *)pid
            otaData:(NSData *)otaData
            success:(TYSuccessHandler)success
            failure:(TYFailureHandler)failure __deprecated_msg("This method is deprecated, Use TuyaSmartBLEManager::sendOTAPack:pid:otaData:otaType:otaVersion:success:failure instead");

/// Send OTA package to upgrade firmware.
///
/// The `otaData`、`otaType` and `otaVersion` can be obtained from TuyaSmartFirmwareUpgradeModel. You can get TuyaSmartFirmwareUpgradeModel by TuyaSmartDevice::getFirmwareUpgradeInfo:failure: .
///
/// @note Please make sure your device is connected via Bluetooth before upgrading.
///
/// @param uuid         The UUID for the device.
/// @param pid          The product Id for the device.
/// @param otaData      The OTA package data.
/// @param otaType      The OTA type.
/// @param otaVersion   The OTA version.
/// @param success      When ota successfully, this block will be called success.
/// @param failure      This block will be called if some error occurred.
- (void)sendOTAPack:(NSString *)uuid
                pid:(NSString *)pid
            otaData:(NSData *)otaData
            otaType:(TuyaSmartBLEOTAType)otaType
         otaVersion:(NSString *)otaVersion
            success:(TYSuccessHandler)success
            failure:(TYFailureHandler)failure;

/// Get the RSSI of the BLE device
///
/// @param uuid        The UUID for the device.
///
/// @return The RSSI of the BLE device
- (NSInteger)getPeripheralRSSI:(NSString *)uuid;

/// Get the local connection status of the BLE device by device UUID
///
/// @param uuid        The UUID for the device.
///
/// @return The local connection status of the BLE device
- (BOOL)deviceStatueWithUUID:(NSString *)uuid;

/// Sending parameters data to the BLE device, whilc make device report data through big data channels.
/// 
/// @param devId        The device Id for the device.
/// @param paramsDict   A dictionary of parameter, defined by the protocol party.
/// @param success      When ota successfully, this block will be called success.
/// @param failure      This block will be called if some error occurred.
- (void)postBleBigDataChannel:(NSString *)devId params:(NSDictionary *)paramsDict success:(TYSuccessHandler)success failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
