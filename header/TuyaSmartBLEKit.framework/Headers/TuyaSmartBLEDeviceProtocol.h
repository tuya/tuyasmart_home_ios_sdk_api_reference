//
// TuyaSmartBLEDeviceProtocol.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TYBluetooth/TYBluetooth.h>
#import "TuyaSmartBLEDeviceProtocol.h"
#import "TuyaSmartBLEManager.h"

@class TYBLEScan;
@class TYBLEAgent;
@protocol TuyaSmartBLEDeviceProtocol;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Scan Protocol

/// @brief TuyaSmartBLEDeviceProtocol provides protocol methods for developers to implement activator, control or OTA and others by itself protocol.
@protocol TuyaSmartBLEScanProtocol <NSObject>

typedef void(^TYBLEScanResultHandher)(id<TuyaSmartBLEDeviceProtocol> deviceInfo);

/// Results of the scanning inactive devices.
///
/// @param agent        Scan agent.
/// @param scan         Scan class itself.
/// @param peripheral   Scanned Bluetooth peripheral.
/// @param error        Scan Error.
/// @param handler      Scan callback.
- (void)bleAgent:(TYBLEAgent *)agent bleScan:(TYBLEScan *)scan didScanBLEDevicePeripheral:(TYBLEPeripheral *)peripheral error:(NSError *)error scanResultHandher:(TYBLEScanResultHandher)handler;

@end

#pragma mark -------------------------------------------------------------


#pragma mark - Active Protocol

@protocol TuyaSmartBLEActiveProtocol <NSObject>

/// Activator BLE device.
///
/// @param deviceInfo       The advertisingData model for the BLE device.
/// @param homeId           The Id for the current home.
/// @param success          When activator successfully, this block will be called with DeviceModel.
/// @param failure          This block will be called if some error occurred.
- (void)startActiveWithDevice:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                       homeId:(long long)homeId
                      success:(void(^)(TuyaSmartDeviceModel *deviceModel))success
                      failure:(TYFailureError)failure;

@end

#pragma mark -------------------------------------------------------------


#pragma mark - Config Protocol

@protocol TuyaSmartBLEConfigProtocol <NSObject>

/// Dp command publish.
///
/// @param deviceInfo   Tuya BEL protocol-based device object.
/// @param dps          The dp dictionary.
/// @param success      When query successfully, this block will be called.
/// @param failure      This block will be called if some error occurred.
- (void)publishDpsWithDeviceInfo:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                             dps:(NSDictionary *)dps
                             success:(TYSuccessHandler)success
                             failure:(TYFailureError)failure;

/// Query device dp data by Bluetooth channel.
///
/// @param deviceInfo   Tuya BEL protocol-based device object.
/// @param dpIds        Array of dpId's to be queried.
/// @param success      When query successfully, this block will be called.
/// @param failure      This block will be called if some error occurred.
- (void)publishQueryDpCommand:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                        dpIds:(NSArray *)dpIds
                      success:(TYSuccessHandler)success
                      failure:(TYFailureError)failure;

/// Connect device
///
/// @param deviceInfo   Tuya BEL protocol-based device object.
/// @param success      When connect successfully, this block will be called success.
/// @param failure      This block will be called if some error occurred.
- (void)connectWithDeviceInfo:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                      success:(TYSuccessHandler)success
                      failure:(TYFailureError)failure;

/// Disconnect device
///
/// @param deviceInfo   Tuya BEL protocol-based device object.
/// @param success      When disconnect successfully, this block will be called success.
/// @param failure      This block will be called if some error occurred.
- (void)disconnectWithDeviceInfo:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                         success:(TYSuccessHandler)success
                         failure:(TYFailureError)failure;

/// Remove device
///
/// @param deviceInfo   Tuya BEL protocol-based device object.
/// @param success      When remove successfully, this block will be called success.
/// @param failure      This block will be called if some error occurred.
- (void)removeWithDeviceInfo:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                     success:(TYSuccessHandler)success
                     failure:(TYFailureError)failure;

/// Restore factory settings
///
/// @param deviceInfo   Tuya BEL protocol-based device object.
/// @param success      When reset successfully, this block will be called success.
/// @param failure      This block will be called if some error occurred.
- (void)resetWithDeviceInfo:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                    success:(TYSuccessHandler)success
                    failure:(TYFailureError)failure;

/// Send OTA package to upgrade firmware.
///
/// The `otaData`、`otaType` and `otaVersion` can be obtained from TuyaSmartFirmwareUpgradeModel. You can get TuyaSmartFirmwareUpgradeModel by TuyaSmartDevice::getFirmwareUpgradeInfo:failure: .
///
/// @note Please make sure your device is connected via Bluetooth before upgrading.
///
/// @param deviceInfo   Tuya BEL protocol-based device object.
/// @param otaData      The OTA package data.
/// @param otaType      The OTA type.
/// @param otaVersion   The OTA version.
/// @param success      When ota successfully, this block will be called success.
/// @param failure      This block will be called if some error occurred.
- (void)sendOTAPackWithDeviceInfo:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo
                          otaData:(NSData *)otaData
                          otaType:(TuyaSmartBLEOTAType)otaType
                       otaVersion:(NSString *)otaVersion
                          success:(TYSuccessHandler)success
                          failure:(TYFailureError)failure;

/// Get the RSSI of the BLE device
///
/// @param deviceInfo       Tuya BEL protocol-based device object.
///
/// @return The RSSI of the BLE device
- (NSInteger)peripheralRSSI:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo;

/// Get the local connection status of the BLE device by deviceInfo
///
/// @param deviceInfo       Tuya BEL protocol-based device object.
///
/// @return The local connection status of the BLE device
- (BOOL)deviceOnlineState:(id<TuyaSmartBLEDeviceProtocol>)deviceInfo;

@end

#pragma mark -------------------------------------------------------------


#pragma mark - Device Protocol

@protocol TuyaSmartBLEDeviceProtocol <NSObject>

/// Tuya BLE agent.
@property (nonatomic, strong) TYBLEAgent                        *agent;

/// Tuya BLE peripheral.
@property (nonatomic, strong) TYBLEPeripheral                   *peripheral;

/// Tuya BLE advertising model.
@property (nonatomic, strong) TYBLEAdvModel                     *advModel;

/// Tuya active protocol-based manager object.
@property (nonatomic, strong) id<TuyaSmartBLEActiveProtocol>    activeManager;

/// Tuya config protocol-based manager object.
@property (nonatomic, strong) id<TuyaSmartBLEConfigProtocol>    configManager;


@optional
/// Methods for initializing TuyaSmartBLEDeviceProtocol-based device objects.
///
/// @param activeManager      Tuya active protocol-based manager object.
/// @param configManager      Tuya config protocol-based manager object.
- (instancetype)initWithActiveManager:(id<TuyaSmartBLEActiveProtocol>)activeManager
                        configManager:(id<TuyaSmartBLEConfigProtocol>)configManager;

@end

NS_ASSUME_NONNULL_END
